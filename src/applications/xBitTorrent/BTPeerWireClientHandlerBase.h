// Copyright 2009 Konstantinos V. Katsaros
//                              ntinos@aueb.gr
//                              http://mm.aueb.gr/~katsaros
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


#ifndef __BTPEERWIREHANDLERBASE_H_
#define __BTPEERWIREHANDLERBASE_H_

#include "BTPeerWireBase.h"
#include "BTTrackerClientBase.h"
#include <TCPConnection.h>


enum PeerWireStates {
	EARLY_ABORTING, //When we were instructed to close the connection before its final establishment
	ACTIVE_ABORTING, //When we are closing the connection
	PASSIVE_ABORTING, //When the peer has closed the connection
	INITIAL, //When the thread has just initialized
	CONNECTED, //When the connection has been established, app layer acceptance pending ,,,
	ACTIVE_HANDSHAKE, //When initating the handshake procedure
	PASSIVE_HANDSHAKE, //When the remote peer initiates the handshake procedure (not actually required, just for
	//state transition clearness).
	SENT_HANDSHAKE, //Have ONLY sent a handshake msg
	RECEIVED_HANDSHAKE, //Have ONLY received a handshake msg
	HANDSHAKE_COMPLETE, //Have completed the handshake procedure
	//BITFIELD_PENDING,	//Have not sent the bitfield because it is empty
	BITFIELD_COMPLETE, //Have sent the bitfield
	ANTI_SNUBBING
//In anti-snubbing state i.e. not uploading unless as an optimistic unchoke
};

/**
 * Handles communication with a remote peer.
 */

class BTPeerWireClientHandlerBase : public TCPServerThreadBase
{
protected:
    cMessage *evtKeepAlive;
    cMessage *evtIsAlive;
    cMessage *evtDelThread;
    cMessage *evtAntiSnub;
    cMessage *evtHandshake;
    cMessage *evtMeasureDownloadRate;
    cMessage *evtMeasureUploadRate;
    BTInternalMsg *delThreadMsg;
    int Keep_Alive_Duration;
    BTPeerWireBase *peerWireBase;
    BTTrackerClientBase *trackerClient;
    string remotePeerID;
    BitField *remoteBitfield;
    bool keepAliveExpired;
    bool amChoking_var;
    bool amInterested_var;
    bool peerChoking_var;
    bool peerInterested_var;
    bool HAVE_SENT_KEEP_ALIVE;
    bool isCacheThread_var;
    int state_var;
    bool activeConnection_var;
    bool firstTimeHere;
    int pieceSize;
    int blockSize;
    bool threadRemovelScheduled;
    simtime_t connectTimeShift_var;
    simtime_t lastDownloadTime_var;
    float downloadRate;
    vector<float> downloadRateSamples;
    simtime_t lastUploadTime_var;
    float uploadRate;
    vector<float> uploadRateSamples;
    bool inEndGame_var;
    bool seeder_var;
    bool optimisticallyUnchoked;
    void closeConnection();
    simtime_t lastChokeUnchoke_var;
    bool allowedToRequest_var;
    void renewAliveTimer(cMessage*);
    void renewAntiSnubTimer();
    RequestState requests;
    RequestState chokedRequests;
    RequestState chokedIncomingRequests;
    void cancelBlockRequest(BTRequestCancelMsg*);
    void cancelIncomingBlockRequests();
    void sendMessage(cMessage*);
    void cancelAndDelete(cMessage*);
    void printState();
    void handleRemotePeerMessage(cMessage*);
    void handleCacheMessage(cMessage*);
    void removeCurrentThread();
public:
	void enforceThreadRemoval();
    double getPayloadMessageLength(int);
    RequestState incomingRequests;
    BTPeerWireClientHandlerBase();
    virtual ~BTPeerWireClientHandlerBase();
    cMessage *createBTPeerWireMessage(const char*, int);
    cMessage *createBTPeerWireMessage(const char*, int, int, int, int);
    virtual void init(TCPSrvHostApp *hostmodule, TCPSocket *socket);
    void sendBlockRequests(int, int);
    void sendEndGameBlockRequests(int, int);
    void setRemotePeerID(string);
    string getRemotePeerID();
    BitField *getRemoteBitfield()
    {
        return remoteBitfield;
    }

    ;
    httptRequestMessage *buildHttpRequest(BTRequestCancelMsg*);
    bool amChoking();
    void setAmChoking(bool);
    bool amInterested();
    void setAmInterested(bool);
    bool peerChoking();
    void setPeerChoking(bool);
    bool peerInterested();
    void setPeerInterested(bool);
    float getDownloadRate();
    void setDownloadRate(float);
    float getUploadRate();
    void setUploadRate(float);
    bool seeder();
    void setSeeder(bool);
    simtime_t connectTimeShift();
    void setConnectTimeShift(simtime_t);
    bool isOptimisticallyUnchoked()
    {
        return optimisticallyUnchoked;
    }

    ;
    void setOptimisticallyUnchoked(bool);
    void clearPendingRequests();
    void clearPendingIncomingRequests();
    RequestState getRequests();
    int getNumPendingRequests();
    void increaseRequestQueueSize(int);
    int getState();
    void setState(int);
    simtime_t lastChokeUnchoke();
    void setLastChokeUnchoke(simtime_t);
    bool allowedToRequest();
    void setAllowedToRequest(bool);
    bool inEndGame();
    void setInEndGame(bool);
    bool activeConnection();
    void setActiveConnection(bool);
    const char *socketState();
    void updateDowloadRate(BTPieceMsg*, int);
    void updateUploadRate(RequestEntry);
    void updateCorrespondentThreadUploadRate(RequestEntry);
    bool isCacheThread();
    void setIsCacheThread(bool);
    void writeLog(const char*);
    void finalMessageCleaning();
    bool getThreadRemovelScheduled() const;
    void setThreadRemovelScheduled(bool threadRemovel);


protected:
    virtual void established();
	virtual void dataArrived(cMessage*, bool);
	virtual void timerExpired(cMessage*);
	virtual void peerClosed();
	virtual void closed();
	virtual void failure(int);
	virtual void initiatePeerWireProtocol(cMessage*);
	virtual void initiateCacheThread();

};

#endif

