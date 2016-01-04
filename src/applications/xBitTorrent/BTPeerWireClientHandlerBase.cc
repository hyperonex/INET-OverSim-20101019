//
// Copyright 2009 Konstantinos V. Katsaros
//                              ntinos@aueb.gr
//                              http://mm.aueb.gr/~katsaros
//
// Copyright 2015 Achraf Gazdar
//                              agazdar@ksu.edu.sa
//								achraf.gazdar@gmail.com

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


#include "BTPeerWireBase.h"
#include "BTPeerWireClientHandlerBase.h"
#include "BTPeerWireCacheThread.h"

#define BTEV	EV << "[" << getHostModule()->getParentModule()->getFullName() << "]:[PeerWire Thread]: "
#define BTEV_VERB	EV << "[" << getHostModule()->getParentModule()->getFullName() << "]<=>["<< getRemotePeerID()<<"]: "

Register_Class( BTPeerWireClientHandlerBase);
#define DEBUG_CLASS false
BTPeerWireClientHandlerBase::BTPeerWireClientHandlerBase() {
	setAmChoking(false);
	setAmInterested(false);
	setPeerChoking(false);
	setPeerInterested(false);

	setState(INITIAL);

	setThreadRemovelScheduled(false);

	evtIsAlive = new cMessage(peerWireBase->toString(IS_ALIVE_TIMER),
			IS_ALIVE_TIMER);
	evtKeepAlive = new cMessage(peerWireBase->toString(KEEP_ALIVE_TIMER),
			KEEP_ALIVE_TIMER);
	evtDelThread = new cMessage(peerWireBase->toString(DEL_THREAD_TIMER),
			DEL_THREAD_TIMER);
	// Anti-snubbing  not actually supported due to contradictory definitions...
	//evtAntiSnub  = 	new cMessage(peerWireBase->toString(ANTI_SNUB_TIMER), ANTI_SNUB_TIMER);
	delThreadMsg = new BTInternalMsg(peerWireBase->toString(
			INTERNAL_REMOVE_THREAD_MSG), INTERNAL_REMOVE_THREAD_MSG);
	evtMeasureDownloadRate = new cMessage(peerWireBase->toString(
			INTERNAL_MEASURE_DOWNLOAD_RATE_TIMER),
			INTERNAL_MEASURE_DOWNLOAD_RATE_TIMER);
	evtMeasureUploadRate = new cMessage(peerWireBase->toString(
			INTERNAL_MEASURE_UPLOAD_RATE_TIMER),
			INTERNAL_MEASURE_UPLOAD_RATE_TIMER);
	lastDownloadTime_var = 0;
	setDownloadRate(0);
	lastUploadTime_var = simTime();
	firstTimeHere = true;
	setUploadRate(0);
	setConnectTimeShift( simTime());
	setOptimisticallyUnchoked(false);
	setSeeder(false);
	setInEndGame(false);
	setIsCacheThread(true);

}

BTPeerWireClientHandlerBase::~BTPeerWireClientHandlerBase() {

	//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]<=>["<< getRemotePeerID()<<"]: "<< "Cleaning in destructor... " << endl;
	if (remoteBitfield)
		delete remoteBitfield;
	if (evtDelThread)
		cancelAndDelete(evtDelThread);
	if (delThreadMsg)
		cancelAndDelete(delThreadMsg);
	if (evtMeasureDownloadRate)
		cancelAndDelete(evtMeasureDownloadRate);
	//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]<=>["<< getRemotePeerID()<<"]: "<< "...done cleaning in destructor. " << endl;

}

void BTPeerWireClientHandlerBase::cancelAndDelete(cMessage* msg) {
	getHostModule()->cancelAndDelete(msg);
}

void BTPeerWireClientHandlerBase::established() {
	//Connection established but in the mean time it was ordered to close!
	if (getState() == EARLY_ABORTING) {
		closeConnection();
		return;
	}

	setState(CONNECTED);

	BTEV<<"connection established."<<endl;

	Keep_Alive_Duration = ((BTPeerWireBase*)getHostModule())->keepAlive();
	renewAliveTimer(evtIsAlive);
	renewAliveTimer(evtKeepAlive);

	((BTPeerWireBase*)getHostModule())->increaseCurrentNumConnections();

		if (activeConnection())
		{
			BTEV_VERB<<"connection accepted by remote peer "<< getRemotePeerID() <<", sending Handshake msg."<<endl;
			setState(ACTIVE_HANDSHAKE);
			BTMsgHandshake* handShakeMsg = (BTMsgHandshake*)createBTPeerWireMessage(peerWireBase->toString(HANDSHAKE_MSG),HANDSHAKE_MSG);
			sendMessage(handShakeMsg);
		}
}

void BTPeerWireClientHandlerBase::init(TCPSrvHostApp* hostmodule,
		TCPSocket* socket) {

	TCPServerThreadBase::init(hostmodule, socket);
	peerWireBase = (BTPeerWireBase*) getHostModule();
	remoteBitfield = new BitField(peerWireBase->numPieces(),
			peerWireBase->numBlocks(), false);
	remoteBitfield->setLocal(false);

	scheduleAt(simTime(), evtMeasureDownloadRate);

	trackerClient
			= (BTTrackerClientBase*) peerWireBase->getParentModule()->getSubmodule(
					"trackerClient");
	requests.setMaxSize(peerWireBase->requestQueueDepth());
	requests.setCheckSize(true);
	chokedRequests.setMaxSize(peerWireBase->requestQueueDepth());
	chokedRequests.setCheckSize(false);
	incomingRequests.setMaxSize(peerWireBase->requestQueueDepth());
	incomingRequests.setCheckSize(false);
	chokedIncomingRequests.setMaxSize(peerWireBase->requestQueueDepth());
	chokedIncomingRequests.setCheckSize(false);

	setLastChokeUnchoke(0);
	setConnectTimeShift( simTime());
	setAllowedToRequest(true);
}

void BTPeerWireClientHandlerBase::dataArrived(cMessage* mmsg, bool urgent) {

	cMessage* msg;
	if (getState() < CONNECTED) {
		BTEV_VERB<<"the connection is being torn down. Discarding received message ..."<<endl;
		msg = (dynamic_cast<cPacket*>(mmsg))->decapsulate();
		//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]<=>["<< getRemotePeerID()<<"]: "<< "In dataArrived. Deleting msg because we are not connected... " << endl;
		delete mmsg;
		delete msg;
		//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]<=>["<< getRemotePeerID()<<"]: "<< "...In dataArrived. Done deleting msg because we are not connected. " << endl;
		return;
	}

	msg = (dynamic_cast<cPacket*>(mmsg))->decapsulate();

	delete mmsg;

	if (msg->getKind() == HANDSHAKE_MSG) {
		setIsCacheThread(false);
		initiatePeerWireProtocol(msg);
	}
	else
	{
		if(!isCacheThread())
		handleRemotePeerMessage(msg);
		else {
			if(firstTimeHere) {
				firstTimeHere = false;
				initiateCacheThread();
			}
			handleCacheMessage(msg);
		}
	}//else
}

void BTPeerWireClientHandlerBase::handleCacheMessage(cMessage* msg) {
	switch (msg->getKind()) {
	case HTTP_REQUEST_MSG: {//this is the only
		//FIXME: Should consider moving it to a separate method, for clarity reasons ...
		renewAliveTimer(evtIsAlive);
		//FW this msg to the main application to be handled by the HttpVideoServer
		httptRequestMessage* request = check_and_cast<httptRequestMessage*> (
				msg);
		BTEV_VERB<<"Forwarding the HTTP_REQUEST_MSG to the VideoHttpServer for URI: "<<request->uri()<<endl;
		scheduleAt(simTime(), request);
		break;

	}
	default:
	getHostModule()->error("%s:%d at %s() Uknown peer-wire protocol message received from the cache (msg->getKind() = %d).\n", __FILE__, __LINE__, __func__,msg->getKind());
}//switch
}

void BTPeerWireClientHandlerBase::handleRemotePeerMessage(cMessage* msg) {

	if (getState() >= HANDSHAKE_COMPLETE) {
		switch (msg->getKind()) {
		case KEEP_ALIVE_MSG: {
			//If we haven't Handshaked it is not expected to receive a Keep-Alive msg.
			BTEV_VERB<<"received Keep-Alive message."<<endl;
			BTKeepAliveMsg* keepAliveMsg = check_and_cast<BTKeepAliveMsg*>(msg);
			renewAliveTimer(evtIsAlive);
			delete keepAliveMsg;
			break;
		}//KEEP_ALIVE_MSG
		case CHOKE_MSG:
		{
			BTEV_VERB<<"received Choke message."<<endl;
			setPeerChoking(true);
			renewAliveTimer(evtIsAlive);
			printState();
			clearPendingRequests();
			cancelEvent(evtMeasureDownloadRate);
			delete msg;
			break;
		}//CHOKE_MSG
		case UNCHOKE_MSG:
		{
			BTEV_VERB<<"received Unchoke message."<<endl;
			setPeerChoking(false);
			renewAliveTimer(evtIsAlive);
			printState();

			//The peer has unchoked us, if we are interested in this peer we shall begin
			//sending requests for specific blocks. So we have to inform the application
			//to decide which piece we shall request.
			if (amInterested())
			scheduleAt(simTime(), msg);
			else
			delete msg;

			break;
		}//UNCHOKE_MSG
		case INTERESTED_MSG:
		{
			BTEV_VERB<<"received Interested message."<<endl;
			setPeerInterested(true);
			renewAliveTimer(evtIsAlive);
			printState();

			if (!amChoking())
			scheduleAt(simTime(), msg);
			else
			delete msg;
			break;
		}//INTERESTED_MSG
		case NOT_INTERESTED_MSG:
		{
			BTEV_VERB<<"received Not-Interested message."<<endl;
			setPeerInterested(false);
			renewAliveTimer(evtIsAlive);
			printState();
			delete msg;
			break;
		}//NOT_INTERESTED_MSG
		case HAVE_MSG:
		{
			BTHaveMsg* have = check_and_cast<BTHaveMsg*>(msg);
			BTEV_VERB<<"received Have message for piece #"<<have->index()<<endl;
			//Update the bietfield for this peer
			remoteBitfield->update(have->index());
			//FW to application, in order to update this piece's frequence
			scheduleAt(simTime(), have);
			renewAliveTimer(evtIsAlive);
			break;
		}//HAVE_MSG
		case BITFIELD_MSG:
		{
			BTBitfieldMsg* bitfield = check_and_cast<BTBitfieldMsg*>(msg);

			if (bitfield->bitfieldArraySize()!= (unsigned short)(peerWireBase->numPieces()))
			{
				BTEV_VERB<<"recieved Bitfield of incorrect length i.e. "<< bitfield->bitfieldArraySize()<< " != "<< peerWireBase->numPieces() <<" ! Aborting connection ... "<<endl;

				closeConnection();
			}
			else
			{
				//Now check the bietfield to see if there is something interesting there
				//and if so (maybe) schedule an Interested message.
				BTEV_VERB<<"recieved Bitfield"<<endl;
				renewAliveTimer(evtIsAlive);

				//Assuming the same number of Blocks!
				delete remoteBitfield;
				remoteBitfield = NULL;

				remoteBitfield = new BitField(bitfield,peerWireBase->numBlocks());

				//FW this msg to the main application
				scheduleAt(simTime(), bitfield);

				// TODO: Use a flag here to check whether we have already sent a bitfield
				// OR just leave it as is i.e. send the bitfield only immediately after
				// handshaking.
			}

			//printState();
			break;
		}//BITFIELD_MSG
		case REQUEST_MSG:
		{
			//FIXME: Should consider moving it to a separate method, for clarity reasons ...
			renewAliveTimer(evtIsAlive);

			if ((!amChoking())&&(peerInterested()))
			{
				BTRequestCancelMsg* req = (BTRequestCancelMsg*)msg;

				BTEV_VERB<<"received Request message for piece: "<< req->index() <<", block : "<<req->begin() <<endl;

				if(LOGFILE) {
					//cerr<<"Writing log: "<< "RREQ: " << simTime().str().c_str()<< " "<< req->index() << " " <<req->begin()<<endl;
					std::stringstream log;
					log << "RREQ: " << simTime().str().c_str()<< " "<< req->index() << " " <<req->begin();
					peerWireBase->writeLog(log.str().c_str());
				}

				if (peerWireBase->localBitfield()->isBlockAvailable(req->index(),req->begin()))
				{

					//Actually not implementing anti-snubbing at the moment (due to contradictory definitions).
					if (getState() <ANTI_SNUBBING)
					{

						RequestEntry entry(req->index(),req->begin(),req->dataLength(),simTime(),getRemotePeerID().c_str(),NULL);
						incomingRequests.insert(entry);

						scheduleAt(simTime(),new cMessage(peerWireBase->toString(PIECE_TIMER),PIECE_TIMER));

						//If we are in super-seed mode and we just sent the last block, we shall inform
						//this client of another piece only if we see the current piece in another
						//peer's bitfield
						if ((peerWireBase->superSeedMode()) && (req->begin() == peerWireBase->numBlocks()-1))
						{
							BTInternalMsg* intMsg = new BTInternalMsg(peerWireBase->toString(INTERNAL_SUPER_SEED_COMPLETE_MSG),INTERNAL_SUPER_SEED_COMPLETE_MSG);
							intMsg->setPieceIndex(req->index());
							intMsg->setText(getRemotePeerID().c_str());
							scheduleAt(simTime(),intMsg);
						}
					}
					else
					{
						BTEV_VERB<<"client in anti-snubbing mode, refusing to send the piece."<<endl;
					}
				}
				else
				{
					BTEV_VERB<<"cannot serve request, requested block not available."<<endl;
				}
			}
			else
			{
				BTEV_VERB<<"cannot serve request, peer is choked."<<endl;
			}

			delete msg;
			break;
		}//REQUEST_MSG
		case HTTP_REQUEST_MSG:
		{
			//FIXME: Should consider moving it to a separate method, for clarity reasons ...
			renewAliveTimer(evtIsAlive);
			//FW this msg to the main application to be handled by the HttpVideoServer
			httptRequestMessage* request = check_and_cast<httptRequestMessage*>(msg);
			BTEV_VERB<<"Forwarding the HTTP_REQUEST_MSG to the VideoHttpServer heading: "<<request->heading()<<endl;
			if(LOGFILE) {
				std::stringstream log;
				string uri = request->uri();
				cStringTokenizer tokenizer = cStringTokenizer(uri.c_str(), "_");
				std::vector<string> params = tokenizer.asVector();

				int qlevel = strtol(params[1].c_str(), 0, 10);
				int piece = strtol(params[2].c_str(), 0, 10);
				int block = strtol(params[3].c_str(), 0, 10);
				//cerr<<"Writing log: "<< "HRREQ: " << simTime().str().c_str()<< " " << piece << " " << block << " " << qlevel<<endl;
				log << "HRREQ: " << simTime().str().c_str()<< " " << piece << " " << block << " " << qlevel;
				peerWireBase->writeLog(log.str().c_str());
			}
			scheduleAt(simTime(), request);
			break;

		}
		case PIECE_MSG:
		{
			//FIXME: Should consider moving it to a separate method, for clarity reasons ...
			renewAliveTimer(evtIsAlive);

			BTPieceMsg* piece = check_and_cast<BTPieceMsg*>(msg);

			//FW to application, in order to forward to the HttpVideoServer for updating
			scheduleAt(simTime(), piece);

			//Perform local bitfield updating
			int block = piece->begin();
			BTEV_VERB<<"received Piece message (data). Piece #"<<piece->index()<<", Block #"<<block<<endl;

			if(LOGFILE) {
				std::stringstream log;
				//cerr<<"Writing log: "<<"RPIECE: " << simTime().str().c_str() <<" "<< piece->index() << " " << block <<endl;
				log << "RPIECE: " << simTime().str().c_str() <<" "<< piece->index() << " " <<block;
				peerWireBase->writeLog(log.str().c_str());
			}

			int requestIndex = requests.findRequest(piece->index(),block);
			bool expected = true;
			if (requestIndex<0)
			expected = false;

			//Update our bitfield
			peerWireBase->updateBitField(piece->index(),block, expected, getRemotePeerID().c_str());

			if (getRemotePeerID().find("overlayTerminal-1")!=-1) {
				//printf(">>>%s Getting blocks from Seeder %s\n",getHostModule()->getParentModule()->getFullName(),getRemotePeerID().c_str());
				peerWireBase->increamentBlocksFromSeeder();
			} /*else
			 printf(">>>%s Getting blocks from Leecher %s \n",getHostModule()->getParentModule()->getFullName(),getRemotePeerID().c_str());*/

			if (expected)
			{
				//Update the download rate and remove the request from the queue
				updateDowloadRate(piece, requestIndex);

			}
			break;
		}//PIECE_MSG
		case HTTP_RESPONSE_MSG:
		{
			renewAliveTimer(evtIsAlive);
			double blockSize = 0.0;
			httptReplyMessage * response = check_and_cast<httptReplyMessage*>(msg);
			string uri = response->relatedUri();
			string responseOriginator = response->originatorUrl();
			cStringTokenizer tokenizer = cStringTokenizer(uri.c_str(),"_");
			std::vector<string> params = tokenizer.asVector();

			int qlevel = strtol(params[1].c_str(),0,10);
			int piece_index = strtol(params[2].c_str(),0,10);
			int block = strtol(params[3].c_str(),0,10);

			BTEV_VERB<<"received ***HTTP*** piece: "<< piece_index <<", block : "<< block <<endl;
			//printf("received ***HTTP*** piece: %d block : %d\n", piece_index, block);
			if(LOGFILE) {
				std::stringstream log;
				//cerr << "Writing log: "<< "HRPIECE: "<< simTime().str().c_str() << " " << piece_index << " " <<block << " " << qlevel << endl;
				log << "HRPIECE: "<< simTime().str().c_str() << " " << piece_index << " " <<block << " " << qlevel;
				peerWireBase->writeLog(log.str().c_str());
			}

			blockSize = getPayloadMessageLength(piece_index);
			BTRequestCancelMsg* req =
			(BTRequestCancelMsg*) createBTPeerWireMessage(
					peerWireBase->toString(REQUEST_MSG), REQUEST_MSG,
					piece_index, block, blockSize);

			BTPieceMsg* piece = (BTPieceMsg*)createBTPeerWireMessage(peerWireBase->toString(PIECE_MSG),PIECE_MSG,req->index(),req->begin(),req->dataLength());
			delete req;
			//FW to application, in order to forward to the HttpVideoServer for updating
			scheduleAt(simTime(), piece);

			//Perform local bitfield updating
			block = piece->begin();
			BTEV_VERB<<"received Piece message (data) through Http. Piece #"<<piece->index()<<", Block #"<<block<<endl;

			int requestIndex = requests.findRequest(piece->index(),block);
			bool expected = true;
			if (requestIndex<0)
			expected = false;

			//Update our bitfield
			peerWireBase->updateBitField(piece->index(),block, expected, getRemotePeerID().c_str());

			if (getRemotePeerID().find("overlayTerminal-1")!=-1
					||responseOriginator.find("overlayTerminal-1")!=-1) {
				//printf(">>>%s Getting blocks from a Seeder %s\n",getHostModule()->getParentModule()->getFullName() ,getRemotePeerID().c_str());
				peerWireBase->increamentBlocksFromSeeder();
			}/*else
			 printf(">>>%s Getting blocks from a Leecher%s\n",getHostModule()->getParentModule()->getFullName() ,getRemotePeerID().c_str());*/

			if (expected)
			{
				//renewAntiSnubTimer();
				//if (getState()==ANTI_SNUBBING)
				//setState(BITFIELD_COMPLETE);
				updateDowloadRate(piece, requestIndex);

			}
			delete msg;
			break;

		}//HTTP_RESPONSE_MSG
		case CANCEL_MSG:
		{
			BTEV_VERB<<"received Cancel message."<<endl;
			renewAliveTimer(evtIsAlive);
			cancelBlockRequest((BTRequestCancelMsg*)msg);
			break;
		}//CANCEL_MSG
		default:
		getHostModule()->error("%s:%d at %s() Uknown peer-wire protocol message (msg->getKind() = %d).\n", __FILE__, __LINE__, __func__,msg->getKind());
	}//switch
}
else
getHostModule()->error("%s:%d at %s() Invalid peer-wire protocol state, received unexpected msg (msg->getKind() = %d, state = %d).\n", __FILE__, __LINE__, __func__,msg->getKind(),getState());
}

void BTPeerWireClientHandlerBase::updateDowloadRate(BTPieceMsg* piece,
		int requestIndex) {
	//Collect sample for download rate calculation
	RequestEntry corrRequest = requests.getRequestEntry(requestIndex);
	simtime_t baseTime = max(lastDownloadTime_var, corrRequest.getTimestamp());

	float downloadRate = piece->getByteLength() / (simTime() - baseTime) / 1024;

	lastDownloadTime_var = simTime();
	downloadRateSamples.insert(downloadRateSamples.end(), downloadRate);

	//Take snapshots until we get enough samples
	if (getDownloadRate() == 0)
		setDownloadRate(downloadRate);

	if (!evtMeasureDownloadRate->isScheduled()) {
		scheduleAt(simTime(), new cMessage(
				"INTERNAL_RECORD_DATA_PROVIDER_TIMER",
				INTERNAL_RECORD_DATA_PROVIDER_TIMER));
	}

	BTEV_VERB<<"observed download rate ="<<getDownloadRate()<<" KB/sec"<<endl;
	//Remove request from the queue
	requests.removeRequest(requestIndex);

	//Check whether we can request one more block
	if ((requests.canRequestMore()) && (peerWireBase->getState() != ENDGAME))
	{
		int nextBlock = peerWireBase->localBitfield()->nextBlock(piece->index());

		if ((nextBlock>=0))
		{
			sendBlockRequests(piece->index(),nextBlock);
		}
		else
		{
			//We cannot request any other block for this piece, so we will try for another piece...
			scheduleAt(simTime(), new cMessage(peerWireBase->toString(INTERNAL_NEXT_REQUEST_MSG),INTERNAL_NEXT_REQUEST_MSG));
		}
	}

}
void BTPeerWireClientHandlerBase::initiateCacheThread() {
	setState(HANDSHAKE_COMPLETE);

}
void BTPeerWireClientHandlerBase::initiatePeerWireProtocol(cMessage* msg) {
	BTMsgHandshake* incomingHandShake = check_and_cast<BTMsgHandshake*> (msg);

	if (getState() == CONNECTED)
		setState(PASSIVE_HANDSHAKE);

	if (getState() == ACTIVE_HANDSHAKE) {
		//TODO: Check this only in the case of known peerIDs (i.e. not in compact mode)
		if (strcmp(incomingHandShake->peerId(), (getRemotePeerID()).c_str())
				!= 0) {
			BTEV_VERB<<"peer ID included in received Handshake does not match the expected. Received peerID='"<<incomingHandShake->peerId()<<"' Expected peerID: '"<< getRemotePeerID()<<"' Aborting connection ..."<<endl;

			closeConnection();
			delete msg;
			return;
		}
	}
	else if (getState() == PASSIVE_HANDSHAKE)
	{
		//Now that we have the peer ID we can update our peer state.
		BTInternalMsg* upmsg = new BTInternalMsg("Update peer entry",INTERNAL_UPDATE_THREAD_MSG);
		//The text field carries the IP+port tmp peer ID, while the PEER struct carries the
		//received peer ID.
		upmsg->setText(getRemotePeerID().c_str());
		setRemotePeerID(incomingHandShake->peerId());

		PEER peer;
		peer.peerId = *(new opp_string(getRemotePeerID().c_str()));
		upmsg->setPeer(peer);

		scheduleAt(simTime(),upmsg);
	}

	//Check if this is a handshake for the correct info_hash
	const char* info_hash = incomingHandShake->infoHash();
	if (!strcmp(trackerClient->infoHash().c_str(),info_hash))
	{
		renewAliveTimer(evtIsAlive);
		BTEV_VERB<<"received Handshake message"<<endl;
		//Now check whether we have already answered/or trigered this Handshake message.
		if (getState() == PASSIVE_HANDSHAKE)
		{
			BTEV_VERB<<"replying with a Handshake message."<<endl;
			BTMsgHandshake* response = (BTMsgHandshake*)createBTPeerWireMessage(peerWireBase->toString(HANDSHAKE_MSG),HANDSHAKE_MSG);
			sendMessage(response);
		}
		else if (getState() == ACTIVE_HANDSHAKE)
		{
			BTEV_VERB<<"have already exchanged Handshakes."<<endl;
		}
		else
		getHostModule()->error("%s:%d at %s() Invalid peer-wire protocol msg sequence (state = %d).\n", __FILE__, __LINE__, __func__,getState());

		//Either we have received or sent a handshake reply. In both cases we have completed
		//the peer-wire handshake procedure.
		setState(HANDSHAKE_COMPLETE);

		//We schedule the transmission of a bitfield message. In timerExpired() we will
		//check whether we have any piece or we should cancel (or postpone) this msg transmission.
		scheduleAt(simTime(), new cMessage(peerWireBase->toString(BITFIELD_TIMER),BITFIELD_TIMER));

		if (peerWireBase->superSeedMode())
		scheduleAt(simTime(),new cMessage(peerWireBase->toString(INTERNAL_SUPER_SEED_HAVE_MSG),INTERNAL_SUPER_SEED_HAVE_MSG));
	}
	else
	{
		BTEV_VERB<<"Handshake received for a torrent not served by this peer. Received info_hash="<<info_hash<<" Served info hash: "<< trackerClient->infoHash().c_str()<<" Aborting connection ..."<<endl;

		closeConnection();
	}

	delete incomingHandShake;
	incomingHandShake = NULL;

}

void BTPeerWireClientHandlerBase::sendMessage(cMessage* mmsg) {
	if (getState() >= CONNECTED) {
		/*if (isCacheThread())
		 if (mmsg->getKind() != HTTP_RESPONSE_MSG) {
		 BTEV_VERB<<"This is not an HTTP reply message to be sent to the cache. Deleting the message"<<endl;
		 delete mmsg;
		 return;
		 }*/

		mmsg->setTimestamp();
		cPacket* wrapper = new cPacket(mmsg->getName(), TCP_I_DATA);
		wrapper->encapsulate(dynamic_cast<cPacket*> (mmsg));

		sock->send(wrapper);
		if (!isCacheThread())
			renewAliveTimer(evtKeepAlive);
	} else {
		BTEV_VERB<<"cannot send message ("<<peerWireBase->toString(mmsg->getKind())<<"). Peers no longer connected."<<endl;
		delete mmsg;
	}
}

void BTPeerWireClientHandlerBase::timerExpired(cMessage *timer) {

	switch (timer->getKind()) {

	case IS_ALIVE_TIMER: {
		break;
	}
	case KEEP_ALIVE_TIMER: {
		BTEV_VERB<<"local Keep-Alive timer expired, sending KEEP-ALIVE message."<<endl;
		BTKeepAliveMsg* keepAlive = (BTKeepAliveMsg*)createBTPeerWireMessage(peerWireBase->toString(KEEP_ALIVE_MSG),KEEP_ALIVE_MSG);
		if(!isCacheThread())
		sendMessage(keepAlive);
		else
		delete keepAlive;
		break;
	}
	case DEL_THREAD_TIMER:
	{
		//It is possible for a client to close a connection on its part but then none of peerClosed, closed, failure
		//methods to be called. It is also possible for the remote peer to have its peerClosed called but not its closed or
		//failure. At least failure shoud be called (probably a bug!).So we set this timer to ensure our thread is removed.
		BTEV_VERB<<"the connection to the remote peer closed. Deleting serving thread."<<endl;
		//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]<=>["<< getRemotePeerID()<<"]: "<< "the connection to the remote peer closed. Deleting serving thread..."<<endl;

		/*if (evtIsAlive)
		 if(evtIsAlive->isScheduled())*/
		cancelAndDelete(evtIsAlive);
		evtIsAlive = NULL;
		//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]: "<< "Going to Delete evtKeepAlive..." << endl;
		/*if (evtKeepAlive)
		 if(evtKeepAlive->isScheduled())*///Error processing command ABORT: connection not open.

		cancelAndDelete(evtKeepAlive);
		evtKeepAlive = NULL;
		//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]: "<< "Going to abort socket and remove thread..." << endl;
		if (!delThreadMsg->isScheduled())
		{
			//if(sock->getState()!=CONNECTED /* +++> */ && sock->getState() != RECEIVING && sock->getState() != ACCEPTING /* <+++ */
			/*&& sock->getState()!=PEER_CLOSED && sock->getState()!=CONNECTING && sock->getState()!=LISTENING){*/
			//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]: "<< "Socket Status: " << sock->getState() << endl;
			/*if((sock->getState() != TCPSocket::CLOSED) && (sock->getState() != TCPSocket::SOCKERROR)
			 &&(sock->getState() != TCPSocket::LOCALLY_CLOSED))*/
			sock->abort();
			//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]:<=>["<< getRemotePeerID()<<"]:...Socket aborted" << endl;
			/*}*/
			removeCurrentThread();
			//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]: "<< "...Thread removed" << endl;
		}
		//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]<=>["<< getRemotePeerID()<<"]: "<< "...done deleting serving thread."<<endl;
		break;
	}
	case DEL_THREAD_TIMER_FROM_HOST:
	{
		//It is possible for a client to close a connection on its part but then none of peerClosed, closed, failure
		//methods to be called. It is also possible for the remote peer to have its peerClosed called but not its closed or
		//failure. At least failure shoud be called (probably a bug!).So we set this timer to ensure our thread is removed.
		BTEV_VERB<<"the connection to the remote peer closed. Deleting serving thread."<<endl;
		//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]<=>["<< getRemotePeerID()<<"]: "<< "the connection to the remote peer closed. Deleting serving thread..."<<endl;

		/*if (evtIsAlive)
		 if(evtIsAlive->isScheduled())*/
		cancelAndDelete(evtIsAlive);
		evtIsAlive = NULL;
		//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]: "<< "Going to Delete evtKeepAlive..." << endl;
		/*if (evtKeepAlive)
		 if(evtKeepAlive->isScheduled())*///Error processing command ABORT: connection not open.
		cancelAndDelete(evtKeepAlive);
		evtKeepAlive = NULL;
		//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]: "<< "Going to abort socket and remove thread..." << endl;
		if (!delThreadMsg->isScheduled())
		{
			//if(sock->getState()!=CONNECTED /* +++> */ && sock->getState() != RECEIVING && sock->getState() != ACCEPTING /* <+++ */
			/*&& sock->getState()!=PEER_CLOSED && sock->getState()!=CONNECTING && sock->getState()!=LISTENING){*/
			//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]: "<< "Socket Status: " << sock->getState() << endl;
			/*if((sock->getState() != TCPSocket::CLOSED) && (sock->getState() != TCPSocket::SOCKERROR)
			 &&(sock->getState() != TCPSocket::LOCALLY_CLOSED))*/
			sock->abort();
			//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]:<=>["<< getRemotePeerID()<<"]:...Socket aborted" << endl;
			/*}*/
			removeCurrentThread();
			//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]: "<< "...Thread removed" << endl;
		}
		//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]<=>["<< getRemotePeerID()<<"]: "<< "...done deleting serving thread."<<endl;
		delete timer;
		break;
	}
	case ANTI_SNUB_TIMER:
	{
		BTEV_VERB<<"snubbed by remote peer. Engaging in anti-snubbing mode."<<endl;
		setState(ANTI_SNUBBING);
		scheduleAt(simTime(), new cMessage(peerWireBase->toString(CHOKE_TIMER),CHOKE_TIMER));
		break;
	}
	case BITFIELD_TIMER:
	{
		BitField* bitfield = peerWireBase->localBitfield();
		if (bitfield->havePiece())
		{
			setState(BITFIELD_COMPLETE);
			BTEV_VERB<<"sending Bitfield message."<<endl;
			BTBitfieldMsg* bietfieldMsg = (BTBitfieldMsg*)createBTPeerWireMessage(peerWireBase->toString(BITFIELD_MSG),BITFIELD_MSG);
			sendMessage(bietfieldMsg);
		}
		else
		{
			//TODO: At least for the time being, we just cancel the bitfield msg. If we do not schedule
			//this event in the future (ACTIVE) so as to re-check for piece availability, then maybe the
			//parent module should schedule it when another thread has received a piece (ACTIVE).
			BTEV_VERB<<"will not send a bitfield message, no pieces in possession."<<endl;
		}

		delete timer;
		break;
	}
	case HAVE_TIMER:
	{
		//Here we could also use the createBTPeerWireMessage() method, but a message with
		//the piece index would (either way) serve as the timer, why not that msg be a Have from the
		//beginning ...
		if (getState() >= HANDSHAKE_COMPLETE)
		{
			BTHaveMsg* have = check_and_cast<BTHaveMsg*>(timer);

			//In case of HAVE suppression we will not send the Have msg to those peers that already have the piece.
			if (!((peerWireBase->haveSupression()) && (remoteBitfield->isPieceAvailable(have->index()))))
			{
				BTEV_VERB<<"sending Have message for piece #"<< have->index()<<endl;
				have->setKind(HAVE_MSG);
				sendMessage((cMessage*)have->dup());
			}
			else
			{
				BTEV_VERB<<"Have suppression: not sending Have message for piece #"<< have->index()<<endl;
			}
		}
		else
		{
			//In this case we could now send our bitfield to the remote peer,
			//but we wont since the Bitfield msg is optional.
			//scheduleAt(simTime(),new cMessage(NULL,BITFIELD_TIMER));
		}

		delete timer;
		break;
	}
	case INTERESTED_TIMER:
	{
		BTEV_VERB<<"sending Interested message."<<endl;
		BTPeerStateMsg* interested = (BTPeerStateMsg*)createBTPeerWireMessage(peerWireBase->toString(INTERESTED_MSG),INTERESTED_MSG);

		sendMessage(interested);
		cancelAndDelete(timer);
		setAmInterested(true);

		if (!peerChoking())
		scheduleAt(simTime(), new cMessage(peerWireBase->toString(INTERNAL_NEXT_REQUEST_MSG),INTERNAL_NEXT_REQUEST_MSG));

		break;
	}
	case NOT_INTERESTED_TIMER:
	{
		BTEV_VERB<<"sending Not-Interested message"<<endl;
		BTPeerStateMsg* not_interested = (BTPeerStateMsg*)createBTPeerWireMessage(peerWireBase->toString(NOT_INTERESTED_MSG),NOT_INTERESTED_MSG);
		sendMessage(not_interested);
		if (timer) delete timer;
		setAmInterested(false);
		break;
	}
	case REQUEST_TIMER:
	{
		BTRequestCancelMsg* request = check_and_cast<BTRequestCancelMsg*>(timer);
		httptRequestMessage * httpReq = NULL;

		if (!peerChoking())
		{
			if (peerWireBase->httpUse()) {
				httpReq = buildHttpRequest(request);
				if(LOGFILE) {
					std::stringstream log;
					string uri = httpReq->uri();

					cStringTokenizer tokenizer = cStringTokenizer(uri.c_str(), "_");
					std::vector<string> params = tokenizer.asVector();

					int qlevel = strtol(params[1].c_str(), 0, 10);
					int piece = strtol(params[2].c_str(), 0, 10);
					int block = strtol(params[3].c_str(), 0, 10);

					log << "HSREQ: "<< simTime().str().c_str() << " " << piece << " " << block << " " << qlevel;
					peerWireBase->writeLog(log.str().c_str());
				}
				if(peerWireBase->httpCacheUse()) {
					BTPeerWireCacheThread *handler = (BTPeerWireCacheThread *) peerWireBase->getCacheThread();
					if (handler) {
						BTEV<<peerWireBase->getParentModule()->getFullName() <<" : Sending HTTP Request message for piece: "<<request->index()<< ", block : "<< request->begin()<<" / "<< (peerWireBase->pieceSize()/peerWireBase->blockSize())<<endl;
						//printf("%s Sending The HTTP request for piece %d, block %d through the cache\n",peerWireBase->getParentModule()->getFullName(),request->index(),request->begin());
						handler->sendMessage(httpReq);
					} else {
						BTEV<<peerWireBase->getParentModule()->getFullName() <<"We are enable to send the Request through the cache\n"<<endl;
						getHostModule()->error("%s:%d at %s() We are enable to send the Request through the cache\n", __FILE__, __LINE__, __func__);
					}
				} else
				sendMessage(httpReq);
				delete request;
			} else {
				if(LOGFILE) {
					std::stringstream log;
					log << "SREQ: "<< simTime().str().c_str() << " " << request->index() << " " << request->begin();
					peerWireBase->writeLog(log.str().c_str());
				}
				request->setKind(REQUEST_MSG);
				sendMessage(request);
			}
		} else
		delete request;

		break;
	}
	case PIECE_TIMER:
	{
		RequestEntry req = incomingRequests.getFirstCome();
		if (req.getIndex()>=0)
		{
			BTPieceMsg* piece;
			httptReplyMessage * response;
			response = (httptReplyMessage*) req.httpReplyMessage();

			if (!response) {
				piece = (BTPieceMsg*)createBTPeerWireMessage(peerWireBase->toString(PIECE_MSG),PIECE_MSG,req.getIndex(),req.begin(),req.length());
				BTEV_VERB<<"sending Piece message (data)"<<endl;
				if(LOGFILE) {
					std::stringstream log;
					log << "SPIECE: "<< simTime().str().c_str() << " " << req.getIndex() << " " << req.begin();
					peerWireBase->writeLog(log.str().c_str());
				}
				sendMessage(piece);
			}
			else
			{
				string uri = response->relatedUri();
				cStringTokenizer tokenizer = cStringTokenizer(uri.c_str(),"_");
				std::vector<string> params = tokenizer.asVector();

				int qlevel = strtol(params[1].c_str(),0,10);
				int piece = strtol(params[2].c_str(),0,10);
				int block = strtol(params[3].c_str(),0,10);

				if(LOGFILE) {
					std::stringstream log;
					log << "HSPIECE: "<< simTime().str().c_str() << " " << piece << " " << block << " " << qlevel;
					peerWireBase->writeLog(log.str().c_str());
				}
				//printf(">>>*%s Sending HTTP Piece %d - Block %d\n",getHostModule()->getParentModule()->getFullName(),piece,block);
				response->setKind(HTTP_RESPONSE_MSG);
				sendMessage((cMessage*)response);
			}
			//Look for the
			if(!isCacheThread())
			updateUploadRate(req);
			else
			updateCorrespondentThreadUploadRate(req);
		}

		delete timer;
		//delete req;
		break;
	}
	case CANCEL_TIMER:
	{
		//TODO: Should we remove the pending requests too ... ? A block may be in transit though!
		BTEV_VERB<<"sending the Cancel message."<<endl;
		BTRequestCancelMsg* cancel = check_and_cast<BTRequestCancelMsg*>(timer);

		//Remove the corresponding request
		requests.removeRequest(cancel->index(),cancel->begin(), true);

		cancel->setBegin(cancel->begin()*1024*peerWireBase->blockSize());
		cancel->setID(CANCEL);
		cancel->setKind(CANCEL_MSG);
		cancel->setByteLength(CANCEL_MSG_SIZE);
		sendMessage(cancel);

		break;
	}
	case UNCHOKE_TIMER:
	{
		BTEV_VERB<<"sending Unchoke message."<<endl;
		BTPeerStateMsg* unchoke = (BTPeerStateMsg*)createBTPeerWireMessage(peerWireBase->toString(UNCHOKE_MSG),UNCHOKE_MSG);

		clearPendingIncomingRequests();
		sendMessage(unchoke);
		setAmChoking(false);
		setLastChokeUnchoke(simTime());

		delete timer;
		break;
	}
	case CHOKE_TIMER:
	{
		BTEV_VERB<<"sending Choke message."<<endl;
		BTPeerStateMsg* choke = (BTPeerStateMsg*)createBTPeerWireMessage(peerWireBase->toString(CHOKE_MSG),CHOKE_MSG);

		clearPendingIncomingRequests();
		setLastChokeUnchoke(simTime());

		setAmChoking(true);
		setOptimisticallyUnchoked(false);

		sendMessage(choke);
		TCPServerThreadBase::cancelEvent(evtMeasureUploadRate);
		delete timer;
		break;
	}
	case CLOSE_CONNECTION_TIMER:
	{
		BTEV_VERB<<"closing connection gracefully."<<endl;
		/*if(isCacheThread())
		 printf("I am a cache thread for %s. going to close connections\n",getRemotePeerID().c_str());
		 else
		 printf("I am a normal thread for %s. going to close connections\n",getRemotePeerID().c_str());*/
		//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]<=>["<< getRemotePeerID()<<"]: "<< "Closing connection gracefully."<<endl;
		if (!amChoking() && !isCacheThread())
		{
			BTPeerStateMsg* choke = (BTPeerStateMsg*)createBTPeerWireMessage(peerWireBase->toString(CHOKE_MSG),CHOKE_MSG);
			sendMessage(choke);
		}

		closeConnection();
		delete timer;
		break;
	}
	case INTERNAL_MEASURE_DOWNLOAD_RATE_TIMER:
	{

		if (downloadRateSamples.size()>0)
		{
			float sum = 0;
			for (int i=0; i<downloadRateSamples.size();i++)
			{
				sum = sum + downloadRateSamples[i];

			}

			setDownloadRate(sum/downloadRateSamples.size());
		}
		else
		setDownloadRate(0);

		downloadRateSamples.clear();

		scheduleAt(simTime()+peerWireBase->getDownloadRateSamplingDuration(),evtMeasureDownloadRate);
		break;

	}
	case INTERNAL_MEASURE_UPLOAD_RATE_TIMER:
	{
		if (uploadRateSamples.size()>0)
		{
			float sum = 0;
			for (int i=0; i<uploadRateSamples.size();i++)
			{
				sum = sum + uploadRateSamples[i];
			}

			setUploadRate(sum/uploadRateSamples.size());
		}
		else
		setUploadRate(0);

		uploadRateSamples.clear();
		break;
	}
	case INTERNAL_REFUSE_CONNECTION_TIMER:
	{
		BTEV<<"Refusing incoming connection..."<<endl;

		closeConnection();
		delete timer;
		break;
	}
	case HTTP_REQUEST_MSG :
	{
		BTEV<<"Nothing to do the message is simply forwarded ..."<<endl;
		break;
	}

	default:
	getHostModule()->error("%s:%d at %s() Uknown timer expired %d\n", __FILE__, __LINE__, __func__,timer->getKind());
}
}

void BTPeerWireClientHandlerBase::sendEndGameBlockRequests(int pieceIndex,
		int blockIndex) {
	if (requests.findRequest(pieceIndex, blockIndex) < 0)
		sendBlockRequests(pieceIndex, blockIndex);
}

void BTPeerWireClientHandlerBase::updateUploadRate(RequestEntry req) {
	simtime_t interval = simTime() - lastUploadTime_var;

	if (interval > 0) {
		float sample = (req.length() / interval);

		lastUploadTime_var = simTime();

		uploadRateSamples.insert(uploadRateSamples.end(), sample);

		if (!evtMeasureUploadRate->isScheduled()) {
			scheduleAt(simTime()
					+ peerWireBase->getDownloadRateSamplingDuration(),
					evtMeasureUploadRate);
		}

		BTEV_VERB<<"observed upload rate ="<<getUploadRate()<<" KB/sec"<<endl;
	}
}

void BTPeerWireClientHandlerBase::updateCorrespondentThreadUploadRate(
		RequestEntry req) {
	httptReplyMessage * response;
	response = (httptReplyMessage*) req.httpReplyMessage();

	cStringTokenizer tokenizer = cStringTokenizer(response->targetUrl(), ".");
	std::vector<string> params = tokenizer.asVector();

	//printf("Looking for the thread of Peer %s\n", params[0].c_str());

	TCPServerThreadBase *thread;
	BTPeerWireClientHandlerBase * handler;
	PeerEntryVector peerVector = peerWireBase->getPeerState().getVector();

	unsigned int i;

	for (i = 0; i < peerVector.size(); i++) {
		PeerEntry entry = peerVector[i];
		thread = check_and_cast<TCPServerThreadBase *> (entry.getPeerThread());
		handler = (BTPeerWireClientHandlerBase*) thread;
		if (!thread)
			getHostModule()->error(
					"%s:%d at %s() Inconsistent thread state, Invalid Correspondant Peer Thread . \n",
					__FILE__, __LINE__, __func__);
		if (handler->isCacheThread())
			continue;

		cStringTokenizer tokenizer1 = cStringTokenizer(
				handler->getRemotePeerID().c_str(), "-");
		std::vector<string> params1 = tokenizer1.asVector();
		string remotePeerId = "overlayTerminal-" + params1[1];
		if (remotePeerId == params[0]) {
			handler->updateUploadRate(req);
			//printf("We found the correspondent thread for peer ID %s\n",	remotePeerId.c_str());
			break;
		}
	}

}

httptRequestMessage * BTPeerWireClientHandlerBase::buildHttpRequest(
		BTRequestCancelMsg* request) {
	std::stringstream header;
	header << "GET /Segment_1_" << request->index() << "_" << request->begin()
			<< " HTTP/1.1";
	const char * hdr = (header.str()).c_str();
	httptRequestMessage * httpReq = NULL;
	httpReq = new httptRequestMessage(hdr, HTTP_REQUEST_MSG);
	httpReq->setHeaderLength(1);
	httpReq->setContentLength(0);
	httpReq->setByteLength(1); // = |header| + |content|
	httpReq->setEntitySize(getPayloadMessageLength(request->index())); // size of the entity to be returned.
	std::stringstream uri;
	uri << "/Segment_1_" << request->index() << "_" << request->begin();
	BTEV<<"the sent HTTP URI is: "<<uri.str()<<endl;
	//cerr << peerWireBase->getParentModule()->getFullName() << ". The sent HTTP URI is : "<<uri.str()<<endl;
	httpReq->setUri((uri.str()).c_str());
	httpReq->setProtocol(11); // 1.1
	httpReq->setHeading(hdr);
	cStringTokenizer tokenizer = cStringTokenizer(getRemotePeerID().c_str(),"-");
	std::vector<string> params = tokenizer.asVector();
	httpReq->setTargetUrl(("overlayTerminal-"+params[1]+".omnet.net").c_str());
	string wwwOriginatorName="";
	wwwOriginatorName += peerWireBase->getParentModule()->getFullName();
	wwwOriginatorName += ".omnet.net";
	httpReq->setOriginatorUrl(wwwOriginatorName.c_str());
	httpReq->setKeepAlive(true);
	return httpReq;
}
	/**
	 * Based on a single request for a new piece-block, this method generates requests
	 * for this and the subsequent blocks according to the default queuing policy. If no more block requests can be issued
	 * this thread asks the base module to designade a new piece.
	 *
	 */

void BTPeerWireClientHandlerBase::sendBlockRequests(int pieceIndex,
		int blockIndex) {
	int nextBlockIndex = blockIndex;
	int procDelay = 0;
	double blockSize = 0.0;

	while (requests.canRequestMore()) {

		//NOTE: selectPiece finds which is the currently available block so that we can resume
		//We should check here if we have placed a request
		blockSize = getPayloadMessageLength(nextBlockIndex);
		procDelay += peerWireBase->procDelay();
		BTRequestCancelMsg* req =
				(BTRequestCancelMsg*) createBTPeerWireMessage(
						peerWireBase->toString(REQUEST_MSG), REQUEST_MSG,
						pieceIndex, nextBlockIndex, blockSize);

		requests.addRequest(pieceIndex, nextBlockIndex, req->dataLength(),
				simTime() + procDelay, getRemotePeerID().c_str(), NULL);

		BTEV<<peerWireBase->getParentModule()->getFullName() <<" : Sending Request message for piece: "<<req->index()<< ", block : "<< (nextBlockIndex + 1)<<" / "<< (peerWireBase->pieceSize()/peerWireBase->blockSize())<<", Request queue size = "<< requests.size()<<endl;

		//We set this block to "requested".
		peerWireBase->updateBlockRequests(pieceIndex,nextBlockIndex, true);
		req->setKind(REQUEST_TIMER);
		scheduleAt(simTime()+procDelay,req);

		//If this is an individual endGame mode request we shall not try and ask for subsequent
		//blocks
		if (peerWireBase->getState() == ENDGAME) break;

		int nextBlock = peerWireBase->localBitfield()->nextBlock(pieceIndex);

		if ((nextBlock<0)&& (requests.canRequestMore()))
		{
			//Ask for another piece to request, since we can send more requests than
			//the remaining blocks.
			scheduleAt(simTime(),new cMessage(peerWireBase->toString(INTERNAL_NEXT_REQUEST_MSG),INTERNAL_NEXT_REQUEST_MSG));
			break;
		}
		else
		nextBlockIndex = nextBlock;

	}

}
/**
 * Called in the end game mode, when a Cancel message is received. It removes the corresponding request.
 *
 */
void BTPeerWireClientHandlerBase::cancelBlockRequest(BTRequestCancelMsg* cancel) {
	int requestIndex = incomingRequests.findRequest(cancel->index(),
			cancel->begin());
	BTEV_VERB<<"received Cancel msg for Request about piece #"<< cancel->index()<<" , block #"<< cancel->begin()<<". ";

	if (requestIndex >= 0)
	{
		BTEV_VERB<<"canceling request."<<endl;
		incomingRequests.removeRequest(requestIndex);
	}
	else
	BTEV_VERB<<"this request does not exist. Either we have already sent the data or this is an error."<<endl;

	if (cancel) delete cancel;
}
/**
 * Remove all pending messages and timers
 *
 */
void BTPeerWireClientHandlerBase::finalMessageCleaning() {

}

/**
 * Closes the TCP connection with the remote peer.
 *
 */
void BTPeerWireClientHandlerBase::closeConnection() {
	/*if(this->isCacheThread())
	 cerr << "Going to perform closeConnection on a Cache Thread..." << endl;*/

	if ((getState() > INITIAL) || (getState() == EARLY_ABORTING)) {
		if (getState() != EARLY_ABORTING) {
			/*if(this->isCacheThread())
			 cerr << "\t\tCache Thread : closing connections ongoing (state<>EARLY_ABORTING and >INITIAL)" << endl;*/
			cancelAndDelete(evtIsAlive);
			evtIsAlive = NULL;
			cancelAndDelete(evtKeepAlive);
			evtKeepAlive = NULL;

			// Anti-snubbing  not actually supported due to contradictory definitions...
			//cancelAndDelete(evtAntiSnub);
		}
		/*if(this->isCacheThread())
		 cerr << "\t\tCache Thread : closing connections ongoing (state == EARLY_ABORTING)" << endl;*/
		setState(ACTIVE_ABORTING);

		if (evtDelThread->isScheduled()) {
			cancelEvent(evtDelThread);
		}
		/*cerr << getHostModule()->getParentModule()->getFullName()
		 << ": Closing Socket with: " << this->getRemotePeerID().c_str()
		 << ":" << sock->getRemoteAddress().get4().str().c_str() << endl;*/
		//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]<=>["<< getRemotePeerID()<<"]: "<< "going to close the socket..."<<endl;
		scheduleAt(simTime() + 2 * TCP_TIMEOUT_2MSL, evtDelThread);
		if ((sock->getState() != TCPSocket::CLOSED) && (sock->getState()
				!= TCPSocket::SOCKERROR)) {
			sock->close();
			//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]<=>["<< getRemotePeerID()<<"]: "<< "...done closing the socket"<<endl;
		}
	} else if (getState() == INITIAL) {
		setState(EARLY_ABORTING);
		//cerr << "["<< getHostModule()->getParentModule()->getFullName() << "]<=>["<< getRemotePeerID()<<"]: "<< "We are in the INITIAL state and will perform EARLY_ABORTING state"<<endl;
	}

}

void BTPeerWireClientHandlerBase::peerClosed() {
	BTEV_VERB<<"Closing connection requested by remote peer"<<endl;
	if (getState() > ACTIVE_ABORTING) {
		setState(PASSIVE_ABORTING);
		if (evtDelThread->isScheduled()) {
			cancelEvent(evtDelThread);
		}

		scheduleAt(simTime() + 2 * TCP_TIMEOUT_2MSL, evtDelThread);

		cancelAndDelete(evtIsAlive);
		evtIsAlive = NULL;
		cancelAndDelete(evtKeepAlive);
		evtKeepAlive = NULL;
		// Anti-snubbing  not actually supported due to contradictory definitions...
		//cancelAndDelete(evtAntiSnub);
	}

	//If this thread hasn't initated this CLOSE, respond by CLOSING

	if (this->sock->getState() != TCPSocket::CLOSED)
	this->sock->close();

}

	/*void BTPeerWireClientHandlerBase::socketClosed(int connId, void *yourPtr) {

	 this->closed();
	 }*/

void BTPeerWireClientHandlerBase::closed() {

	((BTPeerWireBase*) getHostModule())->decreaseCurrentNumConnections();
	removeCurrentThread();

}

bool BTPeerWireClientHandlerBase::getThreadRemovelScheduled() const {
	return threadRemovelScheduled;
}

void BTPeerWireClientHandlerBase::setThreadRemovelScheduled(
		bool threadRemovelScheduled) {
	this->threadRemovelScheduled = threadRemovelScheduled;
}

void BTPeerWireClientHandlerBase::failure(int code) {
	if ((getState() > PASSIVE_ABORTING) || (getState() == EARLY_ABORTING)) {
		//If this connection has not been established...
		if ((getState() == INITIAL) || (getState() == EARLY_ABORTING)) {
			((BTPeerWireBase*) getHostModule())->decreasePendingNumConnections();
		}

		setState(PASSIVE_ABORTING);
		if (evtIsAlive) {
			cancelAndDelete(evtIsAlive);
		}
		if (evtKeepAlive) {
			cancelAndDelete(evtKeepAlive);
		}
		if (evtDelThread)
			cancelEvent(evtDelThread);

		// Anti-snubbing  not actually supported due to contradictory definitions...
		//if(evtAntiSnub) cancelAndDelete(evtAntiSnub);
	}

	//Remove this thread
	removeCurrentThread();
}

/**
 * Informs the peer-wire module that it is safe to delete this thread from its peer state.
 *
 */
void BTPeerWireClientHandlerBase::removeCurrentThread() {
	clearPendingIncomingRequests();
	clearPendingRequests();
	chokedRequests.clear();
	for (int i = 0; i < chokedIncomingRequests.size(); i++) {
		RequestEntry re = chokedIncomingRequests.getRequestEntry(i);
		if (re.httpReplyMessage()) {
			delete (re.httpReplyMessage());
		}
	}
	chokedIncomingRequests.clear();
	cancelAndDelete(evtMeasureDownloadRate);
	evtMeasureDownloadRate = NULL;
	cancelAndDelete(evtMeasureUploadRate);
	evtMeasureUploadRate = NULL;
	if (evtDelThread) {
		cancelAndDelete(evtDelThread);
		evtDelThread = NULL;
	}

	//Remove this thread
	delThreadMsg->setText(getRemotePeerID().c_str());
	if (delThreadMsg->isScheduled())
		cancelEvent(delThreadMsg);
	setThreadRemovelScheduled(true);
	scheduleAt(simTime(), delThreadMsg);
}
/**
 * Sometime the host module stays in an endless waiting for the thread to be removed.
 * This method enforce the thread removal
 */
void BTPeerWireClientHandlerBase::enforceThreadRemoval() {
	if ((sock->getState() != TCPSocket::CLOSED) && (sock->getState()
			!= TCPSocket::SOCKERROR))
		sock->abort();
	removeCurrentThread();

}
/**
 * Removes all pending requests and informs the peer-wire module to mark the corresponding
 * blocks as not requested (at least by this thread).
 */
void BTPeerWireClientHandlerBase::clearPendingRequests() {
	for (int i = 0; i < requests.size(); i++) {
		RequestEntry re = requests.getRequestEntry(i);
		peerWireBase->updateBlockRequests(re.getIndex(), re.begin(), false);

		chokedRequests.addRequest(re);
	}

	cMessage* uiMsg = new cMessage(peerWireBase->toString(
			INTERNAL_UPDATE_INTERESTS_MSG), INTERNAL_UPDATE_INTERESTS_MSG);
	scheduleAt(simTime(), uiMsg);

	requests.clear();
}
/**
 * Removes all pending incoming requests.
 *
 */
void BTPeerWireClientHandlerBase::clearPendingIncomingRequests() {
	for (int i = 0; i < incomingRequests.size(); i++) {
		RequestEntry re = incomingRequests.getRequestEntry(i);
		chokedIncomingRequests.addRequest(re);
		if (re.httpReplyMessage()) {
			delete (re.httpReplyMessage());
		}
	}

	incomingRequests.clear();
}

int BTPeerWireClientHandlerBase::getNumPendingRequests() {
	return requests.getNumRequests();
}

RequestState BTPeerWireClientHandlerBase::getRequests() {
	return requests;
}

void BTPeerWireClientHandlerBase::increaseRequestQueueSize(int newSize) {
	requests.setMaxSize(newSize);
}

/**
 * Renewing the keep alive timer so that the connection is not closed.
 *
 */
void BTPeerWireClientHandlerBase::renewAliveTimer(cMessage* timer) {
	cancelEvent(timer);
	scheduleAt(simTime() + Keep_Alive_Duration, timer);
}

/**
 * Currently not used...
 *
 */
void BTPeerWireClientHandlerBase::renewAntiSnubTimer() {
	if (evtAntiSnub->isScheduled())
		cancelEvent(evtAntiSnub);

	scheduleAt(simTime() + peerWireBase->snubbingInterval(), evtAntiSnub);
}

void BTPeerWireClientHandlerBase::setRemotePeerID(string id) {
	this->remotePeerID.assign(id);
}

string BTPeerWireClientHandlerBase::getRemotePeerID() {
	return this->remotePeerID;
}

void BTPeerWireClientHandlerBase::setDownloadRate(float rate) {
	downloadRate = rate;
}

void BTPeerWireClientHandlerBase::setUploadRate(float rate) {
	uploadRate = rate;
}

float BTPeerWireClientHandlerBase::getUploadRate() {
	return uploadRate;
}

float BTPeerWireClientHandlerBase::getDownloadRate() {
	if (((BTPeerWireBase*) getHostModule())->getState() < COMPLETED)
		return downloadRate;
	else
		return uploadRate;
}

bool BTPeerWireClientHandlerBase::seeder() {
	return seeder_var;
}

void BTPeerWireClientHandlerBase::setSeeder(bool seeder) {
	seeder_var = seeder;
}

simtime_t BTPeerWireClientHandlerBase::connectTimeShift() {
	return this->connectTimeShift_var;
}

void BTPeerWireClientHandlerBase::setConnectTimeShift(
		simtime_t connectTimeShift) {
	this->connectTimeShift_var = connectTimeShift;
}

void BTPeerWireClientHandlerBase::setOptimisticallyUnchoked(bool value) {
	optimisticallyUnchoked = value;
}

bool BTPeerWireClientHandlerBase::inEndGame() {
	return inEndGame_var;
}

void BTPeerWireClientHandlerBase::setInEndGame(bool inEndGame) {
	inEndGame_var = inEndGame;
}

double BTPeerWireClientHandlerBase::getPayloadMessageLength(int pieceIndex) {
	int qualities = peerWireBase->getQualities();
	int localBimapSize = peerWireBase->localBitfield()->numPieces();
	int offset = (int) (localBimapSize / qualities);
	int qualityIndex = (int) (pieceIndex / offset);
	int pieceSize = (int) (peerWireBase->getQualityBitRate(qualityIndex)
			* peerWireBase->getPiecePlaybackDuration());
	double blockSize = ((double) (pieceSize / peerWireBase->pieceSize())
			* peerWireBase->blockSize());
	//cerr<<"READY TO SEND BLOCK SIZE"<<blockSize<<endl;
	return (blockSize);

}

cMessage* BTPeerWireClientHandlerBase::createBTPeerWireMessage(
		const char* name, int kind, int index, int begin, int length) {
	switch (kind) {
	case PIECE_MSG: {
		BTPieceMsg* piece = new BTPieceMsg(name, kind);
		piece->setIndex(index);
		piece->setBegin(begin);
		piece->setLength_prefix(PIECE_HEADER_MSG_SIZE + length);
		piece->setByteLength(PIECE_HEADER_MSG_SIZE + length * 1024);
		//piece->setLevel(level);
		return piece;

	}//PIECE_MSG
	case REQUEST_MSG: {
		BTRequestCancelMsg* request = new BTRequestCancelMsg(name, kind);
		request->setIndex(index);
		request->setBegin(begin);
		request->setDataLength(length);
		request->setByteLength(REQUEST_MSG_SIZE);
		return request;
	}//REQUEST_MSG
	default:
		getHostModule()->error(
				"%s:%d at %s() Cannot create message, uknown message type %d\n",
				__FILE__, __LINE__, __func__, kind);
	}

	return NULL;
}

cMessage* BTPeerWireClientHandlerBase::createBTPeerWireMessage(
		const char* name, int kind) {
	switch (kind) {
	case HANDSHAKE_MSG: {
		BTMsgHandshake* handShakeMsg = new BTMsgHandshake(name, kind);
		handShakeMsg->setPstrlen(peerWireBase->pstrlen());
		handShakeMsg->setPstr(peerWireBase->pstr());
		handShakeMsg->setInfoHash(trackerClient->infoHash().c_str());
		handShakeMsg->setPeerId(trackerClient->peerId().c_str());
		handShakeMsg->setByteLength(HANDSHAKE_MSG_SIZE);
		return handShakeMsg;
		//break;
	}//HANDSHAKE_MSG
	case KEEP_ALIVE_MSG: {
		BTKeepAliveMsg* keepAlive = new BTKeepAliveMsg(name, kind);
		keepAlive->setByteLength(KEEP_ALIVE_MSG_SIZE);
		return keepAlive;
		//break;
	}//KEEP_ALIVE_MSG
	case CHOKE_MSG: {
		BTPeerStateMsg* chokeMsg = new BTPeerStateMsg(name, kind);
		chokeMsg->setID(CHOKE);
		chokeMsg->setByteLength(CHOKE_MSG_SIZE);
		return chokeMsg;
	}//CHOKE_MSG
	case UNCHOKE_MSG: {
		BTPeerStateMsg* unChokeMsg = new BTPeerStateMsg(name, kind);
		unChokeMsg->setID(UNCHOKE);
		unChokeMsg->setByteLength(UNCHOKE_MSG_SIZE);
		return unChokeMsg;
	}//UNCHOKE_MSG
	case INTERESTED_MSG: {
		BTPeerStateMsg* interestedMsg = new BTPeerStateMsg(name, kind);
		interestedMsg->setID(INTERESTED);
		interestedMsg->setByteLength(INTERESTED_MSG_SIZE);
		return interestedMsg;
	}//INTERESTED_MSG
	case NOT_INTERESTED_MSG: {
		BTPeerStateMsg* notInterestedMsg = new BTPeerStateMsg(name, kind);
		notInterestedMsg->setID(NOT_INTERESTED);
		notInterestedMsg->setByteLength(NOT_INTERESTED_MSG_SIZE);
		return notInterestedMsg;
	}//NOT_INTERESTED_MSG
	case HAVE_MSG: {
		BTHaveMsg* have = new BTHaveMsg(name, kind);
		have->setByteLength(HAVE_MSG_SIZE);
		//have->setIndex(index);
		have->setLength_prefix(HAVE_MSG_SIZE);
		have->setID(HAVE);
		return have;
		break;
	}//HAVE_MSG
	case BITFIELD_MSG: {
		BTBitfieldMsg* bietfieldMsg = new BTBitfieldMsg(name, kind);
		BitField* bitfield;
		// If we are in super seed mode we will present an empty bitfield and then
		// send a Have msg for a rare piece.
		if (peerWireBase->superSeedMode())
			bitfield = new BitField(peerWireBase->numPieces(),
					peerWireBase->numBlocks(), false);
		else
			bitfield = peerWireBase->localBitfield();

		bietfieldMsg->setBitfieldArraySize(bitfield->numPieces());
		bitfield->putInMessage(bietfieldMsg);
		bietfieldMsg->setByteLength(BITFIELD_MSG_SIZE);
		bietfieldMsg->setLength_prefix(bitfield->numPieces() + 4 + 1);

		if (peerWireBase->superSeedMode())
			if (bitfield) {
				delete bitfield;
				bitfield = NULL;
			}

		return bietfieldMsg;
		break;
	}//BITFIELD_MSG
	case CANCEL_MSG: {
		break;
	}//CANCEL_MSG
	default:
		getHostModule()->error(
				"%s:%d at %s() Cannot create message, uknown message type %d\n",
				__FILE__, __LINE__, __func__, kind);
	}

	return NULL;
}

int BTPeerWireClientHandlerBase::getState() {
	return state_var;
}

bool BTPeerWireClientHandlerBase::isCacheThread() {
	return isCacheThread_var;
}

void BTPeerWireClientHandlerBase::setIsCacheThread(bool isItCacheThread) {
	isCacheThread_var = isItCacheThread;
}

bool BTPeerWireClientHandlerBase::amChoking() {
	return amChoking_var;
}

void BTPeerWireClientHandlerBase::setAmChoking(bool amChoking) {
	amChoking_var = amChoking;
}

bool BTPeerWireClientHandlerBase::amInterested() {
	return amInterested_var;
}

void BTPeerWireClientHandlerBase::setAmInterested(bool amInterested) {
	amInterested_var = amInterested;
}

bool BTPeerWireClientHandlerBase::peerChoking() {
	return peerChoking_var;
}

void BTPeerWireClientHandlerBase::setPeerChoking(bool peerChoking) {
	peerChoking_var = peerChoking;
}

bool BTPeerWireClientHandlerBase::peerInterested() {
	return peerInterested_var;
}

void BTPeerWireClientHandlerBase::setPeerInterested(bool peerInterested) {
	peerInterested_var = peerInterested;
}

void BTPeerWireClientHandlerBase::setState(int state) {
	state_var = state;
}

simtime_t BTPeerWireClientHandlerBase::lastChokeUnchoke() {
	return lastChokeUnchoke_var;
}

void BTPeerWireClientHandlerBase::setLastChokeUnchoke(
		simtime_t lastChokeUnchoke) {
	lastChokeUnchoke_var = lastChokeUnchoke;
}

bool BTPeerWireClientHandlerBase::activeConnection() {
	return activeConnection_var;
}

void BTPeerWireClientHandlerBase::setActiveConnection(bool activeConnection) {
	activeConnection_var = activeConnection;
}

bool BTPeerWireClientHandlerBase::allowedToRequest() {
	return allowedToRequest_var;
}

void BTPeerWireClientHandlerBase::setAllowedToRequest(bool allowedToRequest) {
	allowedToRequest_var = allowedToRequest;
}

void BTPeerWireClientHandlerBase::printState() {
	BTEV_VERB<<"AM CHOKING = "<< amChoking()<< endl;
	BTEV_VERB<<"AM INTERESTED = "<< amInterested()<< endl;
	BTEV_VERB<<"PEER CHOKING = "<< peerChoking()<< endl;
	BTEV_VERB<<"PEER INTERESTED = "<< peerInterested()<< endl;
}

const char* BTPeerWireClientHandlerBase::socketState() {
	return sock->stateName(sock->getState());
}

void BTPeerWireClientHandlerBase::writeLog(const char* logText) {
	peerWireBase->writeLog(logText);
}
