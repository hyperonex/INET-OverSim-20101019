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


#ifndef BTCACHE_H_
#define BTCACHE_H_
#include "httptServerBase.h"
#include "LRUCache.h"
#include "TCPSocket.h"
#include "TCPSocketMap.h"
#include "IPAddressResolver.h"
#include "WebResource.h"
#include "BTStatistics.h"
#include <TCP.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

# define HTTP_REQUEST_MSG			6509
# define HTTP_RESPONSE_MSG			6513
# define BT_STATS_HITS				764
# define BT_STATS_MISSES			765
# define BT_STATS_FINISH			7660
# define BT_CONFIRM_FINISH			7661
// log file printing
#define LOGFILE		1

/* +++> Added ACCEPTING and RECEIVING states <+++ */
	enum State
	{					/* +++> comments are new */
		NOT_BOUND, 		/**< Socket is not bound. */
		BOUND,			/**< Socket is bound. */
		LISTENING,		/**< Socket is a listening socket. */
		ACCEPTING,		/**< Socket should accept a new socket and notify the application when ready. */
		CONNECTING,		/**< Socket is connecting. */
		CONNECTED,		/**< Socket is connected. */
		RECEIVING,		/**< Socket should buffer received bytes and notify the application when ready. */
		PEER_CLOSED,	/**< The other end of the TCP connection has closed. */
		LOCALLY_CLOSED, /**< This end of the TCP connection has closed. */
		CLOSED,			/**< Socket is closed. */
		SOCKERROR,		/**< An error has occurred on the socket. */
						/* <+++ */
	};

enum WebCacheSockType {
	SERVER, CLIENT, LISTENER
};
struct CACHE_SOCK_DS {
	WebCacheSockType sockType; // type of socket (server means socket where cache acts as a server, client means socket where cache acts as client)
	TCPSocket *socket; // A reference to the socket object.
	MESSAGE_QUEUE_TYPE messageQueue; //> Queue of pending messages.
	int pendingReplies; // A counter for the number of outstanding replies.
};

class BTCache: public httptServerBase, public TCPSocket::CallbackInterface {
protected:
	httptController *controller; // Reference to central controller object.
	TCPSocket * listensocket;
	TCPSocketMap sockCollection;
	TCP* tcp;
	cModule* btStatisticsModule;
	cSimpleModule* btStatistics;
	typedef std::map<TCPSocket*, cPacket*> ClientMap;
	ClientMap pendingRequests;
	typedef std::vector<cPacket*> pendingServerRequestsVector;
	pendingServerRequestsVector serverRequestsNotYetSent;
	unsigned long serverSocketsBroken;
	unsigned long serverSocketsOpened;
	unsigned long clientSocketsBroken;
	unsigned long clientSocketsOpened;
	unsigned long numBroken;
	unsigned long socketsOpened;
	unsigned long requestsReceived;
	unsigned long pendingServerRequests;
	cStdDev* numHits;
	cOutVector numHits_vec;

	cStdDev* numMisses;
	cOutVector numMisses_vec;
	Cache * resourceCache;
	int hits;
	int misses;
	typedef std::set<int> TSet;
	TSet serverConnections; // Distinguish a server socket from a client socket

	ofstream logFile;
	int runNumber_var;
	const char *resultFolder_var;

	virtual void updateDisplay(); //> Update the display string if running in GUI mode
public:
	BTCache();
	virtual ~BTCache();
private:
	string extractURLFromRequest(httptRequestMessage * request);
	string extractURLFromResponse(httptReplyMessage * response);

	// cModule methods
	virtual void initialize();
	virtual void finish();
	virtual void handleMessage(cMessage *msg);

	// socket API methods
	virtual void socketEstablished(int connId, void *yourPtr);
	virtual void socketDataArrived(int connId, void *yourPtr, cPacket *msg,
			bool urgent);
	virtual void socketPeerClosed(int connId, void *yourPtr);
	virtual void socketClosed(int connId, void *yourPtr);
	virtual void socketFailure(int connId, void *yourPtr, int code);
	virtual void socketStatusArrived(int connId, void *yourPtr,
			TCPStatusInfo *status);
	// server methods
	bool serverHasResource(cPacket * msg);
	bool meantForServer(cMessage * msg);
	// void sendResource(); Not sure on this yet.
	// void receiveRequest(int connId, cPacket * msg); // or on this
	bool isErrorMessage(httptReplyMessage *);
	// client methods
	httptRequestMessage * generateServerRequest(cPacket * msg);
	TCPSocket * sendRequest(httptRequestMessage * request);
	void receiveResource(cPacket * msg);

	// pipelining via client
	TCPSocket * submitToSocket(const char* moduleName, int connectPort,
			cMessage *msg);
	TCPSocket * submitToSocket(const char* moduleName, int connectPort,
			MESSAGE_QUEUE_TYPE &queue);
	/** @name httptServerBase redefinitions */
	//@ {
	virtual httptReplyMessage* handleGetRequest(httptRequestMessage *request,
			string resource);
	void checkAndScheduleExit();

};

#endif /* BTCACHE_H_ */
