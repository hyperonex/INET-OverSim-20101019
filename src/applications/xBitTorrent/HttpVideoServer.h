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

#ifndef HTTPVIDEOSERVER_H_
#define HTTPVIDEOSERVER_H_

#include "httptServerBase.h"
#include "TCPSocketAPI_Inet.h"
#include "../tcpapp/TCPSrvHostApp.h"
#include "TCPSocketMgrAppUtils.h"
#include "BTPeerWireMsg_m.h"
#include "BitField.h"
#include "BTPeerWireClientHandlerBase.h"

#define HTTP_REQUEST_MSG			6509
#define HTTP_RESPONSE_MSG			6513
#define PIECE_MSG					6510

class HttpVideoServer: public httptServerBase,
		public TCPSocketAPI_Inet::CallbackHandler {
protected:
	double file_size_var; // the size of the file, in KB
	double piece_size_var; // the size of a piece, in KB
	double block_size_var; // the size of a block, in KB
	int numPieces_var; // the number of pieces comprising the file
	int numBlocks_var; // the number of blocks comprising piece file
	const char *qualities_var;
	std::vector<int> qualitiesBitRates_var;
	BitField* localBitfield_var;
	TCPSocketAPI_Inet * tcp_api;
public:
	HttpVideoServer();
	virtual ~HttpVideoServer();
	double fileSize();
	void setFileSize(double);
	double pieceSize();
	void setPieceSize(double);
	double blockSize();
	void setBlockSize(double);
	int numPieces();
	void setNumPieces(int);
	int numBlocks();
	void setNumBlocks(int);
	BitField* localBitfield();
	void initializeLocalBitfield(bool);
	double getBlockSize(int);
protected:
	virtual void initialize();
	virtual void handleMessage(cMessage *msg);

	virtual void acceptCallback(int socket_id, int ret_status, void * myPtr);
	virtual void recvCallback(int socket_id, int ret_status, cPacket * msg,
			void * myPtr);
	/** @name httptServerBase redefinitions */
	//@ {
	virtual httptReplyMessage* handleGetRequest(httptRequestMessage *request,
			string resource);
	virtual void updateDisplay();
	//@ }

};

#endif /* HTTPVIDEOSERVER_H_ */
