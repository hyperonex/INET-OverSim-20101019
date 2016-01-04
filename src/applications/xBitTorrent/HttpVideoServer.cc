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

#include "HttpVideoServer.h"

using namespace std;

#define BEV	EV << "[" << this->getParentModule()->getFullName() << "]: "

Define_Module( HttpVideoServer);

HttpVideoServer::HttpVideoServer() {
	// TODO Auto-generated constructor stub

}

HttpVideoServer::~HttpVideoServer() {
	// TODO Auto-generated destructor stub
	if (localBitfield_var)
		delete localBitfield_var;
}

void HttpVideoServer::initialize() {
	//httptServerBase::initialize();
	badRequests = 0;
	EV_DEBUG<< "Initializing server base component\n";

	wwwName = par("www").stdstringValue();
	if ( wwwName.size() == 0 )
	{
		wwwName += getParentModule()->getFullName();
		wwwName += ".omnet.net";
	}
	EV_DEBUG << "Initializing HTTP server. Using WWW name " << wwwName << endl;
	port = (int) this->getParentModule()->getSubmodule("peerWire")->par("port");
	ASSERT(TCP_PORT_RANGE_MIN <= port && port <= TCP_PORT_RANGE_MAX);

	httpProtocol = par("httpProtocol");
	ASSERT(httpProtocol == HTTP_10 || httpProtocol == HTTP_11);
	tcp_api = findTCPSocketMgr(this);
	// find and register with controller
	controller = (httptController*)((cModule*) simulation.getModuleByPath(par("controllerModulePath")))->getSubmodule("controller", 0);
	EV_DEBUG << "registerWithController: parent module's full name: "<<getParentModule()->getFullName()<<endl;
	controller->registerWWWserver(getParentModule()->getFullName(),wwwName.c_str(),port,INSERT_END,activationTime);

	// logging parameters
	ll = par("logLevel");
	logFileName = par("logFile").stdstringValue();
	enableLogging = !logFileName.empty();
	outputFormat = lf_short;

	activationTime = par("activationTime");

	updateDisplay();

	qualities_var = (const char*) this->getParentModule()->getSubmodule("peerWire")->par("qualities");
	cStringTokenizer tokenizer = cStringTokenizer(qualities_var, " ");
	std::vector<string> params = tokenizer.asVector();
	char * pEnd;
	unsigned int i;
	for (i = 0; i < params.size(); i++) {
		qualitiesBitRates_var.push_back(strtol(params[i].c_str(), &pEnd, 10));
	}


	file_size_var = (double) this->getParentModule()->getSubmodule("peerWire")->par("file_size") * 1024;
	piece_size_var = (double) this->getParentModule()->getSubmodule("peerWire")->par("piece_size");
	block_size_var = (double) this->getParentModule()->getSubmodule("peerWire")->par("block_size");

	setNumPieces((int)((int) (file_size_var / piece_size_var))*qualitiesBitRates_var.size());
	setNumBlocks((int) (piece_size_var / block_size_var));

	//cerr<<getParentModule()->getFullName()<<"-HTTPVideoServer: Pieces Number: "<<this->numPieces()<<" and Blocks Number: "<<this->numBlocks()<<endl;

	if (!strcmp(this->getParentModule()->getNedTypeName(),
					"inet.applications.xBitTorrent.BTHostSeeder")) {
		initializeLocalBitfield(true);
	} else {
		initializeLocalBitfield(false);
	}
}

void HttpVideoServer::handleMessage(cMessage *msg) {
	if (msg->isSelfMessage()) {
		error("%s:%d at %s() We shouldn't receive a self message. \n",
				__FILE__, __LINE__, __func__);

	} else {
		if (msg->arrivedOn("peerwireIn")) {
			switch (msg->getKind()) {
			case PIECE_MSG: {
				BTPieceMsg* piece = check_and_cast<BTPieceMsg*> (msg);
				int block = piece->begin();
				BEV << "Updating the HTTP server bitfield. Piece: " << piece->index() << " Block: "<<block<<endl;
				//cerr <<  getParentModule()->getFullName() << " Updating the HTTP server bitfield. Piece: " << piece->index() << " Block: "<<block<<endl;
				localBitfield_var->update(piece->index(), block, true);
				delete msg;
				break;
			}
			case HTTP_REQUEST_MSG: {
				httptRequestMessage* request = (httptRequestMessage*) msg;
				//Just To Debug

				string uri = request->uri();
				BEV<<"received ***HTTP*** Request URI: "<< request->uri() <<endl;
				cStringTokenizer tokenizer = cStringTokenizer(uri.c_str(), "_");
				std::vector<string> params = tokenizer.asVector();

				int qlevel = strtol(params[1].c_str(), 0, 10);
				int piece = strtol(params[2].c_str(), 0, 10);
				int block = strtol(params[3].c_str(), 0, 10);

				//
				TCPServerThreadBase *thread =
				(TCPServerThreadBase *) msg->getContextPointer();

				//BEV<<"received ***HTTP*** Request message for piece: "<< piece <<", block : "<< block <<endl;
				//**************This is a Hack***********************//
				cStringTokenizer headingTokenizer = cStringTokenizer(request->heading()," ");
				std::vector<string> res = headingTokenizer.asVector();
				if ( res.size() == 1 ) {
					std::stringstream header;
					header << "GET "<<request->heading()<<" HTTP/1.1";
					const char * hdr = (header.str()).c_str();
					request->setHeading(hdr);
				}
				BEV<<"received ***HTTP*** Request message with header: "<<request->heading()<<endl;
				//cerr << getParentModule()->getFullName() << ": Received HTTP request:" << request->heading()<<endl;
				httptReplyMessage * response = handleRequestMessage(request);

				response->setContextPointer(thread);
				//cerr << getParentModule()->getFullName() << ": Sending back response: " << response->heading() << " for request: " << request->heading()<<endl;
				delete msg;

				//BEV<<"sending the ***HTTP*** Replay message to peerwireBase"<<endl;
				send(response,"peerwireOut");

				break;
			}

		}

	}

}
}

httptReplyMessage* HttpVideoServer::handleGetRequest(
		httptRequestMessage *request, string resource_uri) {

	string uri = resource_uri;
	cStringTokenizer tokenizer = cStringTokenizer(uri.c_str(), "_");

	std::vector<string> params = tokenizer.asVector();
	if (params.size()!=4){
		cerr << getParentModule()->getFullName() << ". Bad Request for URI : "<< uri.c_str() << ". And heading : " << request->heading() << endl;
		return generateErrorReply(request, resource_uri, 400);
	}
	string requestOriginator = request->originatorUrl();
	//int qlevel = strtol(params[1].c_str(), 0, 10);
	int piece = strtol(params[2].c_str(), 0, 10);
	int block = strtol(params[3].c_str(), 0, 10);

	BEV<< "Preparing the ***HTTP*** response message for piece: "
	<< piece << ", block : " << block <<" To : "<<requestOriginator<< endl;

	if (!localBitfield_var->isBlockAvailable(piece, block)) {
		cerr << getParentModule()->getFullName() << " Block: "<< piece << "_" << block << " NOT FOUND!" << endl;
		return generateErrorReply(request, resource_uri, 404);
	}

	//cerr<<"----HttpVideoServer----Current Block Size = "<<getBlockSize(piece)<<endl;
	int res_size = (int) getBlockSize(piece);//file_system->getResourceSize(request, resource_uri);

	//int res_size = request->entitySize(); //file_system->getResourceSize(resource_uri);


	httptReplyMessage * rep = generateByteRangeReply(request, resource_uri,
			res_size*1024, rt_vidseg);

	rep->setKind(HTTP_RESPONSE_MSG);
	rep->setTargetUrl(requestOriginator.c_str());
	BEV << "Sending back the ***HTTP*** response message for piece: "
	<< piece << ", block : " << block << endl;
	return rep;

}

double HttpVideoServer::getBlockSize(int pieceIndex){
	double blockPieceDuration = 0.0;
	double currQualityBlockSize = 0.0;
	int numPiecesByQuality = 0;
	int currQualityIndex = 0;
	int currQualityBitRate = 0;
	int highestBitRate = qualitiesBitRates_var[0];
	blockPieceDuration = (double) blockSize()/highestBitRate;
	numPiecesByQuality = (int) localBitfield()->numPieces()/qualitiesBitRates_var.size();
	currQualityIndex = (int) pieceIndex/numPiecesByQuality;
	currQualityBitRate = qualitiesBitRates_var[currQualityIndex];
	currQualityBlockSize = (double) blockPieceDuration*currQualityBitRate;
	return(currQualityBlockSize);

}

void HttpVideoServer::acceptCallback(int socket_id, int ret_status, void *myPtr) {
}

void HttpVideoServer::recvCallback(int socket_id, int ret_status, cPacket *msg,
		void *myPtr) {
}
void HttpVideoServer::setNumPieces(int numPieces) {
	numPieces_var = numPieces;
}

int HttpVideoServer::numPieces() {
	return numPieces_var;
}

int HttpVideoServer::numBlocks() {
	return numBlocks_var;
}

void HttpVideoServer::setNumBlocks(int numBlocks) {
	numBlocks_var = numBlocks;
}

BitField* HttpVideoServer::localBitfield() {
	return localBitfield_var;
}

void HttpVideoServer::initializeLocalBitfield(bool seeder) {
	localBitfield_var = new BitField(numPieces(), numBlocks(), seeder);
}

double HttpVideoServer::fileSize() {
	return file_size_var;
}

void HttpVideoServer::setFileSize(double file_size) {
	file_size_var = file_size;
}

double HttpVideoServer::pieceSize() {
	return piece_size_var;
}

void HttpVideoServer::setPieceSize(double piece_size) {
	piece_size_var = piece_size;
}

double HttpVideoServer::blockSize() {
	return block_size_var;
}

void HttpVideoServer::setBlockSize(double block_size) {
	block_size_var = block_size;
}

void HttpVideoServer::updateDisplay() {
	//httptServerBase::updateDisplay();
}

