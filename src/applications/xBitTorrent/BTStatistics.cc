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


#include "BTStatistics.h"

Define_Module( BTStatistics);

BTStatistics::~BTStatistics() {
	if (dwSuccess)
		delete dwSuccess;
	if (numBlockFail)
		delete numBlockFail;
	if (dataProviders)
		delete dataProviders;
	if (numSeederBlocks)
		delete numSeederBlocks;
	if (numHits)
		delete numHits;
	if (numMisses)
		delete numMisses;
}

void BTStatistics::initialize() {
	currentTerminalNum = 0;
	finsihConfirmationNum = 0;
	targetOverlayTerminalNum = par("targetOverlayTerminalNum");
	dwSuccess = new cStdDev("BitTorrent:Download Duration");
	dwSuccess_vec.setName("BitTorrent:Download Duration");

	numBlockFail = new cStdDev(
			"BitTorrent:Failed Downloads:Number of Completed Blocks");
	numBlockFail_vec.setName(
			"BitTorrent:Failed Downloads:Number of Completed Blocks");

	dataProviders = new cStdDev(
			"BitTorrent:Number of Distinct Data Providing Peers");
	dataProviders_vec.setName(
			"BitTorrent:Number of Distinct Data Providing Peers");

	numSeederBlocks = new cStdDev(
			"BitTorrent:Number of Blocks Download From Seeder");
	numSeederBlocks_vec.setName(
			"BitTorrent:Number of Blocks Download From Seeder");

	numHits = new cStdDev("BitTorrent:Number of Cache Hits");
	numHits_vec.setName("BitTorrent:Number Cache Hits");

	numMisses = new cStdDev("BitTorrent:Number of Cache Misses");
	numMisses_vec.setName("BitTorrent:Number of Cache Misses");
}

void BTStatistics::handleMessage(cMessage* msg) {
	switch (msg->getKind()) {
	case BT_STATS_DWL: {
		BTStatisticsDWLMsg* dwMsg = dynamic_cast<BTStatisticsDWLMsg*> (msg);
		double dwTime = dwMsg->downloadTime();
		double rmBlocks = dwMsg->remainingBlocks();
		if (rmBlocks == 0) {
			dwSuccess->collect(dwTime);
			dwSuccess_vec.record(dwTime);
		} else {
			numBlockFail->collect(rmBlocks);
			numBlockFail_vec.record(rmBlocks);
		}

		checkFinish();
		delete msg;
		break;
	}
	case BT_STATS_PP: {
		BTStatisticsNumProvidersMsg* ppMsg =
				dynamic_cast<BTStatisticsNumProvidersMsg*> (msg);
		dataProviders->collect(ppMsg->numPeers());
		dataProviders_vec.record(ppMsg->numPeers());
		delete msg;
		break;
	}
	case BT_STATS_NSB: {
		BTStatisticsNumSeederBlocksMsg* nsbMsg =
				dynamic_cast<BTStatisticsNumSeederBlocksMsg*> (msg);
		numSeederBlocks->collect(nsbMsg->numSeederBlocks());
		numSeederBlocks_vec.record(nsbMsg->numSeederBlocks());
		delete msg;
		break;
	}
	case BT_STATS_HITS: {
		BTStatisticsNumHitsMsg* nhMsg =
				dynamic_cast<BTStatisticsNumHitsMsg*> (msg);
		numHits->collect(nhMsg->numHits());
		numHits_vec.record(nhMsg->numHits());
		delete msg;
		break;
	}
	case BT_STATS_MISSES: {
		BTStatisticsNumMissesMsg* nmMsg =
				dynamic_cast<BTStatisticsNumMissesMsg*> (msg);
		numMisses->collect(nmMsg->numMisses());
		numMisses_vec.record(nmMsg->numMisses());
		delete msg;
		break;
	}
	case BT_STATS_EXIT: {
		delete msg;
		doFinish();
		break;
	}
	case STAT_SUBSCRIBE:{

		cModule* senderModule = (cModule*) msg->getSenderModule();

		if(senderModule != NULL){
			//cerr<<"STAT MODULE. SUBMODULE "<<senderModule->getFullName()<<" FOUND"<<endl;
			if (!strcmp(senderModule->getParentModule()->getNedTypeName(),"inet.applications.xBitTorrent.BTHostSeeder")||
					!strcmp(senderModule->getParentModule()->getNedTypeName(),"inet.applications.xBitTorrent.BTHostCache"))
				moduleVector.push_back(senderModule);
		}
		delete msg;
		break;
	}
	case BT_CONFIRM_FINISH:
	{
		checkTheEnd();
		delete msg;
		break;
	}
	default: {
		opp_error("Unknown message type %d", msg->getKind());
		break;
	}
	}
}

void BTStatistics::checkTheEnd(){
	finsihConfirmationNum++;
	if(finsihConfirmationNum==moduleVector.size())
		scheduleAt(simTime() + BT_STATS_MSG_TIME, new cMessage(NULL,
						BT_STATS_EXIT));
}

void BTStatistics::doFinishNow(){
	unsigned int i;
	for(i = 0 ; i < moduleVector.size() ; i++){
		sendDirect(new cMessage("BT_STATS_FINISH",BT_STATS_FINISH),
				moduleVector[i],
				moduleVector[i]->findGate("statdirect"));
	}

}

void BTStatistics::checkFinish() {
	currentTerminalNum++;
	if (currentTerminalNum == targetOverlayTerminalNum) {
		//cerr << "Statistic Module: going to doFinishNow()" <<endl;
		doFinishNow();
	}
}

void BTStatistics::doFinish() {
	recordScalar("Simulation duration", simTime());
	dwSuccess->record();
	numBlockFail->record();
	dataProviders->record();
	numSeederBlocks->record();
	numHits->record();
	numMisses->record();
	endSimulation();
}

void BTStatistics::finish() {

}

