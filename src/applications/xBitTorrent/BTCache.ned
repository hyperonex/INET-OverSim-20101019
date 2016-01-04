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
import inet.applications.tcpapp.TCPApp;
import inet.httptools.base.httptServerBaseInterface;
import inet.httptools.cache.webcache.mod;

simple BTCache like TCPApp, httptServerBaseInterface
{
    parameters:
        
        //int fileSize @unit(KB) = default(1KB);
        // the domain name for this server
        string www = default("");
        // the port this server is listening on
        int port = default(80);
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
        int cacheSize = default(30000000);  // capacity of cache in bytes
        string serverwww = default(""); //upstream server
        string statisticsModulePath;
        // for stats logging in logfile
        int runNumber = default(0);
	    string resultFolder = default("/home/achraf/Research/Papers/P2PDASH/simulationResults/newResultFolder/p10-s1-b6-c30-np2-cc2");
        
    gates:
        input tcpIn;
        input statdirect;
        output tcpOut;

}
