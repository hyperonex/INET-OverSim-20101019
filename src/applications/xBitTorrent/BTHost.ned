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
package inet.applications.xBitTorrent;

import inet.base.NotificationBoard;
import inet.networklayer.common.InterfaceTable; ;
import inet.applications.tcpapp.socketapi.ITCPSocketMgrApp;
import inet.networklayer.ipv4.RoutingTable; 
import inet.transport.udp.UDP; 
import inet.nodes.inet.NetworkLayer; ;
import inet.applications.pingapp.PingApp; ;
import inet.linklayer.ppp.PPPInterface; ;
import inet.applications.tcpapp.TCPApp; 
import inet.transport.tcp.TCP; 
import inet.linklayer.ethernet.EthernetInterface;
import inet.transport.contract.TCPSocketMgr;


//
// Host that participates in the overlay
//
// @author Konstantinos Katsaros
//
// Based on StandardHost module created by Markus Mauch, Bernhard Heep
//

module BTHost
{
    parameters:
        string channelType;
        double numTcpApps;
        string tcpAppType;
        double ASID;	//Ntinos Katsaros: ID of the AS this host belongs to (negative)
        bool IPForward; // true if ip packets should be forwarded
        string trackerClientTCPAppType;
        string peerWireTCPAppType;
        string routingFile; // use predefined routing file if given

        @display("bgb=337,472");
    gates:
        inout pppg[];
        //output out[];
        inout ethg[];
        //output ethOut[];

    submodules:
        notificationBoard: NotificationBoard {
            parameters:
                @display("p=68,208;i=block/control");
        }
        interfaceTable: InterfaceTable {
            parameters:
                @display("p=68,278;i=block/table");
        }
        routingTable: RoutingTable {
            parameters:
                IPForward = IPForward; // true if ip packets should be forwarded
                routerId = ""; // id of the router
                routingFile = routingFile; // use predefined routing file if given
                @display("p=68,348;i=block/table");
        }
        //httpServer: HttpVideoServer {
        //    parameters:
        //        @display("p=90,80;i=block/app");
        //}
        tcpsocketapi: TCPSocketMgr {//TODO rename to tcpsocketmgr
            parameters:
                @display("p=186,102");
        }
        tcpApp[numTcpApps]: <tcpAppType> like ITCPSocketMgrApp {
            parameters:
                @display("p=186,33");
                socketapi = "tcpsocketapi";
        }
        trackerClient: <trackerClientTCPAppType> like TCPApp {
            parameters:
                @display("p=170,80;i=block/app");
        }
        peerWire: <peerWireTCPAppType> like TCPApp {
            parameters:
                @display("p=250,80;i=block/app");
        }
        tcp: TCP {
            parameters:
                @display("p=200,160;i=block/wheelbarrow");
        }
        networkLayer: NetworkLayer {
            parameters:
                proxyARP = false; // sets proxy \ARP mode (replying to \ARP requests for the addresses for which a routing table entry exists)
                @display("p=200,240;i=block/fork;q=queue");
            gates:
                ifIn[sizeof(pppg)+sizeof(ethg)];
                ifOut[sizeof(pppg)+sizeof(ethg)];
        }
        ppp[sizeof(pppg)]: PPPInterface {
            parameters:
                @display("p=200,320,row,90;q=txQueue;i=block/ifcard");
        }
        eth[sizeof(ethg)]: EthernetInterface {
            parameters:
                @display("p=240,350,row,90;q=txQueue;i=block/ifcard");

        }
    connections allowunconnected:
        peerWire.btorrentOut --> trackerClient.btorrentIn;
        trackerClient.btorrentOut --> peerWire.btorrentIn;
		
		tcpApp[0].peerwireOut --> peerWire.videoserverIn;
        tcpApp[0].peerwireIn <-- peerWire.videoserverOut;
        //httpServer.peerwireOut --> peerWire.videoserverIn;
        //httpServer.peerwireIn <-- peerWire.videoserverOut;
              
        //httpServer.tcpOut --> tcp.appIn++;
        //httpServer.tcpIn <-- tcp.appOut++;
        tcpsocketapi.tcpOut --> tcp.appIn++;
        tcpsocketapi.tcpIn  <-- tcp.appOut++;
        
        peerWire.tcpOut --> tcp.appIn++;
        peerWire.tcpIn <-- tcp.appOut++;

        trackerClient.tcpOut --> tcp.appIn++;
        trackerClient.tcpIn <-- tcp.appOut++;

        tcp.ipOut --> networkLayer.tcpIn;
        tcp.ipIn <-- networkLayer.tcpOut;

        // connections to network outside
        for i=0..sizeof(pppg)-1 {
            pppg[i] <--> ppp[i].phys;
            
            ppp[i].netwOut --> networkLayer.ifIn[i];
            ppp[i].netwIn <-- networkLayer.ifOut[i];
        }

        for i=0..sizeof(ethg)-1 {
            ethg[i] <--> eth[i].phys;
            
            eth[i].netwOut --> networkLayer.ifIn[sizeof(pppg)+i];
            eth[i].netwIn <-- networkLayer.ifOut[sizeof(pppg)+i];
        }

}

