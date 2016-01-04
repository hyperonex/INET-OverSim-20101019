//
// Copyright 2009 Konstantinos V. Katsaros
//                              ntinos@aueb.gr
//                              http://mm.aueb.gr/~katsaros
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


#include "BTPeerWireClientHandlerBase.h"
#include "BTPeerWireCacheThread.h"
#include "BTPeerWireBase.h"
#include <TCP.h>

using namespace std;

#define BEV	EV << "[" << this->getParentModule()->getFullName() << "]: "

Define_Module( BTPeerWireBase);

BTPeerWireBase::BTPeerWireBase() {
}

BTPeerWireBase::~BTPeerWireBase() {
	if (tcp)
		delete tcp;
	if (localBitfield_var)
		delete localBitfield_var;
}

void BTPeerWireBase::finish() {
	serverThreadsVector::iterator it;
	//cerr << getParentModule()->getFullName() << ": Going to delete all the serverThreads..." <<endl;
	for (it = serverThreads.begin(); it != serverThreads.end(); it++) {
		socketMap.removeSocket((*it)->getSocket());
		delete (*it);
	}

	serverThreads.clear();
}

void BTPeerWireBase::writeLog(const char* logText) {
	logFile << logText << endl;
}

void BTPeerWireBase::initialize() {
	// parent initialize
	TCPSrvHostApp::initialize();

	//TODO://To be removed, used for debugging
	debuggedNode = par("debuggedNode").stringValue();
	if (LOGFILE) {
		runNumber_var = (int) par("runNumber");
		resultFolder_var = (const char*) par("resultFolder");
		std::stringstream fileName;
		fileName << resultFolder_var << "/run" << runNumber_var << "/"
				<< getParentModule()->getFullName() << ".txt";
		logFile.open((fileName.str()).c_str());
		//cerr << getParentModule()->getFullName() <<" Writing to log file: " << (fileName.str()).c_str() <<endl;
	}
	// member init
	file_size_var = (double) par("file_size") * 1024;
	piece_size_var = (double) par("piece_size");
	block_size_var = (double) par("block_size");
	DHT_port_var = (size_t) par("DHT_port");
	pstr_var = (const char*) par("pstr");
	pstrlen_var = (int) par("pstrlen");
	keep_alive_var = (int) par("keep_alive");
	have_supression_var = (bool) par("have_supression");
	chocking_interval_var = (int) par("chocking_interval");
	downloaders_var = (int) par("downloaders");
	optUnchockedPeers_var = (int) par("optUnchockedPeers");
	optUnchocking_interval_var = (int) par("optUnchocking_interval");
	snubbing_interval_var = (int) par("snubbing_interval");
	rarest_list_size_var = (int) par("rarest_list_size");
	minNumConnections_var = (int) par("minNumConnections");
	maxNumConnections_var = (int) par("maxNumConnections");
	timeToSeed_var = (int) par("timeToSeed");
	request_queue_depth_var = (int) par("request_queue_depth");
	super_seed_mode_var = (bool) par("super_seed_mode");
	maxNumEmptyTrackerResponses_var = (int) par("maxNumEmptyTrackerResponses");
	newlyConnectedOptUnchokeProb_var = (double) par(
			"newlyConnectedOptUnchokeProb");
	enableEndGameMode_var = (bool) par("enableEndGameMode");
	downloadRateSamplingDuration_var
			= (int) par("downloadRateSamplingDuration");

	use_http_var = (bool) par("use_http");
	use_chache_server_var = (bool) par("use_chache_server");

	cacheIpAddress_var = (const char*) par("cacheIpAddress");
	cachePort_var = (int) par("cachePort");

	bufferingDuration_var = (int) par("bufferingDuration");

	setWaitingDurationWhenPieceNotFound((int) par(
			"waitingDurationWhenPieceNotFound"));

	//We suppose that something goes wrong after 3 iterations and we force killing threads
    currentWaitingIteration = 0 ;
    waitingIterationThreshold = 3;
	
	secondPiecePlaybackTrial = false;
	playbackFinish = false;

	setProcDelay((int) par("procDelay") / 1000000);

	tcp = new TCP();
	btStatisticsModule = (cModule*) simulation.getModuleByPath(par(
			"statisticsModulePath"));
	btStatistics = (cSimpleModule*) btStatisticsModule->getSubmodule(
			"btstatistics", 0);
	//btStatistics = (cSimpleModule*)simulation.getModuleByPath(par("statisticsModulePath"));

	if (btStatistics == NULL)
		opp_error("Wrong statisticsModulePath configuration");

	/*cMessage* subscribe = new cMessage("STAT_SUBSCRIBE", STAT_SUBSCRIBE);
	 sendDirect(subscribe, btStatistics, btStatistics->findGate("direct_in"));*/

	setAnnounceInterval(0);
	setCurrentNumConnections(0);
	setPendingNumConnections(0);
	setDownloadDuration( simTime());
	setCurrentNumEmptyTrackerResponses(0);
	setBlocksFromSeeder(0);
	trackerResponse_var = NULL;

	//adaptive qualities initialization
	qualities_var = (const char*) par("qualities");
	cStringTokenizer tokenizer = cStringTokenizer(qualities_var, " ");
	std::vector<string> params = tokenizer.asVector();
	char * pEnd;
	unsigned int i;
	for (i = 0; i < params.size(); i++) {
		qualitiesBitRates_var.push_back(strtol(params[i].c_str(), &pEnd, 10));
	}

	setQualitiesNumber(qualitiesBitRates_var.size());

	setAdaptive((bool) par("adaptiveQuality"));

	maxSupportedQualityIndex_var = (int) par("maxSupportedQualityIndex");
	setCurrentQualityIndex(maxSupportedQualityIndex_var);

	qualityOffset_var = (int) (file_size_var / piece_size_var);

	setLastPieceIndex((maxSupportedQualityIndex_var * qualityOffset_var)
			+ (qualityOffset_var - 1));

	setNextPieceToPlay(maxSupportedQualityIndex_var * qualityOffset_var);

	setPiecePlaybackDuration((double) ((piece_size_var)
			/ qualitiesBitRates_var[0]));

	missedPlayerPieces_var = 0;
	missedPiecesThreshold_var = (int) par("missedPiecesThreshold");
	succesivePlayedPiecesThreshold_var = (int) par(
			"succesivePlayedPiecesThreshold");
	sucessivePlayedPieces_var = 0;
	successiveMissedPieces_var = 0;

	setLastPlayedPieceIndex(-1);
	setFifoPieceSelectionWindow((int) par("fifoPieceSelectionWindow"));

	setIsStatsWritten(false);

	setNumPieces(((int) (file_size_var / piece_size_var)) * getQualities());
	setNumBlocks((int) (piece_size_var / block_size_var));
	peerState.setMinDownloaderRate(numeric_limits<float>::max());
	pieceFreqState.initializePieceFrequencies(numPieces());
	cacheThread = NULL;
	if (!strcmp(this->getParentModule()->getNedTypeName(),
			"inet.applications.xBitTorrent.BTHostSeeder")) {
		setSuperSeedMode(superSeedMode());
		setState(SEEDER);
		downloaders_var = (int) par("seederDownloaders");
		optUnchockedPeers_var = (int) par("seederOptUnchockedPeers");
		initializeLocalBitfield(true);
		setTimeToSeed(std::numeric_limits<double>::max());
		use_chache_server_var = false;
		playbackFinish = true;
		cMessage* subscribe = new cMessage("STAT_SUBSCRIBE", STAT_SUBSCRIBE);
		sendDirect(subscribe, btStatistics, btStatistics->findGate("direct_in"));
	} else {
		setSuperSeedMode(false);
		setState(NORMAL);
		initializeLocalBitfield(false);
	}

	if (this->httpUse()) {
		downloaders_var *= 2;
	}

	// WATCHES
	WATCH(piece_size_var);
	WATCH(block_size_var);
	WATCH(numPieces_var);
	WATCH(numBlocks_var);
	WATCH(DHT_port_var);
	WATCH(pstr_var);
	WATCH(pstrlen_var);
	WATCH(keep_alive_var);
	WATCH(have_supression_var);
	WATCH(chocking_interval_var);
	WATCH(downloaders_var);
	WATCH(optUnchockedPeers_var);
	WATCH(optUnchocking_interval_var);
	WATCH(snubbing_interval_var);
	WATCH(rarest_list_size_var);
	WATCH(minNumConnections_var);
	WATCH(maxNumConnections_var);
	WATCH(timeToSeed_var);
	WATCH(request_queue_depth_var);
	WATCH(super_seed_mode_var);
	WATCH(maxNumEmptyTrackerResponses_var);
	WATCH(newlyConnectedOptUnchokeProb_var);
	WATCH(currentNumConnections_var);
	WATCH(pendingNumConnections_var);
	WATCH(downloadDuration_var);
	WATCH(currentNumEmptyTrackerResponses_var);
	WATCH(state_var);

	evtChokeAlg = new cMessage(toString(INTERNAL_CHOKE_TIMER),
			INTERNAL_CHOKE_TIMER);
	evtOptUnChoke = new cMessage(toString(INTERNAL_OPT_UNCHOKE_TIMER),
			INTERNAL_OPT_UNCHOKE_TIMER);
	evtTrackerComm = new cMessage(toString(INTERNAL_TRACKER_COM_MSG),
			INTERNAL_TRACKER_COM_MSG);
	evtCacheThreadCreation = new cMessage(toString(
			INTERNAL_CACHE_THREAD_CREATION), INTERNAL_CACHE_THREAD_CREATION);
	evtPlayNextPiece = new cMessage(toString(INTERNAL_PLAYER_MSG),
			INTERNAL_PLAYER_MSG);

	//Immediately schedule the communication with the tracker. We will then learn by the tracker about the interval between requests.

	scheduleAt(simTime(), evtTrackerComm);

	//Schedule a cache thread creation.
	if (!strcmp(this->getParentModule()->getNedTypeName(),
			"inet.applications.xBitTorrent.BTHost")) {
		BEV<<"try to connect to the cache address : "<<par("cacheIpAddress").stringValue()<<endl;
		scheduleAt(simTime(), evtCacheThreadCreation);
		//Schedule the playback process
		scheduleAt(simTime()+bufferingDuration_var,evtPlayNextPiece);
		if (LOGFILE) {
			const char* adaptive;
			if(this->isAdaptive())
			adaptive = "Yes";
			else
			adaptive = "No";
			std::stringstream log;
			log << "PARAM Q_NBR: "<<getQualities()<<"\n"
			<< "PARAM MAX_SUPP_Q_BITRATE: "<<maxSupportedQualityBitrate()<<"\n"
			<< "PARAM MAX_SUPP_Q_INDEX: "<<maxSupportedQualityIndex_var<<"\n"
			<< "PARAM NEXT_PIECE_TO_PLAY:"<<getNextPieceToPlay()<<"\n"
			<< "PARAM LAST_PIECE_INDEX: "<<getLastPieceIndex()<<"\n"
			<< "PARAM OFFSET: "<<qualityOffset_var<<"\n"
			<< "PARAM PIECE_DURATION: "<<getPiecePlaybackDuration()<<"\n"
			<< "PARAM NUM_PIECES: "<<numPieces()<<"\n"
			<< "PARAM ADAPTIVE: "<<adaptive;
			this->writeLog(log.str().c_str());
		}
	} else
	{
		cancelAndDelete(evtPlayNextPiece);
		evtPlayNextPiece = NULL;
		cancelAndDelete(evtCacheThreadCreation);
	}

}
/**
 * This method is called to intialize the cache thread which will be used by all the
 * peers' threads to send HTTP piece request
 */
TCPServerThreadBase * BTPeerWireBase::initializeCacheThread() {

	BEV<<"initializing a thread for the connection with cache"<<endl;

	// new connection -- create new socket object and server process
	TCPSocket *newsocket = new TCPSocket();

	unsigned short port = tcp->getEphemeralPort();
	int peerWirePort = par("port");

	//It could be the case that the peerWire port is freed so that we do not accept connections.
	while ((port==peerWirePort))
	port = tcp->getEphemeralPort();

	newsocket->bind(port);

	TCPServerThreadBase *proc = check_and_cast<TCPServerThreadBase *>(createOne("BTPeerWireCacheThread"));

	newsocket->setCallbackObject(proc);

	BTPeerWireCacheThread* myProc = (BTPeerWireCacheThread*) proc;
	myProc->init(this, newsocket);
	myProc->setActiveConnection(false);
	myProc->setRemotePeerID((const char*)par("cacheIpAddress"));
	//peerState.addPeer(peer,proc);

	newsocket->setOutputGate(gate("tcpOut"));

	IPvXAddress cacheAddress = IPAddressResolver().resolve(par("cacheIpAddress").stringValue());
	ASSERT(!cacheAddress.isUnspecified());

	if (LOGFILE) {
		std::stringstream log;
		log << "PARAM ISBEHINDCACHE: YES \n";
		this->writeLog(log.str().c_str());
	}

	newsocket->connect(cacheAddress , cachePort_var);
	socketMap.addSocket(newsocket);

	increasePendingNumConnections();
	updateDisplay();

	return (proc);
}

/**
 * This method is called in order to close the server socket listening for incoming
 * connection requests. This way the number of allowed TCP connections is capped.
 */
void BTPeerWireBase::stopListening() {
	int sockstate = serverSocket.getState();
	if (sockstate == TCPSocket::LISTENING) {
		serverSocket.close();
		serverSocket.renewSocket();
	}
}

/**
 * This method is called in order to prepare the server socket for incoming connection requests,
 * in case it was previously closed to cap the number of allowed TCP connections.
 */
void BTPeerWireBase::startListening() {
	int sockstate = serverSocket.getState();

	if ((sockstate == TCPSocket::NOT_BOUND) && (getState() != EXITING)) {
		const char *address = par("address");
		int port = par("port");

		serverSocket.setOutputGate(gate("tcpOut"));
		serverSocket.bind(address[0] ? IPvXAddress(address) : IPvXAddress(),
				port);
		serverSocket.listen();
	}
}

/**
 * Main peer wire protocol functionality. This method manages connections/messages/timers etc.
 * The major deviation from the standard TCPSrvHost (INET) is that it also supports active
 * establishment of connections (and the corresponding threads).
 *
 *
 */
void BTPeerWireBase::handleMessage(cMessage *msg) {

	if (msg->isSelfMessage()) {
		if (msg->getKind() < _PEER_WIRE_BASE_MSG_FLAG)
			handleSelfMessage(msg);
		else
			handleThreadMessage(msg);
	}// !=selfMessage()
	else {
		//TODO: Make this a method call ...
		if (msg->arrivedOn("btorrentIn")) {
			if (getState() < EXITING) {
				//This is the only msg possible to receive from the tracker client. All checks have already been
				//performed by that module.
				BTTrackerMsgResponse* trackerResponse_msg = check_and_cast<
						BTTrackerMsgResponse*> (msg);

				//Keep this response for reference (until the next one)...
				setTrackerResponse(trackerResponse_msg);

				setAnnounceInterval(trackerResponse()->announceInterval());

				BEV<<"received a Tracker Response containing "<< trackerResponse()->peersArraySize()<<" peers."<<endl;

				//Based on the peer dictionary, establish connections to remote peers.
				//Furthermore, initiate the (optimistic un-)choking procedures.
				if (trackerResponse()->peersArraySize() > 0)
				{
					setCurrentNumEmptyTrackerResponses(0);
					scheduleConnections(trackerResponse());

					//Check if we have already scheduled the execution of the algorithms i.e. this is not the first
					//tracker response received.
					if (!((cMessage*)evtChokeAlg)->isScheduled())
					scheduleAt(simTime(), evtChokeAlg);

					if (!((cMessage*)evtOptUnChoke)->isScheduled())
					scheduleAt(simTime(), evtOptUnChoke);
				}
				else
				{
					setCurrentNumEmptyTrackerResponses(currentNumEmptyTrackerResponses()+1);

					//Exiting due to empty response will be scheduled only if this is not a Seeding (not seeder) node.
					//Else, exit would be scheduled twice!
					if ((currentNumEmptyTrackerResponses() >= maxNumEmptyTrackerResponses()) && (peerState.size()==0)
							&& (getState()!=SEEDING))
					{
						BEV<<"reached maximum allowed number of empty subsequent tracker responses ( ="<<maxNumEmptyTrackerResponses() <<")."<<endl;
						setState(EXITING);
						stopChokingAlorithms();

						//Setting download duration to zero: will be interprented as a failure
						//in BTStatistics
						setDownloadDuration(0);
						scheduleAt(simTime(),new cMessage(toString(INTERNAL_EXIT_MSG), INTERNAL_EXIT_MSG));
					}
				}

				//Scheduling next contact with the tracker.
				scheduleAt(simTime()+announceInterval(), evtTrackerComm);
			}
			if (trackerResponse_var) {
				delete trackerResponse_var;
				trackerResponse_var = NULL;
			}
			delete msg;
		}
		else if(msg->arrivedOn("videoserverIn"))
		{
			BEV<<"HTTP response received from the HttpVideoServer"<<endl;
			TCPServerThreadBase *thread =
			(TCPServerThreadBase *) msg->getContextPointer();
			BTPeerWireClientHandlerBase* handler =
			(BTPeerWireClientHandlerBase*) thread;

			if(msg->getKind() == HTTP_RESPONSE_MSG) {
				if (((!handler->amChoking())&&(handler->peerInterested()))
						||handler->isCacheThread())
				{
					httptReplyMessage* response = check_and_cast<httptReplyMessage*>(msg);
					string uri = response->relatedUri();
					cStringTokenizer tokenizer = cStringTokenizer(uri.c_str(),"_");
					std::vector<string> params = tokenizer.asVector();

					int qlevel = strtol(params[1].c_str(),0,10);
					int piece = strtol(params[2].c_str(),0,10);
					int block = strtol(params[3].c_str(),0,10);

					BEV<<"Message for piece: "<< piece <<", block : "<< block <<endl;

					BTRequestCancelMsg* req =
					(BTRequestCancelMsg*) handler->createBTPeerWireMessage(
							this->toString(REQUEST_MSG), REQUEST_MSG,
							piece, block,(int) handler->getPayloadMessageLength(piece));//bloc size to be fixed

					if (this->localBitfield()->isBlockAvailable(piece,block))
					{

						//Actually not implementing anti-snubbing at the moment (due to contradictory definitions).
						if (handler->getState() <ANTI_SNUBBING)
						{

							RequestEntry entry(req->index(),req->begin(),req->dataLength(),simTime(),handler->getRemotePeerID().c_str(),check_and_cast<httptReplyMessage*>(msg));
							handler->incomingRequests.insert(entry);
							handler->scheduleAt(simTime(),new cMessage(toString(PIECE_TIMER),PIECE_TIMER));

							//If we are in super-seed mode and we just sent the last block, we shall inform
							//this client of another piece only if we see the current piece in another
							//peer's bitfield
							if ((superSeedMode()) && (req->begin() == numBlocks()-1))
							{
								BTInternalMsg* intMsg = new BTInternalMsg(toString(INTERNAL_SUPER_SEED_COMPLETE_MSG),INTERNAL_SUPER_SEED_COMPLETE_MSG);
								intMsg->setPieceIndex(req->index());
								intMsg->setText(handler->getRemotePeerID().c_str());
								scheduleAt(simTime(),intMsg);
							}
						}
						else
						{
							BEV<<"client in anti-snubbing mode, refusing to send the piece."<<endl;
							delete response;

						}
					}
					else
					{
						BEV<<"cannot serve request, requested block not available."<<endl;
						delete response;
					}
					delete req;
				}
				else
				{
					BEV<<"cannot serve request, peer is choked."<<endl;
					delete msg;
				}

			}
			else {
				BEV<<"received unexpected message from the HttpVideoServer !"<<endl;
				delete msg;
			}
		} else if(msg->arrivedOn("statdirect"))
		{

			if (msg->getKind() == BT_STATS_FINISH) {
				//cerr << this->getParentModule()->getName() << " Receiving BT_STATS_FINISH message form BTStatistic module" << endl;
				checkAndScheduleExit();
			}
			delete msg;
		}
		else
		{
			TCPSocket *socket = socketMap.findSocketFor(msg);

			if (!socket)
			{
				//This is not a self-message. If it is not a TCP_I_ESTABLISHED message then there should
				//exist a socket for it.
				//cerr << getParentModule()->getFullName() << " Socket not found case" << endl;
				if (msg->getKind()==TCP_I_ESTABLISHED)
				{

					// new connection -- create new socket object and server process
					socket = new TCPSocket(msg);
					socket->setOutputGate(gate("tcpOut"));

					const char *serverThreadClass = (const char*)par("serverThreadClass");
					TCPServerThreadBase *proc = check_and_cast<TCPServerThreadBase *>(createOne(serverThreadClass));

					socket->setCallbackObject(proc);

					BTPeerWireClientHandlerBase* myProc = (BTPeerWireClientHandlerBase*) proc;
					myProc->init(this, socket);
					myProc->setActiveConnection(false);

					//NOTE: Since we dont have the peer's name we just make an entry with the IP address and port.
					// We will update this entry with the peerId once we have received it via the Handshake msg.
					ostringstream o;
					o << socket->getRemoteAddress().str()<< "_"<<socket->getRemotePort();
					PEER peer;

					opp_string* tmp = new opp_string(o.str().c_str());
					peer.peerId = *tmp;
					myProc->setRemotePeerID(o.str().c_str());

					peer.ipAddress = socket->getRemoteAddress();
					peer.peerPort = socket->getRemotePort();
					peerState.addPeer(peer,proc,SIMTIME_DBL(simTime()));
					socketMap.addSocket(socket);
					increasePendingNumConnections();

					int index = peerState.findPeer(peer.ipAddress);
					bool rejectConn = false;

					if (index>=0)
					rejectConn = connectionAlreadyEstablished(index);

					if (!rejectConn)
					{
						BEV<<"established ('passive') connection to "<<socket->getRemoteAddress()<<":"<<socket->getRemotePort()<<" , adding peerInfo..."<<endl;

						updateDisplay();
						socket->processMessage(msg);
					}
					else
					{
						//The peer-state will be taken care of later when the connection will have closed
						//i.e. the thread itself will indicate that it must be removed from the state.
						if(!myProc->isCacheThread()) {
							socket->close();
							//By closing the socket here the current number of connections is decreased
							//however "established" was never called so we have to increase it again.
							increaseCurrentNumConnections();
							delete msg;
						} else {
							updateDisplay();
							socket->processMessage(msg);
						}

					}
				}
				else
				{
					delete msg;

				}
			}
			else
			{
				//cerr << getParentModule()->getFullName() << " Socket found case" << endl;

				int kind = msg->getKind();

				bool rejectConn = false;

				if (kind==TCP_I_ESTABLISHED)
				{
					BEV<<"a connection initiated by this peer is now established."<<endl;
					//cerr << getParentModule()->getFullName() << " a connection initiated by this peer is now established." << endl;
					int connIndex = peerState.findPeer(socket->getRemoteAddress());
					if (connIndex>=0)
					{
						rejectConn = connectionAlreadyEstablished(connIndex);
						peerState.getPeerEntryRef(connIndex)->setConnTime(SIMTIME_DBL(simTime()));
					}
				}

				if (!rejectConn)
				{
					socket->processMessage(msg);
					//int connIndex;
					/*if (kind == TCP_I_CLOSED) {
					 //cerr << getParentModule()->getFullName() << " Entering TCP_I_TCP case." << endl;
					 connIndex = peerState.findPeer(socket->getRemoteAddress());
					 //cerr << getParentModule()->getFullName() << " Processing message TCP_I_CLOSED from terminal: "
					 // << socket->getRemoteAddress().get4().str().c_str()<<endl;
					 if (connIndex >= 0) {
					 //cerr << getParentModule()->getFullName()<<": Normal Thread Socket Closing. Current State: "<<socket->getState()<< endl;

					 //cerr << getParentModule()->getFullName() << "\t for Remote terminal ID: "
					 // << ((BTPeerWireClientHandlerBase*)(peerState.getPeerEntryRef(connIndex))->getPeerThread())->getRemotePeerID().c_str()<<endl;
					 BTPeerWireClientHandlerBase* currentThread = (BTPeerWireClientHandlerBase*)(peerState.getPeerEntryRef(connIndex))->getPeerThread();
					 //if(!currentThread->getSocketRemoved()){
					 // socket->processMessage(msg);
					 // currentThread->setSocketRemoved(true);
					 //if((socket->getState() != TCPSocket::CLOSED) && (socket->getState() != TCPSocket::SOCKERROR)
					 //		) {
					 if(!currentThread->getThreadRemovelScheduled())
					 socket->processMessage(msg);
					 else {
					 //socket->abort();
					 decreaseCurrentNumConnections();
					 cerr << getParentModule()->getFullName() << " Thread of this socket already in removal process !!!!" << endl;
					 delete msg;
					 }
					 //} else {
					 //	//cerr << getParentModule()->getFullName() << "Socket already closed !!!!" << endl;
					 //	delete msg;
					 //}
					 //cerr <<"\t\t ...done Normal Thread Socket Closing" << endl;
					 }
					 else {
					 if (this->cacheThread) {
					 //cerr <<"\t\t Cache Thread Socket Closing. Current State: "<< cacheThread->getSocket()->getState()<<endl;
					 cacheThread->getSocket()->processMessage(msg);
					 //cerr <<"\t\t ...done Cache Thread Socket Closing" << endl;
					 } else {
					 //cerr << getParentModule()->getFullName() << "Thread not found to process TCP_I_CLOSED message!!!!" << endl;
					 delete msg;
					 }
					 }
					 } else {
					 //printf("Processing the socket message as a server \n");
					 if((socket->getState() != TCPSocket::CLOSED) && (socket->getState() != TCPSocket::SOCKERROR)) {
					 //cerr << getParentModule()->getFullName() << "Handling TCP message other than TCP_I_CLOSE and TCP_I_ESTABLISHED. Kind: " << kind << endl;
					 socket->processMessage(msg);
					 //cerr << getParentModule()->getFullName() << "...Done handling TCP message of kind = " << kind << endl;
					 } else {
					 cerr << getParentModule()->getFullName() << " Socket already closed !!!!" << endl;
					 delete msg;
					 cerr << getParentModule()->getFullName() << " ...done deleting the received message" << endl;
					 }
					 }*/
				}
				else
				{
					//cerr << getParentModule()->getFullName() << " Something wrong with the socket. Let's close it !" << endl;
					int connIndex = peerState.findPeer(socket->getRemoteAddress());
					if (connIndex>=0) {
						socket->close();
						increaseCurrentNumConnections();
						delete msg;
					} else {
						if (this->cacheThread) {
							cacheThread->getSocket()->processMessage(msg);
						} else {
							delete msg;
						}
					}
					//cerr << getParentModule()->getFullName() << " ...done deleting the received message" << endl;
				}
			}
		}
	}
}

/**
 * Handles a message sent by a thread to inform this Peer Wire protocol base module about an event or
 * an action that must take place.
 */

void BTPeerWireBase::handleThreadMessage(cMessage* msg) {
	/*cerr << getParentModule()->getFullName()
	 << "Entering handleThreadMessage..." << endl;*/
	TCPServerThreadBase *thread =
			(TCPServerThreadBase *) msg->getContextPointer();
	BTPeerWireClientHandlerBase* handler =
			(BTPeerWireClientHandlerBase*) thread;
	//cerr << getParentModule()->getFullName() << "Handler ready..." << endl;
	switch (msg->getKind()) {
	case INTERNAL_REMOVE_THREAD_MSG: {
		//This socket may be removed only if it has closed or failed (due to a timeout e.g. the remote peer exited)
		/*cerr << getParentModule()->getFullName()
		 << "Handling INTERNAL_REMOVE_THREAD_MSG message..." << endl;*/
		if ((thread->getSocket()->getState() != TCPSocket::CLOSED)
				&& (thread->getSocket()->getState() != TCPSocket::SOCKERROR)) {
			cerr << getParentModule()->getFullName()
			 << ": waiting for socket to close with"
			 << (handler)->getRemotePeerID().c_str() << ":"
			 << thread->getSocket()->getRemoteAddress().get4().str().c_str()
			 << "Socket Status: "<< thread->getSocket()->getState()
			 << endl;
			scheduleAt(simTime() + 200, msg);
		} else {
			/*cerr << getParentModule()->getFullName()
			 << ": removing thread for remote terminal: "
			 << (handler)->getRemotePeerID().c_str() << ":"
			 << thread->getSocket()->getRemoteAddress().get4().str().c_str()
			 << "Socket Status: "<< thread->getSocket()->getState()
			 << endl;*/
			removeThread(thread);
			peerState.removePeer((handler)->getRemotePeerID());
			serverThreads.push_back(thread);
			/*cerr << getParentModule()->getFullName()
			 << " ... done removing thread" << endl;*/
			//delete msg;
		}
		break;
	}
	case INTERNAL_UPDATE_THREAD_MSG: {
		//cerr << getParentModule()->getFullName() << "Handling INTERNAL_UPDATE_THREAD_MSG message..." << endl;
		BTInternalMsg* upmsg = (BTInternalMsg*) msg;

		PEER peer = upmsg->peer();

		int index = peerState.findPeer((string) upmsg->text());

		if (index >= 0)
			peerState.updatePeerID(index, peer.peerId.c_str());
		else
			error(
					"%s:%d at %s() Inconsistent peer state, received a handshake msg from an unknown connection. \n",
					__FILE__, __LINE__, __func__);

		delete upmsg;
		break;
	}

	case INTERNAL_SUPER_SEED_HAVE_MSG: {
		//cerr << getParentModule()->getFullName() << "Handling INTERNAL_SUPER_SEED_HAVE_MSG message..." << endl;
		BEV<<"in Super-Seed mode: sending a Have message for a rare piece"<<endl;

		scheduleSuperSeedHaveMsg(thread);
		delete msg;
		break;
	}
	case INTERNAL_SUPER_SEED_COMPLETE_MSG:
	{
		//cerr << getParentModule()->getFullName() <<"Handling INTERNAL_SUPER_SEED_COMPLETE_MSG message..." << endl;
		BTInternalMsg* intMsg = check_and_cast<BTInternalMsg*>(msg);
		BlockItem* item = new BlockItem(intMsg->pieceIndex(), numBlocks()-1,intMsg->text());
		superSeedPending.push_back(item);
		delete msg;
		break;
	}
	case INTERNAL_UPDATE_INTERESTS_MSG:
	{
		//cerr << getParentModule()->getFullName() << "Handling INTERNAL_UPDATE_INTERESTS_MSG message..." << endl;
		updateInterests();
		delete msg;
		break;
	}
	case BITFIELD_MSG:
	{
		//cerr << getParentModule()->getFullName() << "Handling BITFIELD_MSG message..." << endl;
		BEV<<"received a Bitfield message, updating piece frequencies."<<endl;
		pieceFreqState.updatePieceFrequencies(check_and_cast<BTBitfieldMsg*>(msg));

		if (getState() == SEEDER)
		{
			checkandScheduleHaveMsgs(check_and_cast<BTBitfieldMsg*>(msg), handler->getRemotePeerID().c_str());
		}
		else
		{
			//NOTE: Super-seeding is only recommended for initial seeding servers and NOT for general use.
			//In effect, this seeding server will never be requiered to send a (NOT_)INTERESTED msg.
			//Check whether we are interested in this peer.
			//In any case, send the appropriate msg and set the AM_INTERESTED to true/false
			int interest = amInterested(check_and_cast<BTBitfieldMsg*>(msg));
			if (interest > 0)
			{
				if (interest == numPieces())
				handler->setSeeder(true);
				if (!handler->amInterested())
				thread->timerExpired(new cMessage(toString(INTERESTED_TIMER),INTERESTED_TIMER));
			}
			else
			{
				if (handler->amInterested())
				thread->timerExpired(new cMessage(toString(NOT_INTERESTED_TIMER),NOT_INTERESTED_TIMER));
			}
		}
		delete msg;
		break;
	}
	case HAVE_MSG:
	{
		//cerr << getParentModule()->getFullName() << "Handling HAVE_MSG message..." << endl;
		int index = check_and_cast<BTHaveMsg*>(msg)->index();
		//BEV<<"received a Have message, updating piece's #"<< index <<" frequency."<<endl;
		pieceFreqState.increasePieceFrequency(index);
		//Check whether we were not interested in this peer and this piece makes us interested.
		if ((!handler->amInterested()) && (amInterested(handler->getRemoteBitfield())>0))
		{
			thread->timerExpired(new cMessage(toString(INTERESTED_TIMER),INTERESTED_TIMER));
		}

		delete msg;
		break;
	}
	case UNCHOKE_MSG:
	{
		//BEV<<"received an Unchoke message, from peer "<<handler->getRemotePeerID()<<"."<<endl;
		//This message is simply ignored if this client does not want any data
	}
	case INTERNAL_NEXT_REQUEST_MSG:
	{
		//cerr << getParentModule()->getFullName() << "Handling INTERNAL_NEXT_REQUEST_MSG message ..."<< endl;
		if (getState() < COMPLETED)
		{
			if (getState() != ENDGAME)
			makeNextPeerMove(thread);
			else
			scheduleEndGameRequests();
		}

		delete msg;
		break;
	}
	case INTERESTED_MSG:
	{
		//This module will receive this message only if the remote peer is unchoked.
		//In this case, and if this peer has a better upload rate than a downloader
		// the latter must be replaced (by this one).
		//cerr << getParentModule()->getFullName() << "Handling INTERESTED_MSG message ..."<< endl;
		if (handler->getDownloadRate() > peerState.minDownloaderRate())
		chokeWorstDownloader();

		delete msg;
		break;
	}
	case INTERNAL_RECORD_DATA_PROVIDER_TIMER:
	{
		//cerr << getParentModule()->getFullName() << "Handling INTERNAL_RECORD_DATA_PROVIDER_TIMER message ..."<< endl;
		dataProviderPeerIDs.insert(handler->getRemotePeerID());
		delete msg;
		break;
	}
	case PIECE_MSG:
	{
		//Just forward the message to the HttpVideoServer
		//msg->setContextPointer(thread);
		//cerr << getParentModule()->getFullName() << "Handling PIECE_MSG message ..."<< endl;
		if (LOGFILE) {
			BTPieceMsg* piece = check_and_cast<BTPieceMsg*> (msg);
			int block = piece->begin();
			std::stringstream log;
			//cerr << getParentModule()->getFullName()<< " HRPIECE: "<< piece->index() << " " <<block <<endl;
			log << "HRPIECE: " << simTime().str().c_str() << " "
			<< piece->index() << " " << block;
			this->writeLog(log.str().c_str());
		}
		send(msg,"videoserverOut");
		break;

	}
	case HTTP_REQUEST_MSG:
	{
		//cerr << getParentModule()->getFullName() << "Handling HTTP_REQUEST_MSG message ..."<< endl;
		httptRequestMessage* request = (httptRequestMessage*) msg;
		BEV<<"received an HTTP request : "<<request->heading()<<endl;
		//Just To Debug

		string uri = request->uri();

		cStringTokenizer tokenizer = cStringTokenizer(uri.c_str(), "_");
		std::vector<string> params = tokenizer.asVector();

		int qlevel = strtol(params[1].c_str(), 0, 10);
		int piece = strtol(params[2].c_str(), 0, 10);
		int block = strtol(params[3].c_str(), 0, 10);

		if(LOGFILE) {
			std::stringstream log;
			//cerr << "Writing log: "<< "HRPIECE: "<< simTime().str().c_str() << " " << piece_index << " " <<block << " " << qlevel << endl;
			log << "HRREQ: "<< simTime().str().c_str() << " " << piece << " " <<block;
			this->writeLog(log.str().c_str());
		}

		string wwwName;
		wwwName += getParentModule()->getFullName();
		wwwName += ".omnet.net";
		request->setTargetUrl(wwwName.c_str());
		request->setContextPointer(thread);
		send(request,"videoserverOut");
		break;
	}
	default:
	{
		//If there is a thread responsible for the message, let it handle it.
		//cerr << getParentModule()->getFullName() << "Forwarding the message to the Thread ..."<< endl;
		if (thread!=NULL)
		thread->timerExpired(msg);
		else
		error("%s:%d at %s() Inconsistent thread state, could not find thread to handle this message %d. \n", __FILE__, __LINE__, __func__,msg->getKind());

		break;
	}
}
//cerr << getParentModule()->getFullName() << "... Leaving handleThreadMessage" << endl;
}

void BTPeerWireBase::checkAndScheduleExit() {
	if (getState() < EXITING) {
		//cerr << getParentModule()->getName() << " Going to exit ..." << endl;
		setState(EXITING);
		stopChokingAlorithms();
		scheduleAt(simTime(), new cMessage(toString(INTERNAL_EXIT_MSG),
				INTERNAL_EXIT_MSG));
		return;

	}

}

void BTPeerWireBase::updateBitField(int pieceIndex, int blockIndex,
		bool expected, const char* blockProvider) {
	//BEV<<"received a Piece message for piece #"<< pieceIndex <<" , block #"<< blockIndex<<endl;

	localBitfield()->setLastDownloadTime(simTime());

	bool doUpdateBitfield = true;
	if (getState() == ENDGAME) {
		scheduleEndGameCancel(pieceIndex, blockIndex, blockProvider);
		if (localBitfield()->isBlockAvailable(pieceIndex, blockIndex)) {
			doUpdateBitfield = false;

		}
	}

	//Update the local bitfield and check whether this piece has completed
	//so as to possibly send Have messages and check if we finished downloading.
	//Do not do so however if this is a block already received (due to the endgame mode)
	if (doUpdateBitfield) {
		if (localBitfield()->update(pieceIndex, blockIndex, expected)) {

			bool notCanceledEndGameReq = false;

			//Now check whether we have completed the downloading process
			if ((localBitfield()->finishedDownloading()) && (getState()
					< COMPLETED)) {
				setState(COMPLETED);
				setDownloadDuration(simTime() - downloadDuration());

				BEV<<"\ndownload of file completed! Downloaded = "<< fileSize()/1024 <<" MBs in "<< downloadDuration() << " seconds."<<endl;

				cerr<<"\n*********** "<<getParentModule()->getFullName()<< ": Download of file completed! Downloaded = "<< fileSize()/1024 <<" MBs in "<< downloadDuration() << " seconds. ***********\n"<<endl;
				if (LOGFILE) {
					std::stringstream log;
					//cerr << "Writing log: "<< "HRPIECE: "<< simTime().str().c_str() << " " << piece_index << " " <<block << " " << qlevel << endl;
					log << "DOWNLOAD COMPLETED " << simTime().str().c_str();
					this->writeLog(log.str().c_str());
				}
				if (timeToSeed()>0)
				{
					//cerr<<"\n*********** "<<getParentModule()->getFullName()<< ": We are seeding for "<< timeToSeed() <<" seconds. ***********\n"<<endl;
					setState(SEEDING);
					scheduleAt(simTime()+timeToSeed(),new cMessage(toString(INTERNAL_EXIT_MSG), INTERNAL_EXIT_MSG));
				}
				else
				{
					setState(EXITING);
					stopChokingAlorithms();
					scheduleAt(simTime(),new cMessage(toString(INTERNAL_EXIT_MSG), INTERNAL_EXIT_MSG));
					return;
				}
			}
			else if ((localBitfield()->finishedDownloading()) && (getState() >= COMPLETED))
			{
				BEV<<"received a block item more than once, could not cancel end-game mode request."<<endl;
				notCanceledEndGameReq = true;
			}

			//Do not inform peers if exiting or if they have been previously informed
			if ((getState() != EXITING) && (!notCanceledEndGameReq))
			{
				informPeers(pieceIndex);
			}
		}
	}
}

/**
 * Handles a message scheduled by this Peer Wire protocol base module. It practically handles timers
 * scheduled by this module for itself.
 */

void BTPeerWireBase::handleSelfMessage(cMessage* msg) {
	switch (msg->getKind()) {
	case INTERNAL_CACHE_THREAD_CREATION: {
		delete msg;
		BEV<<"try to connect to the cache address : "<<par("cacheIpAddress").stringValue()<<endl;
		//printf("In BTPeerWireBase::handleSelfMessage. Case INTERNAL_CACHE_THREAD_CREATION\n");
		if (!strcmp(par("cacheIpAddress").stringValue(), ""))
		BEV<<"no cache IP address. No cache thread creation"<<endl;
		else
		BEV<<"trying to create cache thread for IP address: "<<cacheIpAddress_var<<endl;
		if (httpCacheUse() && strcmp(par("cacheIpAddress").stringValue(),"")) {
			BEV<<"creating cache thread for IP address: "<<cacheIpAddress_var<<endl;
			cacheThread = initializeCacheThread();
			if(!cacheThread)
			BEV<<"cannot create cache thread"<<endl;
			else
			BEV<<"cache thread created"<<endl;
		} else {
			cacheThread = NULL;
			use_chache_server_var = false;
			if (LOGFILE) {
				std::stringstream log;
				log << "PARAM ISBEHINDCACHE: NO \n";
				writeLog(log.str().c_str());
			}
		}

		break;
	}
	case INTERNAL_TRACKER_COM_MSG: {
		BEV<< "instructing communication with the tracker..."<<endl;
		//printf("In BTPeerWireBase::handleSelfMessage. Case INTERNAL_TRACKER_COM_MSG\n");
		switch (getState())
		{
			case NORMAL:
			case ENDGAME:
			case SEEDER:
			{

				send(new cMessage(toString(EVT_CONN),EVT_CONN),"btorrentOut");
				break;
			}
			case COMPLETED:
			case SEEDING:
			{
				send(new cMessage(toString(EVT_COMP),EVT_COMP),"btorrentOut");
				break;
			}
			case EXITING:
			{
				send(new cMessage(toString(EVT_STOP),EVT_STOP),"btorrentOut");
				break;
			}
			default:
			error("%s:%d at %s() Invalid client state (STATE = %d). \n", __FILE__, __LINE__, __func__,getState());

		}

		//NOTE: Take a look at not in handleMessage() from gate "btorrentIn"...
		//if ((getState()<EXITING) && (announceInterval()>0))
		//	scheduleAt(simTime()+announceInterval(), evtTrackerComm);

		break;
	}
	case INTERNAL_CHOKE_TIMER:
	{
		BEV<<"running chocking algorithm."<<endl;
		//printf("In BTPeerWireBase::handleSelfMessage. Case INTERNAL_CHOKE_TIMER\n");
		ChokingAlgorithm();
		scheduleAt(simTime() + chockingInterval(), evtChokeAlg);

		break;
	}
	case INTERNAL_OPT_UNCHOKE_TIMER:
	{
		BEV << "optimistic unchoking..."<<endl;
		//printf("In BTPeerWireBase::handleSelfMessage. Case INTERNAL_OPT_UNCHOKE_TIMER\n");
		OptimisticUnChokingAlgorithm();
		scheduleAt(simTime()+ optUnchockingInterval(), evtOptUnChoke );

		break;
	}
	case INTERNAL_INIT_CONNECTION_MSG:
	{
		//printf("In BTPeerWireBase::handleSelfMessage. Case INTERNAL_INIT_CONNECTION_MSG\n");
		if (getState()< EXITING)
		{
			//Get the information for the peer that we are going to connect and send a handshake
			BTInternalMsg* intMsg = (BTInternalMsg*)msg;
			PEER peer = intMsg->peer();

			BEV <<"initializing a thread for the connection with peer: " << peer.peerId <<"."<<endl;

			// new connection -- create new socket object and server process
			TCPSocket *newsocket = new TCPSocket();

			unsigned short port = tcp->getEphemeralPort();
			int peerWirePort = par("port");

			//It could be the case that the peerWire port is freed so that we do not accept connections.
			while ((port==peerWirePort))
			port = tcp->getEphemeralPort();

			newsocket->bind(port);

			const char *serverThreadClass = (const char*)par("serverThreadClass");

			TCPServerThreadBase *proc = check_and_cast<TCPServerThreadBase *>(createOne(serverThreadClass));

			newsocket->setCallbackObject(proc);

			BTPeerWireClientHandlerBase* myProc = (BTPeerWireClientHandlerBase*) proc;
			myProc->init(this, newsocket);
			myProc->setActiveConnection(true);
			myProc->setRemotePeerID(peer.peerId.c_str());
			peerState.addPeer(peer,proc);

			newsocket->setOutputGate(gate("tcpOut"));

			newsocket->connect(peer.ipAddress, peer.peerPort);
			socketMap.addSocket(newsocket);

			increasePendingNumConnections();
			updateDisplay();
		}

		delete msg;
		break;
	}
	case INTERNAL_EXIT_MSG:
	{
		//printf("%s In BTPeerWireBase::handleSelfMessage. Case INTERNAL_EXIT_MSG\n", getParentModule()->getFullName());
		delete msg;

		if(playbackFinish) {
			if (getState()==SEEDING)
			{
				setState(EXITING);
				stopChokingAlorithms();
			}

			cancelAndDelete(evtPlayNextPiece);

			BEV<<"exiting application ..."<<endl;
			BEV<<"closing all peer wire connections..."<<endl;
			TCPServerThreadBase *thread;
			BTPeerWireClientHandlerBase* handler;
			PeerEntryVector peerVector = peerState.getVector();
			//cerr << getParentModule()->getFullName() << ". Going to delete " << peerVector.size() << "threads" << endl;
			for (unsigned int i=0; i<peerVector.size(); i++)
			{
				PeerEntry entry= peerVector[i];
				thread = check_and_cast<TCPServerThreadBase *>(entry.getPeerThread());
				if (!thread)
				error("%s:%d at %s() Inconsistent thread state, could not find peer thread. \n", __FILE__, __LINE__, __func__);
				handler = (BTPeerWireClientHandlerBase*) thread;
				pair<set<string>::iterator, bool> result = closedRemotePeersID.insert(handler->getRemotePeerID());
				if (result.second) {
					thread->timerExpired(new cMessage(toString(CLOSE_CONNECTION_TIMER),CLOSE_CONNECTION_TIMER));
					//cerr << getParentModule()->getFullName() << ". " << i <<" sending CLOSE_CONNECTION_TIMER to thread responsible for: " << handler->getRemotePeerID() <<endl;
				}
				else {
					thread->timerExpired(new cMessage(toString(DEL_THREAD_TIMER_FROM_HOST),DEL_THREAD_TIMER_FROM_HOST));
					//cerr << getParentModule()->getFullName() << ". " << i <<" sending DEL_THREAD_TIMER to thread responsible for: " << handler->getRemotePeerID() <<endl;
				}
			}
			if(cacheThread) {
				cacheThread->timerExpired(new cMessage(toString(CLOSE_CONNECTION_TIMER),CLOSE_CONNECTION_TIMER));
			}

			stopListening();

			scheduleAt(simTime()+1000, new cMessage(toString(INTERNAL_EXIT_SAFE_MSG),INTERNAL_EXIT_SAFE_MSG));
		} else {
			scheduleAt(simTime()+1000,new cMessage(toString(INTERNAL_EXIT_MSG), INTERNAL_EXIT_MSG));
		}
		break;

	}
	case INTERNAL_EXIT_SAFE_MSG:
	{
		//printf("In BTPeerWireBase::handleSelfMessage. Case INTERNAL_EXIT_SAFE_MSG\n");
		delete msg;

		//Wait until all connections have been closed properly
		if ((peerState.size() > 0) || (evtTrackerComm->isScheduled()))
		{
			//FIXME: No time available ... remove this hardcoded value (working nice though)
			cerr<<"\n*********** "<<getParentModule()->getFullName()<< ": Still waiting for " << peerState.size() << " threads to be cleaned.  ***********\n"<<endl;
			currentWaitingIteration ++;
			if(currentWaitingIteration == waitingIterationThreshold){
				currentWaitingIteration = 0;
				PeerEntryVector peerVector = peerState.getVector();
				BTPeerWireClientHandlerBase* handler;
				for (unsigned int i=0; i<peerVector.size(); i++)
				{
					PeerEntry entry= peerVector[i];
					TCPServerThreadBase * thread = check_and_cast<TCPServerThreadBase *>(entry.getPeerThread());
					if (!thread)
					error("%s:%d at %s() Inconsistent thread state, could not find peer thread. \n", __FILE__, __LINE__, __func__);

					handler = (BTPeerWireClientHandlerBase*) thread;
					handler->enforceThreadRemoval();
					/*cerr<<"\t======> "<<getParentModule()->getFullName()<< ": Still waiting for thread responsible for: " << handler->getRemotePeerID()
				 	<< " to be cleaned. Its socket status is : "<< handler->getSocket()->getState()<<" <======\n"<<endl;*/
				
				}
			}
			scheduleAt(simTime()+1000, new cMessage(toString(INTERNAL_EXIT_SAFE_MSG),INTERNAL_EXIT_SAFE_MSG));
		}
		else
		{
			BEV<<"***** EXITING SAFELY *****"<<endl;
			cerr<<"\t\t\t\t\t***** "<<getParentModule()->getFullName()<<" EXITING SAFELY *****"<<endl;
			if (LOGFILE) {
				std::stringstream log;
				//cerr << "Writing log: "<< "HRPIECE: "<< simTime().str().c_str() << " " << piece_index << " " <<block << " " << qlevel << endl;
				log << "EXITING SAFELY " << simTime().str().c_str();
				this->writeLog(log.str().c_str());
			}
			if (strcmp(getParentModule()->getNedTypeName(),"inet.applications.xBitTorrent.BTHostSeeder")!=0)
			{
				BEV<<"recording collected statistics..."<<endl;
				cerr<<"\t\t\t\t\t***** "<<getParentModule()->getFullName()<<" recording collected statistics...*****"<<endl;
				writeStats();
			} else {
				//cerr<<"\t\t\t\t\t***** "<<getParentModule()->getFullName()<<" sending finish to BTStatistic module...*****"<<endl;
				cMessage* confirmFinish = new cMessage("BT_CONFIRM_FINISH", BT_CONFIRM_FINISH);
				sendDirect(confirmFinish, btStatistics, btStatistics->findGate("direct_in"));
			}

			//Clean up ...
			cancelAndDelete(evtTrackerComm);
			deleteTrackerResponse();
			superSeedPending.clear();
			pieceFreqState.clear();
			endGameRequests.clear();
			peerState.clear();
			dataProviderPeerIDs.clear();
			closedRemotePeersID.clear();
			if (cacheThread) delete cacheThread;
			if(LOGFILE) {
				logFile.close();
			}
			BEV<<"Exit."<<endl;
		}

		break;
	}
	case INTERNAL_PLAYER_MSG:
	{
		//delete msg;

		playNextPiece(msg);

		break;
	}
	default:
	error("%s:%d at %s() Unknown self-message type (msg->getKind() = %d). \n", __FILE__, __LINE__, __func__,msg->getKind());
}
}
/**
 * Here we try to play the next piece. The player tries to retrieve the next piece following the best
 * quality first policy if the adaptive mode is enabled.
 */
void BTPeerWireBase::playNextPiece(cMessage* msg) {
	bool playbackSuccess = false;
	if (LOGFILE) {
		std::stringstream log;
		log << "NEXT_PIECE_TO_PLAY: " << simTime().str().c_str() << " "
				<< getNextPieceToPlay();
		this->writeLog(log.str().c_str());
	}
	if (localBitfield()->isPieceAvailable(getNextPieceToPlay())) {
		playbackSuccess = true;
		successiveMissedPieces_var = 0;
		sucessivePlayedPieces_var++;
		setLastPlayedPieceIndex(getNextPieceToPlay());
		if (LOGFILE) {
			std::stringstream log;
			log << "PLAY: " << simTime().str().c_str() << " "
					<< getNextPieceToPlay();
			this->writeLog(log.str().c_str());
		}
		//nextPieceToPlay_var++;
		if (isAdaptive()) {
			if (LOGFILE) {
				std::stringstream log;
				log << "PARAM CUR_Q_INDEX " << simTime().str().c_str() << " "
						<< currentQualityIndex();
				this->writeLog(log.str().c_str());
			}
			if (currentQualityIndex() > maxSupportedQualityIndex_var) {

				if (LOGFILE) {
					std::stringstream log;
					log << "PARAM SUCCIVE_PLAYED: " << simTime().str().c_str()
							<< " " << sucessivePlayedPieces_var << " "
							<< "PARAM SUCCIVE_MISSED: "
							<< successiveMissedPieces_var;
					this->writeLog(log.str().c_str());
				}

				if (sucessivePlayedPieces_var
						>= succesivePlayedPiecesThreshold_var) {

					setCurrentQualityIndex(currentQualityIndex() - 1);
					if (LOGFILE) {
						std::stringstream log;
						log << "PARAM SUCCIVE_PLAYED: "
								<< simTime().str().c_str() << " "
								<< sucessivePlayedPieces_var << " "
								<< "UPGRADE_Q_INDEX_TO: "
								<< currentQualityIndex();
						this->writeLog(log.str().c_str());
					}
					sucessivePlayedPieces_var = 0;
				}
			}

		}
	} else {
		sucessivePlayedPieces_var = 0;
		successiveMissedPieces_var++;
		if (LOGFILE) {
			std::stringstream log;
			log << "NEXT_PIECE_TO_PLAY: " << simTime().str().c_str() << " "
					<< getNextPieceToPlay()
					<< " NOT FOUND. TRY A LOWER QUALITY";
			this->writeLog(log.str().c_str());
		}
		if (isAdaptive()) {
			//try to get the same piece with a low quality
			int i = maxSupportedQualityIndex_var + 1;

			int nextPieceIndex = getNextPieceToPlay();

			while (nextPieceIndex < (i * qualityOffset_var))
				nextPieceIndex += qualityOffset_var;

			while (i < getQualities()) {
				if (LOGFILE) {
					std::stringstream log;
					log << "NEXT_PIECE_TO_PLAY: " << simTime().str().c_str()
							<< " " << nextPieceIndex;
					this->writeLog(log.str().c_str());
				}
				if (localBitfield()->isPieceAvailable(nextPieceIndex)) {
					if (LOGFILE) {
						std::stringstream log;
						log << "NEXT_PIECE_TO_PLAY: "
								<< simTime().str().c_str() << " "
								<< nextPieceIndex << " FOUND.";
						this->writeLog(log.str().c_str());
					}
					break;
				}
				if (LOGFILE) {
					std::stringstream log;
					log << "NEXT_PIECE_TO_PLAY: " << simTime().str().c_str()
							<< " " << nextPieceIndex
							<< " NOT FOUND. ADD OFFSET: " << qualityOffset_var;
					this->writeLog(log.str().c_str());
				}
				i++;
				nextPieceIndex += qualityOffset_var;
			}

			if (i >= getQualities()) {
				if (secondPiecePlaybackTrial)
					missedPlayerPieces_var++;
				if (LOGFILE) {
					std::stringstream log;
					log << "NEXT_PIECE_TO_PLAY: " << simTime().str().c_str()
							<< " " << nextPieceIndex - qualityOffset_var
							<< " NOT FOUND. " << "PARAM TOTAL_MISSED_PIECES: "
							<< missedPlayerPieces_var;
					this->writeLog(log.str().c_str());
				}
			} else {
				playbackSuccess = true;
				if (LOGFILE) {
					std::stringstream log;
					//cerr << "Writing log: "<< "HRPIECE: "<< simTime().str().c_str() << " " << piece_index << " " <<block << " " << qlevel << endl;
					log << "PLAY: " << simTime().str().c_str() << " "
							<< nextPieceIndex;
					this->writeLog(log.str().c_str());
				}
			}
			// see whether we should downgrade the quality
			if (currentQualityIndex() < getQualities() - 1) {
				if (LOGFILE) {
					std::stringstream log;
					log << "PARAM SUCCIVE_PLAYED: " << simTime().str().c_str()
							<< " " << sucessivePlayedPieces_var << " "
							<< "PARAM SUCCIVE_MISSED: "
							<< successiveMissedPieces_var;
					this->writeLog(log.str().c_str());
				}

				if (successiveMissedPieces_var >= missedPiecesThreshold_var) {
					setCurrentQualityIndex(currentQualityIndex() + 1);
					if (LOGFILE) {
						std::stringstream log;
						log << "PARAM SUCCIVE_MISSED: "
								<< simTime().str().c_str() << " "
								<< successiveMissedPieces_var
								<< " DOWN_Q_INDEX_TO: "
								<< currentQualityIndex();
						this->writeLog(log.str().c_str());
					}
					successiveMissedPieces_var = 0;
				}

			}

		} else if (secondPiecePlaybackTrial)
			missedPlayerPieces_var++;
	}

	if (playbackSuccess)
		incrementNextPieceToPlay();
	else if (secondPiecePlaybackTrial)
		incrementNextPieceToPlay();

	if (getNextPieceToPlay() > getLastPieceIndex()) {

		cerr << "\n*********** " << getParentModule()->getFullName()
				<< ": Playing of file completed! ***********\n" << endl;

		if (LOGFILE) {
			std::stringstream log;
			//cerr << "Writing log: "<< "HRPIECE: "<< simTime().str().c_str() << " " << piece_index << " " <<block << " " << qlevel << endl;
			log << "PLAYBACK COMPLETED " << simTime().str().c_str() << "\n"
					<< "PARAM TOTAL_MISSED_PIECES: " << missedPlayerPieces_var;
			this->writeLog(log.str().c_str());
		}

		playbackFinish = true;

		if ((getState() < COMPLETED)) {
			setState(COMPLETED);
			if (timeToSeed() > 0) {
				/*cerr << "\n*********** " << getParentModule()->getFullName()
				 << ": We are seeding for " << timeToSeed()
				 << " seconds. ***********\n" << endl;*/
				setState(SEEDING);
				scheduleAt(simTime() + timeToSeed(), new cMessage(toString(
						INTERNAL_EXIT_MSG), INTERNAL_EXIT_MSG));
			} else {
				setState(EXITING);
				stopChokingAlorithms();
				scheduleAt(simTime(), new cMessage(toString(INTERNAL_EXIT_MSG),
						INTERNAL_EXIT_MSG));
			}
		}
		return;
	} else {
		if (getNextPieceToPlay() <= getLastPieceIndex()) {
			if (playbackSuccess) {
				//schedule next piece playback after playing the current one
				secondPiecePlaybackTrial = false;
				scheduleAt(simTime() + getPiecePlaybackDuration(), msg);
			} else
			//immediately schedule the next piece playback
			if (!secondPiecePlaybackTrial) {
				secondPiecePlaybackTrial = true;
				scheduleAt(simTime() + getWaitingDurationWhenPieceNotFound(),
						msg);
			} else {
				secondPiecePlaybackTrial = false;
				//incrementNextPieceToPlay();
				scheduleAt(simTime(), msg);
			}

		}
	}
}

/**
 * Here we try to avoid the situation in which a peer thread is unchoked but it cannot ask for more
 * blocks because they have been marked as requested BUT the peer thread that marked them as such
 * has been choked. The former thread must be informed so that it can ask for data.
 *
 */

void BTPeerWireBase::updateInterests() {
	TCPServerThreadBase *thread;
	BTPeerWireClientHandlerBase* handler;
	PeerEntryVector peerVector = peerState.getVector();

	for (unsigned int i = 0; i < peerVector.size(); i++) {
		PeerEntry entry = peerVector[i];
		thread = check_and_cast<TCPServerThreadBase *> (entry.getPeerThread());
		handler = (BTPeerWireClientHandlerBase*) thread;

		if (handler->getState() >= HANDSHAKE_COMPLETE)
			if ((!handler->allowedToRequest()) && (!handler->peerChoking())
					&& (amInterested(handler->getRemoteBitfield()))) {
				handler->setAllowedToRequest(true);

				if (getState() != ENDGAME)
					makeNextPeerMove(thread);
				else
					scheduleEndGameRequests();
			}
	}
}

/**
 * Help method used to print information about this clients peer state i.e. connections with other peers.
 *
 */

void BTPeerWireBase::printConnections() {
	TCPServerThreadBase *thread;

	PeerEntryVector peerVector = peerState.getVector();

	for (unsigned int i = 0; i < peerVector.size(); i++) {
		PeerEntry entry = peerVector[i];
		thread = check_and_cast<TCPServerThreadBase *> (entry.getPeerThread());
		if (!thread)
			error(
					"%s:%d at %s() Inconsistent thread state, could not find peer thread. \n",
					__FILE__, __LINE__, __func__);

		BTPeerWireClientHandlerBase* handler =
				(BTPeerWireClientHandlerBase*) thread;

		cerr << "\t\t\t\t" << getParentModule()->getFullName()
				<< " connected to  " << handler->getRemotePeerID()
				<< ", State = " << handler->getState() << ", SocketState = "
				<< handler->socketState() << ", Time: " << entry.connTime()
				<< " Active: " << handler->activeConnection() << endl;
	}
}

void BTPeerWireBase::stopChokingAlorithms() {
	cancelAndDelete(evtChokeAlg);
	cancelAndDelete(evtOptUnChoke);
}

/**
 * Schedules the transmission of a Have Msg in super-seed mode i.e. a Have msg redarding a rare piece not
 * available at the remote peer.
 *
 * This method should be re-implemented in future subclasses in order to extend/add/change the behavior of the client.
 */
void BTPeerWireBase::scheduleSuperSeedHaveMsg(TCPServerThreadBase* thread) {
	BTPeerWireClientHandlerBase* handler = check_and_cast<
			BTPeerWireClientHandlerBase*> (thread);

	BlockItem* bi = selectPiece(handler->getRemoteBitfield(), true);

	if (bi->isValid()) {
		BTHaveMsg* have = new BTHaveMsg("HAVE_TIMER", HAVE_TIMER);
		have->setByteLength(HAVE_MSG_SIZE);
		have->setIndex(bi->pieceIndex());
		have->setLength_prefix(HAVE_MSG_SIZE);
		have->setID(HAVE);

		thread->timerExpired(have);
	} else
		error(
				"%s:%d at %s() A peer that has completed downloading, is connected to the initial seeder. \n",
				__FILE__, __LINE__, __func__);

	delete bi;
}

/**
 * Makes the next move regarding a certain peer that has just provided a piece or has just unchoked this client.
 * This may either mean requesting one more piece or denoting that this client is not interested in this remote
 * peer any more.
 *
 * This method should be re-implemented in future subclasses in order to extend/add/change the behavior of the client.
 */
void BTPeerWireBase::makeNextPeerMove(TCPServerThreadBase* thread) {

	BTPeerWireClientHandlerBase* handler =
			(BTPeerWireClientHandlerBase*) thread;

	BlockItem* bi = selectPiece(handler->getRemoteBitfield(), false);

	if (bi->isValid()) {
		if (!handler->peerChoking()) {
			handler->sendBlockRequests(bi->pieceIndex(), bi->blockIndex());
		}

	} else {
		// This is either the case in which the peer does not have anything interesting to offer
		// or the case in which have already requested the remainig pieces from another peer.
		if (amInterested(handler->getRemoteBitfield()) == 0) {
			thread->timerExpired(new cMessage(toString(NOT_INTERESTED_TIMER),
					NOT_INTERESTED_TIMER));
		} else {
			handler->setAllowedToRequest(false);
		}
	}

	if (bi) {
		delete bi;
		bi = NULL;
	}
}

/**
 * Choking algorithm as specified in the <a href=\"http://wiki.theory.org/BitTorrentSpecification\"> BitTorrent
 * Protocol Specification v1.0. </a>
 *
 * This method should be re-implemented in future subclasses in order to extend/add/change the behavior of the client.
 */
void BTPeerWireBase::ChokingAlgorithm() {

	TCPServerThreadBase* thread;
	BTPeerWireClientHandlerBase *handler;

	PeerEntryVector peerVector = peerState.getVector();

	//First short the peerVector in decreasing download rate order.
	sort(peerVector.rbegin(), peerVector.rend());

	int numDownloaders = 0;

	for (unsigned int i = 0; i < peerVector.size(); i++) {
		PeerEntry* peer = &peerVector[i];
		thread = (TCPServerThreadBase*) peer->getPeerThread();
		handler = (BTPeerWireClientHandlerBase*) thread;

		//Ensuring that the algorithm acts upon established and not pending connections
		//and that will not result in (un-)choking a seeder.
		//Also ensuring that the combination of (opt-un-)choke timers values does not result
		//in fibrilation.
		if ((handler->getState() < HANDSHAKE_COMPLETE) || (handler->seeder()
				|| (handler->isCacheThread())) || ((handler->lastChokeUnchoke()
				+ chockingInterval() > simTime())
				&& handler->lastChokeUnchoke() != 0)) {
			continue;
		}

		if (handler->amChoking()) {

			if (handler->peerInterested()) {

				if (numDownloaders < downloaders()) {

					if (handler->getDownloadRate()
							<= peerState.minDownloaderRate())
						peerState.setMinDownloaderRate(
								handler->getDownloadRate());

					thread->timerExpired(new cMessage(toString(UNCHOKE_TIMER),
							UNCHOKE_TIMER));
					numDownloaders++;
				} else {
					BEV<<"[Choking Algorithm]: reached maxNumDownloaders. Not adding "<<handler->getRemotePeerID()<<" to Downloaders. "<<endl;
				}
			}
			else
			{

				if (handler->getDownloadRate()> peerState.minDownloaderRate())
				{
					BEV<<"[Choking Algorithm]: not Interested in "<<handler->getRemotePeerID()<<", unchoking though due to rate."<<endl;
					thread->timerExpired(new cMessage(toString(UNCHOKE_TIMER),UNCHOKE_TIMER));
				}
			}
		}
		else
		{
			if ((numDownloaders==downloaders()) && (!handler->isOptimisticallyUnchoked()))
			{
				BEV<<"[Choking Algorithm]: "<<handler->getRemotePeerID()<<" not in the top "<<downloaders()<<" of data providers (download rate), Choking it ..."<<endl;
				thread->timerExpired(new cMessage(toString(CHOKE_TIMER),CHOKE_TIMER));
			}
			else
			{
				BEV<<"[Choking Algorithm]: "<<handler->getRemotePeerID()<<" already in the top "<<downloaders()<<" of data providers (download rate)."<<endl;
				numDownloaders++;
			}

		}

	}//for
}

/**
 * Optimistic Unchoking algorithm. The implementation deviates from the <a href=\"http://wiki.theory.org/BitTorrentSpecification\"> specification </a>  in the following aspect:
 * the peer that is selected to be optimistically unchoked, is interested and does not count for a downloader. The reasoning
 * behind this deviation is that if this peer is not interested it means that it already has some data. In effect, the
 * bootstrapping aspect of this algorithm is weakened i.e. optimistic unchoking is also used (apart from finding better
 * connections) to let newly connected peers download some data that can later "exchange".
 *
 * This method should be re-implemented in future subclasses in order to extend/add/change the behavior of the client.
 */
void BTPeerWireBase::OptimisticUnChokingAlgorithm() {

	//BEV<<"Optimistic Unchoking algorithm running now."<<endl;

	PeerEntry peer;
	TCPServerThreadBase* thread;
	BTPeerWireClientHandlerBase *handler;
	PeerEntryVector peerVector = peerState.getVector();
	vector<int> candidatesVector;
	set<int> optUnchoked;
	set<int>::iterator it;

	//PeerEntryVector antiSnubbingCandidatesVector;

	for (unsigned int i = 0; i < peerVector.size(); i++) {
		peer = peerVector[i];
		thread = (TCPServerThreadBase*) peer.getPeerThread();
		handler = (BTPeerWireClientHandlerBase*) thread;

		//Ensuring that the algorithm acts upon established connections
		//and that will not result in (un-)choking a seeder.
		//Also ensuring that the combination of (opt-un-)choke timers values does not result
		//in fibrilation.
		if ((handler->getState() < HANDSHAKE_COMPLETE) || (handler->seeder()
				|| (handler->isCacheThread())) || ((handler->lastChokeUnchoke()
				+ chockingInterval() > simTime())
				&& handler->lastChokeUnchoke() != 0))
			continue;

		if ((handler->amChoking())) {
			candidatesVector.push_back(i);

			//Marking as antisnubbed
			//if ((!handler->isOptimisticallyUnchoked())
			//antiSnubbingCandidatesVector.push_back(peerVector[i]);
		} else if (handler->isOptimisticallyUnchoked()) {
			optUnchoked.insert(i);
		}
	}

	//Now choose one of the candidates
	if (candidatesVector.size() > 0) {
		int numUnchoked = 0;

		while ((numUnchoked < optUnchockedPeers()) && (candidatesVector.size()
				> 0)) {
			int optUnchokePeerIndex = chooseOptUnchokePeer(
					candidatesVector.size());
			if (optUnchokePeerIndex > -1) {
				peer = peerVector[candidatesVector[optUnchokePeerIndex]];
				candidatesVector.erase(candidatesVector.begin()
						+ optUnchokePeerIndex);
			}

			thread = (TCPServerThreadBase*) peer.getPeerThread();
			handler = (BTPeerWireClientHandlerBase*) thread;

			BEV<<"optimistically unchoking peer: "<< handler->getRemotePeerID()<<"."<<endl;
			handler->setOptimisticallyUnchoked(true);

			thread->timerExpired(new cMessage(toString(UNCHOKE_TIMER),UNCHOKE_TIMER));
			numUnchoked++;
		}

		//If we have not reached the target number of optimistically unchoked peers
		//we will keep some of the previously optimistically unchoked.
		while (numUnchoked < optUnchockedPeers())
		{
			it = optUnchoked.begin();
			optUnchoked.erase(it);
			numUnchoked++;
		}

		//Choke previously optimistically unchoked peer
		//-----------------------------------------------
		for (it=optUnchoked.begin(); it!=optUnchoked.end(); it++)
		{
			peer= peerVector[*it];
			thread = (TCPServerThreadBase*)peer.getPeerThread();
			handler = (BTPeerWireClientHandlerBase*)thread;

			BEV<<"choking peer: "<<handler->getRemotePeerID()<<" ,that was previously optimistically unchoked."<<endl;
			handler->setOptimisticallyUnchoked(false);

			thread->timerExpired(new cMessage(toString(CHOKE_TIMER),CHOKE_TIMER));
		}
	}
}

void BTPeerWireBase::incrementNextPieceToPlay() {
	nextPieceToPlay_var++;
}
int BTPeerWireBase::getNextPieceToPlay() {
	return nextPieceToPlay_var;
}

void BTPeerWireBase::setNextPieceToPlay(int nextPieceToPlay) {
	nextPieceToPlay_var = nextPieceToPlay;
}
/**
 * Given the set of the candidate peers (for optimistic unchocking), it chooses one, giving priority to newly
 * connected peers. The followed <a href=\"http://wiki.theory.org/BitTorrentSpecification\"> specification </a>
 * states that "<i>Newly connected peers are three times as likely to start as the current optimistic unchoke as
 * anywhere else in the rotation</i>". This is interprented as follows:
 *
 * The candidate peers have been inserted in the candidates vector in decreasing connection time (the time elapsed
 * since the establishement of their connection with this client) i.e. the last peer in the vector is the most recently
 * connected. As defined in the specification, we select a newly connected peer with a probability three times greater
 * than the probability of selecting any other peer.
 *
 * This method should be re-implemented in future subclasses in order to extend/add/change the behavior of the client.
 */

int BTPeerWireBase::chooseOptUnchokePeer(int candidatesVectorSize) {
	int index = -1;

	if (dblrand() <= newlyConnectedOptUnchokeProb()) {
		index = (candidatesVectorSize - 1);
	} else {
		index = intrand(candidatesVectorSize);
	}

	return index;

}

/**
 * Called when a peer with an upload rate better than (at least) one of the current downloaders gets interested. In this case,
 * the downloader with the worst upload rate gets choked.
 *
 * This method should be re-implemented in future subclasses in order to extend/add/change the behavior of the client.
 */
void BTPeerWireBase::chokeWorstDownloader() {
	TCPServerThreadBase* thread;
	BTPeerWireClientHandlerBase *handler;

	PeerEntryVector peerVector = peerState.getVector();

	//First short the peerVector in decreasing download rate order.
	sort(peerVector.begin(), peerVector.end());

	int numDownloaders = 0;

	for (unsigned int i = 0; i < peerVector.size(); i++) {
		PeerEntry* peer = &peerVector[i];
		thread = (TCPServerThreadBase*) peer->getPeerThread();
		handler = (BTPeerWireClientHandlerBase*) thread;

		//Ensuring that the algorithm acts upon established and not pending connections
		if (handler->getState() < CONNECTED || (handler->isCacheThread())) {
			continue;
		}

		if (!handler->amChoking()) {
			numDownloaders++;

			if (numDownloaders == downloaders()) {
				thread->timerExpired(new cMessage(toString(CHOKE_TIMER),
						CHOKE_TIMER));
				return;
			}
		}
	}
}

/**
 * Schedules the establishment of connections with other peers. Note that this is orthogonal to the chocking algorithm.
 * The latter is rather enforced on the connections established by this method.
 *
 * This method should be re-implemented in future subclasses in order to extend/add/change the behavior of the client.
 */
void BTPeerWireBase::scheduleConnections(BTTrackerMsgResponse* msg) {
	checkConnections();
	int remainingConns = maxNumConnections() - currentNumConnections()
			- pendingNumConnections() - 1;

	if (remainingConns <= 0) {
		BEV<<"refraining from active connection establishment, reached limit of allowed connections."<<endl;
		return;
	}

	int index = -1;

	for (unsigned int i=0;i<msg->peersArraySize();i++)
	{
		PEER peer = msg->peers(i);
		opp_string id = peer.peerId;

		index = peerState.findPeer(peer.ipAddress);

		//Keeping one for passive ...
		if ( (index<0) && (remainingConns>1))
		{
			BEV<< "received peer "<< peer.peerId.c_str()<< " in tracker's response. Attempting connection ..."<<endl;
			BTInternalMsg* intMsg = new BTInternalMsg("INTERNAL_INIT_CONNECTION_MSG",INTERNAL_INIT_CONNECTION_MSG);
			intMsg->setPeer(peer);
			scheduleAt(simTime(),intMsg);
			remainingConns--;
		}
		else //TODO: Remove PART OF THIS, used only for testing!
		{
			if (index >= 0)
			{
				BEV<< "received peer "<< peer.peerId.c_str()<< " in tracker's response. Already connected to this peer ..."<<endl;

			}

			if (remainingConns<=1)
			{
				BEV<< "received "<< peer.peerId.c_str()<< " in tracker's response. Refraining from connecting, reached maximum of connections (maxNumConnections = "<< maxNumConnections()<<")."<<endl;
				checkConnections();
				return;
			}
		}
	}
}

/**
 * This method should re-implemented in future subclasses in order to extend/add/change the behavior of the client.
 */
bool BTPeerWireBase::connectionAlreadyEstablished(int connIndex) {
	PeerEntry pe = peerState.getPeerEntry(connIndex);
	BTPeerWireClientHandlerBase* handler =
			(BTPeerWireClientHandlerBase*) pe.getPeerThread();

	if (handler->getState() >= CONNECTED)
		return true;

	return false;
}

/**
 * Selects the piece that this client will request from the (remote) peer. It actually implements the Rarest First policy.
 * Note that when this client has not downloaded any piece, this method actually implements the Random First policy.
 * In case superSeedMode var is set true, it operates in reverse mode i.e. it will select a rare piece available in this
 * client and not available in the remote peer.
 *
 * This method should re-implemented in future subclasses in order to extend/add/change the behavior of the client.
 */

BlockItem* BTPeerWireBase::selectPiece(BitField* remoteBitfield,
		bool superSeedMode) {
	PieceFreqEntry pieceEntry;

	//First find the indexes and the frequencies of the pieces the peer can offer
	// and store them in a vector.
	PieceFreqEntryVector peerPieces;
	PieceFreqEntryVector::iterator it;
	int index, freq = -1;
	int size = 0;
	PieceFreqEntryVector pieceFrequencies = pieceFreqState.getVector();

	int qualityOffsetBegin = qualityOffset_var * currentQualityIndex();
	int qualityOffsetEnd = ((int) (file_size_var / piece_size_var))
			+ qualityOffsetBegin;

	if (LOGFILE) {
		std::stringstream log;
		log << "PARAM CUR_Q_INDEX: " << simTime().str().c_str() << " "
				<< currentQualityIndex() << " PIECE SELECTION FROM: "
				<< qualityOffsetBegin << " TO: " << qualityOffsetEnd;

		this->writeLog(log.str().c_str());
	}

	for (it = (pieceFrequencies.begin() + qualityOffsetBegin); it
			< pieceFrequencies.end()/*pieceFrequencies.begin() + qualityOffsetEnd*/; it++) {
		index = (*it).getIndex();
		freq = (*it).frequency();

		if (!superSeedMode) {

			if ((remoteBitfield->isPieceAvailable(index))
					&& (!localBitfield()->isPieceAvailable(index)) && (freq
					!= 0) && (!localBitfield()->isPieceRequested(index))) {
				peerPieces.push_back(*it);
				size++;
			}
		} else {
			if ((!remoteBitfield->isPieceAvailable(index))
					&& (localBitfield()->isPieceAvailable(index))) {
				peerPieces.push_back(*it);
				size++;
			}
		}
	}

	if (size > 0) {
		if (checkBufferSequence(getLastPlayedPieceIndex(),
				getLastPlayedPieceIndex() + getFifoPieceSelectionWindow())
				&& (getLastPlayedPieceIndex() > 0)) {
			//Sort this vector in rarest first order...

			//Commenting the following line will turn the Rarest into FIFO
			sort(peerPieces.begin(), peerPieces.end());

			//If the first condition is true we actually implement the Random First Policy
			/*if ((!localBitfield()->havePiece()) || (rarestListSize() >= size)) {
			 if (size > 1)
			 index = intrand(size);
			 else
			 index = 0;
			 } else {
			 index = intrand(rarestListSize());
			 }*/
			//In case of FIFO request the first remote available piece otherwise please comment the following and uncomment
			//the precedent instruction bloc
		} /*else*/

		index = 0;

		//Also return the offset within the piece.
		int pieceIndex = peerPieces[index].getIndex();

		//Requesting the next of the currently available block
		//So that we can resume previously aborted pieces
		//==//int blockIndex  = localBitfield()->currentBlock(pieceIndex)+1;
		int blockIndex = localBitfield()->nextBlock(pieceIndex);
		peerPieces.clear();

		if (LOGFILE) {
			std::stringstream log;
			log << "PARAM CUR_Q_INDEX: " << simTime().str().c_str() << " "
					<< currentQualityIndex() << " SELECTED PIECE: "
					<< pieceIndex << " SELECETD BLOCK: " << blockIndex;

			this->writeLog(log.str().c_str());
		}

		return new BlockItem(pieceIndex, blockIndex);
	} else {
		if (LOGFILE) {
			std::stringstream log;
			log << "PARAM CUR_Q_INDEX: " << simTime().str().c_str() << " "
					<< currentQualityIndex() << " NO PIECE SELECTED!";
			this->writeLog(log.str().c_str());
		}
		return new BlockItem(-1, -1);
	}
}

bool BTPeerWireBase::checkBufferSequence(int indexStartPiece, int indexEndPiece) {
	bool approved = true;
	int i = indexStartPiece;
	while (i <= indexEndPiece) {
		if (!localBitfield()->isPieceAvailable(i)) {
			approved = false;
			break;
		}
		i++;
	}
	return (approved);
}

/**
 * Updates the state about the requests placed by this client. A block is marked as requested when a thread
 * sends a request for it to a peer. The whole piece this block belongs to is also marked as requested so that
 * we avoid situation in which multiple threads request blocks of the same piece. This would induce unecessary
 * synchronization overhead. However, if a request is cancelled  (e.g. the peer has choked this client) the
 * blocks/pieces are set back to not requested so that no thread is blocked from requesting a block.
 *
 */
int BTPeerWireBase::updateBlockRequests(int pieceIndex, int blockIndex,
		bool value) {

	int result = -1;
	//Check whether this request triggers the endgame mode
	if ((getState() != ENDGAME)) {
		//We do not set the block as requested because if we are in such mode, this
		//has already been done.
		result = localBitfield()->setBlockRequested(pieceIndex, blockIndex,
				value);

		if ((enterEndGameMode()) && (value)) {
			BEV<<"entering End-Game Mode ..."<<endl;
			setState(ENDGAME);
			scheduleEndGameRequests();
		}
	}

	return result;

}

			/**
			 * Checks the local bitfield against a remote one and determines whether this client is interested
			 * in a piece available at the remote peer.
			 *
			 */
int BTPeerWireBase::amInterested(BTBitfieldMsg* msg) {
	int interestingPieces = 0;

	if (getState() < COMPLETED)
		for (unsigned int i = 0; i < msg->bitfieldArraySize(); i++) {
			if ((msg->bitfield(i)) && (!localBitfield()->isPieceAvailable(i)))
				interestingPieces++;
		}

	return interestingPieces;
}

/**
 * Checks the local bitfield against a remote one and determines whether this client is interested
 * in a piece available at the remote peer.
 */
int BTPeerWireBase::amInterested(BitField* bitField) {
	int interestingPieces = 0;

	for (int i = 0; i < bitField->numPieces(); i++) {
		if ((bitField->isPieceAvailable(i))
				&& (!localBitfield()->isPieceAvailable(i)))
			interestingPieces++;
	}

	return interestingPieces;
}

/**
 * Schedules a Have msg to inform connected peers about the reception of this piece.
 *
 */
void BTPeerWireBase::informPeers(int pieceIndex) {
	TCPServerThreadBase *thread;
	BTPeerWireClientHandlerBase* handler;

	PeerEntryVector peerVector = peerState.getVector();
	for (unsigned int i = 0; i < peerVector.size(); i++) {
		PeerEntry* entry = &peerVector[i];
		thread = (TCPServerThreadBase *) entry->getPeerThread();
		handler = (BTPeerWireClientHandlerBase*) thread;
		if (!thread)
			error(
					"%s:%d at %s() Inconsistent thread state, could not find peer thread. \n",
					__FILE__, __LINE__, __func__);

		if (handler->getState() >= HANDSHAKE_COMPLETE) {
			BTHaveMsg* have = new BTHaveMsg("HAVE_TIMER", HAVE_TIMER);
			have->setByteLength(HAVE_MSG_SIZE);
			have->setIndex(pieceIndex);
			have->setLength_prefix(HAVE_MSG_SIZE);
			have->setID(HAVE);

			thread->timerExpired(have);
		}
	}
}

/**
 * Determins whether this client should enter the end-game phase.
 * According to the <a href=\"http://wiki.theory.org/BitTorrentSpecification\"> specification </a>
 * "<i> There is no documented thresholds, recommended percentages, or block counts that could be used as a
 * guide or Recommended Best Practice here.</i>. In this implementation, we follow the approach described in:
 * B. Cohen, â€œIncentives build robustness in bittorrent,â€� in Proc. First Workshop on Economics of Peer-to-Peer Systems,
 * Berkeley, USA, June 2003 and also adopted in <a href=\"http://hal.inria.fr/inria-00000156/en\"> the technical report
 * suggested by the <a href=\"http://wiki.theory.org/BitTorrentSpecification\"> specification </a>. In this approach,
 * the end game mode "<i>... starts once a peer has requested all blocks, i.e., blocks are either requested or already
 * received.</i>" . At the same time, since the specification indicates that "<i> ... it's a good idea to keep the
 * number of the pending block low (1 or 2 blocks)..."</i>, we make a compromise and set this threashold to the maximum
 * size of the request queue.
 *
 * This method should re-implemented in future subclasses in order to extend/add/change the behavior of the client.
 */
bool BTPeerWireBase::enterEndGameMode() {
	if ((!enableEndGameMode()) || (getState() >= ENDGAME))
		return false;
	else
		return (localBitfield()->numNonRequestedNonAvailableBlocks() == 0);
}

/**
 * This method schedules the transmission of the requests in the end-game phase i.e. the phase
 * in which all remaining blocks are requested by all non-choking peers in the peer set.
 *
 * This is impplemented with a double pass over the peer set. In the first pass all pending requests
 * are gathered and in the second pass each request is send to all peers (except the one it has already been sent to).
 * This may seem inefficient but it is only executed at the end game mode. Otherwise,
 * we would have to maintain all requests in this module rather than in each thread. This would reduce
 * the simplicity and flexibility, the threads offer us and would result in a high base-thread communication overhead
 * during the normal mode of the game, which is the major part of it.
 *
 * This method should re-implemented in future subclasses in order to extend/add/change the behavior of the client.
 */
void BTPeerWireBase::scheduleEndGameRequests() {

	PeerEntryVector peerVector = peerState.getVector();
	TCPServerThreadBase* thread;
	BTPeerWireClientHandlerBase* handler;
	PeerEntry* peer;

	for (unsigned int i = 0; i < peerVector.size(); i++) {
		peer = &peerVector[i];
		thread = (TCPServerThreadBase*) peer->getPeerThread();
		handler = (BTPeerWireClientHandlerBase*) thread;
		if (handler->isCacheThread())
			continue;
		for (int j = 0; j < handler->getRequests().size(); j++) {
			RequestEntry re = handler->getRequests().getRequestEntry(j).dup();

			if (!localBitfield()->isBlockAvailable(re.getIndex(), re.begin()))
				endGameRequests.push_back(re);
		}
	}

	for (unsigned int j = 0; j < endGameRequests.size(); j++) {
		for (unsigned int i = 0; i < peerVector.size(); i++) {
			peer = &peerVector[i];
			thread = (TCPServerThreadBase*) peer->getPeerThread();
			handler = (BTPeerWireClientHandlerBase*) thread;
			if (handler->isCacheThread())
				continue;
			//The pending blocks (plus the ones carently  in the queues) may be more
			//than the queueing policy allows!
			//handler->getRequests().setMaxSize(numBlocks()*numPieces());
			handler->increaseRequestQueueSize(numBlocks() * numPieces());

			if ((strcmp(handler->getRemotePeerID().c_str(),
					endGameRequests[j].peerID()) != 0) && (handler->getState()
					>= HANDSHAKE_COMPLETE) && (!handler->peerChoking())) {
				handler->setInEndGame(true);
				handler->sendEndGameBlockRequests(
						endGameRequests[j].getIndex(),
						endGameRequests[j].begin());
			}
		}
	}
}

/**
 * Called when the client is in end-game mode and a block has arrived. It schedules a Cancel message for each
 * peer to which a request was previously sent for this block.
 *
 * This method should re-implemented in future subclasses in order to extend/add/change the behavior of the client.
 */
void BTPeerWireBase::scheduleEndGameCancel(int pieceIndex, int blockIndex,
		const char* blockProvider) {
	PeerEntryVector peerVector = peerState.getVector();
	TCPServerThreadBase* thread;
	BTPeerWireClientHandlerBase* handler;
	PeerEntry* peer;
	RequestEntryVector someRequests;
	int pos = -1;

	for (unsigned int j = 0; j < endGameRequests.size(); j++) {
		if ((endGameRequests[j].getIndex() == pieceIndex)
				&& (endGameRequests[j].begin() == blockIndex)) {
			pos = j;
			break;
		}
	}

	if (pos >= 0) {
		for (unsigned int i = 0; i < peerVector.size(); i++) {
			peer = &peerVector[i];
			thread = (TCPServerThreadBase*) peer->getPeerThread();
			handler = (BTPeerWireClientHandlerBase*) thread;

			if ((handler->inEndGame()) && (strcmp(
					handler->getRemotePeerID().c_str(), blockProvider) != 0))
			//&& (strcmp(handler->getRemotePeerID().c_str(),endGameRequests[pos].peerID())!=0))
			{
				//TODO: Check whether we need a createMsg method in this module
				BTRequestCancelMsg* cancelMsg = new BTRequestCancelMsg(
						toString(CANCEL_TIMER), CANCEL_TIMER);
				cancelMsg->setIndex(endGameRequests[pos].getIndex());
				cancelMsg->setBegin(endGameRequests[pos].begin()/** 1024*blockSize()*/);
				cancelMsg->setBitLength(blockSize());
				thread->timerExpired(cancelMsg);
			}
		}
		endGameRequests.erase(endGameRequests.begin() + pos);
	}
	//else
	//error("%s:%d at %s() Inconsistent end-game state. Cannot find request for received block (Piece #%d, Block #%d. )\n", __FILE__, __LINE__, __func__, pieceIndex, (blockIndex+1));

}

/**
 * In super-seeding mode, it schedules a Have msg to a peer that previously downloaded a piece, only
 * if this piece has been seen in an other peer's bitfield.
 *
 * This method should re-implemented in future subclasses in order to extend/add/change the behavior of the client.
 */
void BTPeerWireBase::checkandScheduleHaveMsgs(BTBitfieldMsg* msg,
		const char* peerID) {
	for (unsigned int i = 0; i < superSeedPending.size(); i++) {
		BlockItem* bi = superSeedPending[i];

		if ((strcmp(peerID, bi->peerID()) != 0) && (msg->bitfield(
				bi->pieceIndex()))) {
			PeerEntry peer = peerState.getPeerEntry(bi->peerID());
			if (!peer.isValid()) {
				BEV<<"super-seed mode: peer "<<bi->peerID()<<" waiting for another Have msg, is not connected any more."<<endl;
				return;
			}
			else
			{
				TCPServerThreadBase* thread = peer.getPeerThread();
				scheduleSuperSeedHaveMsg(thread);
				continue;
			}
		}
	}
}

// GET/SET Functions
//----------------------------------------------------
double BTPeerWireBase::fileSize() {
	return file_size_var;
}

void BTPeerWireBase::setFileSize(double file_size) {
	file_size_var = file_size;
}

double BTPeerWireBase::pieceSize() {
	return piece_size_var;
}

void BTPeerWireBase::setPieceSize(double piece_size) {
	piece_size_var = piece_size;
}

double BTPeerWireBase::blockSize() {
	return block_size_var;
}

void BTPeerWireBase::setBlockSize(double block_size) {
	block_size_var = block_size;
}

bool BTPeerWireBase::getIsStatsWritten() const {
	return isStatsWritten;
}

void BTPeerWireBase::setIsStatsWritten(bool isStatsWritten) {
	this->isStatsWritten = isStatsWritten;
}

int BTPeerWireBase::DHTPort() {
	return DHT_port_var;
}

void BTPeerWireBase::setDHTPort(int DHT_port) {
	DHT_port_var = DHT_port;
}

const char* BTPeerWireBase::pstr() {
	return pstr_var;
}
/*
 * This should probably be static and defined at startup (ini file)
 void BTPeerWireBase::setPstr(const char* pstr)
 {
 pstr_var = pstr;
 }
 */

int BTPeerWireBase::pstrlen() {
	return pstrlen_var;
}

/*
 * This should probably be static and defined at startup (ini file)
 void BTPeerWireBase::setPstrlen(int pstrlen)
 {
 pstrlen_var = pstrlen;
 }
 */

int BTPeerWireBase::keepAlive() {
	return keep_alive_var;
}

void BTPeerWireBase::setKeepAlive(int keep_alive) {
	keep_alive_var = keep_alive;
}

bool BTPeerWireBase::haveSupression() {
	return have_supression_var;
}

void BTPeerWireBase::setHaveSupression(bool have_supression) {
	have_supression_var = have_supression;
}

int BTPeerWireBase::chockingInterval() {
	return chocking_interval_var;
}

void BTPeerWireBase::setChockingInterval(int chocking_interval) {
	chocking_interval_var = chocking_interval;
}

int BTPeerWireBase::downloaders() {
	return downloaders_var;
}

void BTPeerWireBase::setDownloaders(int downloaders) {
	downloaders_var = downloaders;
}

int BTPeerWireBase::optUnchockedPeers() {
	return optUnchockedPeers_var;
}

void BTPeerWireBase::setOptUnchockedPeers(int optUnchockedPeers) {
	optUnchockedPeers_var = optUnchockedPeers;
}

int BTPeerWireBase::optUnchockingInterval() {
	return optUnchocking_interval_var;
}

void BTPeerWireBase::setOptUnchockingInterval(int optUnchocking_interval) {
	optUnchocking_interval_var = optUnchocking_interval;
}

int BTPeerWireBase::snubbingInterval() {
	return snubbing_interval_var;
}

void BTPeerWireBase::setSnubbingInterval(int snubbing_interval) {
	snubbing_interval_var = snubbing_interval;
}

void BTPeerWireBase::setPiecePlaybackDuration(double duration) {
	piecePlaybackDuration = duration;
}

int BTPeerWireBase::getLastPlayedPieceIndex() const {
	return lastPlayedPieceIndex;
}

void BTPeerWireBase::setLastPlayedPieceIndex(int lastPlayedPieceIndex) {
	this->lastPlayedPieceIndex = lastPlayedPieceIndex;
}

double BTPeerWireBase::getPiecePlaybackDuration() {
	return piecePlaybackDuration;
}

int BTPeerWireBase::rarestListSize() {
	return rarest_list_size_var;
}

void BTPeerWireBase::setRarestListSize(int size) {
	rarest_list_size_var = size;
}

int BTPeerWireBase::requestQueueDepth() {
	return request_queue_depth_var;
}

void BTPeerWireBase::setRequestQueueDepth(int depth) {
	request_queue_depth_var = depth;

}

int BTPeerWireBase::minNumConnections() {
	return minNumConnections_var;
}

void BTPeerWireBase::setMinNumConnections(int minNumConns) {
	minNumConnections_var = minNumConns;
}

int BTPeerWireBase::maxNumConnections() {
	return maxNumConnections_var;
}

void BTPeerWireBase::setMaxNumConnections(int maxNumConns) {
	maxNumConnections_var = maxNumConns;
}

bool BTPeerWireBase::superSeedMode() {
	return super_seed_mode_var;
}

void BTPeerWireBase::setSuperSeedMode(bool value) {
	super_seed_mode_var = value;
}

int BTPeerWireBase::maxNumEmptyTrackerResponses() {
	return maxNumEmptyTrackerResponses_var;
}

void BTPeerWireBase::setMaxNumEmptyTrackerResponses(int num) {
	maxNumEmptyTrackerResponses_var = num;
}

int BTPeerWireBase::currentNumEmptyTrackerResponses() {
	return currentNumEmptyTrackerResponses_var;
}

void BTPeerWireBase::setCurrentNumEmptyTrackerResponses(
		int currentNumEmptyTrackerResponses) {
	currentNumEmptyTrackerResponses_var = currentNumEmptyTrackerResponses;
}

int BTPeerWireBase::currentNumConnections() {
	return currentNumConnections_var;
}

void BTPeerWireBase::setCurrentNumConnections(int currNumConns) {
	currentNumConnections_var = currNumConns;

}

void BTPeerWireBase::increaseCurrentNumConnections() {
	//printf("%s In increaseCurrentNumConnections... \n",this->getParentModule()->getFullName());
	currentNumConnections_var++;
	decreasePendingNumConnections();
	checkConnections();
	//printf("...%s In increaseCurrentNumConnections \n",this->getParentModule()->getFullName());
}

void BTPeerWireBase::decreaseCurrentNumConnections() {
	//printf("%s In decreaseCurrentNumConnections... \n",this->getParentModule()->getFullName());
	currentNumConnections_var--;
	checkConnections();
	//printf("...%s In decreaseCurrentNumConnections \n",this->getParentModule()->getFullName());
}

int BTPeerWireBase::pendingNumConnections() {
	return pendingNumConnections_var;
}

void BTPeerWireBase::checkConnections() {
	//printf("%s In checkConnections... \n",this->getParentModule()->getFullName());
	if ((maxNumConnections() - currentNumConnections_var
			- pendingNumConnections() - 1) <= 0) {
		stopListening();
	}

	if ((currentNumConnections_var + pendingNumConnections())
			<= minNumConnections()) {
		startListening();
	}
	//printf("...%s In checkConnections \n",this->getParentModule()->getFullName());

}
void BTPeerWireBase::setPendingNumConnections(int pendingNumConns) {
	pendingNumConnections_var = pendingNumConns;
	checkConnections();
}

void BTPeerWireBase::decreasePendingNumConnections() {
	pendingNumConnections_var--;
	checkConnections();
}

void BTPeerWireBase::increasePendingNumConnections() {
	pendingNumConnections_var++;
	checkConnections();
}

BTTrackerMsgResponse* BTPeerWireBase::trackerResponse() {
	return trackerResponse_var;
}

void BTPeerWireBase::setTrackerResponse(BTTrackerMsgResponse* msg) {
	if (trackerResponse_var) {
		delete trackerResponse_var;
		trackerResponse_var = NULL;
	}

	trackerResponse_var = (BTTrackerMsgResponse*) msg->dup();
}

bool BTPeerWireBase::haveTrackerResponse() {
	if (trackerResponse_var)
		return true;
	else
		return false;

}

void BTPeerWireBase::deleteTrackerResponse() {
	cancelAndDelete(trackerResponse_var);
}

simtime_t BTPeerWireBase::downloadDuration() {
	return downloadDuration_var;
}
void BTPeerWireBase::setDownloadDuration(simtime_t time) {
	downloadDuration_var = time;
}

int BTPeerWireBase::getDownloadRateSamplingDuration() {
	return downloadRateSamplingDuration_var;
}

void BTPeerWireBase::setDownloadRateSamplingDuration(
		int downloadRateSamplingDuration) {
	downloadRateSamplingDuration_var = downloadRateSamplingDuration;
}

double BTPeerWireBase::blocksFromSeeder() {
	return blocksFromSeeder_var;
}

void BTPeerWireBase::setBlocksFromSeeder(double blocksFromSeeder) {
	blocksFromSeeder_var = blocksFromSeeder;
}

void BTPeerWireBase::increamentBlocksFromSeeder() {
	blocksFromSeeder_var++;
}

int BTPeerWireBase::numPieces() {
	return numPieces_var;
}

void BTPeerWireBase::setNumPieces(int numPieces) {
	numPieces_var = numPieces;
}

int BTPeerWireBase::numBlocks() {
	return numBlocks_var;
}

void BTPeerWireBase::setNumBlocks(int numBlocks) {
	numBlocks_var = numBlocks;
}

BitField* BTPeerWireBase::localBitfield() {
	return localBitfield_var;
}

void BTPeerWireBase::initializeLocalBitfield(bool seeder) {
	localBitfield_var = new BitField(numPieces(), numBlocks(), seeder);
}

int BTPeerWireBase::timeToSeed() {
	return timeToSeed_var;
}

void BTPeerWireBase::setTimeToSeed(int timeToSeed) {
	timeToSeed_var = timeToSeed;
}

double BTPeerWireBase::newlyConnectedOptUnchokeProb() {
	return newlyConnectedOptUnchokeProb_var;
}

void BTPeerWireBase::setNewlyConnectedOptUnchokeProb(
		double newlyConnectedOptUnchokeProb) {
	newlyConnectedOptUnchokeProb_var = newlyConnectedOptUnchokeProb;
}

int BTPeerWireBase::announceInterval() {
	return announceInterval_var;
}

void BTPeerWireBase::setAnnounceInterval(int announceInterval) {
	announceInterval_var = announceInterval;
}

void BTPeerWireBase::setProcDelay(float delay) {
	procDelay_var = delay;
}

float BTPeerWireBase::procDelay() {
	return procDelay_var;
}

int BTPeerWireBase::getState() {
	return state_var;
}

void BTPeerWireBase::setState(int state) {
	state_var = state;
}

PeerState BTPeerWireBase::getPeerState() {
	return peerState;
}

bool BTPeerWireBase::httpUse() {
	return use_http_var;
}
void BTPeerWireBase::setHttpUse(bool useHttp) {
	use_http_var = useHttp;
}

bool BTPeerWireBase::httpCacheUse() {
	return use_chache_server_var;
}

void BTPeerWireBase::setHttpCacheUse(bool cacheUse) {
	use_chache_server_var = cacheUse;
}

void BTPeerWireBase::setCurrentQualityIndex(int currQualityIndex) {
	currentQualityIndex_var = currQualityIndex;
}
int BTPeerWireBase::currentQualityIndex() {
	return currentQualityIndex_var;
}

int BTPeerWireBase::currentQualityBitrate() {
	return qualitiesBitRates_var[currentQualityIndex()];
}

int BTPeerWireBase::maxSupportedQualityBitrate() {
	return qualitiesBitRates_var[maxSupportedQualityIndex_var];
}

int BTPeerWireBase::getQualityBitRate(int qualityIndex) {
	return qualitiesBitRates_var[qualityIndex];
}

TCPServerThreadBase * BTPeerWireBase::getCacheThread() {
	return cacheThread;
}

bool BTPeerWireBase::enableEndGameMode() {
	return enableEndGameMode_var;
}

void BTPeerWireBase::setEnableEndGameMode(bool enableEndGameMode) {
	enableEndGameMode_var = enableEndGameMode;
}

void BTPeerWireBase::removeThread(TCPServerThreadBase *thread) {
	//socketMap.removeSocket(thread->getSocket());
	updateDisplay();
}

void BTPeerWireBase::writeStats() {
	if (!getIsStatsWritten()) {
		this->setIsStatsWritten(true);
		BTStatisticsDWLMsg* msgDWL = new BTStatisticsDWLMsg("BT_STATS_DWL",
				BT_STATS_DWL);
		msgDWL->setDownloadTime(SIMTIME_DBL(downloadDuration()));
		msgDWL->setRemainingBlocks(localBitfield()->numRemainingBlocks());
		sendDirect(msgDWL, btStatistics, btStatistics->findGate("direct_in"));

		BTStatisticsNumProvidersMsg* msgPP = new BTStatisticsNumProvidersMsg(
				"BT_STATS_PP", BT_STATS_PP);
		msgPP->setNumPeers(dataProviderPeerIDs.size());
		sendDirect(msgPP, btStatistics, btStatistics->findGate("direct_in"));

		BTStatisticsNumSeederBlocksMsg
				* msgNSB = new BTStatisticsNumSeederBlocksMsg("BT_STATS_NSB",
						BT_STATS_NSB);
		msgNSB->setNumSeederBlocks(blocksFromSeeder());
		sendDirect(msgNSB, btStatistics, btStatistics->findGate("direct_in"));
	}
}

void BTPeerWireBase::setAdaptive(bool isadaptive) {
	adaptiveQuality_var = isadaptive;
}
bool BTPeerWireBase::isAdaptive() {
	return adaptiveQuality_var;
}

void BTPeerWireBase::setQualitiesNumber(int nbrQualities) {
	qualitiesNumber_var = nbrQualities;
}
int BTPeerWireBase::getQualities() {
	return qualitiesNumber_var;
}

int BTPeerWireBase::getLastPieceIndex() const {
	return lastPieceIndex;
}

void BTPeerWireBase::setLastPieceIndex(int lastPiece) {
	lastPieceIndex = lastPiece;
}

int BTPeerWireBase::getFifoPieceSelectionWindow() const {
	return fifoPieceSelectionWindow_var;
}

void BTPeerWireBase::setFifoPieceSelectionWindow(
		int fifoPieceSelectionWindow_var) {
	this->fifoPieceSelectionWindow_var = fifoPieceSelectionWindow_var;
}

int BTPeerWireBase::getWaitingDurationWhenPieceNotFound() const {
	return waitingDurationWhenPieceNotFound_var;
}

void BTPeerWireBase::setWaitingDurationWhenPieceNotFound(
		int waitingDurationWhenPieceNotFound_var) {
	this->waitingDurationWhenPieceNotFound_var
			= waitingDurationWhenPieceNotFound_var;
}

//----- Used for testing -----------------------------------------
const char* BTPeerWireBase::toString(int type) {

	switch (type) {
	case INTERNAL_REFUSE_CONNECTION_TIMER:
		return "INTERNAL_REFUSE_CONNECTION_TIMER";
		break;
	case INTERNAL_INIT_CONNECTION_MSG:
		return "INTERNAL_INIT_CONNECTION_MSG";
		break;
	case INTERNAL_REMOVE_THREAD_MSG:
		return "INTERNAL_REMOVE_THREAD_MSG";
		break;
	case INTERNAL_CHOKE_TIMER:
		return "INTERNAL_CHOKE_TIMER";
		break;
	case INTERNAL_OPT_UNCHOKE_TIMER:
		return "INTERNAL_OPT_UNCHOKE_TIMER";
		break;
	case INTERNAL_MEASURE_DOWNLOAD_RATE_TIMER:
		return "INTERNAL_MEASURE_DOWNLOAD_RATE_TIMER";
		break;
	case INTERNAL_MEASURE_UPLOAD_RATE_TIMER:
		return "INTERNAL_MEASURE_UPLOAD_RATE_TIMER";
		break;
	case INTERNAL_TRACKER_COM_MSG:
		return "INTERNAL_TRACKER_COM_MSG";
		break;
	case INTERNAL_UPDATE_THREAD_MSG:
		return "INTERNAL_UPDATE_THREAD_MSG";
		break;
	case INTERNAL_EXIT_MSG:
		return "INTERNAL_EXIT_MSG";
		break;
	case INTERNAL_SUPER_SEED_HAVE_MSG:
		return "INTERNAL_SUPER_SEED_HAVE_MSG";
		break;
	case INTERNAL_SUPER_SEED_COMPLETE_MSG:
		return "INTERNAL_SUPER_SEED_COMPLETE_MSG";
		break;
	case INTERNAL_NEXT_REQUEST_MSG:
		return "INTERNAL_NEXT_REQUEST_MSG";
		break;
	case INTERNAL_UPDATE_INTERESTS_MSG:
		return "INTERNAL_UPDATE_INTERESTS_MSG";
		break;
	case HANDSHAKE_MSG:
		return "HANDSHAKE_MSG";
		break;
	case KEEP_ALIVE_MSG:
		return "KEEP_ALIVE_MSG";
		break;
	case CHOKE_MSG:
		return "CHOKE_MSG";
		break;
	case UNCHOKE_MSG:
		return "UNCHOKE_MSG";
		break;
	case INTERESTED_MSG:
		return "INTERESTED_MSG";
		break;
	case NOT_INTERESTED_MSG:
		return "NOT_INTERESTED_MSG";
		break;
	case HAVE_MSG:
		return "HAVE_MSG";
		break;
	case BITFIELD_MSG:
		return "BITFIELD_MSG";
		break;
	case REQUEST_MSG:
		return "REQUEST_MSG";
		break;
	case PIECE_MSG:
		return "PIECE_MSG";
		break;
	case CANCEL_MSG:
		return "CANCEL_MSG";
		break;
	case PORT_MSG:
		return "PORT_MSG";
		break;
	case IS_ALIVE_TIMER:
		return "IS_ALIVE_TIMER";
		break;
	case KEEP_ALIVE_TIMER:
		return "KEEP_ALIVE_TIMER";
		break;
	case DEL_THREAD_TIMER:
		return "DEL_THREAD_TIMER";
		break;
	case DEL_THREAD_TIMER_FROM_HOST:
		return "DEL_THREAD_TIMER_FROM_HOST";
		break;
	case BITFIELD_TIMER:
		return "BITFIELD_TIMER";
		break;
	case REQUEST_TIMER:
		return "REQUEST_TIMER";
		break;
	case PIECE_TIMER:
		return "PIECE_TIMER";
		break;
	case UNCHOKE_TIMER:
		return "UNCHOKE_TIMER";
		break;
	case INTERESTED_TIMER:
		return "INTERESTED_TIMER";
		break;
	case ANTI_SNUB_TIMER:
		return "ANTI_SNUB_TIMER";
		break;
	case INTERNAL_CACHE_THREAD_CREATION:
		return "INTERNAL_CACHE_THREAD_CREATION";
		break;
	case INTERNAL_PLAYER_MSG:
		return "INTERNAL_PLAYER_MSG";
		break;
	case BT_CONFIRM_FINISH:
		return "BT_CONFIRM_FINISH";
		break;
	default:
		return NULL;
		break;

	}
}

