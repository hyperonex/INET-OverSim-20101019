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


#ifndef __BTPEERWIREBASE_H_
#define __BTPEERWIREBASE_H_

#include <omnetpp.h>
#include <limits>
#include <algorithm>
#include "../tcpapp/TCPSrvHostApp.h"
#include "BTPeerWireMsg_m.h"
#include "BTUtils.h"
#include "BitField.h"
#include "BTTrackerMsg_m.h"
#include "BTStatistics.h"
#include "httptServerBase.h"

#include <TCP.h>

using namespace std;
//PLEASE NOTE THAT WE RETRIEVED 0 FROM THE MSG VALUES EXAMPLE 6200 instead of 62000
// Messages/timers sent/scheduled by the PeerWireBase module itself.
// They all must be less than _PEER_WIRE_BASE_MSG_FLAG
#define INTERNAL_PLAYER_MSG						6198
#define INTERNAL_CACHE_THREAD_CREATION			6199
#define INTERNAL_TRACKER_COM_MSG				6200
#define INTERNAL_INIT_CONNECTION_MSG			6201
#define INTERNAL_ACCEPT_CONNECTION_TIMER		6202
#define INTERNAL_REFUSE_CONNECTION_TIMER		6203
#define INTERNAL_CHOKE_TIMER					6204
#define INTERNAL_OPT_UNCHOKE_TIMER				6205
#define INTERNAL_EXIT_MSG						6206
#define INTERNAL_EXIT_SAFE_MSG					6207
#define _PEER_WIRE_BASE_MSG_FLAG				6299

// Messages/timers used for the PeerWireBase-Threads communication
#define INTERNAL_REMOVE_THREAD_MSG				6300
#define INTERNAL_UPDATE_THREAD_MSG				6301
#define INTERNAL_SUPER_SEED_HAVE_MSG			6302
#define INTERNAL_SUPER_SEED_COMPLETE_MSG		6303
#define INTERNAL_NEXT_REQUEST_MSG				6304
#define INTERNAL_UPDATE_INTERESTS_MSG			6305
#define INTERNAL_MEASURE_DOWNLOAD_RATE_TIMER	6306
#define INTERNAL_MEASURE_UPLOAD_RATE_TIMER		6307
#define INTERNAL_RECORD_DATA_PROVIDER_TIMER		6308

#define KEEP_ALIVE_TIMER			6400
#define IS_ALIVE_TIMER				6401
#define DEL_THREAD_TIMER			6402
#define BITFIELD_TIMER				6403
#define HAVE_TIMER					6404
#define INTERESTED_TIMER			6405
#define NOT_INTERESTED_TIMER		6406
#define REQUEST_TIMER				6407
#define PIECE_TIMER					6408
#define CANCEL_TIMER				6409
#define CHOKE_TIMER					6410
#define UNCHOKE_TIMER				6411
#define CLOSE_CONNECTION_TIMER		6412
#define ANTI_SNUB_TIMER				6413
#define SUPER_SEED_HAVE_TIMER		6414
#define DEL_THREAD_TIMER_FROM_HOST  6415

#define HANDSHAKE_MSG				6500
#define KEEP_ALIVE_MSG				6501
#define CHOKE_MSG					6502
#define UNCHOKE_MSG					6503
#define INTERESTED_MSG				6504
#define NOT_INTERESTED_MSG			6505
#define HAVE_MSG					6506
#define BITFIELD_MSG				6507
#define REQUEST_MSG					6508
#define PIECE_MSG					6510
#define CANCEL_MSG					6511
#define PORT_MSG					6512
// Added By Achraf
#define HTTP_REQUEST_MSG			6509
#define HTTP_RESPONSE_MSG			6513
#define STAT_SUBSCRIBE				6514
#define BT_STATS_FINISH				7660
#define BT_CONFIRM_FINISH			7661
//********************/
#define HANDSHAKE_MSG_SIZE			(49+peerWireBase->pstrlen())
#define KEEP_ALIVE_MSG_SIZE			4
#define CHOKE_MSG_SIZE				5
#define UNCHOKE_MSG_SIZE			5
#define INTERESTED_MSG_SIZE			5
#define NOT_INTERESTED_MSG_SIZE		5
#define HAVE_MSG_SIZE				7
#define BITFIELD_MSG_SIZE			(peerWireBase->numPieces()+5)
#define PIECE_HEADER_MSG_SIZE		9
#define REQUEST_MSG_SIZE			9
#define CANCEL_MSG_SIZE				9

// client states
#define NORMAL		0 // during downloading
#define ENDGAME		1 // during end-game mode
#define COMPLETED 	2 // finished downloading
#define SEEDING		3 // seeding after download
#define SEEDER		4 // initial seeder
#define EXITING		5 // exiting the application
// log file printing
#define LOGFILE		1
/**
 * BitTorrent protocol
 *
 * Server side of peer-wire protocol: handles all request/response messages during
 * the client <-> peer conversation.
 */

class BTPeerWireBase : public TCPSrvHostApp
{
protected:
    double file_size_var;
    double piece_size_var;
    double block_size_var;
    int numPieces_var;
    int numBlocks_var;
    size_t DHT_port_var;
    const char *pstr_var;
    int pstrlen_var;
    int keep_alive_var;
    bool have_supression_var;
    int chocking_interval_var;
    int downloaders_var;
    int optUnchockedPeers_var;
    int optUnchocking_interval_var;
    int snubbing_interval_var;
    int rarest_list_size_var;
    int minNumConnections_var;
    int maxNumConnections_var;
    int request_queue_depth_var;
    bool super_seed_mode_var;
    int timeToSeed_var;
    int maxNumEmptyTrackerResponses_var;
    double newlyConnectedOptUnchokeProb_var;
    int currentNumEmptyTrackerResponses_var;
    int currentNumConnections_var;
    int pendingNumConnections_var;
    simtime_t downloadDuration_var;
    int downloadRateSamplingDuration_var;
    double announceInterval_var;
    bool enableEndGameMode_var;
    int missedPlayerPieces_var;
    int missedPiecesThreshold_var;
    int successiveMissedPieces_var;
    int succesivePlayedPiecesThreshold_var;
    int sucessivePlayedPieces_var;
    const char *qualities_var;
    std::vector<int> qualitiesBitRates_var;
    int maxSupportedQualityIndex_var;
    int currentQualityIndex_var;
    bool adaptiveQuality_var;
    int bufferingDuration_var;
    int nextPieceToPlay_var;
    int qualitiesNumber_var;
    int qualityOffset_var;
    int fifoPieceSelectionWindow_var;
    double piecePlaybackDuration;
    int lastPieceIndex;
    int lastPlayedPieceIndex;
    bool isStatsWritten;
    int waitingDurationWhenPieceNotFound_var;
    bool secondPiecePlaybackTrial;
    bool playbackFinish;

    ofstream logFile;
    int runNumber_var;
    const char *resultFolder_var;

    const char *cacheIpAddress_var;
    int cachePort_var;
    TCPServerThreadBase *cacheThread;

    typedef std::vector<TCPServerThreadBase *> serverThreadsVector;
    serverThreadsVector serverThreads;

    bool use_http_var;
    bool use_chache_server_var;
    TCP *tcp;
    int procDelay_var;
    cMessage *evtChokeAlg;
    cMessage *evtOptUnChoke;
    cMessage *evtTrackerComm;
    cMessage *evtCacheThreadCreation;
    cMessage *evtPlayNextPiece;
    BitField *localBitfield_var;
    PieceFreqState pieceFreqState;
    PeerState peerState;
    BTTrackerMsgResponse *trackerResponse_var;
    int state_var;
    RequestEntryVector endGameRequests;
    BlockItemVector superSeedPending;
    cModule *btStatisticsModule;
    cSimpleModule *btStatistics;
    set<string> dataProviderPeerIDs;
    double blocksFromSeeder_var;
    set<string> closedRemotePeersID;
    int currentWaitingIteration;
    int waitingIterationThreshold;
public:
    BTPeerWireBase();
    virtual ~BTPeerWireBase();
    const char *debuggedNode;
    PeerState getPeerState();
    double fileSize();
    void setFileSize(double);
    double pieceSize();
    void setPieceSize(double);
    double blockSize();
    void setBlockSize(double);
    bool httpUse();
    void setHttpUse(bool);
    bool httpCacheUse();
    void setHttpCacheUse(bool);
    TCPServerThreadBase *getCacheThread();
    int DHTPort();
    void setDHTPort(int);
    const char *pstr();
    int pstrlen();
    int keepAlive();
    void setKeepAlive(int);
    bool haveSupression();
    void setHaveSupression(bool);
    int chockingInterval();
    void setChockingInterval(int);
    int downloaders();
    void setDownloaders(int);
    int optUnchockedPeers();
    void setOptUnchockedPeers(int);
    int optUnchockingInterval();
    void setOptUnchockingInterval(int);
    int snubbingInterval();
    void setSnubbingInterval(int);
    int rarestListSize();
    void setRarestListSize(int);
    int requestQueueDepth();
    void setRequestQueueDepth(int);
    int minNumConnections();
    void setMinNumConnections(int);
    int maxNumConnections();
    void setMaxNumConnections(int);
    bool superSeedMode();
    void setSuperSeedMode(bool);
    int maxNumEmptyTrackerResponses();
    void setMaxNumEmptyTrackerResponses(int);
    int currentNumEmptyTrackerResponses();
    void setCurrentNumEmptyTrackerResponses(int);
    int currentNumConnections();
    void setCurrentNumConnections(int);
    int pendingNumConnections();
    void setPendingNumConnections(int);
    BTTrackerMsgResponse *trackerResponse();
    void setTrackerResponse(BTTrackerMsgResponse*);
    void deleteTrackerResponse();
    bool haveTrackerResponse();
    int numPieces();
    void setNumPieces(int);
    int numBlocks();
    void setNumBlocks(int);
    BitField *localBitfield();
    void initializeLocalBitfield(bool);
    int timeToSeed();
    void setTimeToSeed(int);
    double newlyConnectedOptUnchokeProb();
    void setNewlyConnectedOptUnchokeProb(double);
    simtime_t downloadDuration();
    void setDownloadDuration(simtime_t);
    int announceInterval();
    void setAnnounceInterval(int);
    bool enableEndGameMode();
    void setEnableEndGameMode(bool);
    int getDownloadRateSamplingDuration();
    void setDownloadRateSamplingDuration(int);
    double blocksFromSeeder();
    void setBlocksFromSeeder(double);
    void increamentBlocksFromSeeder();
    void setProcDelay(float);
    float procDelay();
    void setCurrentQualityIndex(int);
    int currentQualityIndex();
    int currentQualityBitrate();
    int maxSupportedQualityBitrate();
    void increasePendingNumConnections();
    void decreasePendingNumConnections();
    void increaseCurrentNumConnections();
    void decreaseCurrentNumConnections();
    void checkConnections();
    void updateBitField(int, int, bool, const char*);
    int getState();
    void setState(int);
    void setAdaptive(bool);
    bool isAdaptive();
    void setQualitiesNumber(int);
    int getQualities();
    void setPiecePlaybackDuration(double);
    double getPiecePlaybackDuration();
    int updateBlockRequests(int, int, bool);
    const char *toString(int);
    void writeLog(const char*);
    int getLastPieceIndex() const;
    void setLastPieceIndex(int lastPieceIndex);
    void incrementNextPieceToPlay();
    void setNextPieceToPlay(int);
    int getNextPieceToPlay();
    int getQualityBitRate(int);
    int getLastPlayedPieceIndex() const;
    void setLastPlayedPieceIndex(int lastPlayedPieceIndex);
    int getFifoPieceSelectionWindow() const;
    void setFifoPieceSelectionWindow(int fifoPieceSelectionWindow_var);
    bool getIsStatsWritten() const;
    void setIsStatsWritten(bool isStatsWritten);
    int getWaitingDurationWhenPieceNotFound() const;
    void setWaitingDurationWhenPieceNotFound(int);

protected:
    virtual void initialize();
    virtual void finish();
    virtual void handleMessage(cMessage *msg);
    virtual void removeThread(TCPServerThreadBase*);
    void handleThreadMessage(cMessage *msg);
    void handleSelfMessage(cMessage *msg);
    void initializePieceFrequencies(int);
    void printPieceFrequencies();
    void increasePieceFrequency(int);
    void updatePieceFrequencies(BTBitfieldMsg*);
    bool connectionAlreadyEstablished(int);
    int amInterested(BTBitfieldMsg*);
    int amInterested(BitField*);
    TCPServerThreadBase *initializeCacheThread();
    virtual void informPeers(int);
    virtual void scheduleSuperSeedHaveMsg(TCPServerThreadBase*);
    virtual void checkandScheduleHaveMsgs(BTBitfieldMsg*, const char*);
    virtual void makeNextPeerMove(TCPServerThreadBase*);
    void updateInterests();
    virtual void scheduleConnections(BTTrackerMsgResponse*);
    void stopListening();
    void startListening();
    void stopChokingAlorithms();
    virtual void ChokingAlgorithm();
    virtual void chokeWorstDownloader();
    virtual void OptimisticUnChokingAlgorithm();
    virtual int chooseOptUnchokePeer(int);
    virtual BlockItem *selectPiece(BitField*, bool);
    virtual bool enterEndGameMode();
    virtual void scheduleEndGameRequests();
    virtual void scheduleEndGameCancel(int, int, const char*);
    void writeStats();
    void printConnections();
    void playNextPiece(cMessage*);
    void checkAndScheduleExit();
    bool checkBufferSequence(int, int);

};

#endif
