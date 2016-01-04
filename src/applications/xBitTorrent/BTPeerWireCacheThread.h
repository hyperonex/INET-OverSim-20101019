//
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

#ifndef BTPEERWIRECACHETHREAD_H_
#define BTPEERWIRECACHETHREAD_H_

#include "BTPeerWireBase.h"
#include <TCPConnection.h>


/*enum PeerWireThreadStates {
	EARLY_ABORTING, //When we were instructed to close the connection before its final establishment
	ACTIVE_ABORTING, //When we are closing the connection
	PASSIVE_ABORTING, //When the peer has closed the connection
	INITIAL, //When the thread has just initialized
	CONNECTED, //When the connection has been established, app layer acceptance pending ,,,
};*/

class INET_API BTPeerWireCacheThread: public TCPServerThreadBase {
protected:
	BTPeerWireBase* peerWireBase;
	string remoteCacheID_var;
	int state_var;
	bool activeConnection_var;
	//Request related
	void closeConnection();
	void cancelBlockRequest();
	cMessage* createBTPeerWireMessage(
			const char* , int , int , int , int ) ;

public:
	BTPeerWireCacheThread();
	virtual ~BTPeerWireCacheThread();
	virtual void init(TCPSrvHostApp* hostmodule, TCPSocket* socket);
	void setRemotePeerID(string);
	string getRemotePeerID();
	int getState();
	void setState(int);
	bool activeConnection();
	void setActiveConnection(bool);
	void sendMessage(cMessage*);

protected:
	/* Redefined methods from TCPServerThreadBase */
	virtual void established();
	virtual void dataArrived(cMessage*, bool);
	virtual void timerExpired(cMessage*);
	virtual void peerClosed();
	virtual void closed();
	virtual void failure(int);
	bool isErrorMessage(httptReplyMessage *);
};

#endif /* BTPEERWIRECACHETHREAD_H_ */
