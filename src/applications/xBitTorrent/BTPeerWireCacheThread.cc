// Copyright 2008, 2009 Vasileios P. Kemerlis (aka vpk)
//                              vpk@cs.columbia.edu
//                              http://www.cs.columbia.edu/~vpk
// Copyright 2008, 2009 Konstantinos V. Katsaros
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

/*
 * BTPeerWireCacheThread.cpp
 * Created on: Mar 12, 2015
 * Author: Achraf Gazdar (agazdar@ksu.edu.sa; achraf.gazdar@gmail.com)
 */



#include "BTPeerWireBase.h"
#include "BTPeerWireClientHandlerBase.h"
#include "BTPeerWireCacheThread.h"

#define BTEV	EV << "[" << getHostModule()->getParentModule()->getFullName() << "]:[PeerWireCache Thread]: "
#define BTEV_VERB	EV << "[" << getHostModule()->getParentModule()->getFullName() << "]<=>["<< getRemotePeerID()<<"]: "

Register_Class(BTPeerWireCacheThread);

#define DEBUG_CLASS false

void BTPeerWireCacheThread::init(TCPSrvHostApp *hostmodule, TCPSocket *socket) {
	TCPServerThreadBase::init(hostmodule, socket);
	peerWireBase = (BTPeerWireBase*) getHostModule();

}

bool BTPeerWireCacheThread::isErrorMessage(httptReplyMessage *msg) {
		return (msg->result() != 200);
	}

void BTPeerWireCacheThread::dataArrived(cMessage *mmsg, bool bool1) {
	if (getState() < CONNECTED) {
		BTEV_VERB<<"the connection is being torn down. Discarding received message ..."<<endl;
		if (mmsg) delete mmsg;
		return;
	}

	cPacket* msg = (check_and_cast<cPacket*>(mmsg))->decapsulate();

	delete mmsg;

	switch (msg->getKind())
	{
		case HTTP_RESPONSE_MSG:
		{
			httptReplyMessage * response = check_and_cast<httptReplyMessage*>(msg);
			if(isErrorMessage(response)){
				cerr << peerWireBase->getParentModule()->getFullName() << " Receiving An 404 NOT FOUND" << endl;
				delete msg;
				break;
			}

			string uri = response->relatedUri();
			cStringTokenizer tokenizer = cStringTokenizer(uri.c_str(),"_");
			std::vector<string> params = tokenizer.asVector();

			int qlevel = strtol(params[1].c_str(),0,10);
			int piece_index = strtol(params[2].c_str(),0,10);
			int block = strtol(params[3].c_str(),0,10);

			BTEV_VERB<<"received ***HTTP*** piece: "<< piece_index <<", block : "<< block <<endl;
			//printf("%s received ***HTTP*** piece: %d block : %d\n",getHostModule()->getParentModule()->getFullName(),piece_index, block);
			BTRequestCancelMsg* req =
			(BTRequestCancelMsg*) createBTPeerWireMessage(
					peerWireBase->toString(REQUEST_MSG), REQUEST_MSG,
					piece_index, block, peerWireBase->blockSize());

			BTPieceMsg* piece = (BTPieceMsg*)createBTPeerWireMessage(peerWireBase->toString(PIECE_MSG),PIECE_MSG,req->index(),req->begin(),req->dataLength());
			delete req;
			//FW to application, in order to forward to the HttpVideoServer for updating
			scheduleAt(simTime(), piece);
			block = piece->begin();
			BTEV_VERB<<"received Piece message (data) through Http. Piece #"<<piece->index()<<", Block #"<<block<<endl;

			//Look for the clientBaseThread who asked for this piece

			TCPServerThreadBase *thread;
			BTPeerWireClientHandlerBase* handler;
			PeerEntryVector peerVector = peerWireBase->getPeerState().getVector();

			bool expected = true;
			unsigned int i;
			int requestIndex = -1;
			for (i=0; i<peerVector.size(); i++)
			{
				PeerEntry entry= peerVector[i];
				thread = check_and_cast<TCPServerThreadBase *>(entry.getPeerThread());
				handler = (BTPeerWireClientHandlerBase*) thread;
				if (!thread)
				getHostModule()->error("%s:%d at %s() Inconsistent thread state, could not find peer thread. \n", __FILE__, __LINE__, __func__);
				if(handler->isCacheThread())
				continue;
				requestIndex = handler->getRequests().findRequest(piece->index(),block);
				if (requestIndex<0)
				continue;
				break;
			}

			if (requestIndex < 0) {
				expected = false;
				//Select any random thread in this case to continue with
				do {
					PeerEntry entry= peerVector[intuniform(0,peerVector.size() - 1)];
					thread = check_and_cast<TCPServerThreadBase *>(entry.getPeerThread());
					handler = (BTPeerWireClientHandlerBase*) thread;
				}while(handler->isCacheThread());
			}

			//Update our bitfield
			peerWireBase->updateBitField(piece->index(),block, expected, handler->getRemotePeerID().c_str());

			if (handler->getRemotePeerID().find("overlayTerminal-1")!=-1) {
				//printf(">>> %s, Getting blocks from the Seeder %s through the Cache \n",getHostModule()->getParentModule()->getFullName(),handler->getRemotePeerID().c_str());
				peerWireBase->increamentBlocksFromSeeder();
			} /*else
			printf(">>> %s Getting blocks from the Peer  %s through the Cache\n",getHostModule()->getParentModule()->getFullName() ,handler->getRemotePeerID().c_str());*/

			if (expected)
			{
				handler->updateDowloadRate(piece,requestIndex);
			}
			delete msg;
			break;

		}//HTTP_RESPONSE_MSG
		default:
		getHostModule()->error("%s:%d at %s() Uknown peer-wire protocol message (msg->getKind() = %d) coming from the cache.\n", __FILE__, __LINE__, __func__,msg->getKind());
	}//switch
}

cMessage* BTPeerWireCacheThread::createBTPeerWireMessage(const char* name,
		int kind, int index, int begin, int length) {
	switch (kind) {
	case PIECE_MSG: {
		BTPieceMsg* piece = new BTPieceMsg(name, kind);
		piece->setIndex(index);
		piece->setBegin(begin);
		piece->setLength_prefix(PIECE_HEADER_MSG_SIZE + length);
		piece->setByteLength(PIECE_HEADER_MSG_SIZE + length * 1024);
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

void BTPeerWireCacheThread::sendMessage(cMessage *mmsg) {
	if (getState() >= CONNECTED) {
		mmsg->setTimestamp();
		cPacket* wrapper = new cPacket(mmsg->getName(), TCP_I_DATA);
		wrapper->encapsulate(dynamic_cast<cPacket*> (mmsg));
		sock->send(wrapper);
	} else {
		BTEV_VERB<<"cannot send message ("<<peerWireBase->toString(mmsg->getKind())<<"). Cache no longer connected."<<endl;
	}
}

void BTPeerWireCacheThread::closeConnection() {
	BTEV_VERB<<"closing connection with the cache"<<endl;
	if ((getState() > INITIAL) || (getState() == EARLY_ABORTING)) {
		setState(ACTIVE_ABORTING);
		sock->close();
	} else if (getState() == INITIAL)
	setState(EARLY_ABORTING);
}

BTPeerWireCacheThread::BTPeerWireCacheThread() {
	// TODO Auto-generated constructors
	setState(INITIAL);
}

void BTPeerWireCacheThread::closed() {
	((BTPeerWireBase*) getHostModule())->decreaseCurrentNumConnections();
	//printf("BTPeerWireCacheThread. Done closed\n");
}

void BTPeerWireCacheThread::failure(int code) {
	if ((getState() > PASSIVE_ABORTING) || (getState() == EARLY_ABORTING)) {
		//If this connection has not been established...
		if ((getState() == INITIAL) || (getState() == EARLY_ABORTING)) {
			((BTPeerWireBase*) getHostModule())->decreasePendingNumConnections();
		}
		setState(PASSIVE_ABORTING);
	}
}

void BTPeerWireCacheThread::timerExpired(cMessage *timer) {
	switch (timer->getKind()) {
	case CLOSE_CONNECTION_TIMER: {
		BTEV_VERB<<"BTPeerWireCacheThread closing cache thread connection gracefully for : "<<getRemotePeerID()<<endl;
		closeConnection();
		delete timer;
		break;
	}
	default:
		getHostModule()->error("%s:%d at %s() Uknown timer expired %d\n", __FILE__, __LINE__, __func__,timer->getKind());
	}
}

void BTPeerWireCacheThread::established() {
	//Connection established but in the mean time it was ordered to close!
	if (getState() == EARLY_ABORTING) {
		closeConnection();
		return;
	}
	setState(CONNECTED);
	BTEV<<"connection established."<<endl;
	((BTPeerWireBase*)getHostModule())->increaseCurrentNumConnections();
}

void BTPeerWireCacheThread::peerClosed() {
	if (getState() > ACTIVE_ABORTING) {
		setState(PASSIVE_ABORTING);
	}

	//If this thread hasn't initated this CLOSE, respond by CLOSING
	if (this->sock->getState() != TCPSocket::CLOSED)
	this->sock->close();
}

BTPeerWireCacheThread::~BTPeerWireCacheThread() {
	// TODO Auto-generated destructor stub
}

void BTPeerWireCacheThread::setRemotePeerID(string cacheID) {
	remoteCacheID_var = cacheID;
}

string BTPeerWireCacheThread::getRemotePeerID() {
	return remoteCacheID_var;
}

int BTPeerWireCacheThread::getState() {
	return state_var;
}

void BTPeerWireCacheThread::setState(int state) {
	state_var = state;
}

bool BTPeerWireCacheThread::activeConnection() {
	return activeConnection_var;
}

void BTPeerWireCacheThread::setActiveConnection(bool con) {
	activeConnection_var = con;
}

