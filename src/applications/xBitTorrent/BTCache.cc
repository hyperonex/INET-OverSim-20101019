// Copyright 2015 Achraf Gazdar
//                              agazdar@ksu.edu.sa
//								achraf.gazdar@gmail.com
//
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

#include "BTCache.h"
Define_Module( BTCache);

BTCache::BTCache() {
	// TODO Auto-generated constructor stub
	requestsReceived = 0;
	pendingServerRequests = 0;
}

BTCache::~BTCache() {

	delete resourceCache;
	delete tcp;
	ClientMap::iterator it;
	//cerr << getParentModule()->getFullName() << ": Going to delete the client requests 1..." <<endl;
	for (it = pendingRequests.begin(); it != pendingRequests.end(); it++) {
		cMessage *msg = (*it).second;
		cMessage *pkt = (check_and_cast<cPacket *> (msg))->decapsulate();
		//cerr << getParentModule()->getFullName() << ": Going to delete the client request: " << ((httptRequestMessage*)pkt)->heading() <<endl;
		delete msg;
		delete pkt;
	}

	pendingServerRequestsVector::iterator it1;
	//cerr << getParentModule()->getFullName() << ": Going to delete the client requests 2..." <<endl;
	for (it1 = serverRequestsNotYetSent.begin(); it1
			!= serverRequestsNotYetSent.end(); it1++) {
		cMessage* msg = (*it1)->decapsulate();
		delete (*it1);
		//cerr << getParentModule()->getFullName() << ": Going to delete the server request: " << ((httptRequestMessage*)(check_and_cast<cPacket *>(msg)))->heading()<< endl;
		delete (msg);
	}

	serverRequestsNotYetSent.clear();

	//cerr << getParentModule()->getFullName() << ": ...done cleaning." <<endl;


}

void BTCache::socketEstablished(int connId, void *yourPtr) {
	EV_DEBUG<< "BTCache: socketEstablished begin"<< endl;
	EV_INFO << "connected socket with id=" << connId << endl;
	if ( yourPtr==NULL )
	{
		EV_ERROR << "SocketEstablished failure. Null pointer" << endl;
		//cerr << getParentModule()->getFullName() <<": SocketEstablished failure. Null pointer" << endl;
		return;
	}
	CACHE_SOCK_DS * csd = (CACHE_SOCK_DS *)yourPtr;
	if (csd->sockType == SERVER) {
		serverSocketsOpened++;
	} else if (csd->sockType == CLIENT) {
		clientSocketsOpened++;
		TCPSocket * socket = csd->socket;
		if ( csd->messageQueue.size()==0 )
		{
			EV_INFO << "No data to send on client socket with connection id " <<connId << ". Closing" << endl;
			socket->close();
			return;
		}
		// Send pending messages on the established socket.
		cMessage *msg;
		EV_DEBUG << "Proceeding to send messages on socket " << connId << endl;
		while( csd->messageQueue.size()!=0 )
		{
			msg = csd->messageQueue.back();
			cPacket *pckt = check_and_cast<cPacket *>(msg);
			csd->messageQueue.pop_back();
			EV_DEBUG << "Submitting request " << msg->getName() << " to socket " << connId << ". size is " << pckt->getByteLength() << " bytes" << endl;
			//cerr << getParentModule()->getFullName() << ": Sending request message: " << ((httptRequestMessage*)pckt->getEncapsulatedPacket())->heading() << endl;
			socket->send(msg);
			csd->pendingReplies++;
			pendingServerRequests --;
		}
	}
}

void BTCache::updateDisplay() {
	if (ev.isGUI() && resourceCache) {
		char buf[1024];
		float h = 0;
		if (requestsReceived > 0)
			h = 100.0 * hits / requestsReceived;
		int cacheSize = (int) par("cacheSize");
		int remaining = ((LRUCache *) resourceCache)->getRemainingCapacity();
		float full = 0;
		if (cacheSize > 0)
			full = 100.0 * (cacheSize - remaining) / cacheSize;
		sprintf(buf, "Req: %ld\nHit: %.1f\%\nCap: %.1fKB\nFull: %.1f\%",
				requestsReceived, h, cacheSize / 1000.0, full);
		this->getParentModule()->getDisplayString().setTagArg("t", 0, buf);
	}
}

bool BTCache::serverHasResource(cPacket* msg) {
	EV_DEBUG<< "BTCache: serverHasResource begin"<< endl;
	// check if file is in cache.
	httptRequestMessage *request = check_and_cast<httptRequestMessage *>(msg);
	if (request==NULL) this->error("Message (%s)%s is not a valid request", msg->getClassName(), msg->getName());
	string url = request->uri()/*extractURLFromRequest(request)*/;
	Resource * wr = new WebResource(url, 0);
	Resource * existing = NULL;
	//cerr << getParentModule()->getFullName() << ": Going to delete resources wr because it exists..." <<endl;
	if ((existing = resourceCache->has(wr) )!= NULL) {
		EV_INFO <<"CACHE HIT FOR RESOURCE: "<<wr->getID()<<endl;
		//cout <<"CACHE HIT FOR RESOURCE: "<<wr->getID()<<endl;
		resourceCache->add(existing); // changes timestamp on it.
		hits++;

		delete wr;
		//cerr << getParentModule()->getFullName() << ": ...done deleting resources wr in if" <<endl;
		return true;
	}
	else {
		EV_INFO <<"CACHE MISS FOR RESOURCE: "<<wr->getID()<<endl;
		//cout <<"CACHE MISS FOR RESOURCE: "<<wr->getID()<<endl;
		misses++;
		delete wr;
		//cerr << getParentModule()->getFullName() << ": ...done deleting resources wr in else" <<endl;
		return false;
	}
}

void BTCache::socketStatusArrived(int connId, void *yourPtr,
		TCPStatusInfo *status) {
	EV_INFO<< "SOCKET STATUS ARRIVED. Socket: " << connId << endl;
}

TCPSocket *BTCache::sendRequest(httptRequestMessage *request) {
	EV_DEBUG<< "BTCache: sendRequest begin"<< endl;
	int connectPort;
	char szModuleName[127];

	if ( controller->getServerInfo(request->targetUrl(),szModuleName,connectPort) != 0 )
	  {
	    EV_ERROR << "Unable to get server info for URL " << request->targetUrl() << endl;
	    //cerr << this->getParentModule()->getFullName() << ": Unable to get server info for URL" << endl;
	    return NULL;
	  }
	EV_DEBUG << "Sending request to server " << request->targetUrl() << " (" << szModuleName << ") on port " << connectPort << endl;
	return submitToSocket(szModuleName,connectPort,request);
}

void BTCache::finish() {
	EV_DEBUG<< "BTCache: finish begin"<< endl;
	// Call the parent class finish. Takes care of most of the reporting.
	//httptServerBase::finish();

	// Report sockets related statistics.
	EV_SUMMARY << "Server Sockets opened: " << serverSocketsOpened << endl;
	EV_SUMMARY << "Server Broken connections: " << serverSocketsBroken << endl;
	// Record the sockets related statistics
	recordScalar("server.sock.opened", serverSocketsOpened);
	recordScalar("server.sock.broken", serverSocketsBroken);

	// Report sockets related statistics.
	EV_SUMMARY << "Client Sockets opened: " << clientSocketsOpened << endl;
	EV_SUMMARY << "Client Broken connections: " << clientSocketsBroken << endl;
	// Record the sockets related statistics
	recordScalar("client.sock.opened", clientSocketsOpened);
	recordScalar("client.sock.broken", clientSocketsBroken);

	// record cache-related statistics
	EV_SUMMARY<<"Cache Hits: "<< hits<<endl;
	EV_SUMMARY<<"Cache Misses: "<< misses<<endl;
	EV_SUMMARY<<"Current Used Cache Space (Bytes): "<<(((int)par("cacheSize")) - (((LRUCache *)resourceCache)->getRemainingCapacity()))<<endl;
	EV_SUMMARY<<"Current Unused Cache Space (Bytes): "<<((LRUCache *)resourceCache)->getRemainingCapacity()<<endl;
    // Write stats to logfile
	if(LOGFILE){
		std::stringstream log;
		log << "PARAM HITS: "<<hits<<"\n"<<"PARAM MISSES: "<<misses<<endl;
		logFile << log.str().c_str();
		logFile.close();
	}
	// @todo Delete socket data structures........
	sockCollection.deleteSockets();

}

void BTCache::socketDataArrived(int connId, void *yourPtr, cPacket *mmsg,
		bool urgent) {
	EV_DEBUG<< "BTCache: socketDataArrived begin"<< endl;
	if ( yourPtr==NULL )
	{
		EV_ERROR << "Socket establish failure. Null pointer" << endl;
		cPacket* msg = mmsg->decapsulate();
		//cerr << getParentModule()->getFullName() << ": Deleting mmsg and msg in youPtr==NULL in socketDataArrived..." <<endl;
		delete mmsg;
		delete msg;
		//cerr << getParentModule()->getFullName() << ": ...done deleting mmsg and msg in youPtr==NULL in socketDataArrived" <<endl;
		return;
	}
	cPacket* msg = mmsg->getEncapsulatedPacket();
	CACHE_SOCK_DS * sockdata = (CACHE_SOCK_DS *)yourPtr;
	TCPSocket *socket = sockdata->socket;
	if (sockdata->sockType == SERVER) {
		// Should be a httptReplyMessage
		EV_DEBUG << "Socket data arrived on connection " << connId << ". Message=" << msg->getName() << ", kind=" << msg->getKind() << endl;
		//cerr << getParentModule()->getFullName() << ": Receiving client request: " << ((httptRequestMessage*)msg)->heading()<< endl;
		requestsReceived++;
		updateDisplay();
		if (serverHasResource(msg) == true) {
			// call the message handler to process the message.
			((httptRequestMessage*)msg)->setTargetUrl(wwwName.c_str());
			cStringTokenizer headingTokenizer = cStringTokenizer(((httptRequestMessage*)msg)->heading()," ");
			std::vector<string> res = headingTokenizer.asVector();
			if ( res.size() == 1 ) {
				std::stringstream header;
				header << "GET "<<((httptRequestMessage*)msg)->heading()<<" HTTP/1.1";
				const char * hdr = (header.str()).c_str();
				((httptRequestMessage*)msg)->setHeading(hdr);
			}
			httptReplyMessage* reply = (httptReplyMessage*) handleRequestMessage(msg);

			if ( reply!=NULL )
			{
				reply->setTimestamp();
				cPacket* wrapper = new cPacket(reply->getName(), TCP_I_DATA);
				wrapper->encapsulate(dynamic_cast<cPacket*> (reply));
				socket->send(wrapper); // Send to socket if the reply is non-zero.
			}
			//delete msg; // Delete the received message here. Must not be deleted in the handler!
			msg = mmsg->decapsulate();
			//cerr << getParentModule()->getFullName() << ": Deleting mmsg and msg in serverHasResource(msg) == true in socketDataArrived..." <<endl;
			delete mmsg;
			//cerr << getParentModule()->getFullName() << ": Going to delete the Hit-found client request: " << ((httptRequestMessage*)msg)->heading() <<endl;
			delete msg;
			//cerr << getParentModule()->getFullName() << ": ...done deleting mmsg and msg in serverHasResource(msg) == true in socketDataArrived" <<endl;
		} else {
			// request resource
			httptRequestMessage * m = generateServerRequest(msg);
			TCPSocket * srv_socket = sendRequest(m);
			//cerr << getParentModule()->getFullName() << ": Missing found client request: " << ((httptRequestMessage*)msg)->heading() <<endl;
			if(srv_socket) {
				// log sockets;
				// TODO: when client uses same socket for subseq. requests,
				// don't create new server socket for it.
				//cerr << getParentModule()->getFullName() << ": Adding the " << ((httptRequestMessage*)msg)->heading() << " request pending requests" << endl;
				pair<ClientMap::iterator, bool> result;
				result = pendingRequests.insert(pair<TCPSocket *, cPacket *>(srv_socket, mmsg));
				if(!result.second) //Can't insert in the map because the same socket (key) is used for more than only one message
				serverRequestsNotYetSent.push_back(mmsg);

			} else {
				//cerr << getParentModule()->getFullName() << ": Deleting the reply for client request: " << ((httptRequestMessage*)msg)->heading() <<endl;
				//cerr << getParentModule()->getFullName() << ": Deleting m, mmsg and msg in srv_socket==NULL in socketDataArrived..." <<endl;
				delete m;
				msg = mmsg->decapsulate();
				delete mmsg;
				delete msg;
				//cerr << getParentModule()->getFullName() << ": ...done deleting m, mmsg and msg in srv_socket==NULL in socketDataArrived..." <<endl;
			}
		}
	} else if (sockdata->sockType == CLIENT) {
		//handleDataMessage(msg);

		receiveResource(mmsg); // only one type of resource: content.
		updateDisplay();

		if ( --sockdata->pendingReplies==0 )
		{
			EV_DEBUG << "Received last expected reply on this socket. Issuing a close" << endl;
			socket->close();
		}
		// Message deleted in handler - do not delete here!
	}
}

void BTCache::receiveResource(cPacket *mmsg) {
	EV_DEBUG<< "BTCache: receiveResource begin"<< endl;
	cPacket* msg = mmsg->getEncapsulatedPacket();
	if( msg->getKind()!= HTTP_RESPONSE_MSG) {
		EV_DEBUG <<"BTCache: Received in receiveResource unexpected message kind : "<<msg->getKind()<< endl;
		//printf("BTCache: Received in receiveResource unexpected message kind : %d\n",msg->getKind());
		//cerr << getParentModule()->getFullName() << ": Deleting mmsg and msg in msg->getKind()!= HTTP_RESPONSE_MSG in receiveResource..." <<endl;
		msg = mmsg->decapsulate();
		delete mmsg;
		delete msg;
		//cerr << getParentModule()->getFullName() << ": ...done deleting mmsg and msg in msg->getKind()!= HTTP_RESPONSE_MSG in receiveResource..." <<endl;
		return;
	}

	httptReplyMessage *appmsg = (httptReplyMessage*) msg;
	if (appmsg==NULL) error("Message (%s)%s is not a valid reply message",msg->getClassName(), msg->getName());
	logResponse(appmsg);

	// update cache
	if (!isErrorMessage(appmsg)) {
		Resource * wr = new WebResource(appmsg->relatedUri()/*extractURLFromResponse(appmsg)*/,appmsg->getByteLength());

		if (wr->getSize() <= ((int)par("cacheSize"))) {
			EV_INFO << "CACHE ADDING RESOURCE: "<<wr->getID() <<".  REMAINING CAPACITY: "<<((LRUCache *)resourceCache)->getRemainingCapacity()<<endl;
			resourceCache->add(wr);
		}
		else {
			EV_DEBUG<<"Resource not added to cache because bigger than cache capacity"<<endl;
		}
	}
	else {
		EV_DEBUG<<"Resource not added to cache it is an error message."<<endl;
		//cerr << getParentModule()->getFullName() <<": Resource not added to cache it is an error message."<<endl;
	}
	// send message to approp. client
	pendingServerRequests --;
	TCPSocket * srvr = sockCollection.findSocketFor(mmsg);
	ClientMap::iterator i = pendingRequests.find(srvr);
	cPacket * m = i->second;
	TCPSocket * cli = sockCollection.findSocketFor(m);

	if (!cli || (cli->getState() != CONNECTED && cli->getState() != RECEIVING
			&& cli->getState() != CONNECTING && cli->getState() != PEER_CLOSED)) { // client socket was closed or failed earlier
		EV_INFO<<"Cache can not send to client, socket failed or was closed"<<endl;
		//cerr << getParentModule()->getFullName() <<": Cache can not send to client, socket failed or was closed deleting msg in receiveResource"<<endl;
		msg = mmsg->decapsulate();
		delete msg;
		//cerr << getParentModule()->getFullName() <<": Cache can not send to client, socket failed or was closed. done deleting msg in receiveResource"<<endl;

	}
	else {
		cMessage* reqmsg = m->getEncapsulatedPacket();
		//delete m;
		cPacket* msg1 = mmsg->decapsulate();
		httptReplyMessage *appmsg1 = (httptReplyMessage*) msg1;
		httptReplyMessage *appmsg2 = new httptReplyMessage(*appmsg1); // use dup() here?

		httptRequestMessage * rm= check_and_cast<httptRequestMessage *>(reqmsg);
		appmsg2->setTargetUrl(rm->originatorUrl()); // maybe not what httptserver does.
		appmsg2->setOriginatorUrl(rm->targetUrl());
		appmsg2->setKind(HTTP_RESPONSE_MSG);
		appmsg2->setTimestamp();


		string uri = appmsg2->relatedUri();
		cStringTokenizer tokenizer = cStringTokenizer(uri.c_str(), "_");
		std::vector<string> params = tokenizer.asVector();
		//int qlevel = strtol(params[1].c_str(), 0, 10);
		int piece = strtol(params[2].c_str(), 0, 10);
		int block = strtol(params[3].c_str(), 0, 10);
		//printf("Forwarding piece %d - block %d to client %s\n",piece,block,appmsg2->targetUrl());
		cPacket* wrapper = new cPacket(appmsg2->getName(), TCP_I_DATA);
		wrapper->encapsulate(dynamic_cast<cPacket*> (appmsg2));
		int sockstate = cli->getState();
		if (sockstate!=CONNECTED && /* +++> */ sockstate != RECEIVING && /* <+++ */
	    		sockstate!=CONNECTING && sockstate!=PEER_CLOSED){
			cerr<<"BTCache-"<<getParentModule()->getFullName()<<"TCPSocket::send(): not connected or connecting."
			<<"\n\t Sending to "<<cli->getRemoteAddress().get4().str().c_str()<<" skipped!!!"<<endl;
			cPacket* msg = (check_and_cast<cPacket*>(wrapper))->decapsulate();
			//cerr << getParentModule()->getFullName() <<": Socket failed or was closed deleting wrapper and msg in receiveResource"<<endl;
			delete wrapper;
			delete msg;
			//cerr << getParentModule()->getFullName() <<": Socket failed or was closed. done deleting wrapper and msg in receiveResource"<<endl;
		}
		else
			cli->send(wrapper);
		delete msg1;
	}
	//cerr << getParentModule()->getFullName() <<": Deleting mmsg in receiveResource..."<<endl;
	delete mmsg;
	//cerr << getParentModule()->getFullName() <<": ...done deleting mmsg in receiveResource."<<endl;

}

httptReplyMessage* BTCache::handleGetRequest(httptRequestMessage *request,
		string resource_uri) {
	string uri = resource_uri;
	cStringTokenizer tokenizer = cStringTokenizer(uri.c_str(), "_");
	std::vector<string> params = tokenizer.asVector();
	string requestOriginator = request->originatorUrl();
	int qlevel = strtol(params[1].c_str(), 0, 10);
	int piece = strtol(params[2].c_str(), 0, 10);
	int block = strtol(params[3].c_str(), 0, 10);
	int blockSize = request->entitySize();
	EV_DEBUG<<"BTCache: preparing the ***HTTP*** response from the cache for piece: "
		<< piece << ", block : " << block << " Size :"<<blockSize<<" To : "<<requestOriginator<< endl;

	httptReplyMessage * rep = generateByteRangeReply(request, resource_uri,
			blockSize*1024, rt_vidseg);

	rep->setKind(HTTP_RESPONSE_MSG);
	rep->setTargetUrl(requestOriginator.c_str());
	EV_DEBUG<<"BTCache: Sending back the ***HTTP*** response message for piece: "
	<< piece << ", block : " << block << endl;
	return rep;

}

bool BTCache::isErrorMessage(httptReplyMessage *msg) {
	return (msg->result() != 200);
}

void BTCache::initialize() {
	EV_DEBUG<< "BTCache: initialize begin"<< endl;
	btStatisticsModule = (cModule*) simulation.getModuleByPath(par(
					"statisticsModulePath"));
	btStatistics = (cSimpleModule*) btStatisticsModule->getSubmodule(
			"btstatistics", 0);
	//btStatistics = (cSimpleModule*)simulation.getModuleByPath(par("statisticsModulePath"));

	if (btStatistics == NULL)
	opp_error("BTCache: Wrong statisticsModulePath configuration");

	cMessage* subscribe = new cMessage("STAT_SUBSCRIBE",STAT_SUBSCRIBE);
	sendDirect(subscribe, btStatistics, btStatistics->findGate("direct_in"));

	badRequests = 0;
	wwwName = par("www").stdstringValue();
	if ( wwwName.size() == 0 )
	{
		wwwName += getParentModule()->getFullName();
		wwwName += ".omnet.net";
	}
	httpProtocol = par("httpProtocol");
	//httptHTMLServerBase::initialize();
	EV_DEBUG << "Initializing cache" << endl;
	int port = par("port");
	tcp = new TCP();
	TCPSocket * listensocket = new TCPSocket();
	CACHE_SOCK_DS *csd = new CACHE_SOCK_DS;
	csd->sockType = LISTENER;
	csd->socket = listensocket;
	listensocket->setOutputGate(gate("tcpOut"));
	listensocket->bind(port);
	listensocket->setCallbackObject(this,csd);
	listensocket->listen();

	controller = (httptController*)((cModule*) simulation.getModuleByPath(par("controllerModulePath")))->getSubmodule("controller", 0);

	serverSocketsBroken=0;
	serverSocketsOpened=0;

	clientSocketsBroken = 0;
	clientSocketsOpened = 0;
	hits = 0;
	misses = 0;
	WATCH(numBroken);
	WATCH(socketsOpened);

	resourceCache = new LRUCache(par("cacheSize").longValue());
	// logging parameters
	ll = par("logLevel");
	logFileName = par("logFile").stdstringValue();
	enableLogging = !logFileName.empty();
	outputFormat = lf_short;
	activationTime = par("activationTime");
	// file logging
	if (LOGFILE) {
		runNumber_var = (int) par("runNumber");
		resultFolder_var = (const char*) par("resultFolder");
		std::stringstream fileName;
		fileName << resultFolder_var << "/run" << runNumber_var << "/"
		<< getParentModule()->getFullName() << ".txt";
		logFile.open((fileName.str()).c_str());
	}
	updateDisplay();
	//EV_INFO << "INITIALIZING LRUCache OF SIZE "<<par("cacheSize")<<endl;

}

bool BTCache::meantForServer(cMessage *msg) {
	TCPCommand *ind = dynamic_cast<TCPCommand *> (msg->getControlInfo());
	if (!ind) {
		//EV_DEBUG << "No control info for the message" << endl;
		return true;
	}
	int connId = ind->getConnId();
	EV_DEBUG<< "Connection ID: " << connId << endl;
	TSet::iterator it = serverConnections.find(connId);
	if (it != serverConnections.end()) {
		return true;
	}
	return false;

}

string BTCache::extractURLFromRequest(httptRequestMessage *request) {
	cStringTokenizer tokenizer = cStringTokenizer(request->heading(), " ");
	vector<string> res = tokenizer.asVector();
	string r_msg = res[1];
	if (!strcmp(r_msg.c_str(), "/")) {
		r_msg = "root";
	}
	r_msg = trimLeft(r_msg, "/");
	//cout<<"EXTRACTED From request: "<<r_msg<<endl;
	return r_msg;
}

string BTCache::extractURLFromResponse(httptReplyMessage *response) {
	cStringTokenizer tokenizer =
			cStringTokenizer(response->getFullName(), "()");
	vector<string> res = tokenizer.asVector();
	//cout<<"RESULT LENGTH: "<<res.size()<<endl;
	//cout<<"Imported: "<<res[1]<<endl;

	string resp = res[1];

	return resp;
}

TCPSocket *BTCache::submitToSocket(const char *moduleName, int connectPort,
		cMessage *msg) {
	// Create a queue and push the single message
	MESSAGE_QUEUE_TYPE queue;
	msg->setTimestamp();
	cPacket* wrapper = new cPacket(msg->getName(), TCP_I_DATA);
	wrapper->encapsulate(dynamic_cast<cPacket*> (msg));
	queue.push_back(wrapper);

	// Call the overloaded version with the queue as parameter
	return submitToSocket(moduleName, connectPort, queue);
}

TCPSocket *BTCache::submitToSocket(const char *moduleName, int connectPort,
		MESSAGE_QUEUE_TYPE & queue) {
	// Dont do anything if the queue is empty.s
	if (queue.size() == 0) {
		EV_INFO<< "Submitting to socket. No data to send to " << moduleName <<". Skipping connection." << endl;
		return NULL;
	}
	EV_DEBUG << "Submitting to socket. Module: " << moduleName << ", port: " << connectPort << ". Total messages: " << queue.size() << endl;

	// Create and initialize the socket
	TCPSocket *socket = new TCPSocket();
	socket->setOutputGate(gate("tcpOut"));
	unsigned short port = tcp->getEphemeralPort();
	int cachePort = (int) par("port");

	//It could be the case that the peerWire port is freed so that we do not accept connections.
	while ((port==cachePort))
	port = tcp->getEphemeralPort();

	socket->bind(port);
	sockCollection.addSocket(socket);

	// Initialize the associated data structure
	CACHE_SOCK_DS * sockdata = new CACHE_SOCK_DS;
	sockdata->sockType = CLIENT;
	sockdata->messageQueue = MESSAGE_QUEUE_TYPE(queue);
	sockdata->socket=socket;
	sockdata->pendingReplies=0;
	socket->setCallbackObject(this,sockdata);

	// Issue a connect to the socket for the specified module and port.
	socket->connect(IPAddressResolver().resolve(moduleName), connectPort);
	return socket;
}

void BTCache::socketFailure(int connId, void *yourPtr, int code) {
	EV_DEBUG<< "BTCache: socketFailure begin"<< endl;
	EV_WARNING << "connection broken. Conneciton id " << connId << endl;
	//cerr << "connection broken. Conneciton id " << connId << endl;
	if ( yourPtr==NULL )
	{
		EV_ERROR << "Socket establish or other failure. Null pointer" << endl;
		//cerr << getParentModule()->getFullName() << ": Socket establish or other failure. Null pointer" << endl;
		return;
	}
	CACHE_SOCK_DS * csd = (CACHE_SOCK_DS *)yourPtr;
	TCPSocket *socket = csd->socket;
	if (csd->sockType == SERVER) {
		serverSocketsBroken++;
	}
	else if (csd->sockType == CLIENT) {
		clientSocketsBroken++;

		//cerr << getParentModule()->getFullName() <<": Purging socket queue in receiveResource..."<<endl;
		while( csd->messageQueue.size()!=0 )
		{
			cMessage* mmsg = csd->messageQueue.back();
			cMessage* msg = (check_and_cast<cPacket *>(mmsg))->decapsulate();
			delete mmsg;
			delete msg;
			csd->messageQueue.pop_back();
			EV_DEBUG << "Deleting remaining pending requests" << endl;
			//cerr << getParentModule()->getName() << " Deleting remaining pending requests in Socket Failure" << endl;

		}
		//cerr << getParentModule()->getFullName() <<": ...done purging socket queue in receiveResource"<<endl;

	}

	EV_INFO << "connection closed. Connection id " << connId << endl;
	//cerr << "BTCache: socket failure with peer: "<<socket->getRemoteAddress().get4().str().c_str()<< endl;
	if (code==TCP_I_CONNECTION_RESET)
	EV_WARNING << "Connection reset!\\n";
	else if (code==TCP_I_CONNECTION_REFUSED)
	EV_WARNING << "Connection refused!\\n";

	// Cleanup
	sockCollection.removeSocket(socket);
	delete socket;
	delete csd;
}

void BTCache::socketClosed(int connId, void *yourPtr) {

	EV_DEBUG<< "BTCache: socketClosed begin"<< endl;
	EV_INFO << "connection closed. Connection id " << connId << endl;
	//printf("BTCache: socketClosed begin. Connection id %d\n",connId);
	if ( yourPtr==NULL )
	{
		EV_ERROR << "Socket establish OR socket closed failure. Null pointer" << endl;
		return;
	}
	// Cleanup
	CACHE_SOCK_DS * csd = (CACHE_SOCK_DS *)yourPtr;
	TCPSocket *socket = csd->socket;
	//cerr << "BTCache: socket closed with peer: "<<socket->getRemoteAddress().get4().str().c_str()<< endl;
	sockCollection.removeSocket(socket);
	//cerr << getParentModule()->getFullName() <<": In socketClosed. Deleting msg..."<<endl;
	delete socket;
	delete csd;
	//cerr << getParentModule()->getFullName() <<": ...In socketClosed. Done deleting msg."<<endl;

}

httptRequestMessage *BTCache::generateServerRequest(cPacket *msg) {
	httptRequestMessage* request = check_and_cast<httptRequestMessage *> (msg);
	string uri = request->uri();
	EV_DEBUG<<"BTCache: received ***HTTP*** Request URI: "<< request->uri() <<endl;
	cStringTokenizer tokenizer = cStringTokenizer(uri.c_str(), "_");
	std::vector<string> params = tokenizer.asVector();

	int qlevel = strtol(params[1].c_str(), 0, 10);
	int piece = strtol(params[2].c_str(), 0, 10);
	int block = strtol(params[3].c_str(), 0, 10);

	EV_DEBUG<< "BTCache: Generating ***HTTP*** Request message for piece: "<< piece <<", block : "<< block <<endl;

	//httptRequestMessage *request = check_and_cast<httptRequestMessage *> (msg);
	if (request == NULL)
	error("Message (%s)%s is not a valid request", msg->getClassName(),
			msg->getName());

	httptRequestMessage * request2 = new httptRequestMessage(*request);
	request2->setTargetUrl(request->targetUrl());
	request2->setOriginatorUrl(request->originatorUrl());
	uri = request2->uri();

	cStringTokenizer tokenizer1 = cStringTokenizer(uri.c_str(), "_");
	params = tokenizer1.asVector();
	qlevel = strtol(params[1].c_str(), 0, 10);
	piece = strtol(params[2].c_str(), 0, 10);
	block = strtol(params[3].c_str(), 0, 10);
	EV_DEBUG<< "BTCache: Forwarding the ***HTTP*** Request message for piece: "<< piece <<", block : "<< block <<" to: "<<request2->targetUrl()<<endl;

	return request2;
}

void BTCache::handleMessage(cMessage *msg) {
	EV_DEBUG<< "BTCache: handleMessage begin"<< endl;
	if (msg->isSelfMessage())
	{
		// Self messages not used at the moment
	}

	if(msg->arrivedOn("statdirect")) {
		if (msg->getKind() == BT_STATS_FINISH) {
			//cerr << this->getParentModule()->getName() << " Receiving BT_STATS_FINISH message form BTStatistic module" << endl;
			checkAndScheduleExit();
		}
		delete msg;
	} else {
		//	else if (meantForServer(msg))
		//	{
		EV_DEBUG << "Handle inbound (SERVER) message " << msg->getName() << " of kind " << msg->getKind() << endl;
		TCPSocket *socket = sockCollection.findSocketFor(msg);
		/// Warning: if socket is null, we're assuming that it cannot be of type client.
		if (!socket && strcmp(msg->getFullName(),"PEER_CLOSED"))
		{
			EV_DEBUG << "No socket found for the message. Create a new one, assuming it is supposed to be of type server." << endl;
			// new connection -- create new socket object and server process
			socket = new TCPSocket(msg);
			serverConnections.insert(socket->getConnectionId());
			socket->setOutputGate(gate("tcpOut"));
			CACHE_SOCK_DS *csd = new CACHE_SOCK_DS;
			csd->sockType = SERVER;
			csd->socket = socket;
			socket->setCallbackObject(this,csd);
			sockCollection.addSocket(socket);
		}
		if (socket == NULL) {
			//cerr << getParentModule()->getFullName() <<": Socket==NULL in handleMessage. Deleting msg..."<<endl;
			delete msg;
			//cerr << getParentModule()->getFullName() <<": ...Socket==NULL in handleMessage. Done deleting msg."<<endl;
			return;
		}
		EV_DEBUG << "Process the message " << msg->getName() << endl;
		socket->processMessage(msg);
		/*	}
		 else // meant for client
		 {
		 EV_DEBUG << "Handle message for (CLIENT) received: " << msg->getName() << endl;

		 // Locate the socket for the incoming message. One should definitely exist.
		 TCPSocket *socket = sockCollection.findSocketFor(msg);
		 if ( socket==NULL )
		 {
		 // Handle errors. @todo error instead of warning?
		 EV_WARNING << "No socket found for message " << msg->getName() << endl;
		 delete msg;
		 return;
		 }
		 // Submit to the socket handler. Calls the TCPSocket::CallbackInterface methods.
		 // Message is deleted in the socket handler
		 socket->processMessage(msg);
		 }
		 */
		httptServerBase::handleMessage(msg);
	}
}

void BTCache::checkAndScheduleExit() {
	BTStatisticsNumHitsMsg* nhMsg = new BTStatisticsNumHitsMsg("BT_STATS_HITS",
			BT_STATS_HITS);
	nhMsg->setNumHits(hits);
	sendDirect(nhMsg, btStatistics, btStatistics->findGate("direct_in"));
	BTStatisticsNumMissesMsg* nmMsg = new BTStatisticsNumMissesMsg(
			"BT_STATS_MISSES", BT_STATS_MISSES);
	nmMsg->setNumMisses(misses);
	sendDirect(nmMsg, btStatistics, btStatistics->findGate("direct_in"));

	/*cerr << "\t\t\t\t\t***** " << getParentModule()->getFullName()
	 << " sending finish to BTStatistic module...*****" << endl;*/
	cMessage* confirmFinish = new cMessage("BT_CONFIRM_FINISH",
			BT_CONFIRM_FINISH);
	sendDirect(confirmFinish, btStatistics, btStatistics->findGate("direct_in"));

}

void BTCache::socketPeerClosed(int connId, void *yourPtr) {
	EV_DEBUG<< "BTCache: socketPeerClosed begin"<< endl;
	//printf("BTCache: socketPeerClosed begin. Connection id %d\n",connId);
	if ( yourPtr==NULL )
	{
		EV_ERROR << "Socket establish failure. Null pointer" << endl;
		return;
	}
	CACHE_SOCK_DS * csd = (CACHE_SOCK_DS *)yourPtr;
	TCPSocket *socket = csd->socket;

	// close the connection (if not already closed)
	if ( socket->getState()==TCPSocket::PEER_CLOSED)
	{
		if (csd->sockType == CLIENT) {
			//cerr << getParentModule()->getFullName() <<": Purging socket queue in socketPeerClosed..."<<endl;
			while( csd->messageQueue.size()!=0 )
			{
				cMessage* mmsg = csd->messageQueue.back();
				cMessage* msg = (check_and_cast<cPacket *>(mmsg))->decapsulate();
				delete mmsg;
				delete msg;
				csd->messageQueue.pop_back();
				EV_DEBUG << "Deleting remaining pending requests" << endl;
				//cerr << getParentModule()->getName() << " Deleting remaining pending requests in Socket Peer Close" << endl;

			}
			//cerr << getParentModule()->getFullName() <<": ...done purging socket queue in socketPeerClosed"<<endl;
		}

		EV_INFO << "remote TCP closed, closing here as well. Connection id is " << connId << endl;
		socket->close(); // Call the close method to properly dispose of the socket.
	}
}

