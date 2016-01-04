//
// Copyright 2008, 2009 Vasileios P. Kemerlis (aka vpk)
//                              vpk@cs.columbia.edu
//                              http://www.cs.columbia.edu/~vpk
//

// This file is part of BitTorrent Implementation for OMNeT++.

//    BitTorrent Implementation for OMNeT++ is free software: you can redistribute
//	  it and/or modify it under the terms of the GNU General Public License as
//    published by the Free Software Foundation, either version 2 of the License,
//	  or (at your option) any later version.

//    BitTorrent Implementation for OMNeT++ is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with BitTorrent Implementation for OMNeT++.
//    If not, see <http://www.gnu.org/licenses/>.


#include "BTTrackerMsg_m.h"
#include "BTTrackerClientBase.h"

#define BEV	EV << "[" << peerId_var << "]::[Tracker Client]: "

Define_Module(BTTrackerClientBase)
;

/**
 * Constructor.
 */
BTTrackerClientBase::BTTrackerClientBase() {
	evtTout = new cMessage(NULL, EVT_TOUT);
}

/**
 * Destructor.
 */
BTTrackerClientBase::~BTTrackerClientBase() {
	// delete any pending events
	cancelAndDelete(evtTout);
}

/**
 * Called after the module creation.
 */
void BTTrackerClientBase::initialize() {
	// parent initialize()
	TCPGenericCliAppBase::initialize();

	// member init
	state_var = ST_STARTED;
	transient_var = 0;
	trackerId_var = "";
	connectGiveUp_var = (size_t) par("connectGiveUp");
	sessionTimeout_var = (simtime_t) par("sessionTimeout");
	reconnectInterval_var = (simtime_t) par("reconnectInterval");
	infoHash_var = par("infoHash").stdstringValue();
	peerPort_var = (size_t) par("peerPort");
	compact_var = (bool) par("compact");
	noPeerId_var = (bool) par("noPeerId");
	numWant_var = (size_t) par("numWant");
	key_var = par("key").stdstringValue();
	//connectPort			= par("connectPort").doubleValue();
	//The peerID shall be unique for each peer, so it cannot be retrieved
	// from a parameter.
	peerId_var = generatePeerID();

	// watches
	WATCH(state_var);
	WATCH(transient_var);
	WATCH(trackerId_var);
	WATCH(ipaddress_var);
	WATCH(connectGiveUp_var);
	WATCH(sessionTimeout_var);
	WATCH(reconnectInterval_var);
	WATCH(infoHash_var);
	WATCH(peerId_var);
	WATCH(peerPort_var);
	WATCH(compact_var);
	WATCH(noPeerId_var);
	WATCH(numWant_var);
	WATCH(key_var);
}

/**
 * Called each time a new message is received.
 */
void BTTrackerClientBase::handleMessage(cMessage* msg) {
	BEV<<">>>>>>>>>>Receiving Message Kind: "<<msg->getKind()<<" -- Name: "<<msg->getName() << "\n";
	if(msg->isSelfMessage() || msg->arrivedOn("btorrentIn"))
	{
		handleTimer(msg);
	}
	else
	{
		BEV<<">>>>>>>>>>Message needs to be processed by socket \n";
		socket.processMessage(msg);
	}
}

/**
 * Called from handleTimer() each time a self message or a message from btorrentIn gate is received.
 */
void BTTrackerClientBase::handleTimer(cMessage *msg) {

	// different actions for each event
	switch (msg->getKind()) {
	// complete event
	case EVT_COMP:
		// changing state to COMPLETED
		transient_var = ST_TRANS_COMP;
		// this type of message was not self scheduled - dispose it
		if (msg) {
			delete msg;
			msg = NULL;
		}
		break;

		// stop event
	case EVT_STOP:
		// changing state to STOPPED
		transient_var = ST_TRANS_STOP;
		// this type of message was not self scheduled - dispose it
		if (msg) {
			delete msg;
			msg = NULL;
		}
		break;

		// connect event
	case EVT_CONN:
		// changing state to NORMAL
		transient_var = ST_TRANS_NORM;

		// this type of message was not self scheduled - dispose it
		if (msg) {
			delete msg;
			msg = NULL;
		}
		break;

		// session timeout and error events
	case EVT_TOUT:

		// logging
		BEV<< "session with Tracker[address=" << par("connectAddress").stringValue() << ", port=" << par("connectPort").doubleValue() << "] expired\n";

		// close the pending connection - if it is still in pending state
		if(socket.getState() == TCPSocket::CONNECTING || socket.getState() == TCPSocket::CONNECTED || socket.getState() == TCPSocket::PEER_CLOSED)
		close();

		// retry up to connectGiveUp_var times
		if(--connectGiveUp_var > 0)
		{
			// logging
			BEV << "scheduling another try at " << reconnectInterval_var << "secs\n";

			// schedule a future connect event
			switch(transient_var)
			{
				// we were about to complete - schedule another EVT_COMP
				case ST_TRANS_COMP:
				scheduleAt(simTime() + reconnectInterval_var, new cMessage(NULL, EVT_COMP));
				break;

				// we were about to stop - schedule another EVT_STOP
				case ST_TRANS_STOP:
				scheduleAt(simTime() + reconnectInterval_var, new cMessage(NULL, EVT_STOP));
				break;

				// normal - schedule another EVT_CONN
				case ST_TRANS_NORM:
				scheduleAt(simTime() + reconnectInterval_var, new cMessage(NULL, EVT_CONN));
				break;

				// error - timeout while not being on a transient state
				default:
				// report the error
				error("%s:%d at %s() timeout occured while not being on transient state(transient_var=%d)\n", __FILE__, __LINE__, __func__, transient_var);
			}
		}

		// reset transient stuff
		transient_var = 0;
		// finish - do not go any further
		return;
		break;

		// error - unknown event
		default:
		// report the error
		error("%s:%d at %s() unknown event(kind=%d) occured\n", __FILE__, __LINE__, __func__, msg->getKind());
	}

	// we should reach this point only if a timeout did not occur

	// logging
	BEV << "connecting to Tracker[address=" << par("connectAddress").stringValue() << ", port=" << par("connectPort").doubleValue() << "]\n";

	// grab my IP address
	findAndSetIPAddress();
	// fire the actual connect() - TCP
	connect();
}

/**
 * Starts a new connection.
 *
 * This method should be re-implemented in future subclasses in order to extend/add/change the behavior of the client.
 */
void BTTrackerClientBase::connect() {
	// logging
	BEV<< "starting session timer[" << sessionTimeout_var << " secs]\n";

	// schedule a session timeout and call default connect()
	scheduleAt(simTime() + sessionTimeout_var, evtTout);
	TCPGenericCliAppBase::connect();
}

/**
 * Closes an active connection
 */
void BTTrackerClientBase::close() {

	// cancel the session timeout event and call default close()
	cancelEvent(evtTout);
	TCPGenericCliAppBase::close();
}

/**
 * Starts a session and performs some logging.
 *
 * This method should be re-implemented in future subclasses in order to extend/add/change the behavior of the client.
 */
void BTTrackerClientBase::socketEstablished(int connId, void *ptr) {
	// default handling
	TCPGenericCliAppBase::socketEstablished(connId, ptr);

	// logging
	BEV<< "connected to Tracker[address=" << par("connectAddress").stringValue() << ", port=" << par("connectPort").doubleValue() << "]\n";

	// perform the announce
	announce();
}

/**
 * Generates an Azureus-style 20 character long, unique peer ID, with:
 * 	- client ID = 'OM' (OMnet++)
 * 	- version number  = 0001
 * (See  http://wiki.theory.org/BitTorrentSpecification for more information)
 *
 * The peer ID is augmented with the hosting module's name, for clarity/debugging purposes.
 *
 * This method should be re-implemented in future subclasses in order to change the.way peer IDs are generated.
 */
const char* BTTrackerClientBase::generatePeerID() {
	string strID("-OM0001-");
	stringstream oss;
	string moduleName(getParentModule()->getFullName());
	oss << moduleName;

	oss << strID;

	for (int i = 0; i < 12; i++)
		oss << intrand(10);

	return oss.str().c_str();
}

/**
 * Handles the response from the tracker.
 *
 * This method should be re-implemented in future subclasses in order to extend/add/change the behavior of the client.
 */
void BTTrackerClientBase::socketDataArrived(int connId, void *ptr,
		cPacket *msg, bool urgent) {
	// cast the response
	BTTrackerMsgResponse* mmsg = dynamic_cast<BTTrackerMsgResponse*>(msg);
	// invalid message type received
	if(!mmsg)
	{
		delete mmsg;
		// report the error
		error("%s:%d at %s() invalid message received, should be a BTTrackerMsgResponse\n", __FILE__, __LINE__, __func__);
	}

	// logging
	BEV << "announce reply from Tracker[address=" << par("connectAddress").stringValue() << ", port=" << par("connectPort").doubleValue() << "]\n";

	// we have a valid reply - reset previous failures
	connectGiveUp_var = (size_t)par("connectGiveUp");

	// differentiate based on the actual state (we should be on a transient state)
	switch(transient_var)
	{
		// move to COMPLETED state
		case ST_TRANS_COMP:
		state_var = ST_COMPLETED;
		break;

		// move to STOPPED state
		case ST_TRANS_STOP:
		state_var = ST_STOPPED;
		break;

		// move to NORMAL state
		case ST_TRANS_NORM:
		state_var = ST_NORMAL;
		break;

		// error - invalid state
		case 0:
		default:
		{

			// report the error
			error("%s:%d at %s() invalid state occured, should a transient state(state_var=%d, transient_var=%d) occured (simTime() = %f)\n", __FILE__, __LINE__, __func__, state_var, transient_var, SIMTIME_DBL(simTime()));

		}

	}

	// grab tracker id, if the tracker returned it to us
	if(strlen(mmsg->trackerId()) > 0)
	{
		trackerId_var = mmsg->trackerId();
	}
	// default handling
	packetsRcvd++;
	bytesRcvd += mmsg->getByteLength();
	// we changed state
	transient_var = 0;

	// forward the message to the btorrent application
	send(mmsg, "btorrentOut");
	// connection teardown
	close();
}

	/**
	 * Handles the connection teardown.
	 *
	 * This method should be re-implemented in future subclasses in order to extend/add/change the behavior of the client.
	 */
void BTTrackerClientBase::socketPeerClosed(int connId, void *yourPtr) {
	// the tracker closed the connection while been in a transient state
	if (transient_var != 0) {
		// logging
		BEV<< "session with Tracker[address=" << par("connectAddress").stringValue() << ", port=" << par("connectPort").doubleValue() << "] ended unexpectedly\n";

		// fire the timeout event to handle possible errors
		cancelEvent(evtTout);
		scheduleAt(simTime(), evtTout);

		// default handling
		EV << "remote TCP closed, closing here as well\n";
	}
}

/**
 * Handles connection failures.
 *
 * This method should be re-implemented in future subclasses in order to extend/add/change the behavior of the client.
 */
void BTTrackerClientBase::socketFailure(int connId, void *yourPtr, int code) {
	// default handling
	TCPGenericCliAppBase::socketFailure(connId, yourPtr, code);

	// error in the connection while been in a transient state
	if (transient_var != 0) {
		// logging
		BEV<< "session with Tracker[address=" << par("connectAddress").stringValue() << ", port=" << par("connectPort").doubleValue() << "] died unexpectedly\n";

		// fire the timeout event to handle possible errors
		cancelEvent(evtTout);
		scheduleAt(simTime(), evtTout);
	}
}

/**
 * Sends an announce to the tracker.
 *
 * This method should be re-implemented in future subclasses in order to extend/add/change the behavior of the client.
 */
void BTTrackerClientBase::announce() {
	// get an annouse message
	BTTrackerMsgAnnounce *msg = new BTTrackerMsgAnnounce();

	// mandatory fields
	msg->setInfoHash(infoHash().c_str());
	msg->setPeerId(peerId().c_str());
	msg->setPeerPort(peerPort_var);
	msg->setTrackerId(trackerId_var.c_str()); // will be "" at the beginning
	msg->setCompact(compact_var);
	msg->setNoPeerId(noPeerId_var);
	msg->setNumWant(numWant_var);
	msg->setKey(key_var.c_str());

	// differentiate based on the actual state (we should be on a transient state)
	switch (transient_var) {
	// going to completed
	case ST_TRANS_COMP:
		msg->setEvent(A_COMPLETED); // completed event
		break;

		// going to stopped
	case ST_TRANS_STOP:
		msg->setEvent(A_STOPPED); // stopped event
		break;

		// going to normal
	case ST_TRANS_NORM:
		if (state_var == ST_STARTED) {
			msg->setEvent(A_STARTED); // started event
		} else {
			msg->setEvent(A_NORMAL); // normal event
		}
		break;

		// error - invalid state
	case 0:
	default:
		// report the error
		error(
				"%s:%d at %s() invalid state occured, should a transient state(state_var=%d, transient_var=%d) occured (simTime() = %f)\n",
				__FILE__, __LINE__, __func__, state_var, transient_var,
				SIMTIME_DBL(simTime()));
	}

	// set the announce size
	findAndSetAnnounceSize(msg);

	// update the statistics
	packetsSent++;
	bytesSent += msg->getByteLength();

	// logging
	BEV<< "sending announce to Tracker[address=" << par("connectAddress").stringValue() << ", port=" << par("connectPort").doubleValue() << "]\n";

	// send the announce
	socket.send(msg);

	// in case of a stopped event issue a session close immediately after the announce
	if(transient_var == ST_TRANS_STOP)
	{
		transient_var = 0;
		close();
	}
}

/**
 * Set the size of the announce message.
 *
 * This method should be re-implemented in future subclasses in order to extend/add/change the behavior of the client.
 */
void BTTrackerClientBase::findAndSetAnnounceSize(cMessage* msg) const {
	// cast the message
	BTTrackerMsgAnnounce* mmsg = dynamic_cast<BTTrackerMsgAnnounce*> (msg);
	if (mmsg) // success
	{
		string httpHeader = "Content-Type: text/plain; \n\n";
		//FIXME: use some readable macro here...
		int msgLength = (httpHeader.length() * sizeof(char)) + 20 + 20 + 2
				+ (trackerId_var.length() * sizeof(char)) + 1 + 1 + 2 + 4;
		mmsg->setByteLength(msgLength); // FIXME
	} else // failure
	{
		// report the error
		error(
				"%s:%d at %s() invalid message, should be of BTTrackerMsgAnnounce type\n",
				__FILE__, __LINE__, __func__);
	}
}

/**
 * Find the IP address of the client.
 *
 * This method should be re-implemented in future subclasses in order to extend/add/change the behavior of the client.
 */
void BTTrackerClientBase::findAndSetIPAddress() {
	IInterfaceTable* ift = NULL;
	InterfaceEntry* iff = NULL;
	cModule* mod = this;

	// traverse the hierarchy to grab the interface table
	while ((ift = IPAddressResolver().findInterfaceTableOf(mod)) == NULL)
		mod = mod->getParentModule();

	// no interface table found? -- something nasty is happening here
	if (ift == NULL)
		// report the error
		error("%s:%d at %s() self-address resolution failed\n", __FILE__,
				__LINE__, __func__);

	// traverse the interface table and grab the appropriate IP address
	for (int i = 0; i < ift->getNumInterfaces(); i++) {
		iff = ift->getInterface(i);

		// ignore loopbacks
		if (iff->isLoopback())
			continue;

		// if the interface has an IPv4 address then use it
		if (iff->ipv4Data() != NULL) {
			// update the address value
			ipaddress_var = IPvXAddress(
					iff->ipv4Data()->getIPAddress().str().c_str());
			// update the address parameter - just in case other objects use it (e.g., TCPSocket...)
			par("address").setStringValue(ipaddress_var.str().c_str());
			break;
		}
		// try with IPv6
		else {
			// update the address value
			ipaddress_var = IPvXAddress(
					iff->ipv6Data()->getPreferredAddress().str().c_str());
			// update the address parameter - just in case other objects use it (e.g., TCPSocket...)
			par("address").setStringValue(ipaddress_var.str().c_str());
			break;
		}
	}
}

/**
 * Get the state of the client.
 */
size_t BTTrackerClientBase::cstate() const {
	return state_var;
}

/**
 * Set the state of the client.
 */
void BTTrackerClientBase::setCstate(size_t state) {
	state_var = state;
}

/**
 * Get the tracker id.
 */
const string& BTTrackerClientBase::trackerId() const {
	return trackerId_var;
}

/**
 * Set the tracker id.
 */
void BTTrackerClientBase::setTrackerId(const string& trackerId) {
	trackerId_var = trackerId;
}

/**
 * Get the re-connect tries.
 */
size_t BTTrackerClientBase::connectGiveUp() const {
	return connectGiveUp_var;
}

/**
 * Set the re-connect tries.
 */
void BTTrackerClientBase::setConnectGiveUp(size_t connectGiveUp) {
	connectGiveUp_var = connectGiveUp;
}

/**
 * Get the session timeout (seconds).
 */
simtime_t BTTrackerClientBase::sessionTimeout() const {
	return sessionTimeout_var;
}

/**
 * Set the session timeout (seconds).
 */
void BTTrackerClientBase::setSessionTimeout(simtime_t sessionTimeout) {
	sessionTimeout_var = sessionTimeout;
}

/**
 * Get the re-connect interval.
 */
double BTTrackerClientBase::reconnectInterval() const {
	return SIMTIME_DBL(reconnectInterval_var);
}

/**
 * Set the re-connect interval.
 */
void BTTrackerClientBase::setReconnectInterval(double reconnectInterval) {
	reconnectInterval_var = reconnectInterval;
}

/**
 * Get the info hash.
 */
const string& BTTrackerClientBase::infoHash() const {
	return infoHash_var;
}

/**
 * Set the info hash.
 */
void BTTrackerClientBase::setInfoHash(const string& infoHash) {
	infoHash_var = infoHash;
}

/**
 * Get the peer id.
 */
const string& BTTrackerClientBase::peerId() const {
	return peerId_var;
}

/**
 * Set the peer id.
 */
void BTTrackerClientBase::setPeerId(const string& peerId) {
	peerId_var = peerId;
}

/**
 * Get the peer port.
 */
size_t BTTrackerClientBase::peerPort() const {
	return peerPort_var;
}

/**
 * Set the peer port.
 */
void BTTrackerClientBase::setPeerPort(size_t peerPort) {
	peerPort_var = peerPort;
}

/**
 * Get the compact flag.
 */
bool BTTrackerClientBase::compact() const {
	return compact_var;
}

/**
 * Set the compact flag.
 */
void BTTrackerClientBase::setCompact(bool compact) {
	compact_var = compact;
}

/**
 * Get the no_peer_id flag.
 */
bool BTTrackerClientBase::noPeerId() const {
	return noPeerId_var;
}

/**
 * Set the no_peer_id flag.
 */
void BTTrackerClientBase::setNoPeerId(bool noPeerId) {
	noPeerId_var = noPeerId;
}

/**
 * Get the numWant peers count.
 */
size_t BTTrackerClientBase::numWant() const {
	return numWant_var;
}

/**
 * Set the numWant peers count.
 */
void BTTrackerClientBase::setNumWant(size_t numWant) {
	numWant_var = numWant;
}

/**
 * Get the peer's key.
 */
const string& BTTrackerClientBase::key() const {
	return key_var;
}

/**
 * Set the peer's key.
 */
void BTTrackerClientBase::setKey(const string& key) {
	key_var = key;
}
