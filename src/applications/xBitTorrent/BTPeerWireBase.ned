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


//
// Client for the Peer-Wire (P2P) BitTorrent communication.
// Serves as a generic request-reply handler, for BitTorrent, over TCP.
//
// The model communicates with other BitTorrent clients (i.e. BitTorrentPeerWireBase modules).
// This communication is based on the TCPSrvHostApp model. However, this model is extended 
// to act symmetrically i.e. the BitTorrentPeerWireBase can actively spawn a BitTorrentPeerWireClientHandlerBase
// thread that will initiate a connection with a remote peer. After connection establishement, each 
// thread separately handles the exchange of the protocol's messages with the remote peer. The 
// neccessary coordination among the spawned threads (e.g. rarest piece selection, choking algorithm, etc.)
// is provided by this module.
//
// @see TCPSrvHostApp, TCPGenericSrvThread, BitTorrentPeerWireClientHandlerBase, <Y>
//
package inet.applications.xBitTorrent;
import inet.applications.tcpapp.TCPApp;
import inet.httptools.base.*;
simple BTPeerWireBase like TCPApp
{
    parameters:

        string debuggedNode;				//To be removed, used for debugging

        string address;

        volatile int port;
        
        string qualities = default("220"); //H264 baseprofile bitrate kbps (CBR)
        
        int maxSupportedQualityIndex = default(0); //the index of the maximum supported quality in the qualities level
        
        bool adaptiveQuality = default(false); //is the quality changing allowed
        
        double file_size;			// the size of the file, in MB (Highest Quality Bitrate)

        double piece_size;			// the size of a piece, in KB (Highest Quality Bitrate)

        double block_size;			// the size of a block, in KB (Highest Quality Bitrate)

        double DHT_port;			// for DHT trackers (optional,not supported)

        string pstr;					// string identifier of the protocol, 
							//default value = "BitTorrent protocol"

        double pstrlen;				// length of pstr, used to avoid the calculation

        double keep_alive;			// keep-alive message timer, in sec (default = 120 sec)

        bool have_supression;				// if HAVE message suppresion is supported

        double chocking_interval;		// time between choke/unchoke, in sec (default = 10 sec)

        double seederDownloaders;			// number of concurrent downloaders allowed from a seeder	

        double downloaders;			// number of concurrent downloaders allowed (default = 4)	

        double optUnchockedPeers;		// number of optimisticaly unchocked peers (default = 1)

        double seederOptUnchockedPeers;		// number of optimisticaly unchocked peers by the seeder

        double optUnchocking_interval;		// time between optimistic unchocking events, in sec 
												// (default = 30 sec)

        double snubbing_interval;		// time interval until a peer is condifered to snub the client, in sec
											// (default = 60 sec)

        double rarest_list_size;		// the number of rarest pieces among which we shall 
											// randomize selection

        double minNumConnections;		// minimum number of maintained connections (default = 30)

        double maxNumConnections;		// maximum number of maintained connections (default = 55)

        string serverThreadClass;

        double timeToSeed;				// the time a peer remains in the system as a seeder

        double request_queue_depth;		// number of allowed pending requests (default = 5)

        bool super_seed_mode;					// whether this node is in super seeding mode

        double maxNumEmptyTrackerResponses; 	// maximum number of subsequent empty peer sets received 
													// from the tracker before exiting

        double newlyConnectedOptUnchokeProb;	// probability by which a newly connected peer is selected 
													// for optimistic unchoke, compared to a random choice (default = 0.75)

        bool enableEndGameMode;						//whether to enable end-game mode of the peer-wire protocol

        string statisticsModulePath;					//location of BtTorrentStatics module under simulation

        double downloadRateSamplingDuration;	//duration of dowload rate sampling (default = 20 sec)

        volatile double procDelay;								//processing delay (in micro-seconds)
        
        bool use_http; //whether we request and send pieces using http
		bool use_chache_server; //whether we use or not a caching server
		
		string cacheIpAddress = default("");
		int cachePort = default(80);
		
		int missedPiecesThreshold = default(3); // upper bound of the successive missed pieces before down-grading the quality
    	int succesivePlayedPiecesThreshold = default(4); // lower number of successive pieces successfully downloaded before upgrading the quality
    	
		int bufferingDuration @unit(s) = default(10s); //sec
		int fifoPieceSelectionWindow = default(5); //pieces
		int waitingDurationWhenPieceNotFound @unit(s) = default(10s); //waiting duration to try to download the not found piece for playback before skipping to the next one   
	    
	    int runNumber = default(0);
	    string resultFolder = default("/home/achraf/Research/Papers/P2PDASH/simulationResults/newResultFolder/p10-s1-b6-c30-np2-cc2");			  
     
     gates:
        input tcpIn;
        input btorrentIn;
        input videoserverIn;
        input statdirect;
        output tcpOut;
        output btorrentOut;
        output videoserverOut;
}
