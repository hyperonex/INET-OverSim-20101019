//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package inet.applications.xBitTorrent;
import inet.applications.tcpapp.socketapi.ITCPSocketMgrApp;
import inet.httptools.base.httptServerBaseInterface;

simple HttpVideoServer like ITCPSocketMgrApp, httptServerBaseInterface
{
    parameters:
        string socketapi = default("tcpsocketapi");
        //int fileSize @unit(KB) = default(1KB);
        // the domain name for this server
        string www = default("");
        // the port this server is listening on
        int port = default(1000);
        // the httptController to be used by this server
        string controllerModulePath = default("");
        string controller = default("controller");
        // the HTTP protocol to use: 10 for 1.0 and 11 for 1.1
        int httpProtocol = default(11);
        // the size of a reply message indicating an error
        volatile int errorReplySize = default(200);
        // the level of logging to be used: 2: Debug, 1: Info; 0: Errors and warnings only
        int logLevel = default(0);
        // the file to log events in
        string logFile = default("");
        // the time it takes for the server to be activated
        double activationTime @unit(s) = default(0s);
        // bitfield parameters
        double file_size;			// the size of the file, in KB
        double piece_size;			// the size of a piece, in KB
        double block_size;			// the size of a block, in KB
        
        
    gates:
        input peerwireIn;
        output peerwireOut;

}
