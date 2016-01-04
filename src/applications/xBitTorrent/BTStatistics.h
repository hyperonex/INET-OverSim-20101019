//
// Copyright 2009 Konstantinos V. Katsaros
//                              ntinos@aueb.gr
//                              http://mm.aueb.gr/~katsaros
//
// Copyright 2015 Achraf Gazdar
//                              agazdar@ksu.edu.sa
//								achraf.gazdar@gmail.com
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


#ifndef __BTStatistics_H__
#define __BTStatistics_H__

#include <omnetpp.h>
#include "BTStatisticsMsg_m.h"

# define BT_STATS_DWL			760//old one 59760
# define BT_STATS_PP			761//old one 59761
# define BT_STATS_NSB			762//old one 59762
# define BT_STATS_EXIT			763//old one 59763
# define BT_STATS_HITS			764
# define BT_STATS_MISSES		765
# define STAT_SUBSCRIBE			6514
# define BT_STATS_FINISH		7660
# define BT_CONFIRM_FINISH		7661
# define BT_STATS_MSG_TIME 		1000

using namespace std;

/**
 * Module that calculates the multicast groups sizes and randomly selects their participants (receivers and sender).
 * It is also used for global statistics measurement such as stretch.
 *
 * @author Konstantinos Katsaros
 */

class INET_API BTStatistics: public cSimpleModule {
public:
	/**
	 * Destructor
	 */
	~BTStatistics();

protected:
	int currentTerminalNum;
	int targetOverlayTerminalNum;
	int finsihConfirmationNum;
	std::vector<cModule*> moduleVector;
	cStdDev* dwSuccess;
	cOutVector dwSuccess_vec;

	cStdDev* numBlockFail;
	cOutVector numBlockFail_vec;

	cStdDev* dataProviders;
	cOutVector dataProviders_vec;

	cStdDev* numSeederBlocks;
	cOutVector numSeederBlocks_vec;

	cStdDev* numHits;
	cOutVector numHits_vec;

	cStdDev* numMisses;
	cOutVector numMisses_vec;
	/**
	 * Check whether the statistics collection has completed
	 */
	void checkFinish();

	/**
	 * Init member function of module
	 */
	virtual void initialize();

	/**
	 * HandleMessage member function of module
	 */
	virtual void handleMessage(cMessage* msg);

	/**
	 * Finish member function of module
	 */
	virtual void finish();

	/**
	 * Send finish message to BTHostSeeder and BTCache modules to clean and confirm
	 */
	void doFinish();

	/**
	* Receive and count the finish confirmation from BTHostSeeder and BTCache modules to end simulation
	*/
	void checkTheEnd();

	/**
	 * Do the actual finish() call and record scalars
	 */

	void doFinishNow();
};

#endif
