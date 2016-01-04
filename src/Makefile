#
# OMNeT++/OMNEST Makefile for libinet
#
# This file was generated with the command:
#  opp_makemake -f --deep --make-so -o inet -O out -I/home/achraf/Developpement/omnetpp-4.1/projects/omnet-extension-master/include -I/home/achraf/Developpement/omnetpp-4.1/projects/omnet-extension-master/src/xmlio -I/home/achraf/Developpement/omnetpp-4.1/projects/omnet-extension-master/src/common -I/home/achraf/Developpement/omnetpp-4.1/projects/omnet-extension-master/src/envir -I/home/achraf/Developpement/omnetpp-4.1/projects/omnet-extension-master/src/sim -I/home/achraf/Development/omnetpp-4.1/src/envir -I/home/achraf/Development/omnetpp-4.1/src/common -I/home/achraf/Development/omnetpp-4.1/include/platdep -I../../omnet-extension-master/src/sim -I../../omnet-extension-master/src/common -I../../omnet-extension-master/src/xmlio -I../../omnet-extension-master/src/xmlio/cs240utils/include -I../../omnet-extension-master/include -I../../omnet-extension-master/src/envir -L/home/achraf/Developpement/omnetpp-4.1/projects/omnet-extension-master -L../../omnet-extension-master/out/$(CONFIGNAME) -lomnetpp41extension -KOMNET_EXTENSION_MASTER_PROJ=../../omnet-extension-master
#

# Name of target to be created (-o option)
TARGET = libinet$(SHARED_LIB_SUFFIX)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I/home/achraf/Developpement/omnetpp-4.1/projects/omnet-extension-master/include \
    -I/home/achraf/Developpement/omnetpp-4.1/projects/omnet-extension-master/src/xmlio \
    -I/home/achraf/Developpement/omnetpp-4.1/projects/omnet-extension-master/src/common \
    -I/home/achraf/Developpement/omnetpp-4.1/projects/omnet-extension-master/src/envir \
    -I/home/achraf/Developpement/omnetpp-4.1/projects/omnet-extension-master/src/sim \
    -I/home/achraf/Development/omnetpp-4.1/src/envir \
    -I/home/achraf/Development/omnetpp-4.1/src/common \
    -I/home/achraf/Development/omnetpp-4.1/include/platdep \
    -I../../omnet-extension-master/src/sim \
    -I../../omnet-extension-master/src/common \
    -I../../omnet-extension-master/src/xmlio \
    -I../../omnet-extension-master/src/xmlio/cs240utils/include \
    -I../../omnet-extension-master/include \
    -I../../omnet-extension-master/src/envir \
    -I. \
    -Iapplications \
    -Iapplications/ethernet \
    -Iapplications/generic \
    -Iapplications/pingapp \
    -Iapplications/rtpapp \
    -Iapplications/sctpapp \
    -Iapplications/tcpapp \
    -Iapplications/tcpapp/socketapi \
    -Iapplications/udpapp \
    -Iapplications/xBitTorrent \
    -Iapplications/xBitTorrent/doc \
    -Iapplications/xBitTorrent/doc/html \
    -Iapplications/xBitTorrent/doc/html/search \
    -Iapplications/xBitTorrent/doc/latex \
    -Ibase \
    -Ihttptools \
    -Ihttptools/Documentation \
    -Ihttptools/base \
    -Ihttptools/cache \
    -Ihttptools/cache/base \
    -Ihttptools/cache/base/ds \
    -Ihttptools/cache/webcache \
    -Ihttptools/cache/webcache/ds \
    -Ihttptools/cache/webcache/mod \
    -Ihttptools/cache/webcache/test \
    -Ihttptools/cache/webcache/test/byterange \
    -Ihttptools/cache/webcache/test/byterange/config \
    -Ihttptools/cache/webcache/test/extfilter \
    -Ihttptools/cache/webcache/test/extfilter/config \
    -Ihttptools/cache/webcache/test/extfilter/results \
    -Ihttptools/htmlcomponents \
    -Ihttptools/messages \
    -Ihttptools/messages/observer \
    -Ihttptools/videocomponents \
    -Ihttptools/videocomponents/client \
    -Ihttptools/videocomponents/client/application \
    -Ihttptools/videocomponents/client/application/codec \
    -Ihttptools/videocomponents/client/application/policy \
    -Ihttptools/videocomponents/client/modules \
    -Ihttptools/videocomponents/client/network \
    -Ihttptools/videocomponents/client/test \
    -Ihttptools/videocomponents/client/test/config \
    -Ihttptools/videocomponents/client/test/results \
    -Ihttptools/videocomponents/server \
    -Ihttptools/videocomponents/test \
    -Ihttptools/videocomponents/workgen \
    -Ilinklayer \
    -Ilinklayer/contract \
    -Ilinklayer/ethernet \
    -Ilinklayer/etherswitch \
    -Ilinklayer/ext \
    -Ilinklayer/ieee80211 \
    -Ilinklayer/ieee80211/mac \
    -Ilinklayer/ieee80211/mgmt \
    -Ilinklayer/mf80211 \
    -Ilinklayer/mf80211/macLayer \
    -Ilinklayer/mf80211/phyLayer \
    -Ilinklayer/mf80211/phyLayer/decider \
    -Ilinklayer/mf80211/phyLayer/snrEval \
    -Ilinklayer/mfcore \
    -Ilinklayer/ppp \
    -Ilinklayer/radio \
    -Imobility \
    -Inetworklayer \
    -Inetworklayer/arp \
    -Inetworklayer/autorouting \
    -Inetworklayer/common \
    -Inetworklayer/contract \
    -Inetworklayer/extras \
    -Inetworklayer/icmpv6 \
    -Inetworklayer/ipv4 \
    -Inetworklayer/ipv6 \
    -Inetworklayer/ldp \
    -Inetworklayer/mpls \
    -Inetworklayer/ospfv2 \
    -Inetworklayer/ospfv2/interface \
    -Inetworklayer/ospfv2/messagehandler \
    -Inetworklayer/ospfv2/neighbor \
    -Inetworklayer/ospfv2/router \
    -Inetworklayer/queue \
    -Inetworklayer/rsvp_te \
    -Inetworklayer/ted \
    -Inodes \
    -Inodes/adhoc \
    -Inodes/ethernet \
    -Inodes/inet \
    -Inodes/ipv6 \
    -Inodes/mpls \
    -Inodes/wireless \
    -Itransport \
    -Itransport/contract \
    -Itransport/observer \
    -Itransport/rtp \
    -Itransport/rtp/profiles \
    -Itransport/rtp/profiles/avprofile \
    -Itransport/sctp \
    -Itransport/tcp \
    -Itransport/tcp/flavours \
    -Itransport/tcp/queues \
    -Itransport/tcp/queues/test \
    -Itransport/tcp/queues/test/config \
    -Itransport/tcp_nsc \
    -Itransport/tcp_nsc/queues \
    -Itransport/tcp_old \
    -Itransport/tcp_old/flavours \
    -Itransport/tcp_old/queues \
    -Itransport/udp \
    -Iutil \
    -Iutil/headerserializers \
    -Iutil/headerserializers/headers \
    -Iworld

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L/home/achraf/Developpement/omnetpp-4.1/projects/omnet-extension-master -L../../omnet-extension-master/out/$(CONFIGNAME)  -lomnetpp41extension
LIBS += -Wl,-rpath,`abspath /home/achraf/Developpement/omnetpp-4.1/projects/omnet-extension-master` -Wl,-rpath,`abspath ../../omnet-extension-master/out/$(CONFIGNAME)`

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/applications/ethernet/EtherAppCli.o \
    $O/applications/ethernet/EtherAppSrv.o \
    $O/applications/generic/IPTrafGen.o \
    $O/applications/pingapp/PingApp.o \
    $O/applications/rtpapp/RTPApplication.o \
    $O/applications/sctpapp/SCTPServer.o \
    $O/applications/sctpapp/SCTPPeer.o \
    $O/applications/sctpapp/SCTPClient.o \
    $O/applications/tcpapp/TCPBasicClientApp.o \
    $O/applications/tcpapp/TCPGenericSrvApp.o \
    $O/applications/tcpapp/TCPSessionApp.o \
    $O/applications/tcpapp/TCPGenericSrvThread.o \
    $O/applications/tcpapp/TCPSinkApp.o \
    $O/applications/tcpapp/TelnetApp.o \
    $O/applications/tcpapp/TCPSessionApp2.o \
    $O/applications/tcpapp/TCPEchoApp.o \
    $O/applications/tcpapp/TCPGenericCliAppBase.o \
    $O/applications/tcpapp/TCPSrvHostApp.o \
    $O/applications/tcpapp/TCPSpoof.o \
    $O/applications/tcpapp/socketapi/TCPSAPIGenericSrvApp.o \
    $O/applications/tcpapp/socketapi/TCPSocketMgrAppUtils.o \
    $O/applications/tcpapp/socketapi/AccessTCPSocketMgrApp.o \
    $O/applications/udpapp/UDPVideoStreamSvr.o \
    $O/applications/udpapp/UDPVideoStreamCli.o \
    $O/applications/udpapp/UDPBasicApp.o \
    $O/applications/udpapp/UDPEchoApp.o \
    $O/applications/udpapp/UDPAppBase.o \
    $O/applications/udpapp/UDPSink.o \
    $O/applications/xBitTorrent/BitField.o \
    $O/applications/xBitTorrent/HttpVideoServer.o \
    $O/applications/xBitTorrent/BTTrackerBase.o \
    $O/applications/xBitTorrent/BTCache.o \
    $O/applications/xBitTorrent/BTPeerWireClientHandlerBase.o \
    $O/applications/xBitTorrent/BTStatistics.o \
    $O/applications/xBitTorrent/BTTrackerClientBase.o \
    $O/applications/xBitTorrent/BTUtils.o \
    $O/applications/xBitTorrent/BTPeerWireCacheThread.o \
    $O/applications/xBitTorrent/BTPeerWireBase.o \
    $O/base/AbstractQueue.o \
    $O/base/ProtocolMap.o \
    $O/base/PassiveQueueBase.o \
    $O/base/NotifierConsts.o \
    $O/base/Join.o \
    $O/base/ReassemblyBuffer.o \
    $O/base/Blackboard.o \
    $O/base/ModuleAccess.o \
    $O/base/NotificationBoard.o \
    $O/base/QueueWithQoS.o \
    $O/base/BasicModule.o \
    $O/base/QueueBase.o \
    $O/base/Sink.o \
    $O/base/ByteArrayMessage.o \
    $O/httptools/base/WebContentExtensionFilter.o \
    $O/httptools/base/httptUtils.o \
    $O/httptools/base/httptRandom.o \
    $O/httptools/base/httptServerBase.o \
    $O/httptools/base/httptNodeBase.o \
    $O/httptools/base/httptController.o \
    $O/httptools/cache/webcache/ds/LRUCache.o \
    $O/httptools/cache/webcache/ds/WebResource.o \
    $O/httptools/cache/webcache/ds/CacheRequestMgr.o \
    $O/httptools/cache/webcache/mod/WebCacheNewAPI.o \
    $O/httptools/cache/webcache/mod/WebCache.o \
    $O/httptools/cache/webcache/test/byterange/DummyServer.o \
    $O/httptools/cache/webcache/test/byterange/ByteRangeClient.o \
    $O/httptools/htmlcomponents/httptHTMLServerDirectEvilA.o \
    $O/httptools/htmlcomponents/httptHTMLServer.o \
    $O/httptools/htmlcomponents/httptBrowserDirect.o \
    $O/httptools/htmlcomponents/httptHTMLServerDirectEvilB.o \
    $O/httptools/htmlcomponents/httptHTMLServerBase.o \
    $O/httptools/htmlcomponents/httptBrowser.o \
    $O/httptools/htmlcomponents/httptBrowserBase.o \
    $O/httptools/htmlcomponents/httptHTMLServerDirect.o \
    $O/httptools/htmlcomponents/httptHTMLServerEvilA.o \
    $O/httptools/htmlcomponents/httptHTMLServerEvilB.o \
    $O/httptools/messages/observer/DuplicateHttpMessageNameObserver.o \
    $O/httptools/messages/observer/DuplicateRecord.o \
    $O/httptools/videocomponents/client/application/ActiveRegion.o \
    $O/httptools/videocomponents/client/application/IApplicationControl.o \
    $O/httptools/videocomponents/client/application/DashState.o \
    $O/httptools/videocomponents/client/application/AdditiveController.o \
    $O/httptools/videocomponents/client/application/DashController.o \
    $O/httptools/videocomponents/client/application/NetworkMonitor.o \
    $O/httptools/videocomponents/client/application/VideoPlayback.o \
    $O/httptools/videocomponents/client/application/codec/AdditiveCodec.o \
    $O/httptools/videocomponents/client/application/codec/Codec.o \
    $O/httptools/videocomponents/client/application/codec/NonAdditiveCodec.o \
    $O/httptools/videocomponents/client/application/policy/NonAdditivePolicy.o \
    $O/httptools/videocomponents/client/application/policy/IPolicy.o \
    $O/httptools/videocomponents/client/application/policy/MeanVerticalPolicy.o \
    $O/httptools/videocomponents/client/application/policy/VerticalPolicy.o \
    $O/httptools/videocomponents/client/application/policy/DiagonalPolicy.o \
    $O/httptools/videocomponents/client/application/policy/HorizontalPolicy.o \
    $O/httptools/videocomponents/client/modules/DASHClient.o \
    $O/httptools/videocomponents/client/modules/AdditiveClient.o \
    $O/httptools/videocomponents/client/modules/IModule.o \
    $O/httptools/videocomponents/client/modules/AdaptiveClient.o \
    $O/httptools/videocomponents/client/network/INetworkControl.o \
    $O/httptools/videocomponents/client/network/Worker.o \
    $O/httptools/videocomponents/client/network/NetworkController.o \
    $O/httptools/videocomponents/client/network/MultiSockets.o \
    $O/httptools/videocomponents/client/network/Job.o \
    $O/httptools/videocomponents/server/VideoServer.o \
    $O/httptools/videocomponents/workgen/PopularizedResourceCollection.o \
    $O/httptools/videocomponents/workgen/VMDWorkloadGenerator.o \
    $O/httptools/videocomponents/workgen/VideoMetaData.o \
    $O/httptools/videocomponents/workgen/NullWorkloadGenerator.o \
    $O/linklayer/contract/MACAddress.o \
    $O/linklayer/ethernet/EtherLLC.o \
    $O/linklayer/ethernet/EtherMAC2.o \
    $O/linklayer/ethernet/EtherEncap.o \
    $O/linklayer/ethernet/EtherHub.o \
    $O/linklayer/ethernet/EtherMAC.o \
    $O/linklayer/ethernet/EtherBus.o \
    $O/linklayer/ethernet/EtherMACBase.o \
    $O/linklayer/etherswitch/MACRelayUnitNP.o \
    $O/linklayer/etherswitch/MACRelayUnitPP.o \
    $O/linklayer/etherswitch/MACRelayUnitBase.o \
    $O/linklayer/ext/cSocketRTScheduler.o \
    $O/linklayer/ext/ExtInterface.o \
    $O/linklayer/ieee80211/mac/Ieee80211Mac.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211MgmtAPSimplified.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211AgentSTA.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211MgmtAPBase.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211MgmtSTA.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211MgmtAdhoc.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211MgmtAP.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211MgmtBase.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211MgmtSTASimplified.o \
    $O/linklayer/mf80211/macLayer/Mac80211.o \
    $O/linklayer/mf80211/macLayer/CSMAMacLayer.o \
    $O/linklayer/mf80211/phyLayer/decider/ErrAndCollDecider.o \
    $O/linklayer/mf80211/phyLayer/decider/SnrDecider.o \
    $O/linklayer/mf80211/phyLayer/decider/Decider80211.o \
    $O/linklayer/mf80211/phyLayer/snrEval/SnrEval80211.o \
    $O/linklayer/mf80211/phyLayer/snrEval/SnrEval.o \
    $O/linklayer/mf80211/phyLayer/snrEval/GilbertElliotSnr.o \
    $O/linklayer/mfcore/WirelessMacBase.o \
    $O/linklayer/mfcore/BasicDecider.o \
    $O/linklayer/mfcore/BasicSnrEval.o \
    $O/linklayer/ppp/ThruputMeter.o \
    $O/linklayer/ppp/PPP.o \
    $O/linklayer/ppp/DuplicatesGenerator.o \
    $O/linklayer/ppp/DropsGenerator.o \
    $O/linklayer/radio/GenericRadioModel.o \
    $O/linklayer/radio/AbstractRadio.o \
    $O/linklayer/radio/GenericRadio.o \
    $O/linklayer/radio/Ieee80211RadioModel.o \
    $O/linklayer/radio/PathLossReceptionModel.o \
    $O/linklayer/radio/Modulation.o \
    $O/linklayer/radio/Ieee80211Radio.o \
    $O/mobility/NullMobility.o \
    $O/mobility/ANSimMobility.o \
    $O/mobility/ConstSpeedMobility.o \
    $O/mobility/TurtleMobility.o \
    $O/mobility/BonnMotionMobility.o \
    $O/mobility/RectangleMobility.o \
    $O/mobility/BasicMobility.o \
    $O/mobility/LinearMobility.o \
    $O/mobility/LineSegmentsMobilityBase.o \
    $O/mobility/CircleMobility.o \
    $O/mobility/BonnMotionFileCache.o \
    $O/mobility/RandomWPMobility.o \
    $O/mobility/MassMobility.o \
    $O/networklayer/arp/ARP.o \
    $O/networklayer/autorouting/FlatNetworkConfigurator.o \
    $O/networklayer/autorouting/NetworkConfigurator.o \
    $O/networklayer/autorouting/FlatNetworkConfigurator6.o \
    $O/networklayer/common/InterfaceTable.o \
    $O/networklayer/common/InterfaceEntry.o \
    $O/networklayer/contract/IPAddress.o \
    $O/networklayer/contract/IPAddressResolver.o \
    $O/networklayer/contract/IPControlInfo.o \
    $O/networklayer/contract/IPv6Address.o \
    $O/networklayer/contract/IPv6ControlInfo.o \
    $O/networklayer/contract/IPvXAddress.o \
    $O/networklayer/extras/Dummy.o \
    $O/networklayer/extras/NetworkInfo.o \
    $O/networklayer/extras/FailureManager.o \
    $O/networklayer/icmpv6/IPv6NeighbourDiscovery.o \
    $O/networklayer/icmpv6/ICMPv6.o \
    $O/networklayer/icmpv6/IPv6NeighbourCache.o \
    $O/networklayer/ipv4/RoutingTable.o \
    $O/networklayer/ipv4/IPFragBuf.o \
    $O/networklayer/ipv4/IPRoute.o \
    $O/networklayer/ipv4/ErrorHandling.o \
    $O/networklayer/ipv4/ICMP.o \
    $O/networklayer/ipv4/RoutingTableParser.o \
    $O/networklayer/ipv4/IPv4InterfaceData.o \
    $O/networklayer/ipv4/IP.o \
    $O/networklayer/ipv6/RoutingTable6.o \
    $O/networklayer/ipv6/IPv6.o \
    $O/networklayer/ipv6/IPv6ErrorHandling.o \
    $O/networklayer/ipv6/IPv6FragBuf.o \
    $O/networklayer/ipv6/IPv6Datagram.o \
    $O/networklayer/ipv6/IPv6InterfaceData.o \
    $O/networklayer/ldp/LDP.o \
    $O/networklayer/mpls/MPLSPacket.o \
    $O/networklayer/mpls/LIBTable.o \
    $O/networklayer/mpls/MPLS.o \
    $O/networklayer/ospfv2/OSPFRouting.o \
    $O/networklayer/ospfv2/interface/OSPFInterfaceStateLoopback.o \
    $O/networklayer/ospfv2/interface/OSPFInterfaceStateBackup.o \
    $O/networklayer/ospfv2/interface/OSPFInterfaceStateWaiting.o \
    $O/networklayer/ospfv2/interface/OSPFInterfaceStateDown.o \
    $O/networklayer/ospfv2/interface/OSPFInterface.o \
    $O/networklayer/ospfv2/interface/OSPFInterfaceStatePointToPoint.o \
    $O/networklayer/ospfv2/interface/OSPFInterfaceStateDesignatedRouter.o \
    $O/networklayer/ospfv2/interface/OSPFInterfaceStateNotDesignatedRouter.o \
    $O/networklayer/ospfv2/interface/OSPFInterfaceState.o \
    $O/networklayer/ospfv2/messagehandler/MessageHandler.o \
    $O/networklayer/ospfv2/messagehandler/HelloHandler.o \
    $O/networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.o \
    $O/networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.o \
    $O/networklayer/ospfv2/messagehandler/LinkStateRequestHandler.o \
    $O/networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.o \
    $O/networklayer/ospfv2/neighbor/OSPFNeighborStateDown.o \
    $O/networklayer/ospfv2/neighbor/OSPFNeighborStateLoading.o \
    $O/networklayer/ospfv2/neighbor/OSPFNeighborStateInit.o \
    $O/networklayer/ospfv2/neighbor/OSPFNeighborStateExchange.o \
    $O/networklayer/ospfv2/neighbor/OSPFNeighborState.o \
    $O/networklayer/ospfv2/neighbor/OSPFNeighbor.o \
    $O/networklayer/ospfv2/neighbor/OSPFNeighborStateFull.o \
    $O/networklayer/ospfv2/neighbor/OSPFNeighborStateTwoWay.o \
    $O/networklayer/ospfv2/neighbor/OSPFNeighborStateExchangeStart.o \
    $O/networklayer/ospfv2/neighbor/OSPFNeighborStateAttempt.o \
    $O/networklayer/ospfv2/router/RouterLSA.o \
    $O/networklayer/ospfv2/router/OSPFArea.o \
    $O/networklayer/ospfv2/router/OSPFRouter.o \
    $O/networklayer/ospfv2/router/SummaryLSA.o \
    $O/networklayer/ospfv2/router/NetworkLSA.o \
    $O/networklayer/ospfv2/router/ASExternalLSA.o \
    $O/networklayer/queue/DropTailQoSQueue.o \
    $O/networklayer/queue/DropTailQueue.o \
    $O/networklayer/queue/REDQueue.o \
    $O/networklayer/queue/BasicDSCPClassifier.o \
    $O/networklayer/rsvp_te/Utils.o \
    $O/networklayer/rsvp_te/SimpleClassifier.o \
    $O/networklayer/rsvp_te/RSVP.o \
    $O/networklayer/ted/TED.o \
    $O/networklayer/ted/LinkStateRouting.o \
    $O/transport/contract/TCPSocketAPI_Inet.o \
    $O/transport/contract/TCPSocket.o \
    $O/transport/contract/SCTPSocket.o \
    $O/transport/contract/UDPSocket.o \
    $O/transport/contract/TCPSocketAPI_Base.o \
    $O/transport/contract/TCPSocketExtension.o \
    $O/transport/contract/TCPSocketMap.o \
    $O/transport/contract/TCPSocketMgr.o \
    $O/transport/contract/ActiveTCPSocketPool.o \
    $O/transport/observer/TCPConnInfoMappingObserver.o \
    $O/transport/observer/TCPConnInfoDatagram.o \
    $O/transport/rtp/RTCP.o \
    $O/transport/rtp/RTPPayloadSender.o \
    $O/transport/rtp/RTPInnerPacket.o \
    $O/transport/rtp/RTPPayloadReceiver.o \
    $O/transport/rtp/RTPParticipantInfo.o \
    $O/transport/rtp/reports.o \
    $O/transport/rtp/RTPInterfacePacket.o \
    $O/transport/rtp/RTP.o \
    $O/transport/rtp/RTPPacket.o \
    $O/transport/rtp/RTPProfile.o \
    $O/transport/rtp/RTPReceiverInfo.o \
    $O/transport/rtp/RTCPPacket.o \
    $O/transport/rtp/sdes.o \
    $O/transport/rtp/RTPSenderInfo.o \
    $O/transport/rtp/profiles/avprofile/RTPAVProfile.o \
    $O/transport/rtp/profiles/avprofile/RTPAVProfilePayload32Receiver.o \
    $O/transport/rtp/profiles/avprofile/RTPAVProfilePayload32Sender.o \
    $O/transport/sctp/SCTPAssociationUtil.o \
    $O/transport/sctp/SCTPMessage.o \
    $O/transport/sctp/SCTPAssociationSendAll.o \
    $O/transport/sctp/SCTPAssociationRcvMessage.o \
    $O/transport/sctp/SCTPAssociationBase.o \
    $O/transport/sctp/SCTPAssociationEventProc.o \
    $O/transport/sctp/SCTPCCFunctions.o \
    $O/transport/sctp/SCTPSSFunctions.o \
    $O/transport/sctp/SCTP.o \
    $O/transport/sctp/SCTPReceiveStream.o \
    $O/transport/sctp/SCTPSendStream.o \
    $O/transport/sctp/SCTPQueue.o \
    $O/transport/sctp/SCTPAlg.o \
    $O/transport/tcp/TCPConnectionEventProc.o \
    $O/transport/tcp/TCPConnectionUtil.o \
    $O/transport/tcp/TCPSACKRexmitQueue.o \
    $O/transport/tcp/TCP.o \
    $O/transport/tcp/TCPConnectionRcvSegment.o \
    $O/transport/tcp/TCPConnectionBase.o \
    $O/transport/tcp/TCPSegment.o \
    $O/transport/tcp/flavours/TCPReno.o \
    $O/transport/tcp/flavours/TCPTahoe.o \
    $O/transport/tcp/flavours/TCPBaseAlg.o \
    $O/transport/tcp/flavours/TCPNewReno.o \
    $O/transport/tcp/flavours/DumbTCP.o \
    $O/transport/tcp/flavours/TCPTahoeRenoFamily.o \
    $O/transport/tcp/flavours/TCPNoCongestionControl.o \
    $O/transport/tcp/queues/TCPVirtualDataSendQueue.o \
    $O/transport/tcp/queues/TCPMsgBasedRcvQueue.o \
    $O/transport/tcp/queues/TCPVirtualDataRcvQueue.o \
    $O/transport/tcp/queues/TCPMsgByteBufferSendQueue.o \
    $O/transport/tcp/queues/MsgByteBuffer.o \
    $O/transport/tcp/queues/TCPMsgBasedSendQueue.o \
    $O/transport/tcp/queues/TCPMsgByteBufferRcvQueue.o \
    $O/transport/tcp/queues/test/ByteBufferServer.o \
    $O/transport/tcp/queues/test/ByteBufferNode.o \
    $O/transport/tcp/queues/test/ByteBufferClient.o \
    $O/transport/tcp_nsc/TCP_NSC_Connection.o \
    $O/transport/tcp_nsc/TCP_NSC.o \
    $O/transport/tcp_nsc/queues/TCP_NSC_VirtualDataQueues.o \
    $O/transport/tcp_old/TCPConnectionEventProc.o \
    $O/transport/tcp_old/TCPConnectionUtil.o \
    $O/transport/tcp_old/TCP.o \
    $O/transport/tcp_old/TCPConnectionRcvSegment.o \
    $O/transport/tcp_old/TCPConnectionBase.o \
    $O/transport/tcp_old/flavours/TCPReno.o \
    $O/transport/tcp_old/flavours/TCPTahoe.o \
    $O/transport/tcp_old/flavours/TCPBaseAlg.o \
    $O/transport/tcp_old/flavours/DumbTCP.o \
    $O/transport/tcp_old/flavours/TCPTahoeRenoFamily.o \
    $O/transport/tcp_old/flavours/TCPNoCongestionControl.o \
    $O/transport/tcp_old/queues/TCPVirtualDataSendQueue.o \
    $O/transport/tcp_old/queues/TCPMsgBasedRcvQueue.o \
    $O/transport/tcp_old/queues/TCPVirtualDataRcvQueue.o \
    $O/transport/tcp_old/queues/TCPMsgBasedSendQueue.o \
    $O/transport/udp/UDP.o \
    $O/util/ThruputMeteringChannel.o \
    $O/util/opp_utils.o \
    $O/util/common.o \
    $O/util/XMLUtils.o \
    $O/util/NetAnimTrace.o \
    $O/util/TCPDump.o \
    $O/util/NAMTraceWriter.o \
    $O/util/headerserializers/SCTPSerializer.o \
    $O/util/headerserializers/ICMPSerializer.o \
    $O/util/headerserializers/TCPSerializer.o \
    $O/util/headerserializers/UDPSerializer.o \
    $O/util/headerserializers/IPSerializer.o \
    $O/util/headerserializers/TCPIPchecksum.o \
    $O/world/ChannelInstaller.o \
    $O/world/ChannelControl.o \
    $O/world/ScenarioManager.o \
    $O/world/NAMTrace.o \
    $O/world/ChannelAccess.o \
    $O/applications/ethernet/EtherApp_m.o \
    $O/applications/pingapp/PingPayload_m.o \
    $O/applications/tcpapp/GenericAppMsg_m.o \
    $O/applications/udpapp/UDPEchoAppMsg_m.o \
    $O/applications/xBitTorrent/BTTrackerMsg_m.o \
    $O/applications/xBitTorrent/BTStatisticsMsg_m.o \
    $O/applications/xBitTorrent/BTPeerWireMsg_m.o \
    $O/base/ByteArrayMessage_m.o \
    $O/httptools/messages/httptEventMessages_m.o \
    $O/httptools/messages/httptMessages_m.o \
    $O/linklayer/contract/Ieee802Ctrl_m.o \
    $O/linklayer/contract/PhyControlInfo_m.o \
    $O/linklayer/ethernet/EtherFrame_m.o \
    $O/linklayer/ext/ExtFrame_m.o \
    $O/linklayer/ieee80211/mac/Ieee80211Frame_m.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211Primitives_m.o \
    $O/linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.o \
    $O/linklayer/mf80211/macLayer/MacPkt_m.o \
    $O/linklayer/mf80211/macLayer/Mac80211Pkt_m.o \
    $O/linklayer/mfcore/SnrControlInfo_m.o \
    $O/linklayer/mfcore/TransmComplete_m.o \
    $O/linklayer/mfcore/AirFrame_m.o \
    $O/linklayer/ppp/PPPFrame_m.o \
    $O/networklayer/arp/ARPPacket_m.o \
    $O/networklayer/contract/IPv6ControlInfo_m.o \
    $O/networklayer/contract/IPControlInfo_m.o \
    $O/networklayer/contract/IPProtocolId_m.o \
    $O/networklayer/icmpv6/IPv6NDMessage_m.o \
    $O/networklayer/icmpv6/ICMPv6Message_m.o \
    $O/networklayer/ipv4/ControlManetRouting_m.o \
    $O/networklayer/ipv4/IPDatagram_m.o \
    $O/networklayer/ipv4/ICMPMessage_m.o \
    $O/networklayer/ipv6/IPv6ExtensionHeaders_m.o \
    $O/networklayer/ipv6/IPv6Datagram_m.o \
    $O/networklayer/ldp/LDPPacket_m.o \
    $O/networklayer/ospfv2/OSPFTimer_m.o \
    $O/networklayer/ospfv2/OSPFPacket_m.o \
    $O/networklayer/rsvp_te/RSVPPacket_m.o \
    $O/networklayer/rsvp_te/SignallingMsg_m.o \
    $O/networklayer/rsvp_te/RSVPHello_m.o \
    $O/networklayer/rsvp_te/RSVPResvMsg_m.o \
    $O/networklayer/rsvp_te/RSVPPathMsg_m.o \
    $O/networklayer/rsvp_te/IntServ_m.o \
    $O/networklayer/ted/LinkStatePacket_m.o \
    $O/networklayer/ted/TED_m.o \
    $O/transport/contract/SCTPCommand_m.o \
    $O/transport/contract/SocketTimeoutMsg_m.o \
    $O/transport/contract/UDPControlInfo_m.o \
    $O/transport/contract/TCPCommand_m.o \
    $O/transport/rtp/RTPSenderStatusMessage_m.o \
    $O/transport/rtp/RTPSenderControlMessage_m.o \
    $O/transport/rtp/profiles/avprofile/RTPMpegPacket_m.o \
    $O/transport/sctp/SCTPMessage_m.o \
    $O/transport/tcp/TCPSegment_m.o \
    $O/transport/tcp/queues/MsgByteBuffer_m.o \
    $O/transport/udp/UDPPacket_m.o

# Message files
MSGFILES = \
    applications/ethernet/EtherApp.msg \
    applications/pingapp/PingPayload.msg \
    applications/tcpapp/GenericAppMsg.msg \
    applications/udpapp/UDPEchoAppMsg.msg \
    applications/xBitTorrent/BTTrackerMsg.msg \
    applications/xBitTorrent/BTStatisticsMsg.msg \
    applications/xBitTorrent/BTPeerWireMsg.msg \
    base/ByteArrayMessage.msg \
    httptools/messages/httptEventMessages.msg \
    httptools/messages/httptMessages.msg \
    linklayer/contract/Ieee802Ctrl.msg \
    linklayer/contract/PhyControlInfo.msg \
    linklayer/ethernet/EtherFrame.msg \
    linklayer/ext/ExtFrame.msg \
    linklayer/ieee80211/mac/Ieee80211Frame.msg \
    linklayer/ieee80211/mgmt/Ieee80211Primitives.msg \
    linklayer/ieee80211/mgmt/Ieee80211MgmtFrames.msg \
    linklayer/mf80211/macLayer/MacPkt.msg \
    linklayer/mf80211/macLayer/Mac80211Pkt.msg \
    linklayer/mfcore/SnrControlInfo.msg \
    linklayer/mfcore/TransmComplete.msg \
    linklayer/mfcore/AirFrame.msg \
    linklayer/ppp/PPPFrame.msg \
    networklayer/arp/ARPPacket.msg \
    networklayer/contract/IPv6ControlInfo.msg \
    networklayer/contract/IPControlInfo.msg \
    networklayer/contract/IPProtocolId.msg \
    networklayer/icmpv6/IPv6NDMessage.msg \
    networklayer/icmpv6/ICMPv6Message.msg \
    networklayer/ipv4/ControlManetRouting.msg \
    networklayer/ipv4/IPDatagram.msg \
    networklayer/ipv4/ICMPMessage.msg \
    networklayer/ipv6/IPv6ExtensionHeaders.msg \
    networklayer/ipv6/IPv6Datagram.msg \
    networklayer/ldp/LDPPacket.msg \
    networklayer/ospfv2/OSPFTimer.msg \
    networklayer/ospfv2/OSPFPacket.msg \
    networklayer/rsvp_te/RSVPPacket.msg \
    networklayer/rsvp_te/SignallingMsg.msg \
    networklayer/rsvp_te/RSVPHello.msg \
    networklayer/rsvp_te/RSVPResvMsg.msg \
    networklayer/rsvp_te/RSVPPathMsg.msg \
    networklayer/rsvp_te/IntServ.msg \
    networklayer/ted/LinkStatePacket.msg \
    networklayer/ted/TED.msg \
    transport/contract/SCTPCommand.msg \
    transport/contract/SocketTimeoutMsg.msg \
    transport/contract/UDPControlInfo.msg \
    transport/contract/TCPCommand.msg \
    transport/rtp/RTPSenderStatusMessage.msg \
    transport/rtp/RTPSenderControlMessage.msg \
    transport/rtp/profiles/avprofile/RTPMpegPacket.msg \
    transport/sctp/SCTPMessage.msg \
    transport/tcp/TCPSegment.msg \
    transport/tcp/queues/MsgByteBuffer.msg \
    transport/udp/UDPPacket.msg

# Other makefile variables (-K)
OMNET_EXTENSION_MASTER_PROJ=../../omnet-extension-master

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppenvir$D $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# inserted from file 'makefrag':
# if you want to use external interfaces with inet, you should install
# winpcap (on windows) or libpcap-dev (on linux) and re-run ./configure in
# the omnetpp root directory and comment out the following line:
HAVE_PCAP=no

ifeq ($(HAVE_PCAP),yes)
  # link with PCAP libs too
  LIBS += $(PCAP_LIBS)
else
  # remove the HAVE_PCAP define if we do not need PCAP
  CFLAGS := $(filter-out -DHAVE_PCAP,$(CFLAGS))
endif

# TCP implementaion using the Network Simulation Cradle
NSC_VERSION= $(shell ls -d ../3rdparty/nsc* 2>/dev/null | sed 's/^.*-//')
ifneq ($(NSC_VERSION),)
  CFLAGS += -DWITH_TCP_NSC -I../3rdparty/nsc-$(NSC_VERSION)/sim
  LIBS += -Wl,-rpath,`abspath ../3rdparty/nsc-$(NSC_VERSION)`
endif

# <<<
#------------------------------------------------------------------------------

# Main target
all: $(TARGET)

$(TARGET) : $O/$(TARGET)
	$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	$(SHLIB_LD) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(LIBS) $(OMNETPP_LIBS) $(LDFLAGS)
	$(SHLIB_POSTPROCESS) $O/$(TARGET)

.PHONY:

.SUFFIXES: .cc

$O/%.o: %.cc
	@$(MKPATH) $(dir $@)
	$(CXX) -c $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	-rm -rf $O
	-rm -f inet inet.exe libinet.so libinet.a libinet.dll libinet.dylib
	-rm -f ./*_m.cc ./*_m.h
	-rm -f applications/*_m.cc applications/*_m.h
	-rm -f applications/ethernet/*_m.cc applications/ethernet/*_m.h
	-rm -f applications/generic/*_m.cc applications/generic/*_m.h
	-rm -f applications/pingapp/*_m.cc applications/pingapp/*_m.h
	-rm -f applications/rtpapp/*_m.cc applications/rtpapp/*_m.h
	-rm -f applications/sctpapp/*_m.cc applications/sctpapp/*_m.h
	-rm -f applications/tcpapp/*_m.cc applications/tcpapp/*_m.h
	-rm -f applications/tcpapp/socketapi/*_m.cc applications/tcpapp/socketapi/*_m.h
	-rm -f applications/udpapp/*_m.cc applications/udpapp/*_m.h
	-rm -f applications/xBitTorrent/*_m.cc applications/xBitTorrent/*_m.h
	-rm -f applications/xBitTorrent/doc/*_m.cc applications/xBitTorrent/doc/*_m.h
	-rm -f applications/xBitTorrent/doc/html/*_m.cc applications/xBitTorrent/doc/html/*_m.h
	-rm -f applications/xBitTorrent/doc/html/search/*_m.cc applications/xBitTorrent/doc/html/search/*_m.h
	-rm -f applications/xBitTorrent/doc/latex/*_m.cc applications/xBitTorrent/doc/latex/*_m.h
	-rm -f base/*_m.cc base/*_m.h
	-rm -f httptools/*_m.cc httptools/*_m.h
	-rm -f httptools/Documentation/*_m.cc httptools/Documentation/*_m.h
	-rm -f httptools/base/*_m.cc httptools/base/*_m.h
	-rm -f httptools/cache/*_m.cc httptools/cache/*_m.h
	-rm -f httptools/cache/base/*_m.cc httptools/cache/base/*_m.h
	-rm -f httptools/cache/base/ds/*_m.cc httptools/cache/base/ds/*_m.h
	-rm -f httptools/cache/webcache/*_m.cc httptools/cache/webcache/*_m.h
	-rm -f httptools/cache/webcache/ds/*_m.cc httptools/cache/webcache/ds/*_m.h
	-rm -f httptools/cache/webcache/mod/*_m.cc httptools/cache/webcache/mod/*_m.h
	-rm -f httptools/cache/webcache/test/*_m.cc httptools/cache/webcache/test/*_m.h
	-rm -f httptools/cache/webcache/test/byterange/*_m.cc httptools/cache/webcache/test/byterange/*_m.h
	-rm -f httptools/cache/webcache/test/byterange/config/*_m.cc httptools/cache/webcache/test/byterange/config/*_m.h
	-rm -f httptools/cache/webcache/test/extfilter/*_m.cc httptools/cache/webcache/test/extfilter/*_m.h
	-rm -f httptools/cache/webcache/test/extfilter/config/*_m.cc httptools/cache/webcache/test/extfilter/config/*_m.h
	-rm -f httptools/cache/webcache/test/extfilter/results/*_m.cc httptools/cache/webcache/test/extfilter/results/*_m.h
	-rm -f httptools/htmlcomponents/*_m.cc httptools/htmlcomponents/*_m.h
	-rm -f httptools/messages/*_m.cc httptools/messages/*_m.h
	-rm -f httptools/messages/observer/*_m.cc httptools/messages/observer/*_m.h
	-rm -f httptools/videocomponents/*_m.cc httptools/videocomponents/*_m.h
	-rm -f httptools/videocomponents/client/*_m.cc httptools/videocomponents/client/*_m.h
	-rm -f httptools/videocomponents/client/application/*_m.cc httptools/videocomponents/client/application/*_m.h
	-rm -f httptools/videocomponents/client/application/codec/*_m.cc httptools/videocomponents/client/application/codec/*_m.h
	-rm -f httptools/videocomponents/client/application/policy/*_m.cc httptools/videocomponents/client/application/policy/*_m.h
	-rm -f httptools/videocomponents/client/modules/*_m.cc httptools/videocomponents/client/modules/*_m.h
	-rm -f httptools/videocomponents/client/network/*_m.cc httptools/videocomponents/client/network/*_m.h
	-rm -f httptools/videocomponents/client/test/*_m.cc httptools/videocomponents/client/test/*_m.h
	-rm -f httptools/videocomponents/client/test/config/*_m.cc httptools/videocomponents/client/test/config/*_m.h
	-rm -f httptools/videocomponents/client/test/results/*_m.cc httptools/videocomponents/client/test/results/*_m.h
	-rm -f httptools/videocomponents/server/*_m.cc httptools/videocomponents/server/*_m.h
	-rm -f httptools/videocomponents/test/*_m.cc httptools/videocomponents/test/*_m.h
	-rm -f httptools/videocomponents/workgen/*_m.cc httptools/videocomponents/workgen/*_m.h
	-rm -f linklayer/*_m.cc linklayer/*_m.h
	-rm -f linklayer/contract/*_m.cc linklayer/contract/*_m.h
	-rm -f linklayer/ethernet/*_m.cc linklayer/ethernet/*_m.h
	-rm -f linklayer/etherswitch/*_m.cc linklayer/etherswitch/*_m.h
	-rm -f linklayer/ext/*_m.cc linklayer/ext/*_m.h
	-rm -f linklayer/ieee80211/*_m.cc linklayer/ieee80211/*_m.h
	-rm -f linklayer/ieee80211/mac/*_m.cc linklayer/ieee80211/mac/*_m.h
	-rm -f linklayer/ieee80211/mgmt/*_m.cc linklayer/ieee80211/mgmt/*_m.h
	-rm -f linklayer/mf80211/*_m.cc linklayer/mf80211/*_m.h
	-rm -f linklayer/mf80211/macLayer/*_m.cc linklayer/mf80211/macLayer/*_m.h
	-rm -f linklayer/mf80211/phyLayer/*_m.cc linklayer/mf80211/phyLayer/*_m.h
	-rm -f linklayer/mf80211/phyLayer/decider/*_m.cc linklayer/mf80211/phyLayer/decider/*_m.h
	-rm -f linklayer/mf80211/phyLayer/snrEval/*_m.cc linklayer/mf80211/phyLayer/snrEval/*_m.h
	-rm -f linklayer/mfcore/*_m.cc linklayer/mfcore/*_m.h
	-rm -f linklayer/ppp/*_m.cc linklayer/ppp/*_m.h
	-rm -f linklayer/radio/*_m.cc linklayer/radio/*_m.h
	-rm -f mobility/*_m.cc mobility/*_m.h
	-rm -f networklayer/*_m.cc networklayer/*_m.h
	-rm -f networklayer/arp/*_m.cc networklayer/arp/*_m.h
	-rm -f networklayer/autorouting/*_m.cc networklayer/autorouting/*_m.h
	-rm -f networklayer/common/*_m.cc networklayer/common/*_m.h
	-rm -f networklayer/contract/*_m.cc networklayer/contract/*_m.h
	-rm -f networklayer/extras/*_m.cc networklayer/extras/*_m.h
	-rm -f networklayer/icmpv6/*_m.cc networklayer/icmpv6/*_m.h
	-rm -f networklayer/ipv4/*_m.cc networklayer/ipv4/*_m.h
	-rm -f networklayer/ipv6/*_m.cc networklayer/ipv6/*_m.h
	-rm -f networklayer/ldp/*_m.cc networklayer/ldp/*_m.h
	-rm -f networklayer/mpls/*_m.cc networklayer/mpls/*_m.h
	-rm -f networklayer/ospfv2/*_m.cc networklayer/ospfv2/*_m.h
	-rm -f networklayer/ospfv2/interface/*_m.cc networklayer/ospfv2/interface/*_m.h
	-rm -f networklayer/ospfv2/messagehandler/*_m.cc networklayer/ospfv2/messagehandler/*_m.h
	-rm -f networklayer/ospfv2/neighbor/*_m.cc networklayer/ospfv2/neighbor/*_m.h
	-rm -f networklayer/ospfv2/router/*_m.cc networklayer/ospfv2/router/*_m.h
	-rm -f networklayer/queue/*_m.cc networklayer/queue/*_m.h
	-rm -f networklayer/rsvp_te/*_m.cc networklayer/rsvp_te/*_m.h
	-rm -f networklayer/ted/*_m.cc networklayer/ted/*_m.h
	-rm -f nodes/*_m.cc nodes/*_m.h
	-rm -f nodes/adhoc/*_m.cc nodes/adhoc/*_m.h
	-rm -f nodes/ethernet/*_m.cc nodes/ethernet/*_m.h
	-rm -f nodes/inet/*_m.cc nodes/inet/*_m.h
	-rm -f nodes/ipv6/*_m.cc nodes/ipv6/*_m.h
	-rm -f nodes/mpls/*_m.cc nodes/mpls/*_m.h
	-rm -f nodes/wireless/*_m.cc nodes/wireless/*_m.h
	-rm -f transport/*_m.cc transport/*_m.h
	-rm -f transport/contract/*_m.cc transport/contract/*_m.h
	-rm -f transport/observer/*_m.cc transport/observer/*_m.h
	-rm -f transport/rtp/*_m.cc transport/rtp/*_m.h
	-rm -f transport/rtp/profiles/*_m.cc transport/rtp/profiles/*_m.h
	-rm -f transport/rtp/profiles/avprofile/*_m.cc transport/rtp/profiles/avprofile/*_m.h
	-rm -f transport/sctp/*_m.cc transport/sctp/*_m.h
	-rm -f transport/tcp/*_m.cc transport/tcp/*_m.h
	-rm -f transport/tcp/flavours/*_m.cc transport/tcp/flavours/*_m.h
	-rm -f transport/tcp/queues/*_m.cc transport/tcp/queues/*_m.h
	-rm -f transport/tcp/queues/test/*_m.cc transport/tcp/queues/test/*_m.h
	-rm -f transport/tcp/queues/test/config/*_m.cc transport/tcp/queues/test/config/*_m.h
	-rm -f transport/tcp_nsc/*_m.cc transport/tcp_nsc/*_m.h
	-rm -f transport/tcp_nsc/queues/*_m.cc transport/tcp_nsc/queues/*_m.h
	-rm -f transport/tcp_old/*_m.cc transport/tcp_old/*_m.h
	-rm -f transport/tcp_old/flavours/*_m.cc transport/tcp_old/flavours/*_m.h
	-rm -f transport/tcp_old/queues/*_m.cc transport/tcp_old/queues/*_m.h
	-rm -f transport/udp/*_m.cc transport/udp/*_m.h
	-rm -f util/*_m.cc util/*_m.h
	-rm -f util/headerserializers/*_m.cc util/headerserializers/*_m.h
	-rm -f util/headerserializers/headers/*_m.cc util/headerserializers/headers/*_m.h
	-rm -f world/*_m.cc world/*_m.h

cleanall: clean
	-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc applications/*.cc applications/ethernet/*.cc applications/generic/*.cc applications/pingapp/*.cc applications/rtpapp/*.cc applications/sctpapp/*.cc applications/tcpapp/*.cc applications/tcpapp/socketapi/*.cc applications/udpapp/*.cc applications/xBitTorrent/*.cc applications/xBitTorrent/doc/*.cc applications/xBitTorrent/doc/html/*.cc applications/xBitTorrent/doc/html/search/*.cc applications/xBitTorrent/doc/latex/*.cc base/*.cc httptools/*.cc httptools/Documentation/*.cc httptools/base/*.cc httptools/cache/*.cc httptools/cache/base/*.cc httptools/cache/base/ds/*.cc httptools/cache/webcache/*.cc httptools/cache/webcache/ds/*.cc httptools/cache/webcache/mod/*.cc httptools/cache/webcache/test/*.cc httptools/cache/webcache/test/byterange/*.cc httptools/cache/webcache/test/byterange/config/*.cc httptools/cache/webcache/test/extfilter/*.cc httptools/cache/webcache/test/extfilter/config/*.cc httptools/cache/webcache/test/extfilter/results/*.cc httptools/htmlcomponents/*.cc httptools/messages/*.cc httptools/messages/observer/*.cc httptools/videocomponents/*.cc httptools/videocomponents/client/*.cc httptools/videocomponents/client/application/*.cc httptools/videocomponents/client/application/codec/*.cc httptools/videocomponents/client/application/policy/*.cc httptools/videocomponents/client/modules/*.cc httptools/videocomponents/client/network/*.cc httptools/videocomponents/client/test/*.cc httptools/videocomponents/client/test/config/*.cc httptools/videocomponents/client/test/results/*.cc httptools/videocomponents/server/*.cc httptools/videocomponents/test/*.cc httptools/videocomponents/workgen/*.cc linklayer/*.cc linklayer/contract/*.cc linklayer/ethernet/*.cc linklayer/etherswitch/*.cc linklayer/ext/*.cc linklayer/ieee80211/*.cc linklayer/ieee80211/mac/*.cc linklayer/ieee80211/mgmt/*.cc linklayer/mf80211/*.cc linklayer/mf80211/macLayer/*.cc linklayer/mf80211/phyLayer/*.cc linklayer/mf80211/phyLayer/decider/*.cc linklayer/mf80211/phyLayer/snrEval/*.cc linklayer/mfcore/*.cc linklayer/ppp/*.cc linklayer/radio/*.cc mobility/*.cc networklayer/*.cc networklayer/arp/*.cc networklayer/autorouting/*.cc networklayer/common/*.cc networklayer/contract/*.cc networklayer/extras/*.cc networklayer/icmpv6/*.cc networklayer/ipv4/*.cc networklayer/ipv6/*.cc networklayer/ldp/*.cc networklayer/mpls/*.cc networklayer/ospfv2/*.cc networklayer/ospfv2/interface/*.cc networklayer/ospfv2/messagehandler/*.cc networklayer/ospfv2/neighbor/*.cc networklayer/ospfv2/router/*.cc networklayer/queue/*.cc networklayer/rsvp_te/*.cc networklayer/ted/*.cc nodes/*.cc nodes/adhoc/*.cc nodes/ethernet/*.cc nodes/inet/*.cc nodes/ipv6/*.cc nodes/mpls/*.cc nodes/wireless/*.cc transport/*.cc transport/contract/*.cc transport/observer/*.cc transport/rtp/*.cc transport/rtp/profiles/*.cc transport/rtp/profiles/avprofile/*.cc transport/sctp/*.cc transport/tcp/*.cc transport/tcp/flavours/*.cc transport/tcp/queues/*.cc transport/tcp/queues/test/*.cc transport/tcp/queues/test/config/*.cc transport/tcp_nsc/*.cc transport/tcp_nsc/queues/*.cc transport/tcp_old/*.cc transport/tcp_old/flavours/*.cc transport/tcp_old/queues/*.cc transport/udp/*.cc util/*.cc util/headerserializers/*.cc util/headerserializers/headers/*.cc world/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/applications/ethernet/EtherAppSrv.o: applications/ethernet/EtherAppSrv.cc \
	applications/ethernet/EtherApp_m.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	applications/ethernet/EtherAppSrv.h \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h
$O/applications/ethernet/EtherApp_m.o: applications/ethernet/EtherApp_m.cc \
	applications/ethernet/EtherApp_m.h \
	base/INETDefs.h
$O/applications/ethernet/EtherAppCli.o: applications/ethernet/EtherAppCli.cc \
	applications/ethernet/EtherAppCli.h \
	applications/ethernet/EtherApp_m.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h
$O/applications/generic/IPTrafGen.o: applications/generic/IPTrafGen.cc \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/contract/IPAddressResolver.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPControlInfo.h \
	applications/generic/IPTrafGen.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	networklayer/contract/IPControlInfo_m.h
$O/applications/pingapp/PingApp.o: applications/pingapp/PingApp.cc \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPAddressResolver.h \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPvXAddress.h \
	applications/pingapp/PingApp.h \
	networklayer/contract/IPv6Address.h \
	applications/pingapp/PingPayload_m.h \
	networklayer/contract/IPAddress.h \
	networklayer/contract/IPControlInfo_m.h
$O/applications/pingapp/PingPayload_m.o: applications/pingapp/PingPayload_m.cc \
	base/INETDefs.h \
	applications/pingapp/PingPayload_m.h
$O/applications/rtpapp/RTPApplication.o: applications/rtpapp/RTPApplication.cc \
	transport/rtp/RTPInterfacePacket.h \
	applications/rtpapp/RTPApplication.h \
	base/INETDefs.h \
	transport/rtp/RTPSenderControlMessage_m.h \
	networklayer/contract/IPAddress.h \
	transport/rtp/RTPSenderStatusMessage_m.h
$O/applications/sctpapp/SCTPServer.o: applications/sctpapp/SCTPServer.cc \
	networklayer/ipv4/RoutingTable.h \
	transport/contract/SCTPCommand_m.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	transport/sctp/SCTP.h \
	base/NotificationBoard.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTPAssociation.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/contract/IPControlInfo.h \
	base/INotifiable.h \
	transport/sctp/SCTPMessage.h \
	networklayer/ipv4/RoutingTableAccess.h \
	util/common.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	transport/contract/SCTPCommand.h \
	transport/contract/SCTPSocket.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	applications/sctpapp/SCTPServer.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/common/InterfaceTableAccess.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPMessage_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/contract/UDPControlInfo_m.h \
	transport/sctp/SCTPSendStream.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h
$O/applications/sctpapp/SCTPPeer.o: applications/sctpapp/SCTPPeer.cc \
	applications/sctpapp/SCTPPeer.h \
	networklayer/ipv4/RoutingTable.h \
	transport/contract/SCTPCommand_m.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	transport/sctp/SCTP.h \
	base/NotificationBoard.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTPAssociation.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/contract/IPControlInfo.h \
	base/INotifiable.h \
	transport/sctp/SCTPMessage.h \
	networklayer/ipv4/RoutingTableAccess.h \
	util/common.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	transport/contract/SCTPCommand.h \
	transport/contract/SCTPSocket.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/common/InterfaceTableAccess.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPMessage_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	transport/sctp/SCTPReceiveStream.h \
	networklayer/contract/IPAddressResolver.h \
	transport/contract/UDPControlInfo_m.h \
	transport/sctp/SCTPSendStream.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h
$O/applications/sctpapp/SCTPClient.o: applications/sctpapp/SCTPClient.cc \
	networklayer/ipv4/RoutingTable.h \
	transport/contract/SCTPCommand_m.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	transport/sctp/SCTP.h \
	base/NotificationBoard.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTPAssociation.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/common/InterfaceEntry.h \
	base/INotifiable.h \
	transport/sctp/SCTPMessage.h \
	networklayer/ipv4/RoutingTableAccess.h \
	util/common.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	transport/contract/SCTPCommand.h \
	transport/contract/SCTPSocket.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	applications/sctpapp/SCTPClient.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/common/InterfaceTableAccess.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPMessage_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	transport/sctp/SCTPReceiveStream.h \
	networklayer/contract/IPAddressResolver.h \
	transport/contract/UDPControlInfo_m.h \
	transport/sctp/SCTPSendStream.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h
$O/applications/tcpapp/TCPGenericSrvThread.o: applications/tcpapp/TCPGenericSrvThread.cc \
	transport/contract/TCPSocketMap.h \
	applications/tcpapp/TCPGenericSrvThread.h \
	applications/tcpapp/GenericAppMsg_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	applications/tcpapp/TCPSrvHostApp.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h
$O/applications/tcpapp/TCPGenericSrvApp.o: applications/tcpapp/TCPGenericSrvApp.cc \
	applications/tcpapp/GenericAppMsg_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	applications/tcpapp/TCPGenericSrvApp.h
$O/applications/tcpapp/TCPGenericCliAppBase.o: applications/tcpapp/TCPGenericCliAppBase.cc \
	networklayer/contract/IPAddressResolver.h \
	applications/tcpapp/GenericAppMsg_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	applications/tcpapp/TCPGenericCliAppBase.h
$O/applications/tcpapp/TCPSrvHostApp.o: applications/tcpapp/TCPSrvHostApp.cc \
	transport/contract/TCPSocketMap.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	applications/tcpapp/TCPSrvHostApp.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h
$O/applications/tcpapp/TCPSessionApp.o: applications/tcpapp/TCPSessionApp.cc \
	applications/tcpapp/TCPSessionApp.h \
	networklayer/contract/IPAddressResolver.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPCommand_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h
$O/applications/tcpapp/GenericAppMsg_m.o: applications/tcpapp/GenericAppMsg_m.cc \
	applications/tcpapp/GenericAppMsg_m.h \
	base/INETDefs.h
$O/applications/tcpapp/TCPBasicClientApp.o: applications/tcpapp/TCPBasicClientApp.cc \
	base/INETDefs.h \
	applications/tcpapp/TCPBasicClientApp.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	applications/tcpapp/TCPGenericCliAppBase.h
$O/applications/tcpapp/TCPSinkApp.o: applications/tcpapp/TCPSinkApp.cc \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	networklayer/contract/IPv6Address.h \
	applications/tcpapp/TCPSinkApp.h \
	networklayer/contract/IPAddress.h
$O/applications/tcpapp/TelnetApp.o: applications/tcpapp/TelnetApp.cc \
	applications/tcpapp/TelnetApp.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	applications/tcpapp/TCPGenericCliAppBase.h
$O/applications/tcpapp/TCPSpoof.o: applications/tcpapp/TCPSpoof.cc \
	transport/tcp/TCPSegment_m.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	transport/tcp/TCPSegment.h \
	networklayer/contract/IPAddressResolver.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	applications/tcpapp/TCPSpoof.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	networklayer/contract/IPControlInfo_m.h
$O/applications/tcpapp/TCPSessionApp2.o: applications/tcpapp/TCPSessionApp2.cc \
	applications/tcpapp/TCPSessionApp2.h \
	networklayer/contract/IPAddressResolver.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h
$O/applications/tcpapp/TCPEchoApp.o: applications/tcpapp/TCPEchoApp.cc \
	applications/tcpapp/TCPEchoApp.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h
$O/applications/tcpapp/socketapi/TCPSocketMgrAppUtils.o: applications/tcpapp/socketapi/TCPSocketMgrAppUtils.cc \
	transport/contract/TCPSocketMap.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	networklayer/contract/IPv6Address.h \
	applications/tcpapp/socketapi/TCPSocketMgrAppUtils.h \
	transport/contract/SocketTimeoutMsg_m.h \
	transport/contract/TCPSocketAPI_Inet.h \
	base/InternetTypeDefsWithStandardTypes.h \
	transport/contract/TCPSocketAPI_Base.h \
	transport/contract/TCPSocketExtension.h \
	networklayer/contract/IPAddressResolver.h \
	base/INETDefs.h \
	transport/contract/TCPSocketMgr.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPAddress.h
$O/applications/tcpapp/socketapi/TCPSAPIGenericSrvApp.o: applications/tcpapp/socketapi/TCPSAPIGenericSrvApp.cc \
	base/InternetTypeDefsWithStandardTypes.h \
	transport/contract/TCPSocketAPI_Base.h \
	applications/tcpapp/GenericAppMsg_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	applications/tcpapp/socketapi/TCPSAPIGenericSrvApp.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/contract/TCPSocketAPI_Inet.h
$O/applications/tcpapp/socketapi/AccessTCPSocketMgrApp.o: applications/tcpapp/socketapi/AccessTCPSocketMgrApp.cc \
	transport/contract/TCPSocketMap.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPCommand_m.h \
	networklayer/contract/IPv6Address.h \
	applications/tcpapp/socketapi/TCPSocketMgrAppUtils.h \
	transport/contract/SocketTimeoutMsg_m.h \
	transport/contract/TCPSocketAPI_Inet.h \
	base/InternetTypeDefsWithStandardTypes.h \
	transport/contract/TCPSocketAPI_Base.h \
	transport/contract/TCPSocketExtension.h \
	networklayer/contract/IPAddressResolver.h \
	applications/tcpapp/socketapi/AccessTCPSocketMgrApp.h \
	transport/contract/TCPSocketMgr.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPAddress.h
$O/applications/udpapp/UDPEchoApp.o: applications/udpapp/UDPEchoApp.cc \
	transport/contract/UDPControlInfo_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	applications/udpapp/UDPAppBase.h \
	applications/udpapp/UDPEchoApp.h \
	applications/udpapp/UDPBasicApp.h \
	applications/udpapp/UDPEchoAppMsg_m.h
$O/applications/udpapp/UDPSink.o: applications/udpapp/UDPSink.cc \
	networklayer/contract/IPAddressResolver.h \
	transport/contract/UDPControlInfo_m.h \
	applications/udpapp/UDPSink.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	applications/udpapp/UDPAppBase.h
$O/applications/udpapp/UDPBasicApp.o: applications/udpapp/UDPBasicApp.cc \
	networklayer/contract/IPAddressResolver.h \
	transport/contract/UDPControlInfo_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	applications/udpapp/UDPAppBase.h \
	applications/udpapp/UDPBasicApp.h
$O/applications/udpapp/UDPEchoAppMsg_m.o: applications/udpapp/UDPEchoAppMsg_m.cc \
	base/INETDefs.h \
	applications/udpapp/UDPEchoAppMsg_m.h
$O/applications/udpapp/UDPVideoStreamSvr.o: applications/udpapp/UDPVideoStreamSvr.cc \
	transport/contract/UDPControlInfo_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	applications/udpapp/UDPAppBase.h \
	applications/udpapp/UDPVideoStreamSvr.h
$O/applications/udpapp/UDPVideoStreamCli.o: applications/udpapp/UDPVideoStreamCli.cc \
	networklayer/contract/IPAddressResolver.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	applications/udpapp/UDPAppBase.h \
	applications/udpapp/UDPVideoStreamCli.h
$O/applications/udpapp/UDPAppBase.o: applications/udpapp/UDPAppBase.cc \
	transport/contract/UDPControlInfo_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	applications/udpapp/UDPAppBase.h \
	transport/contract/UDPSocket.h
$O/applications/xBitTorrent/BTPeerWireBase.o: applications/xBitTorrent/BTPeerWireBase.cc \
	transport/tcp/TCPSegment.h \
	applications/xBitTorrent/BTUtils.h \
	base/NotifierConsts.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	applications/xBitTorrent/BTPeerWireMsg_m.h \
	applications/xBitTorrent/BTTrackerMsg_m.h \
	transport/tcp/TCP.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	httptools/base/httptRandom.h \
	base/INotifiable.h \
	httptools/messages/httptEventMessages_m.h \
	httptools/messages/httptMessages_m.h \
	networklayer/contract/IPAddress.h \
	applications/xBitTorrent/BTPeerWireCacheThread.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	httptools/base/httptUtils.h \
	transport/tcp/TCPSegment_m.h \
	httptools/base/httptLogdefs.h \
	httptools/base/httptController.h \
	applications/xBitTorrent/BTStatisticsMsg_m.h \
	applications/xBitTorrent/BTPeerWireBase.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/TCPPortRangeDefs.h \
	applications/xBitTorrent/BTStatistics.h \
	httptools/messages/HTTPMsgDefs.h \
	applications/xBitTorrent/BitField.h \
	applications/xBitTorrent/BTPeerWireClientHandlerBase.h \
	httptools/base/httptServerBase.h \
	networklayer/contract/IPAddressResolver.h \
	httptools/base/httptNodeBase.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	applications/xBitTorrent/BTTrackerClientBase.h \
	networklayer/common/InterfaceTable.h
$O/applications/xBitTorrent/BTPeerWireMsg_m.o: applications/xBitTorrent/BTPeerWireMsg_m.cc \
	applications/xBitTorrent/BTTrackerMsg_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	applications/xBitTorrent/BTPeerWireMsg_m.h
$O/applications/xBitTorrent/BitField.o: applications/xBitTorrent/BitField.cc \
	applications/xBitTorrent/BTTrackerMsg_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	applications/xBitTorrent/BTPeerWireMsg_m.h \
	applications/xBitTorrent/BitField.h
$O/applications/xBitTorrent/BTTrackerClientBase.o: applications/xBitTorrent/BTTrackerClientBase.cc \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	applications/xBitTorrent/BTTrackerMsg_m.h \
	networklayer/contract/IPAddressResolver.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	base/INotifiable.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPAddress.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	networklayer/common/InterfaceTable.h \
	applications/xBitTorrent/BTTrackerClientBase.h \
	linklayer/contract/MACAddress.h
$O/applications/xBitTorrent/BTStatisticsMsg_m.o: applications/xBitTorrent/BTStatisticsMsg_m.cc \
	applications/xBitTorrent/BTStatisticsMsg_m.h
$O/applications/xBitTorrent/BTPeerWireCacheThread.o: applications/xBitTorrent/BTPeerWireCacheThread.cc \
	transport/tcp/TCPSegment.h \
	applications/xBitTorrent/BTUtils.h \
	base/NotifierConsts.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	applications/xBitTorrent/BTPeerWireMsg_m.h \
	applications/xBitTorrent/BTTrackerMsg_m.h \
	transport/tcp/TCP.h \
	networklayer/common/InterfaceToken.h \
	httptools/base/httptRandom.h \
	networklayer/common/InterfaceEntry.h \
	base/INotifiable.h \
	httptools/messages/httptEventMessages_m.h \
	httptools/messages/httptMessages_m.h \
	networklayer/contract/IPAddress.h \
	applications/xBitTorrent/BTPeerWireCacheThread.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	httptools/base/httptUtils.h \
	transport/tcp/TCPSegment_m.h \
	httptools/base/httptLogdefs.h \
	applications/xBitTorrent/BTStatisticsMsg_m.h \
	httptools/base/httptController.h \
	applications/xBitTorrent/BTPeerWireBase.h \
	transport/tcp/TCPConnection.h \
	applications/xBitTorrent/BTStatistics.h \
	transport/tcp/TCPPortRangeDefs.h \
	httptools/messages/HTTPMsgDefs.h \
	applications/xBitTorrent/BitField.h \
	applications/xBitTorrent/BTPeerWireClientHandlerBase.h \
	httptools/base/httptServerBase.h \
	networklayer/contract/IPAddressResolver.h \
	httptools/base/httptNodeBase.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h \
	applications/xBitTorrent/BTTrackerClientBase.h
$O/applications/xBitTorrent/HttpVideoServer.o: applications/xBitTorrent/HttpVideoServer.cc \
	transport/tcp/TCPSegment.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	base/InternetTypeDefsWithStandardTypes.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	base/INotifiable.h \
	httptools/messages/httptEventMessages_m.h \
	httptools/messages/httptMessages_m.h \
	networklayer/contract/IPAddress.h \
	transport/contract/TCPSocketMap.h \
	httptools/base/httptLogdefs.h \
	applications/xBitTorrent/BTStatisticsMsg_m.h \
	httptools/base/httptController.h \
	applications/xBitTorrent/BTPeerWireBase.h \
	transport/tcp/TCPConnection.h \
	applications/xBitTorrent/BTStatistics.h \
	transport/contract/SocketTimeoutMsg_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	applications/xBitTorrent/BTUtils.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	applications/xBitTorrent/BTPeerWireMsg_m.h \
	applications/xBitTorrent/BTTrackerMsg_m.h \
	transport/contract/TCPSocketExtension.h \
	transport/tcp/TCP.h \
	httptools/base/httptRandom.h \
	transport/contract/TCPSocketMgr.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	httptools/base/httptUtils.h \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCPPortRangeDefs.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPCommand_m.h \
	applications/tcpapp/socketapi/TCPSocketMgrAppUtils.h \
	applications/xBitTorrent/BitField.h \
	httptools/messages/HTTPMsgDefs.h \
	applications/xBitTorrent/BTPeerWireClientHandlerBase.h \
	transport/contract/TCPSocketAPI_Inet.h \
	httptools/base/httptServerBase.h \
	transport/contract/TCPSocketAPI_Base.h \
	networklayer/contract/IPAddressResolver.h \
	httptools/base/httptNodeBase.h \
	applications/xBitTorrent/HttpVideoServer.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h \
	applications/xBitTorrent/BTTrackerClientBase.h
$O/applications/xBitTorrent/BTTrackerMsg_m.o: applications/xBitTorrent/BTTrackerMsg_m.cc \
	applications/xBitTorrent/BTTrackerMsg_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h
$O/applications/xBitTorrent/BTStatistics.o: applications/xBitTorrent/BTStatistics.cc \
	applications/xBitTorrent/BTStatisticsMsg_m.h \
	applications/xBitTorrent/BTStatistics.h
$O/applications/xBitTorrent/BTPeerWireClientHandlerBase.o: applications/xBitTorrent/BTPeerWireClientHandlerBase.cc \
	transport/tcp/TCPSegment.h \
	applications/xBitTorrent/BTUtils.h \
	base/NotifierConsts.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	applications/xBitTorrent/BTPeerWireMsg_m.h \
	applications/xBitTorrent/BTTrackerMsg_m.h \
	transport/tcp/TCP.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	httptools/base/httptRandom.h \
	base/INotifiable.h \
	httptools/messages/httptEventMessages_m.h \
	httptools/messages/httptMessages_m.h \
	networklayer/contract/IPAddress.h \
	applications/xBitTorrent/BTPeerWireCacheThread.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	httptools/base/httptUtils.h \
	transport/tcp/TCPSegment_m.h \
	httptools/base/httptLogdefs.h \
	httptools/base/httptController.h \
	applications/xBitTorrent/BTStatisticsMsg_m.h \
	applications/xBitTorrent/BTPeerWireBase.h \
	transport/tcp/TCPConnection.h \
	applications/xBitTorrent/BTStatistics.h \
	transport/tcp/TCPPortRangeDefs.h \
	httptools/messages/HTTPMsgDefs.h \
	applications/xBitTorrent/BitField.h \
	applications/xBitTorrent/BTPeerWireClientHandlerBase.h \
	httptools/base/httptServerBase.h \
	networklayer/contract/IPAddressResolver.h \
	httptools/base/httptNodeBase.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	applications/xBitTorrent/BTTrackerClientBase.h \
	networklayer/common/InterfaceTable.h
$O/applications/xBitTorrent/BTUtils.o: applications/xBitTorrent/BTUtils.cc \
	transport/tcp/TCPSegment.h \
	applications/xBitTorrent/BTUtils.h \
	base/NotifierConsts.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	applications/xBitTorrent/BTPeerWireMsg_m.h \
	applications/xBitTorrent/BTTrackerMsg_m.h \
	transport/tcp/TCP.h \
	networklayer/common/InterfaceToken.h \
	httptools/base/httptRandom.h \
	networklayer/common/InterfaceEntry.h \
	base/INotifiable.h \
	httptools/messages/httptEventMessages_m.h \
	httptools/messages/httptMessages_m.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	httptools/base/httptUtils.h \
	transport/tcp/TCPSegment_m.h \
	httptools/base/httptLogdefs.h \
	httptools/base/httptController.h \
	applications/xBitTorrent/BTStatisticsMsg_m.h \
	applications/xBitTorrent/BTPeerWireBase.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/TCPPortRangeDefs.h \
	applications/xBitTorrent/BTStatistics.h \
	applications/xBitTorrent/BitField.h \
	httptools/messages/HTTPMsgDefs.h \
	applications/xBitTorrent/BTPeerWireClientHandlerBase.h \
	httptools/base/httptServerBase.h \
	networklayer/contract/IPAddressResolver.h \
	httptools/base/httptNodeBase.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h \
	applications/xBitTorrent/BTTrackerClientBase.h
$O/applications/xBitTorrent/BTCache.o: applications/xBitTorrent/BTCache.cc \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	networklayer/contract/IPv6Address.h \
	httptools/cache/webcache/ds/LRUCache.h \
	transport/tcp/TCP.h \
	httptools/cache/base/ds/Cache.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	httptools/messages/httptMessages_m.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	httptools/base/httptUtils.h \
	httptools/base/httptLogdefs.h \
	transport/contract/TCPSocketMap.h \
	applications/xBitTorrent/BTStatisticsMsg_m.h \
	httptools/base/httptController.h \
	applications/xBitTorrent/BTCache.h \
	transport/contract/TCPSocket.h \
	applications/xBitTorrent/BTStatistics.h \
	transport/tcp/TCPPortRangeDefs.h \
	transport/contract/TCPCommand_m.h \
	httptools/messages/HTTPMsgDefs.h \
	httptools/base/httptServerBase.h \
	networklayer/contract/IPAddressResolver.h \
	base/INETDefs.h \
	httptools/base/httptNodeBase.h \
	networklayer/contract/IPvXAddress.h \
	httptools/cache/webcache/ds/WebResource.h \
	httptools/cache/base/ds/Resource.h \
	base/ModuleAccess.h
$O/applications/xBitTorrent/BTTrackerBase.o: applications/xBitTorrent/BTTrackerBase.cc \
	applications/xBitTorrent/BTTrackerMsg_m.h \
	applications/xBitTorrent/BTTrackerBase.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h
$O/base/QueueBase.o: base/QueueBase.cc \
	base/AbstractQueue.h \
	base/INETDefs.h \
	base/QueueBase.h
$O/base/Join.o: base/Join.cc \
	base/INETDefs.h
$O/base/QueueWithQoS.o: base/QueueWithQoS.cc \
	base/EnqueueHook.h \
	base/AbstractQueue.h \
	base/INETDefs.h \
	base/QueueWithQoS.h
$O/base/ReassemblyBuffer.o: base/ReassemblyBuffer.cc \
	base/INETDefs.h \
	base/ReassemblyBuffer.h
$O/base/Blackboard.o: base/Blackboard.cc \
	base/INETDefs.h \
	base/Blackboard.h \
	base/ModuleAccess.h
$O/base/NotificationBoard.o: base/NotificationBoard.cc \
	base/INotifiable.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	base/NotificationBoard.h \
	base/ModuleAccess.h
$O/base/Sink.o: base/Sink.cc \
	base/Sink.h \
	base/INETDefs.h
$O/base/BasicModule.o: base/BasicModule.cc \
	base/BasicModule.h \
	base/INotifiable.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	base/NotificationBoard.h \
	base/ModuleAccess.h
$O/base/NotifierConsts.o: base/NotifierConsts.cc \
	base/NotifierConsts.h \
	base/INETDefs.h
$O/base/AbstractQueue.o: base/AbstractQueue.cc \
	base/AbstractQueue.h \
	base/INETDefs.h
$O/base/PassiveQueueBase.o: base/PassiveQueueBase.cc \
	base/IPassiveQueue.h \
	base/INETDefs.h \
	base/PassiveQueueBase.h
$O/base/ByteArrayMessage.o: base/ByteArrayMessage.cc \
	base/ByteArrayMessage.h \
	base/INETDefs.h \
	base/ByteArrayMessage_m.h
$O/base/ModuleAccess.o: base/ModuleAccess.cc \
	base/INETDefs.h \
	base/ModuleAccess.h
$O/base/ProtocolMap.o: base/ProtocolMap.cc \
	base/ProtocolMap.h \
	base/INETDefs.h
$O/base/ByteArrayMessage_m.o: base/ByteArrayMessage_m.cc \
	base/INETDefs.h \
	base/ByteArrayMessage_m.h
$O/httptools/base/httptUtils.o: httptools/base/httptUtils.cc \
	httptools/base/httptUtils.h \
	httptools/messages/httptMessages_m.h \
	httptools/messages/HTTPMsgDefs.h
$O/httptools/base/httptRandom.o: httptools/base/httptRandom.cc \
	httptools/base/httptUtils.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptMessages_m.h \
	httptools/messages/HTTPMsgDefs.h
$O/httptools/base/httptNodeBase.o: httptools/base/httptNodeBase.cc \
	httptools/base/httptUtils.h \
	httptools/base/httptLogdefs.h \
	httptools/base/httptController.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	base/INETDefs.h \
	httptools/base/httptNodeBase.h \
	httptools/messages/httptMessages_m.h \
	httptools/messages/HTTPMsgDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h
$O/httptools/base/httptController.o: httptools/base/httptController.cc \
	httptools/base/httptUtils.h \
	httptools/base/httptLogdefs.h \
	httptools/base/httptController.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	httptools/messages/httptMessages_m.h \
	httptools/messages/HTTPMsgDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h
$O/httptools/base/WebContentExtensionFilter.o: httptools/base/WebContentExtensionFilter.cc \
	httptools/base/httptUtils.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/xmlio/XMLIO.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/xmlio/XMLScanner.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/xmlio/XMLText.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/xmlio/XMLToken.h \
	httptools/base/WebContentExtensionFilter.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/xmlio/XMLTokenType.h \
	httptools/messages/HTTPMsgDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/xmlio/XMLConstants.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/xmlio/XMLEntity.h \
	httptools/messages/httptMessages_m.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/xmlio/XMLTag.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/xmlio/XMLWriter.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/xmlio/XMLTagType.h
$O/httptools/base/httptServerBase.o: httptools/base/httptServerBase.cc \
	httptools/base/httptUtils.h \
	httptools/base/httptLogdefs.h \
	httptools/base/httptController.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	transport/tcp/TCPPortRangeDefs.h \
	httptools/messages/HTTPMsgDefs.h \
	httptools/base/httptServerBase.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	httptools/base/httptNodeBase.h \
	base/INETDefs.h \
	httptools/messages/httptMessages_m.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h
$O/httptools/cache/webcache/ds/LRUCache.o: httptools/cache/webcache/ds/LRUCache.cc \
	httptools/base/httptLogdefs.h \
	httptools/cache/base/ds/Cache.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	httptools/cache/webcache/ds/LRUCache.h \
	httptools/cache/base/ds/Resource.h
$O/httptools/cache/webcache/ds/WebResource.o: httptools/cache/webcache/ds/WebResource.cc \
	httptools/cache/webcache/ds/WebResource.h \
	httptools/cache/base/ds/Resource.h
$O/httptools/cache/webcache/ds/CacheRequestMgr.o: httptools/cache/webcache/ds/CacheRequestMgr.cc \
	httptools/messages/httptMessages_m.h \
	httptools/messages/HTTPMsgDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	httptools/cache/webcache/ds/CacheRequestMgr.h
$O/httptools/cache/webcache/mod/WebCacheNewAPI.o: httptools/cache/webcache/mod/WebCacheNewAPI.cc \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/xmlio/XMLConstants.h \
	httptools/messages/URIVarientSimTimeMap.h \
	base/InternetTypeDefsWithStandardTypes.h \
	httptools/cache/base/ds/Cache.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/sim/cobserver.h \
	httptools/messages/httptEventMessages_m.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/xmlio/XMLTag.h \
	httptools/messages/httptMessages_m.h \
	networklayer/contract/IPAddress.h \
	httptools/messages/observer/DuplicateHttpMessageNameObserver.h \
	transport/contract/ActiveTCPSocketPool.h \
	transport/contract/TCPSocketMap.h \
	httptools/base/httptLogdefs.h \
	httptools/base/httptController.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/common/StringIntKey.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/xmlio/XMLText.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/xmlio/XMLTokenType.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/sim/cmessageeventobserver.h \
	transport/contract/SocketTimeoutMsg_m.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/envir/dynamicresultrecorder.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	httptools/cache/base/ds/Resource.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/xmlio/XMLWriter.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/xmlio/XMLScanner.h \
	httptools/messages/observer/DuplicateRecord.h \
	networklayer/contract/IPv6Address.h \
	httptools/cache/webcache/ds/LRUCache.h \
	httptools/cache/webcache/ds/CacheRequestMgr.h \
	transport/contract/TCPSocketExtension.h \
	httptools/base/httptRandom.h \
	transport/contract/TCPSocketMgr.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/xmlio/XMLEntity.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	httptools/base/httptUtils.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/xmlio/XMLIO.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/xmlio/XMLToken.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/EnforceSingleClassInstanceDefs.h \
	httptools/base/WebContentExtensionFilter.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCPPortRangeDefs.h \
	applications/tcpapp/socketapi/TCPSocketMgrAppUtils.h \
	httptools/messages/HTTPMsgDefs.h \
	transport/contract/TCPSocketAPI_Inet.h \
	transport/contract/TCPSocketAPI_Base.h \
	httptools/base/httptServerBase.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/simunits.h \
	networklayer/contract/IPAddressResolver.h \
	httptools/base/httptNodeBase.h \
	httptools/cache/webcache/mod/WebCacheNewAPI.h \
	httptools/cache/webcache/ds/WebResource.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/xmlio/XMLTagType.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/omnetppextension.h
$O/httptools/cache/webcache/mod/WebCache.o: httptools/cache/webcache/mod/WebCache.cc \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	networklayer/contract/IPv6Address.h \
	httptools/cache/webcache/ds/LRUCache.h \
	httptools/cache/base/ds/Cache.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	httptools/htmlcomponents/httptHTMLServer.h \
	httptools/messages/httptMessages_m.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	httptools/base/httptUtils.h \
	transport/contract/TCPSocketMap.h \
	httptools/cache/webcache/mod/WebCache.h \
	httptools/base/httptLogdefs.h \
	httptools/base/httptController.h \
	transport/tcp/TCPPortRangeDefs.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	httptools/messages/HTTPMsgDefs.h \
	httptools/base/httptServerBase.h \
	networklayer/contract/IPAddressResolver.h \
	httptools/base/httptNodeBase.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	httptools/htmlcomponents/httptHTMLServerBase.h \
	httptools/cache/webcache/ds/WebResource.h \
	base/ModuleAccess.h \
	httptools/cache/base/ds/Resource.h
$O/httptools/cache/webcache/test/byterange/ByteRangeClient.o: httptools/cache/webcache/test/byterange/ByteRangeClient.cc \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	networklayer/contract/IPv6Address.h \
	base/InternetTypeDefsWithStandardTypes.h \
	transport/contract/TCPSocketExtension.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	transport/contract/TCPSocketMgr.h \
	httptools/messages/httptMessages_m.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	httptools/base/httptUtils.h \
	transport/contract/TCPSocketMap.h \
	httptools/base/httptLogdefs.h \
	httptools/base/httptController.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	applications/tcpapp/socketapi/TCPSocketMgrAppUtils.h \
	httptools/messages/HTTPMsgDefs.h \
	transport/contract/SocketTimeoutMsg_m.h \
	transport/contract/TCPSocketAPI_Inet.h \
	httptools/cache/webcache/test/byterange/ByteRangeClient.h \
	transport/contract/TCPSocketAPI_Base.h \
	networklayer/contract/IPAddressResolver.h \
	httptools/base/httptNodeBase.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h
$O/httptools/cache/webcache/test/byterange/DummyServer.o: httptools/cache/webcache/test/byterange/DummyServer.cc \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	networklayer/contract/IPv6Address.h \
	base/InternetTypeDefsWithStandardTypes.h \
	transport/contract/TCPSocketExtension.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	transport/contract/TCPSocketMgr.h \
	httptools/messages/httptMessages_m.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	httptools/base/httptUtils.h \
	httptools/cache/webcache/test/byterange/DummyServer.h \
	httptools/base/httptLogdefs.h \
	transport/contract/TCPSocketMap.h \
	httptools/base/httptController.h \
	transport/tcp/TCPPortRangeDefs.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	applications/tcpapp/socketapi/TCPSocketMgrAppUtils.h \
	httptools/messages/HTTPMsgDefs.h \
	transport/contract/SocketTimeoutMsg_m.h \
	transport/contract/TCPSocketAPI_Inet.h \
	httptools/base/httptServerBase.h \
	transport/contract/TCPSocketAPI_Base.h \
	networklayer/contract/IPAddressResolver.h \
	httptools/base/httptNodeBase.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h
$O/httptools/htmlcomponents/httptHTMLServerEvilB.o: httptools/htmlcomponents/httptHTMLServerEvilB.cc \
	httptools/base/httptUtils.h \
	httptools/base/httptLogdefs.h \
	transport/contract/TCPSocketMap.h \
	httptools/base/httptController.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	transport/tcp/TCPPortRangeDefs.h \
	httptools/htmlcomponents/httptHTMLServerEvilB.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	networklayer/contract/IPv6Address.h \
	httptools/messages/HTTPMsgDefs.h \
	httptools/base/httptServerBase.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	httptools/base/httptNodeBase.h \
	base/INETDefs.h \
	httptools/htmlcomponents/httptHTMLServer.h \
	networklayer/contract/IPvXAddress.h \
	httptools/messages/httptMessages_m.h \
	httptools/htmlcomponents/httptHTMLServerBase.h \
	networklayer/contract/IPAddress.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h
$O/httptools/htmlcomponents/httptHTMLServerDirectEvilB.o: httptools/htmlcomponents/httptHTMLServerDirectEvilB.cc \
	httptools/htmlcomponents/httptHTMLServerDirect.h \
	httptools/base/httptUtils.h \
	httptools/base/httptLogdefs.h \
	httptools/htmlcomponents/httptHTMLServerDirectEvilB.h \
	httptools/base/httptController.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	transport/tcp/TCPPortRangeDefs.h \
	httptools/messages/HTTPMsgDefs.h \
	httptools/base/httptServerBase.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	httptools/base/httptNodeBase.h \
	base/INETDefs.h \
	httptools/messages/httptMessages_m.h \
	httptools/htmlcomponents/httptHTMLServerBase.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h
$O/httptools/htmlcomponents/httptHTMLServerDirectEvilA.o: httptools/htmlcomponents/httptHTMLServerDirectEvilA.cc \
	httptools/htmlcomponents/httptHTMLServerDirect.h \
	httptools/base/httptUtils.h \
	httptools/base/httptLogdefs.h \
	httptools/base/httptController.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	transport/tcp/TCPPortRangeDefs.h \
	httptools/messages/HTTPMsgDefs.h \
	httptools/htmlcomponents/httptHTMLServerDirectEvilA.h \
	httptools/base/httptServerBase.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	httptools/base/httptNodeBase.h \
	base/INETDefs.h \
	httptools/messages/httptMessages_m.h \
	httptools/htmlcomponents/httptHTMLServerBase.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h
$O/httptools/htmlcomponents/httptHTMLServerEvilA.o: httptools/htmlcomponents/httptHTMLServerEvilA.cc \
	httptools/base/httptUtils.h \
	httptools/base/httptLogdefs.h \
	transport/contract/TCPSocketMap.h \
	httptools/base/httptController.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	transport/tcp/TCPPortRangeDefs.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPCommand_m.h \
	networklayer/contract/IPv6Address.h \
	httptools/messages/HTTPMsgDefs.h \
	httptools/base/httptServerBase.h \
	httptools/htmlcomponents/httptHTMLServerEvilA.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	httptools/base/httptNodeBase.h \
	base/INETDefs.h \
	httptools/htmlcomponents/httptHTMLServer.h \
	networklayer/contract/IPvXAddress.h \
	httptools/messages/httptMessages_m.h \
	httptools/htmlcomponents/httptHTMLServerBase.h \
	networklayer/contract/IPAddress.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h
$O/httptools/htmlcomponents/httptHTMLServerBase.o: httptools/htmlcomponents/httptHTMLServerBase.cc \
	httptools/base/httptUtils.h \
	httptools/base/httptLogdefs.h \
	httptools/base/httptController.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	transport/tcp/TCPPortRangeDefs.h \
	httptools/messages/HTTPMsgDefs.h \
	httptools/base/httptServerBase.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	base/INETDefs.h \
	httptools/base/httptNodeBase.h \
	httptools/messages/httptMessages_m.h \
	httptools/htmlcomponents/httptHTMLServerBase.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h
$O/httptools/htmlcomponents/httptBrowser.o: httptools/htmlcomponents/httptBrowser.cc \
	httptools/base/httptUtils.h \
	httptools/htmlcomponents/httptBrowser.h \
	transport/contract/TCPSocketMap.h \
	httptools/base/httptLogdefs.h \
	httptools/base/httptController.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPCommand_m.h \
	networklayer/contract/IPv6Address.h \
	httptools/messages/HTTPMsgDefs.h \
	networklayer/contract/IPAddressResolver.h \
	httptools/htmlcomponents/httptBrowserBase.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	base/INETDefs.h \
	httptools/base/httptNodeBase.h \
	networklayer/contract/IPvXAddress.h \
	httptools/messages/httptMessages_m.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h
$O/httptools/htmlcomponents/httptHTMLServerDirect.o: httptools/htmlcomponents/httptHTMLServerDirect.cc \
	httptools/htmlcomponents/httptHTMLServerDirect.h \
	httptools/base/httptUtils.h \
	httptools/base/httptLogdefs.h \
	httptools/base/httptController.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	transport/tcp/TCPPortRangeDefs.h \
	httptools/messages/HTTPMsgDefs.h \
	httptools/base/httptServerBase.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	httptools/base/httptNodeBase.h \
	base/INETDefs.h \
	httptools/messages/httptMessages_m.h \
	httptools/htmlcomponents/httptHTMLServerBase.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h
$O/httptools/htmlcomponents/httptHTMLServer.o: httptools/htmlcomponents/httptHTMLServer.cc \
	httptools/base/httptUtils.h \
	transport/contract/TCPSocketMap.h \
	httptools/base/httptLogdefs.h \
	httptools/base/httptController.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	transport/tcp/TCPPortRangeDefs.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPCommand_m.h \
	networklayer/contract/IPv6Address.h \
	httptools/messages/HTTPMsgDefs.h \
	httptools/base/httptServerBase.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	httptools/base/httptNodeBase.h \
	base/INETDefs.h \
	httptools/htmlcomponents/httptHTMLServer.h \
	networklayer/contract/IPvXAddress.h \
	httptools/messages/httptMessages_m.h \
	httptools/htmlcomponents/httptHTMLServerBase.h \
	networklayer/contract/IPAddress.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h
$O/httptools/htmlcomponents/httptBrowserBase.o: httptools/htmlcomponents/httptBrowserBase.cc \
	httptools/base/httptUtils.h \
	httptools/base/httptLogdefs.h \
	httptools/base/httptController.h \
	httptools/base/httptRandom.h \
	httptools/htmlcomponents/httptBrowserBase.h \
	httptools/messages/httptEventMessages_m.h \
	httptools/base/httptNodeBase.h \
	base/INETDefs.h \
	httptools/messages/httptMessages_m.h \
	httptools/messages/HTTPMsgDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h
$O/httptools/htmlcomponents/httptBrowserDirect.o: httptools/htmlcomponents/httptBrowserDirect.cc \
	httptools/base/httptUtils.h \
	httptools/base/httptLogdefs.h \
	httptools/base/httptController.h \
	httptools/base/httptRandom.h \
	httptools/htmlcomponents/httptBrowserBase.h \
	httptools/messages/httptEventMessages_m.h \
	base/INETDefs.h \
	httptools/base/httptNodeBase.h \
	httptools/messages/httptMessages_m.h \
	httptools/messages/HTTPMsgDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	httptools/htmlcomponents/httptBrowserDirect.h
$O/httptools/messages/httptMessages_m.o: httptools/messages/httptMessages_m.cc \
	httptools/messages/httptMessages_m.h \
	httptools/messages/HTTPMsgDefs.h
$O/httptools/messages/httptEventMessages_m.o: httptools/messages/httptEventMessages_m.cc \
	httptools/messages/httptEventMessages_m.h
$O/httptools/messages/observer/DuplicateHttpMessageNameObserver.o: httptools/messages/observer/DuplicateHttpMessageNameObserver.cc \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/simunits.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/common/stdstringutils.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/sim/cobserver.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/EnforceSingleClassInstanceDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	httptools/messages/observer/DuplicateRecord.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/sim/cmessageeventobserver.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/omnetppextension.h \
	httptools/messages/observer/DuplicateHttpMessageNameObserver.h
$O/httptools/messages/observer/DuplicateRecord.o: httptools/messages/observer/DuplicateRecord.cc \
	httptools/messages/observer/DuplicateRecord.h
$O/httptools/videocomponents/client/application/DashState.o: httptools/videocomponents/client/application/DashState.cc \
	httptools/videocomponents/client/application/DashController.h \
	httptools/videocomponents/client/network/INetworkControl.h \
	httptools/videocomponents/client/network/Job.h \
	httptools/videocomponents/client/modules/IModule.h \
	httptools/videocomponents/client/application/IApplicationControl.h \
	httptools/videocomponents/client/application/DashState.h
$O/httptools/videocomponents/client/application/IApplicationControl.o: httptools/videocomponents/client/application/IApplicationControl.cc \
	httptools/videocomponents/client/network/INetworkControl.h \
	httptools/videocomponents/client/network/Job.h \
	httptools/videocomponents/client/modules/IModule.h \
	httptools/videocomponents/client/application/IApplicationControl.h
$O/httptools/videocomponents/client/application/NetworkMonitor.o: httptools/videocomponents/client/application/NetworkMonitor.cc \
	httptools/videocomponents/client/application/NetworkMonitor.h
$O/httptools/videocomponents/client/application/VideoPlayback.o: httptools/videocomponents/client/application/VideoPlayback.cc \
	httptools/videocomponents/client/application/ActiveRegion.h \
	httptools/videocomponents/client/application/codec/Codec.h \
	httptools/videocomponents/client/application/VideoPlayback.h
$O/httptools/videocomponents/client/application/DashController.o: httptools/videocomponents/client/application/DashController.cc \
	httptools/videocomponents/client/application/DashController.h \
	httptools/videocomponents/client/network/INetworkControl.h \
	httptools/videocomponents/client/network/Job.h \
	httptools/videocomponents/client/modules/IModule.h \
	httptools/videocomponents/client/application/IApplicationControl.h \
	httptools/videocomponents/client/application/DashState.h
$O/httptools/videocomponents/client/application/ActiveRegion.o: httptools/videocomponents/client/application/ActiveRegion.cc \
	httptools/videocomponents/client/application/ActiveRegion.h \
	httptools/videocomponents/client/application/codec/Codec.h \
	httptools/videocomponents/client/application/NetworkMonitor.h \
	httptools/videocomponents/client/application/VideoPlayback.h
$O/httptools/videocomponents/client/application/AdditiveController.o: httptools/videocomponents/client/application/AdditiveController.cc \
	httptools/videocomponents/client/application/AdditiveController.h \
	httptools/videocomponents/client/application/policy/NonAdditivePolicy.h \
	httptools/videocomponents/client/network/Job.h \
	httptools/videocomponents/client/modules/IModule.h \
	httptools/videocomponents/client/application/policy/DiagonalPolicy.h \
	httptools/videocomponents/client/application/VideoPlayback.h \
	httptools/videocomponents/client/application/policy/VerticalPolicy.h \
	httptools/videocomponents/client/application/policy/HorizontalPolicy.h \
	httptools/videocomponents/client/network/INetworkControl.h \
	httptools/videocomponents/client/application/codec/NonAdditiveCodec.h \
	httptools/videocomponents/client/application/policy/IPolicy.h \
	httptools/videocomponents/client/application/ActiveRegion.h \
	httptools/videocomponents/client/application/NetworkMonitor.h \
	httptools/videocomponents/client/application/IApplicationControl.h \
	httptools/videocomponents/client/application/codec/Codec.h \
	httptools/videocomponents/client/application/policy/MeanVerticalPolicy.h \
	httptools/videocomponents/client/application/codec/AdditiveCodec.h
$O/httptools/videocomponents/client/application/codec/AdditiveCodec.o: httptools/videocomponents/client/application/codec/AdditiveCodec.cc \
	httptools/videocomponents/client/application/ActiveRegion.h \
	httptools/videocomponents/client/application/codec/Codec.h \
	httptools/videocomponents/client/application/codec/AdditiveCodec.h
$O/httptools/videocomponents/client/application/codec/NonAdditiveCodec.o: httptools/videocomponents/client/application/codec/NonAdditiveCodec.cc \
	httptools/videocomponents/client/application/codec/NonAdditiveCodec.h \
	httptools/videocomponents/client/application/ActiveRegion.h \
	httptools/videocomponents/client/application/codec/Codec.h
$O/httptools/videocomponents/client/application/codec/Codec.o: httptools/videocomponents/client/application/codec/Codec.cc \
	httptools/videocomponents/client/application/codec/Codec.h
$O/httptools/videocomponents/client/application/policy/DiagonalPolicy.o: httptools/videocomponents/client/application/policy/DiagonalPolicy.cc \
	httptools/videocomponents/client/application/policy/IPolicy.h \
	httptools/videocomponents/client/application/ActiveRegion.h \
	httptools/videocomponents/client/application/NetworkMonitor.h \
	httptools/videocomponents/client/application/codec/Codec.h \
	httptools/videocomponents/client/application/policy/DiagonalPolicy.h \
	httptools/videocomponents/client/application/VideoPlayback.h
$O/httptools/videocomponents/client/application/policy/MeanVerticalPolicy.o: httptools/videocomponents/client/application/policy/MeanVerticalPolicy.cc \
	httptools/videocomponents/client/application/policy/IPolicy.h \
	httptools/videocomponents/client/application/ActiveRegion.h \
	httptools/videocomponents/client/application/codec/Codec.h \
	httptools/videocomponents/client/application/NetworkMonitor.h \
	httptools/videocomponents/client/application/policy/MeanVerticalPolicy.h \
	httptools/videocomponents/client/application/VideoPlayback.h
$O/httptools/videocomponents/client/application/policy/HorizontalPolicy.o: httptools/videocomponents/client/application/policy/HorizontalPolicy.cc \
	httptools/videocomponents/client/application/policy/IPolicy.h \
	httptools/videocomponents/client/application/ActiveRegion.h \
	httptools/videocomponents/client/application/NetworkMonitor.h \
	httptools/videocomponents/client/application/codec/Codec.h \
	httptools/videocomponents/client/application/VideoPlayback.h \
	httptools/videocomponents/client/application/policy/HorizontalPolicy.h
$O/httptools/videocomponents/client/application/policy/IPolicy.o: httptools/videocomponents/client/application/policy/IPolicy.cc \
	httptools/videocomponents/client/application/policy/IPolicy.h \
	httptools/videocomponents/client/application/ActiveRegion.h \
	httptools/videocomponents/client/application/NetworkMonitor.h \
	httptools/videocomponents/client/application/codec/Codec.h \
	httptools/videocomponents/client/application/VideoPlayback.h
$O/httptools/videocomponents/client/application/policy/NonAdditivePolicy.o: httptools/videocomponents/client/application/policy/NonAdditivePolicy.cc \
	httptools/videocomponents/client/application/policy/NonAdditivePolicy.h \
	httptools/videocomponents/client/application/policy/IPolicy.h \
	httptools/videocomponents/client/application/ActiveRegion.h \
	httptools/videocomponents/client/application/codec/Codec.h \
	httptools/videocomponents/client/application/NetworkMonitor.h \
	httptools/videocomponents/client/application/VideoPlayback.h
$O/httptools/videocomponents/client/application/policy/VerticalPolicy.o: httptools/videocomponents/client/application/policy/VerticalPolicy.cc \
	httptools/videocomponents/client/application/policy/IPolicy.h \
	httptools/videocomponents/client/application/ActiveRegion.h \
	httptools/videocomponents/client/application/codec/Codec.h \
	httptools/videocomponents/client/application/NetworkMonitor.h \
	httptools/videocomponents/client/application/VideoPlayback.h \
	httptools/videocomponents/client/application/policy/VerticalPolicy.h
$O/httptools/videocomponents/client/modules/IModule.o: httptools/videocomponents/client/modules/IModule.cc \
	httptools/videocomponents/client/modules/IModule.h
$O/httptools/videocomponents/client/modules/AdaptiveClient.o: httptools/videocomponents/client/modules/AdaptiveClient.cc \
	httptools/videocomponents/client/network/Worker.h \
	transport/tcp/queues/MsgByteBuffer.h \
	transport/tcp/TCPSegment.h \
	networklayer/contract/IPv6Address.h \
	base/InternetTypeDefsWithStandardTypes.h \
	transport/contract/TCPSocketExtension.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	transport/contract/TCPSocketMgr.h \
	httptools/messages/httptMessages_m.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	httptools/base/httptUtils.h \
	transport/contract/TCPSocketMap.h \
	httptools/base/httptLogdefs.h \
	transport/tcp/TCPSegment_m.h \
	httptools/base/httptController.h \
	httptools/videocomponents/client/network/Job.h \
	httptools/videocomponents/client/network/NetworkController.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPCommand_m.h \
	httptools/videocomponents/client/modules/IModule.h \
	httptools/videocomponents/client/modules/AdaptiveClient.h \
	httptools/messages/HTTPMsgDefs.h \
	transport/contract/SocketTimeoutMsg_m.h \
	transport/tcp/queues/MsgByteBuffer_m.h \
	transport/contract/TCPSocketAPI_Inet.h \
	transport/contract/TCPSocketAPI_Base.h \
	httptools/videocomponents/client/network/INetworkControl.h \
	networklayer/contract/IPAddressResolver.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	httptools/videocomponents/client/application/IApplicationControl.h \
	base/ModuleAccess.h
$O/httptools/videocomponents/client/modules/DASHClient.o: httptools/videocomponents/client/modules/DASHClient.cc \
	httptools/videocomponents/client/network/Worker.h \
	transport/tcp/queues/MsgByteBuffer.h \
	transport/tcp/TCPSegment.h \
	networklayer/contract/IPv6Address.h \
	httptools/videocomponents/client/application/DashController.h \
	base/InternetTypeDefsWithStandardTypes.h \
	transport/contract/TCPSocketExtension.h \
	httptools/videocomponents/client/modules/DASHClient.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	transport/contract/TCPSocketMgr.h \
	httptools/messages/httptMessages_m.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	httptools/base/httptUtils.h \
	transport/contract/TCPSocketMap.h \
	httptools/base/httptLogdefs.h \
	transport/tcp/TCPSegment_m.h \
	httptools/base/httptController.h \
	httptools/videocomponents/client/network/Job.h \
	httptools/videocomponents/client/network/NetworkController.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPCommand_m.h \
	httptools/videocomponents/client/modules/IModule.h \
	httptools/videocomponents/client/modules/AdaptiveClient.h \
	httptools/messages/HTTPMsgDefs.h \
	transport/contract/SocketTimeoutMsg_m.h \
	transport/tcp/queues/MsgByteBuffer_m.h \
	transport/contract/TCPSocketAPI_Inet.h \
	transport/contract/TCPSocketAPI_Base.h \
	httptools/videocomponents/client/network/INetworkControl.h \
	networklayer/contract/IPAddressResolver.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	httptools/videocomponents/client/application/IApplicationControl.h \
	base/ModuleAccess.h
$O/httptools/videocomponents/client/modules/AdditiveClient.o: httptools/videocomponents/client/modules/AdditiveClient.cc \
	httptools/videocomponents/client/network/Worker.h \
	transport/tcp/queues/MsgByteBuffer.h \
	transport/tcp/TCPSegment.h \
	networklayer/contract/IPv6Address.h \
	httptools/videocomponents/client/network/MultiSockets.h \
	base/InternetTypeDefsWithStandardTypes.h \
	transport/contract/TCPSocketExtension.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	transport/contract/TCPSocketMgr.h \
	httptools/messages/httptMessages_m.h \
	httptools/videocomponents/client/application/NetworkMonitor.h \
	httptools/videocomponents/client/application/codec/Codec.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	httptools/base/httptUtils.h \
	httptools/videocomponents/client/application/AdditiveController.h \
	httptools/base/httptLogdefs.h \
	transport/tcp/TCPSegment_m.h \
	transport/contract/TCPSocketMap.h \
	httptools/base/httptController.h \
	httptools/videocomponents/client/network/Job.h \
	httptools/videocomponents/client/network/NetworkController.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPCommand_m.h \
	httptools/videocomponents/client/modules/IModule.h \
	httptools/videocomponents/client/modules/AdaptiveClient.h \
	httptools/messages/HTTPMsgDefs.h \
	transport/tcp/queues/MsgByteBuffer_m.h \
	transport/contract/SocketTimeoutMsg_m.h \
	transport/contract/TCPSocketAPI_Inet.h \
	httptools/videocomponents/client/application/VideoPlayback.h \
	transport/contract/TCPSocketAPI_Base.h \
	httptools/videocomponents/client/network/INetworkControl.h \
	httptools/videocomponents/client/application/policy/IPolicy.h \
	httptools/videocomponents/client/modules/AdditiveClient.h \
	networklayer/contract/IPAddressResolver.h \
	httptools/videocomponents/client/application/ActiveRegion.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	httptools/videocomponents/client/application/IApplicationControl.h \
	base/ModuleAccess.h
$O/httptools/videocomponents/client/network/INetworkControl.o: httptools/videocomponents/client/network/INetworkControl.cc \
	httptools/videocomponents/client/network/INetworkControl.h \
	httptools/videocomponents/client/network/Job.h
$O/httptools/videocomponents/client/network/NetworkController.o: httptools/videocomponents/client/network/NetworkController.cc \
	httptools/videocomponents/client/network/Worker.h \
	transport/tcp/queues/MsgByteBuffer.h \
	transport/tcp/TCPSegment.h \
	networklayer/contract/IPv6Address.h \
	base/InternetTypeDefsWithStandardTypes.h \
	transport/contract/TCPSocketExtension.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	transport/contract/TCPSocketMgr.h \
	httptools/messages/httptMessages_m.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	httptools/base/httptUtils.h \
	transport/contract/TCPSocketMap.h \
	transport/tcp/TCPSegment_m.h \
	httptools/base/httptLogdefs.h \
	httptools/base/httptController.h \
	httptools/videocomponents/client/network/Job.h \
	httptools/videocomponents/client/network/NetworkController.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPCommand_m.h \
	applications/tcpapp/socketapi/TCPSocketMgrAppUtils.h \
	httptools/videocomponents/client/modules/IModule.h \
	httptools/messages/HTTPMsgDefs.h \
	transport/contract/SocketTimeoutMsg_m.h \
	transport/tcp/queues/MsgByteBuffer_m.h \
	transport/contract/TCPSocketAPI_Inet.h \
	transport/contract/TCPSocketAPI_Base.h \
	httptools/videocomponents/client/network/INetworkControl.h \
	networklayer/contract/IPAddressResolver.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	httptools/videocomponents/client/application/IApplicationControl.h \
	base/ModuleAccess.h
$O/httptools/videocomponents/client/network/Worker.o: httptools/videocomponents/client/network/Worker.cc \
	base/InternetTypeDefsWithStandardTypes.h \
	httptools/videocomponents/client/network/Worker.h \
	httptools/videocomponents/client/network/Job.h
$O/httptools/videocomponents/client/network/MultiSockets.o: httptools/videocomponents/client/network/MultiSockets.cc \
	httptools/videocomponents/client/network/Worker.h \
	transport/tcp/queues/MsgByteBuffer.h \
	transport/tcp/TCPSegment.h \
	networklayer/contract/IPv6Address.h \
	httptools/videocomponents/client/network/MultiSockets.h \
	base/InternetTypeDefsWithStandardTypes.h \
	transport/contract/TCPSocketExtension.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	transport/contract/TCPSocketMgr.h \
	httptools/messages/httptMessages_m.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	httptools/base/httptUtils.h \
	transport/contract/TCPSocketMap.h \
	transport/tcp/TCPSegment_m.h \
	httptools/base/httptLogdefs.h \
	httptools/base/httptController.h \
	httptools/videocomponents/client/network/Job.h \
	httptools/videocomponents/client/network/NetworkController.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPCommand_m.h \
	httptools/videocomponents/client/modules/IModule.h \
	httptools/messages/HTTPMsgDefs.h \
	transport/contract/SocketTimeoutMsg_m.h \
	transport/tcp/queues/MsgByteBuffer_m.h \
	transport/contract/TCPSocketAPI_Inet.h \
	transport/contract/TCPSocketAPI_Base.h \
	httptools/videocomponents/client/network/INetworkControl.h \
	networklayer/contract/IPAddressResolver.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	httptools/videocomponents/client/application/IApplicationControl.h \
	base/ModuleAccess.h
$O/httptools/videocomponents/client/network/Job.o: httptools/videocomponents/client/network/Job.cc \
	httptools/videocomponents/client/network/Job.h
$O/httptools/videocomponents/server/VideoServer.o: httptools/videocomponents/server/VideoServer.cc \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	httptools/messages/observer/DuplicateRecord.h \
	networklayer/contract/IPv6Address.h \
	base/InternetTypeDefsWithStandardTypes.h \
	transport/contract/TCPSocketExtension.h \
	httptools/base/httptRandom.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/sim/cobserver.h \
	httptools/messages/httptEventMessages_m.h \
	transport/contract/TCPSocketMgr.h \
	httptools/messages/httptMessages_m.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	httptools/messages/observer/DuplicateHttpMessageNameObserver.h \
	httptools/base/httptUtils.h \
	httptools/videocomponents/workgen/IFileSystem.h \
	httptools/base/httptLogdefs.h \
	transport/contract/TCPSocketMap.h \
	httptools/base/httptController.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/EnforceSingleClassInstanceDefs.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCPPortRangeDefs.h \
	applications/tcpapp/socketapi/TCPSocketMgrAppUtils.h \
	httptools/messages/HTTPMsgDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/sim/cmessageeventobserver.h \
	transport/contract/SocketTimeoutMsg_m.h \
	transport/contract/TCPSocketAPI_Inet.h \
	httptools/base/httptServerBase.h \
	transport/contract/TCPSocketAPI_Base.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/simunits.h \
	networklayer/contract/IPAddressResolver.h \
	httptools/videocomponents/server/VideoServer.h \
	base/INETDefs.h \
	httptools/base/httptNodeBase.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/omnetppextension.h
$O/httptools/videocomponents/workgen/PopularizedResourceCollection.o: httptools/videocomponents/workgen/PopularizedResourceCollection.cc \
	base/InternetTypeDefsWithStandardTypes.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/simunits.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/EnforceSingleClassInstanceDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/omnetppextension.h \
	httptools/videocomponents/workgen/PopularizedResourceCollection.h
$O/httptools/videocomponents/workgen/NullWorkloadGenerator.o: httptools/videocomponents/workgen/NullWorkloadGenerator.cc \
	httptools/videocomponents/workgen/IFileSystem.h \
	httptools/videocomponents/workgen/NullWorkloadGenerator.h \
	httptools/messages/httptMessages_m.h \
	httptools/messages/HTTPMsgDefs.h
$O/httptools/videocomponents/workgen/VideoMetaData.o: httptools/videocomponents/workgen/VideoMetaData.cc \
	base/InternetTypeDefsWithStandardTypes.h \
	httptools/base/httptUtils.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/simunits.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/EnforceSingleClassInstanceDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	httptools/messages/httptMessages_m.h \
	httptools/messages/HTTPMsgDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	httptools/videocomponents/workgen/VideoMetaData.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/omnetppextension.h
$O/httptools/videocomponents/workgen/VMDWorkloadGenerator.o: httptools/videocomponents/workgen/VMDWorkloadGenerator.cc \
	base/InternetTypeDefsWithStandardTypes.h \
	httptools/videocomponents/workgen/IVMDAccess.h \
	httptools/videocomponents/workgen/IFileSystem.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/simunits.h \
	httptools/videocomponents/workgen/VMDWorkloadGenerator.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/EnforceSingleClassInstanceDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	httptools/messages/httptMessages_m.h \
	httptools/messages/HTTPMsgDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	httptools/videocomponents/workgen/VideoMetaData.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/omnetppextension.h \
	httptools/videocomponents/workgen/PopularizedResourceCollection.h
$O/linklayer/contract/PhyControlInfo_m.o: linklayer/contract/PhyControlInfo_m.cc \
	base/INETDefs.h \
	linklayer/contract/PhyControlInfo_m.h
$O/linklayer/contract/MACAddress.o: linklayer/contract/MACAddress.cc \
	networklayer/common/InterfaceToken.h \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h
$O/linklayer/contract/Ieee802Ctrl_m.o: linklayer/contract/Ieee802Ctrl_m.cc \
	linklayer/contract/Ieee802Ctrl_m.h \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ethernet/EtherMAC2.o: linklayer/ethernet/EtherMAC2.cc \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/ethernet/EtherFrame_m.h \
	base/IPassiveQueue.h \
	base/NotifierConsts.h \
	linklayer/ethernet/Ethernet.h \
	base/NotificationBoard.h \
	linklayer/contract/TxNotifDetails.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	base/INotifiable.h \
	base/INETDefs.h \
	linklayer/ethernet/EtherMAC2.h \
	linklayer/ethernet/EtherMACBase.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ethernet/EtherHub.o: linklayer/ethernet/EtherHub.cc \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/ethernet/EtherFrame_m.h \
	base/INETDefs.h \
	linklayer/ethernet/Ethernet.h \
	linklayer/ethernet/EtherHub.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ethernet/EtherFrame_m.o: linklayer/ethernet/EtherFrame_m.cc \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/ethernet/EtherFrame_m.h \
	base/INETDefs.h \
	linklayer/ethernet/Ethernet.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ethernet/EtherEncap.o: linklayer/ethernet/EtherEncap.cc \
	linklayer/ethernet/EtherMAC.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/ethernet/EtherFrame_m.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	linklayer/ethernet/Ethernet.h \
	base/NotificationBoard.h \
	networklayer/common/InterfaceTableAccess.h \
	linklayer/contract/TxNotifDetails.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	base/INotifiable.h \
	base/INETDefs.h \
	linklayer/ethernet/EtherMACBase.h \
	base/ModuleAccess.h \
	linklayer/ethernet/EtherEncap.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ethernet/EtherMACBase.o: linklayer/ethernet/EtherMACBase.cc \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/ethernet/EtherFrame_m.h \
	base/IPassiveQueue.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	linklayer/ethernet/Ethernet.h \
	base/NotificationBoard.h \
	networklayer/common/InterfaceTableAccess.h \
	linklayer/contract/TxNotifDetails.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	base/INotifiable.h \
	base/INETDefs.h \
	linklayer/ethernet/EtherMACBase.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ethernet/EtherMAC.o: linklayer/ethernet/EtherMAC.cc \
	linklayer/ethernet/EtherMAC.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/ethernet/EtherFrame_m.h \
	base/IPassiveQueue.h \
	base/NotifierConsts.h \
	linklayer/ethernet/Ethernet.h \
	base/NotificationBoard.h \
	linklayer/contract/TxNotifDetails.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	base/INotifiable.h \
	base/INETDefs.h \
	linklayer/ethernet/EtherMACBase.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ethernet/EtherLLC.o: linklayer/ethernet/EtherLLC.cc \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/ethernet/EtherFrame_m.h \
	base/INETDefs.h \
	linklayer/ethernet/Ethernet.h \
	linklayer/ethernet/EtherLLC.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ethernet/EtherBus.o: linklayer/ethernet/EtherBus.cc \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/ethernet/EtherFrame_m.h \
	base/INETDefs.h \
	linklayer/ethernet/EtherBus.h \
	linklayer/ethernet/Ethernet.h \
	linklayer/contract/MACAddress.h
$O/linklayer/etherswitch/MACRelayUnitBase.o: linklayer/etherswitch/MACRelayUnitBase.cc \
	linklayer/etherswitch/MACRelayUnitBase.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/ethernet/EtherFrame_m.h \
	base/INETDefs.h \
	linklayer/ethernet/Ethernet.h \
	linklayer/contract/MACAddress.h
$O/linklayer/etherswitch/MACRelayUnitNP.o: linklayer/etherswitch/MACRelayUnitNP.cc \
	linklayer/etherswitch/MACRelayUnitBase.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/ethernet/EtherFrame_m.h \
	base/INETDefs.h \
	linklayer/etherswitch/MACRelayUnitNP.h \
	linklayer/ethernet/Ethernet.h \
	linklayer/contract/MACAddress.h
$O/linklayer/etherswitch/MACRelayUnitPP.o: linklayer/etherswitch/MACRelayUnitPP.cc \
	linklayer/etherswitch/MACRelayUnitBase.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/ethernet/EtherFrame_m.h \
	linklayer/etherswitch/MACRelayUnitPP.h \
	base/INETDefs.h \
	linklayer/ethernet/Ethernet.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ext/ExtInterface.o: linklayer/ext/ExtInterface.cc \
	linklayer/ext/ExtInterface.h \
	util/headerserializers/headers/bsdint.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	linklayer/ext/cSocketRTScheduler.h \
	networklayer/ipv4/IPDatagram_m.h \
	linklayer/ext/ExtFrame_m.h \
	base/NotificationBoard.h \
	networklayer/common/InterfaceTableAccess.h \
	util/headerserializers/IPSerializer.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	base/INotifiable.h \
	networklayer/ipv4/IPDatagram.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPAddress.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	networklayer/common/InterfaceTable.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ext/ExtFrame_m.o: linklayer/ext/ExtFrame_m.cc \
	linklayer/ext/ExtFrame_m.h
$O/linklayer/ext/cSocketRTScheduler.o: linklayer/ext/cSocketRTScheduler.cc \
	util/headerserializers/headers/bsdint.h \
	base/INETDefs.h \
	linklayer/ext/cSocketRTScheduler.h \
	linklayer/ext/ExtFrame_m.h \
	util/headerserializers/headers/ethernet.h
$O/linklayer/ieee80211/mac/Ieee80211Mac.o: linklayer/ieee80211/mac/Ieee80211Mac.cc \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	base/IPassiveQueue.h \
	base/NotifierConsts.h \
	linklayer/ieee80211/mac/Ieee80211Mac.h \
	linklayer/contract/RadioState.h \
	networklayer/common/IInterfaceTable.h \
	linklayer/contract/PhyControlInfo_m.h \
	base/NotificationBoard.h \
	base/FSMA.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	base/INotifiable.h \
	linklayer/mfcore/WirelessMacBase.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ieee80211/mac/Ieee80211Frame_m.o: linklayer/ieee80211/mac/Ieee80211Frame_m.cc \
	base/INETDefs.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ieee80211/mgmt/Ieee80211MgmtAdhoc.o: linklayer/ieee80211/mgmt/Ieee80211MgmtAdhoc.cc \
	linklayer/ieee80211/mgmt/Ieee80211MgmtAdhoc.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtBase.h \
	base/IPassiveQueue.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h \
	base/INotifiable.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	base/NotificationBoard.h \
	base/PassiveQueueBase.h \
	base/ModuleAccess.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ieee80211/mgmt/Ieee80211MgmtAPBase.o: linklayer/ieee80211/mgmt/Ieee80211MgmtAPBase.cc \
	linklayer/ieee80211/mgmt/Ieee80211MgmtAPBase.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/ethernet/EtherFrame_m.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtBase.h \
	base/IPassiveQueue.h \
	base/NotifierConsts.h \
	linklayer/ethernet/Ethernet.h \
	base/NotificationBoard.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h \
	base/INotifiable.h \
	base/INETDefs.h \
	base/PassiveQueueBase.h \
	base/ModuleAccess.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.o: linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.cc \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h \
	base/INETDefs.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ieee80211/mgmt/Ieee80211AgentSTA.o: linklayer/ieee80211/mgmt/Ieee80211AgentSTA.cc \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h \
	base/INotifiable.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	base/NotificationBoard.h \
	base/ModuleAccess.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/ieee80211/mgmt/Ieee80211Primitives_m.h \
	linklayer/ieee80211/mgmt/Ieee80211AgentSTA.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ieee80211/mgmt/Ieee80211MgmtAPSimplified.o: linklayer/ieee80211/mgmt/Ieee80211MgmtAPSimplified.cc \
	linklayer/ieee80211/mgmt/Ieee80211MgmtAPBase.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/ethernet/EtherFrame_m.h \
	base/IPassiveQueue.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtBase.h \
	base/NotifierConsts.h \
	linklayer/ethernet/Ethernet.h \
	base/NotificationBoard.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h \
	base/INotifiable.h \
	base/INETDefs.h \
	base/PassiveQueueBase.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtAPSimplified.h \
	base/ModuleAccess.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ieee80211/mgmt/Ieee80211MgmtSTASimplified.o: linklayer/ieee80211/mgmt/Ieee80211MgmtSTASimplified.cc \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtSTASimplified.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtBase.h \
	base/IPassiveQueue.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h \
	base/INotifiable.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	base/NotificationBoard.h \
	base/PassiveQueueBase.h \
	base/ModuleAccess.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ieee80211/mgmt/Ieee80211MgmtSTA.o: linklayer/ieee80211/mgmt/Ieee80211MgmtSTA.cc \
	world/ChannelControl.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	base/IPassiveQueue.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtBase.h \
	base/NotifierConsts.h \
	linklayer/contract/RadioState.h \
	linklayer/contract/PhyControlInfo_m.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	linklayer/ieee80211/mgmt/Ieee80211Primitives_m.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtSTA.h \
	util/FWMath.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h \
	base/INotifiable.h \
	base/INETDefs.h \
	base/PassiveQueueBase.h \
	base/ModuleAccess.h \
	base/Coord.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ieee80211/mgmt/Ieee80211Primitives_m.o: linklayer/ieee80211/mgmt/Ieee80211Primitives_m.cc \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h \
	base/INETDefs.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/ieee80211/mgmt/Ieee80211Primitives_m.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ieee80211/mgmt/Ieee80211MgmtAP.o: linklayer/ieee80211/mgmt/Ieee80211MgmtAP.cc \
	linklayer/ieee80211/mgmt/Ieee80211MgmtAPBase.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/ethernet/EtherFrame_m.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtBase.h \
	base/IPassiveQueue.h \
	base/NotifierConsts.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtAP.h \
	linklayer/contract/RadioState.h \
	linklayer/ethernet/Ethernet.h \
	base/NotificationBoard.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h \
	base/INotifiable.h \
	base/INETDefs.h \
	base/PassiveQueueBase.h \
	base/ModuleAccess.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ieee80211/mgmt/Ieee80211MgmtBase.o: linklayer/ieee80211/mgmt/Ieee80211MgmtBase.cc \
	linklayer/contract/Ieee802Ctrl_m.h \
	base/IPassiveQueue.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtFrames_m.h \
	linklayer/ieee80211/mgmt/Ieee80211MgmtBase.h \
	base/NotifierConsts.h \
	base/INotifiable.h \
	base/INETDefs.h \
	base/PassiveQueueBase.h \
	base/NotificationBoard.h \
	base/ModuleAccess.h \
	linklayer/ieee80211/mac/Ieee80211Frame_m.h \
	linklayer/contract/MACAddress.h
$O/linklayer/mf80211/macLayer/MacPkt_m.o: linklayer/mf80211/macLayer/MacPkt_m.cc \
	linklayer/mf80211/macLayer/MacPkt_m.h \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h
$O/linklayer/mf80211/macLayer/Mac80211.o: linklayer/mf80211/macLayer/Mac80211.cc \
	linklayer/mf80211/macLayer/Consts80211.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	linklayer/mf80211/macLayer/Mac80211Pkt_m.h \
	base/NotifierConsts.h \
	linklayer/contract/RadioState.h \
	networklayer/common/IInterfaceTable.h \
	base/NotificationBoard.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	base/INotifiable.h \
	linklayer/mf80211/macLayer/MacPkt_m.h \
	linklayer/mfcore/WirelessMacBase.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	linklayer/mf80211/macLayer/Mac80211.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h
$O/linklayer/mf80211/macLayer/CSMAMacLayer.o: linklayer/mf80211/macLayer/CSMAMacLayer.cc \
	linklayer/contract/Ieee802Ctrl_m.h \
	base/NotifierConsts.h \
	linklayer/contract/RadioState.h \
	networklayer/common/IInterfaceTable.h \
	base/NotificationBoard.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	linklayer/mf80211/macLayer/MacPkt_m.h \
	base/INotifiable.h \
	linklayer/mfcore/WirelessMacBase.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/mf80211/macLayer/CSMAMacLayer.h \
	linklayer/contract/MACAddress.h
$O/linklayer/mf80211/macLayer/Mac80211Pkt_m.o: linklayer/mf80211/macLayer/Mac80211Pkt_m.cc \
	linklayer/mf80211/macLayer/Mac80211Pkt_m.h \
	linklayer/mf80211/macLayer/MacPkt_m.h \
	base/INETDefs.h \
	linklayer/contract/MACAddress.h
$O/linklayer/mf80211/phyLayer/decider/ErrAndCollDecider.o: linklayer/mf80211/phyLayer/decider/ErrAndCollDecider.cc \
	linklayer/mf80211/phyLayer/decider/SnrDecider.h \
	base/BasicModule.h \
	base/NotifierConsts.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	linklayer/mf80211/phyLayer/decider/ErrAndCollDecider.h \
	linklayer/mfcore/SnrList.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	linklayer/mfcore/SnrControlInfo_m.h \
	linklayer/mfcore/BasicDecider.h \
	base/Coord.h
$O/linklayer/mf80211/phyLayer/decider/SnrDecider.o: linklayer/mf80211/phyLayer/decider/SnrDecider.cc \
	linklayer/mf80211/phyLayer/decider/SnrDecider.h \
	base/BasicModule.h \
	base/NotifierConsts.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	linklayer/mfcore/SnrList.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	linklayer/mfcore/SnrControlInfo_m.h \
	linklayer/mfcore/BasicDecider.h \
	base/Coord.h
$O/linklayer/mf80211/phyLayer/decider/Decider80211.o: linklayer/mf80211/phyLayer/decider/Decider80211.cc \
	linklayer/mf80211/macLayer/Consts80211.h \
	base/BasicModule.h \
	base/NotifierConsts.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	linklayer/mfcore/SnrList.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	linklayer/mfcore/SnrControlInfo_m.h \
	linklayer/mfcore/BasicDecider.h \
	linklayer/mf80211/phyLayer/decider/Decider80211.h \
	base/Coord.h
$O/linklayer/mf80211/phyLayer/snrEval/GilbertElliotSnr.o: linklayer/mf80211/phyLayer/snrEval/GilbertElliotSnr.cc \
	world/ChannelControl.h \
	world/ChannelAccess.h \
	linklayer/mf80211/phyLayer/snrEval/SnrEval.h \
	base/BasicModule.h \
	base/NotifierConsts.h \
	linklayer/contract/RadioState.h \
	linklayer/contract/PhyControlInfo_m.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	linklayer/mfcore/BasicSnrEval.h \
	linklayer/mfcore/SnrList.h \
	linklayer/mf80211/phyLayer/snrEval/GilbertElliotSnr.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	linklayer/mfcore/SnrControlInfo_m.h \
	base/Coord.h
$O/linklayer/mf80211/phyLayer/snrEval/SnrEval.o: linklayer/mf80211/phyLayer/snrEval/SnrEval.cc \
	world/ChannelAccess.h \
	world/ChannelControl.h \
	linklayer/mf80211/phyLayer/snrEval/SnrEval.h \
	base/BasicModule.h \
	base/NotifierConsts.h \
	linklayer/contract/RadioState.h \
	linklayer/contract/PhyControlInfo_m.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	linklayer/mfcore/BasicSnrEval.h \
	linklayer/mfcore/SnrList.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	linklayer/mfcore/SnrControlInfo_m.h \
	base/Coord.h
$O/linklayer/mf80211/phyLayer/snrEval/SnrEval80211.o: linklayer/mf80211/phyLayer/snrEval/SnrEval80211.cc \
	world/ChannelControl.h \
	world/ChannelAccess.h \
	base/BasicModule.h \
	linklayer/mf80211/macLayer/Consts80211.h \
	linklayer/mf80211/phyLayer/snrEval/SnrEval.h \
	base/NotifierConsts.h \
	linklayer/contract/RadioState.h \
	linklayer/mfcore/AirFrame_m.h \
	linklayer/contract/PhyControlInfo_m.h \
	base/NotificationBoard.h \
	linklayer/mfcore/BasicSnrEval.h \
	linklayer/mfcore/SnrList.h \
	linklayer/mf80211/phyLayer/snrEval/SnrEval80211.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	linklayer/mfcore/SnrControlInfo_m.h \
	base/Coord.h
$O/linklayer/mfcore/BasicDecider.o: linklayer/mfcore/BasicDecider.cc \
	linklayer/mfcore/SnrList.h \
	base/BasicModule.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	base/ModuleAccess.h \
	linklayer/mfcore/SnrControlInfo_m.h \
	linklayer/mfcore/BasicDecider.h \
	base/Coord.h
$O/linklayer/mfcore/TransmComplete_m.o: linklayer/mfcore/TransmComplete_m.cc \
	base/INETDefs.h \
	linklayer/mfcore/TransmComplete_m.h
$O/linklayer/mfcore/AirFrame_m.o: linklayer/mfcore/AirFrame_m.cc \
	util/FWMath.h \
	base/INETDefs.h \
	linklayer/mfcore/AirFrame_m.h \
	base/Coord.h
$O/linklayer/mfcore/BasicSnrEval.o: linklayer/mfcore/BasicSnrEval.cc \
	world/ChannelAccess.h \
	world/ChannelControl.h \
	base/BasicModule.h \
	base/NotifierConsts.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	linklayer/mfcore/BasicSnrEval.h \
	linklayer/mfcore/SnrList.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	linklayer/mfcore/SnrControlInfo_m.h \
	linklayer/mfcore/TransmComplete_m.h \
	base/Coord.h
$O/linklayer/mfcore/SnrControlInfo_m.o: linklayer/mfcore/SnrControlInfo_m.cc \
	linklayer/mfcore/SnrList.h \
	base/INETDefs.h \
	linklayer/mfcore/SnrControlInfo_m.h
$O/linklayer/mfcore/WirelessMacBase.o: linklayer/mfcore/WirelessMacBase.cc \
	base/INotifiable.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	linklayer/mfcore/WirelessMacBase.h \
	base/NotificationBoard.h \
	base/ModuleAccess.h
$O/linklayer/ppp/DropsGenerator.o: linklayer/ppp/DropsGenerator.cc \
	base/INETDefs.h \
	linklayer/ppp/DropsGenerator.h
$O/linklayer/ppp/PPPFrame_m.o: linklayer/ppp/PPPFrame_m.cc \
	base/INETDefs.h \
	linklayer/ppp/PPPFrame_m.h
$O/linklayer/ppp/PPP.o: linklayer/ppp/PPP.cc \
	base/IPassiveQueue.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	linklayer/ppp/PPPFrame_m.h \
	linklayer/ppp/PPP.h \
	base/NotificationBoard.h \
	networklayer/common/InterfaceTableAccess.h \
	linklayer/contract/TxNotifDetails.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	base/INotifiable.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h
$O/linklayer/ppp/DuplicatesGenerator.o: linklayer/ppp/DuplicatesGenerator.cc \
	base/INETDefs.h \
	linklayer/ppp/DuplicatesGenerator.h
$O/linklayer/ppp/ThruputMeter.o: linklayer/ppp/ThruputMeter.cc \
	base/INETDefs.h \
	linklayer/ppp/ThruputMeter.h
$O/linklayer/radio/Modulation.o: linklayer/radio/Modulation.cc \
	linklayer/radio/IModulation.h \
	base/INETDefs.h \
	linklayer/radio/Modulation.h
$O/linklayer/radio/GenericRadio.o: linklayer/radio/GenericRadio.cc \
	world/ChannelAccess.h \
	world/ChannelControl.h \
	base/BasicModule.h \
	base/NotifierConsts.h \
	linklayer/radio/IReceptionModel.h \
	linklayer/contract/RadioState.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	linklayer/radio/IRadioModel.h \
	linklayer/radio/GenericRadio.h \
	linklayer/mfcore/SnrList.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	linklayer/radio/AbstractRadio.h \
	base/Coord.h
$O/linklayer/radio/GenericRadioModel.o: linklayer/radio/GenericRadioModel.cc \
	linklayer/mfcore/SnrList.h \
	linklayer/radio/IModulation.h \
	util/FWMath.h \
	base/INETDefs.h \
	linklayer/mfcore/AirFrame_m.h \
	base/Coord.h \
	linklayer/radio/IRadioModel.h \
	linklayer/radio/Modulation.h \
	linklayer/radio/GenericRadioModel.h
$O/linklayer/radio/PathLossReceptionModel.o: linklayer/radio/PathLossReceptionModel.cc \
	world/ChannelControl.h \
	util/FWMath.h \
	linklayer/radio/IReceptionModel.h \
	base/INETDefs.h \
	linklayer/mfcore/AirFrame_m.h \
	linklayer/radio/PathLossReceptionModel.h \
	base/Coord.h
$O/linklayer/radio/AbstractRadio.o: linklayer/radio/AbstractRadio.cc \
	world/ChannelControl.h \
	world/ChannelAccess.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	base/BasicModule.h \
	base/NotifierConsts.h \
	linklayer/radio/IReceptionModel.h \
	linklayer/contract/RadioState.h \
	linklayer/contract/PhyControlInfo_m.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	linklayer/radio/IRadioModel.h \
	linklayer/mfcore/SnrList.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/Coord.h \
	linklayer/radio/AbstractRadio.h
$O/linklayer/radio/Ieee80211Radio.o: linklayer/radio/Ieee80211Radio.cc \
	world/ChannelAccess.h \
	world/ChannelControl.h \
	base/BasicModule.h \
	linklayer/radio/IReceptionModel.h \
	base/NotifierConsts.h \
	linklayer/contract/RadioState.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	linklayer/radio/IRadioModel.h \
	linklayer/radio/Ieee80211Radio.h \
	linklayer/mfcore/SnrList.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/Coord.h \
	linklayer/radio/AbstractRadio.h
$O/linklayer/radio/Ieee80211RadioModel.o: linklayer/radio/Ieee80211RadioModel.cc \
	linklayer/mfcore/SnrList.h \
	linklayer/ieee80211/mac/Ieee80211Consts.h \
	util/FWMath.h \
	base/INETDefs.h \
	linklayer/radio/Ieee80211RadioModel.h \
	linklayer/mfcore/AirFrame_m.h \
	base/Coord.h \
	linklayer/radio/IRadioModel.h
$O/mobility/RectangleMobility.o: mobility/RectangleMobility.cc \
	world/ChannelControl.h \
	base/BasicModule.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	linklayer/mfcore/AirFrame_m.h \
	mobility/RectangleMobility.h \
	base/NotificationBoard.h \
	base/ModuleAccess.h \
	base/Coord.h \
	mobility/BasicMobility.h
$O/mobility/MassMobility.o: mobility/MassMobility.cc \
	world/ChannelControl.h \
	mobility/MassMobility.h \
	base/BasicModule.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	base/ModuleAccess.h \
	base/Coord.h \
	mobility/BasicMobility.h
$O/mobility/TurtleMobility.o: mobility/TurtleMobility.cc \
	world/ChannelControl.h \
	base/BasicModule.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/NotifierConsts.h \
	mobility/TurtleMobility.h \
	base/INETDefs.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	base/ModuleAccess.h \
	mobility/LineSegmentsMobilityBase.h \
	base/Coord.h \
	mobility/BasicMobility.h
$O/mobility/CircleMobility.o: mobility/CircleMobility.cc \
	world/ChannelControl.h \
	base/BasicModule.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	base/ModuleAccess.h \
	mobility/BasicMobility.h \
	base/Coord.h \
	mobility/CircleMobility.h
$O/mobility/BonnMotionMobility.o: mobility/BonnMotionMobility.cc \
	world/ChannelControl.h \
	base/BasicModule.h \
	base/NotifierConsts.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	mobility/LineSegmentsMobilityBase.h \
	mobility/BasicMobility.h \
	mobility/BonnMotionMobility.h \
	mobility/BonnMotionFileCache.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/Coord.h
$O/mobility/LineSegmentsMobilityBase.o: mobility/LineSegmentsMobilityBase.cc \
	world/ChannelControl.h \
	base/BasicModule.h \
	util/FWMath.h \
	base/NotifierConsts.h \
	base/INotifiable.h \
	base/INETDefs.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	base/ModuleAccess.h \
	mobility/LineSegmentsMobilityBase.h \
	mobility/BasicMobility.h \
	base/Coord.h
$O/mobility/RandomWPMobility.o: mobility/RandomWPMobility.cc \
	world/ChannelControl.h \
	mobility/RandomWPMobility.h \
	base/BasicModule.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	base/ModuleAccess.h \
	mobility/LineSegmentsMobilityBase.h \
	base/Coord.h \
	mobility/BasicMobility.h
$O/mobility/BasicMobility.o: mobility/BasicMobility.cc \
	world/ChannelControl.h \
	base/BasicModule.h \
	util/FWMath.h \
	base/NotifierConsts.h \
	base/INotifiable.h \
	base/INETDefs.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	base/ModuleAccess.h \
	base/Coord.h \
	mobility/BasicMobility.h
$O/mobility/BonnMotionFileCache.o: mobility/BonnMotionFileCache.cc \
	world/ChannelControl.h \
	mobility/BonnMotionFileCache.h \
	base/BasicModule.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	base/ModuleAccess.h \
	base/Coord.h \
	mobility/BasicMobility.h
$O/mobility/ANSimMobility.o: mobility/ANSimMobility.cc \
	world/ChannelControl.h \
	base/BasicModule.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	linklayer/mfcore/AirFrame_m.h \
	mobility/ANSimMobility.h \
	base/NotificationBoard.h \
	base/ModuleAccess.h \
	mobility/LineSegmentsMobilityBase.h \
	base/Coord.h \
	mobility/BasicMobility.h
$O/mobility/NullMobility.o: mobility/NullMobility.cc \
	world/ChannelControl.h \
	base/BasicModule.h \
	mobility/NullMobility.h \
	util/FWMath.h \
	base/NotifierConsts.h \
	base/INotifiable.h \
	base/INETDefs.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	base/ModuleAccess.h \
	mobility/BasicMobility.h \
	base/Coord.h
$O/mobility/ConstSpeedMobility.o: mobility/ConstSpeedMobility.cc \
	world/ChannelControl.h \
	base/BasicModule.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	linklayer/mfcore/AirFrame_m.h \
	mobility/ConstSpeedMobility.h \
	base/NotificationBoard.h \
	base/ModuleAccess.h \
	mobility/BasicMobility.h \
	base/Coord.h
$O/mobility/LinearMobility.o: mobility/LinearMobility.cc \
	world/ChannelControl.h \
	mobility/LinearMobility.h \
	base/BasicModule.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	base/ModuleAccess.h \
	mobility/BasicMobility.h \
	base/Coord.h
$O/networklayer/arp/ARPPacket_m.o: networklayer/arp/ARPPacket_m.cc \
	base/INETDefs.h \
	networklayer/arp/ARPPacket_m.h \
	networklayer/contract/IPAddress.h \
	linklayer/contract/MACAddress.h
$O/networklayer/arp/ARP.o: networklayer/arp/ARP.cc \
	networklayer/arp/ARP.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	networklayer/ipv4/IPRoute.h \
	base/NotifierConsts.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ipv4/IPDatagram_m.h \
	networklayer/arp/ARPPacket_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/ipv4/IPDatagram.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/contract/IPAddress.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	networklayer/contract/IPControlInfo_m.h \
	linklayer/contract/MACAddress.h
$O/networklayer/autorouting/NetworkConfigurator.o: networklayer/autorouting/NetworkConfigurator.cc \
	networklayer/ipv4/IPRoute.h \
	base/NotifierConsts.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	networklayer/autorouting/NetworkConfigurator.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/contract/IPAddressResolver.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h
$O/networklayer/autorouting/FlatNetworkConfigurator.o: networklayer/autorouting/FlatNetworkConfigurator.cc \
	networklayer/ipv4/IPRoute.h \
	networklayer/autorouting/FlatNetworkConfigurator.h \
	base/NotifierConsts.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/contract/IPAddressResolver.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h
$O/networklayer/autorouting/FlatNetworkConfigurator6.o: networklayer/autorouting/FlatNetworkConfigurator6.cc \
	networklayer/autorouting/FlatNetworkConfigurator6.h \
	networklayer/ipv6/RoutingTable6.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	networklayer/contract/IPAddressResolver.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	base/INotifiable.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPAddress.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	linklayer/contract/MACAddress.h
$O/networklayer/common/InterfaceEntry.o: networklayer/common/InterfaceEntry.cc \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	linklayer/contract/MACAddress.h
$O/networklayer/common/InterfaceTable.o: networklayer/common/InterfaceTable.cc \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	base/INotifiable.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	networklayer/common/IInterfaceTable.h \
	base/NotificationBoard.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	networklayer/common/InterfaceTable.h \
	linklayer/contract/MACAddress.h
$O/networklayer/contract/IPv6Address.o: networklayer/contract/IPv6Address.cc \
	networklayer/common/InterfaceToken.h \
	base/INETDefs.h \
	networklayer/contract/IPv6Address.h
$O/networklayer/contract/IPProtocolId_m.o: networklayer/contract/IPProtocolId_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h
$O/networklayer/contract/IPControlInfo.o: networklayer/contract/IPControlInfo.cc \
	networklayer/contract/IPControlInfo.h \
	networklayer/ipv4/IPDatagram.h \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/ipv4/IPDatagram_m.h \
	networklayer/contract/IPAddress.h \
	networklayer/contract/IPControlInfo_m.h
$O/networklayer/contract/IPAddress.o: networklayer/contract/IPAddress.cc \
	base/INETDefs.h \
	networklayer/contract/IPAddress.h
$O/networklayer/contract/IPv6ControlInfo.o: networklayer/contract/IPv6ControlInfo.cc \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/contract/IPv6ControlInfo.h \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	networklayer/contract/IPv6Address.h
$O/networklayer/contract/IPAddressResolver.o: networklayer/contract/IPAddressResolver.cc \
	networklayer/ipv6/RoutingTable6.h \
	networklayer/ipv4/IPRoute.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/contract/IPAddressResolver.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	base/INotifiable.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPAddress.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	linklayer/contract/MACAddress.h
$O/networklayer/contract/IPControlInfo_m.o: networklayer/contract/IPControlInfo_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPAddress.h \
	networklayer/contract/IPControlInfo_m.h
$O/networklayer/contract/IPv6ControlInfo_m.o: networklayer/contract/IPv6ControlInfo_m.cc \
	networklayer/contract/IPv6ControlInfo_m.h \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPv6Address.h
$O/networklayer/contract/IPvXAddress.o: networklayer/contract/IPvXAddress.cc \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h
$O/networklayer/extras/FailureManager.o: networklayer/extras/FailureManager.cc \
	base/IScriptable.h \
	base/INETDefs.h \
	networklayer/extras/FailureManager.h
$O/networklayer/extras/NetworkInfo.o: networklayer/extras/NetworkInfo.cc \
	base/IScriptable.h \
	networklayer/extras/NetworkInfo.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/contract/IPAddressResolver.h \
	networklayer/ipv4/IPRoute.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h
$O/networklayer/extras/Dummy.o: networklayer/extras/Dummy.cc
$O/networklayer/icmpv6/ICMPv6Message_m.o: networklayer/icmpv6/ICMPv6Message_m.cc \
	networklayer/icmpv6/ICMPv6Message_m.h \
	base/INETDefs.h
$O/networklayer/icmpv6/IPv6NeighbourDiscovery.o: networklayer/icmpv6/IPv6NeighbourDiscovery.cc \
	networklayer/ipv6/RoutingTable6.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/icmpv6/ICMPv6Message_m.h \
	networklayer/icmpv6/IPv6NDMessage_m.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/common/InterfaceEntry.h \
	base/INotifiable.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ipv6/RoutingTable6Access.h \
	networklayer/icmpv6/ICMPv6.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	networklayer/icmpv6/ICMPv6Access.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	networklayer/icmpv6/IPv6NeighbourDiscovery.h \
	linklayer/contract/MACAddress.h \
	networklayer/icmpv6/IPv6NeighbourCache.h
$O/networklayer/icmpv6/ICMPv6.o: networklayer/icmpv6/ICMPv6.cc \
	networklayer/ipv6/RoutingTable6.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	networklayer/icmpv6/ICMPv6Message_m.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/contract/IPv6ControlInfo.h \
	base/INotifiable.h \
	networklayer/icmpv6/ICMPv6.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ipv6/RoutingTable6Access.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h
$O/networklayer/icmpv6/IPv6NDMessage_m.o: networklayer/icmpv6/IPv6NDMessage_m.cc \
	networklayer/icmpv6/ICMPv6Message_m.h \
	networklayer/icmpv6/IPv6NDMessage_m.h \
	base/INETDefs.h \
	networklayer/contract/IPv6Address.h \
	linklayer/contract/MACAddress.h
$O/networklayer/icmpv6/IPv6NeighbourCache.o: networklayer/icmpv6/IPv6NeighbourCache.cc \
	base/INETDefs.h \
	networklayer/contract/IPv6Address.h \
	linklayer/contract/MACAddress.h \
	networklayer/icmpv6/IPv6NeighbourCache.h
$O/networklayer/ipv4/ICMP.o: networklayer/ipv4/ICMP.cc \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/IPDatagram_m.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/IPDatagram.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/contract/IPAddress.h \
	base/ModuleAccess.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/contract/IPControlInfo_m.h
$O/networklayer/ipv4/IPv4InterfaceData.o: networklayer/ipv4/IPv4InterfaceData.cc \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h
$O/networklayer/ipv4/RoutingTableParser.o: networklayer/ipv4/RoutingTableParser.cc \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/RoutingTable.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ipv4/IRoutingTable.h \
	base/NotificationBoard.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	base/INotifiable.h \
	base/INETDefs.h \
	networklayer/contract/IPAddress.h \
	base/ModuleAccess.h \
	networklayer/ipv4/RoutingTableParser.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h
$O/networklayer/ipv4/IPRoute.o: networklayer/ipv4/IPRoute.cc \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/ipv4/IPRoute.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h
$O/networklayer/ipv4/RoutingTable.o: networklayer/ipv4/RoutingTable.cc \
	networklayer/ipv4/RoutingTable.h \
	networklayer/ipv4/IPRoute.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ipv4/IRoutingTable.h \
	base/NotificationBoard.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	base/INotifiable.h \
	base/INETDefs.h \
	networklayer/contract/IPAddress.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	networklayer/ipv4/RoutingTableParser.h \
	linklayer/contract/MACAddress.h
$O/networklayer/ipv4/IP.o: networklayer/ipv4/IP.cc \
	base/ProtocolMap.h \
	base/NotifierConsts.h \
	base/AbstractQueue.h \
	base/ReassemblyBuffer.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/arp/ARPPacket_m.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/ipv4/IP.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IPFragBuf.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/IPDatagram_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/IPDatagram.h \
	networklayer/ipv4/ICMPAccess.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	base/QueueBase.h \
	networklayer/ipv4/ICMPMessage_m.h
$O/networklayer/ipv4/ControlManetRouting_m.o: networklayer/ipv4/ControlManetRouting_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPAddress.h \
	networklayer/ipv4/ControlManetRouting_m.h
$O/networklayer/ipv4/IPDatagram_m.o: networklayer/ipv4/IPDatagram_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/ipv4/IPDatagram_m.h \
	networklayer/contract/IPAddress.h
$O/networklayer/ipv4/ErrorHandling.o: networklayer/ipv4/ErrorHandling.cc \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/ipv4/IPDatagram.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ipv4/IPDatagram_m.h \
	networklayer/contract/IPAddress.h \
	networklayer/ipv4/ErrorHandling.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/contract/IPControlInfo_m.h
$O/networklayer/ipv4/IPFragBuf.o: networklayer/ipv4/IPFragBuf.cc \
	networklayer/ipv4/ICMP.h \
	networklayer/ipv4/IPFragBuf.h \
	networklayer/ipv4/IPRoute.h \
	base/ReassemblyBuffer.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/IPDatagram_m.h \
	networklayer/ipv4/ICMPMessage.h \
	networklayer/ipv4/IPDatagram.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/contract/IPAddress.h \
	base/ModuleAccess.h \
	networklayer/ipv4/ICMPMessage_m.h
$O/networklayer/ipv4/ICMPMessage_m.o: networklayer/ipv4/ICMPMessage_m.cc \
	base/INETDefs.h \
	networklayer/ipv4/ICMPMessage_m.h
$O/networklayer/ipv6/IPv6.o: networklayer/ipv6/IPv6.cc \
	networklayer/ipv6/IPv6Datagram.h \
	base/ProtocolMap.h \
	linklayer/contract/Ieee802Ctrl_m.h \
	base/NotifierConsts.h \
	base/AbstractQueue.h \
	base/ReassemblyBuffer.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	networklayer/icmpv6/IPv6NDMessage_m.h \
	networklayer/ipv6/IPv6.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/common/InterfaceEntry.h \
	base/INotifiable.h \
	networklayer/ipv6/RoutingTable6Access.h \
	networklayer/icmpv6/ICMPv6.h \
	networklayer/icmpv6/ICMPv6Access.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	networklayer/icmpv6/IPv6NeighbourDiscovery.h \
	linklayer/contract/MACAddress.h \
	networklayer/ipv6/RoutingTable6.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/ipv6/IPv6FragBuf.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/icmpv6/IPv6NeighbourDiscoveryAccess.h \
	networklayer/icmpv6/ICMPv6Message_m.h \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	base/ModuleAccess.h \
	base/QueueBase.h \
	networklayer/icmpv6/IPv6NeighbourCache.h
$O/networklayer/ipv6/IPv6FragBuf.o: networklayer/ipv6/IPv6FragBuf.cc \
	networklayer/ipv6/RoutingTable6.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	base/NotifierConsts.h \
	base/ReassemblyBuffer.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ipv6/IPv6FragBuf.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	networklayer/icmpv6/ICMPv6Message_m.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/contract/IPv6ControlInfo.h \
	base/INotifiable.h \
	networklayer/ipv6/IPv6ExtensionHeaders_m.h \
	networklayer/icmpv6/ICMPv6.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ipv6/RoutingTable6Access.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h
$O/networklayer/ipv6/RoutingTable6.o: networklayer/ipv6/RoutingTable6.cc \
	networklayer/ipv6/RoutingTable6.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	base/INotifiable.h \
	base/INETDefs.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	util/opp_utils.h \
	linklayer/contract/MACAddress.h
$O/networklayer/ipv6/IPv6InterfaceData.o: networklayer/ipv6/IPv6InterfaceData.cc \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	networklayer/contract/IPv6Address.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	linklayer/contract/MACAddress.h
$O/networklayer/ipv6/IPv6Datagram_m.o: networklayer/ipv6/IPv6Datagram_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	networklayer/contract/IPv6Address.h
$O/networklayer/ipv6/IPv6Datagram.o: networklayer/ipv6/IPv6Datagram.cc \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6ExtensionHeaders_m.h \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	networklayer/contract/IPv6Address.h
$O/networklayer/ipv6/IPv6ErrorHandling.o: networklayer/ipv6/IPv6ErrorHandling.cc \
	networklayer/icmpv6/ICMPv6Message_m.h \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6ErrorHandling.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/contract/IPv6ControlInfo.h \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	networklayer/contract/IPv6Address.h
$O/networklayer/ipv6/IPv6ExtensionHeaders_m.o: networklayer/ipv6/IPv6ExtensionHeaders_m.cc \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/ipv6/IPv6ExtensionHeaders_m.h \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	networklayer/contract/IPv6Address.h
$O/networklayer/ldp/LDPPacket_m.o: networklayer/ldp/LDPPacket_m.cc \
	networklayer/ldp/LDPPacket_m.h \
	base/INETDefs.h \
	networklayer/contract/IPAddress.h
$O/networklayer/ldp/LDP.o: networklayer/ldp/LDP.cc \
	transport/udp/UDPPacket.h \
	transport/tcp/TCPSegment.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	transport/contract/UDPSocket.h \
	networklayer/ldp/LDPPacket_m.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/ldp/LDP.h \
	base/INotifiable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/mpls/LIBTableAccess.h \
	transport/tcp/TCPSegment_m.h \
	transport/contract/TCPSocketMap.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/IPDatagram_m.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	networklayer/ted/TEDAccess.h \
	networklayer/ted/TED.h \
	transport/udp/UDPPacket_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/mpls/ConstType.h \
	networklayer/mpls/IClassifier.h \
	networklayer/rsvp_te/IntServ_m.h \
	networklayer/ted/TED_m.h \
	transport/contract/UDPControlInfo_m.h \
	networklayer/ipv4/IPDatagram.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/mpls/LIBTable.h \
	base/ModuleAccess.h
$O/networklayer/mpls/MPLS.o: networklayer/mpls/MPLS.cc \
	transport/tcp/TCPSegment.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	transport/contract/UDPSocket.h \
	networklayer/ldp/LDPPacket_m.h \
	networklayer/rsvp_te/Utils.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/ldp/LDP.h \
	base/INotifiable.h \
	networklayer/mpls/MPLSPacket.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/mpls/LIBTableAccess.h \
	transport/tcp/TCPSegment_m.h \
	transport/contract/TCPSocketMap.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	transport/contract/TCPCommand_m.h \
	networklayer/ipv4/IPDatagram_m.h \
	transport/contract/TCPSocket.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/mpls/ConstType.h \
	networklayer/mpls/IClassifier.h \
	networklayer/rsvp_te/IntServ_m.h \
	transport/contract/UDPControlInfo_m.h \
	networklayer/ipv4/IPDatagram.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/mpls/LIBTable.h \
	networklayer/mpls/MPLS.h \
	base/ModuleAccess.h
$O/networklayer/mpls/MPLSPacket.o: networklayer/mpls/MPLSPacket.cc \
	networklayer/mpls/MPLSPacket.h \
	base/INETDefs.h
$O/networklayer/mpls/LIBTable.o: networklayer/mpls/LIBTable.cc \
	networklayer/mpls/ConstType.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IPDatagram.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/IPDatagram_m.h \
	networklayer/mpls/LIBTable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/contract/IPAddress.h \
	base/ModuleAccess.h \
	util/XMLUtils.h
$O/networklayer/ospfv2/OSPFRouting.o: networklayer/ospfv2/OSPFRouting.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/contract/IPv6Address.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/contract/IPAddressResolver.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/OSPFRouting.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/OSPFPacket_m.o: networklayer/ospfv2/OSPFPacket_m.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	base/INETDefs.h \
	networklayer/contract/IPAddress.h
$O/networklayer/ospfv2/OSPFTimer_m.o: networklayer/ospfv2/OSPFTimer_m.cc \
	base/INETDefs.h \
	networklayer/ospfv2/OSPFTimer_m.h
$O/networklayer/ospfv2/interface/OSPFInterfaceStateBackup.o: networklayer/ospfv2/interface/OSPFInterfaceStateBackup.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateLoopback.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateDown.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/interface/OSPFInterfaceState.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateBackup.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/interface/OSPFInterfaceState.o: networklayer/ospfv2/interface/OSPFInterfaceState.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateDesignatedRouter.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateNotDesignatedRouter.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/interface/OSPFInterfaceState.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateBackup.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/interface/OSPFInterfaceStatePointToPoint.o: networklayer/ospfv2/interface/OSPFInterfaceStatePointToPoint.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateLoopback.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ospfv2/interface/OSPFInterfaceStatePointToPoint.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateDown.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/interface/OSPFInterfaceState.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/interface/OSPFInterfaceStateLoopback.o: networklayer/ospfv2/interface/OSPFInterfaceStateLoopback.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/LSA.h \
	base/INETDefs.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateDown.h \
	networklayer/ospfv2/interface/OSPFInterfaceState.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateLoopback.h \
	networklayer/contract/IPAddress.h
$O/networklayer/ospfv2/interface/OSPFInterfaceStateNotDesignatedRouter.o: networklayer/ospfv2/interface/OSPFInterfaceStateNotDesignatedRouter.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateNotDesignatedRouter.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateLoopback.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateDown.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/interface/OSPFInterfaceState.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/interface/OSPFInterface.o: networklayer/ospfv2/interface/OSPFInterface.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	networklayer/contract/IPControlInfo_m.h \
	linklayer/contract/MACAddress.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateDown.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/interface/OSPFInterfaceState.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/interface/OSPFInterfaceStateWaiting.o: networklayer/ospfv2/interface/OSPFInterfaceStateWaiting.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateLoopback.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateDown.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/interface/OSPFInterfaceState.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateWaiting.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/interface/OSPFInterfaceStateDesignatedRouter.o: networklayer/ospfv2/interface/OSPFInterfaceStateDesignatedRouter.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateDesignatedRouter.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateLoopback.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateDown.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/interface/OSPFInterfaceState.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/interface/OSPFInterfaceStateDown.o: networklayer/ospfv2/interface/OSPFInterfaceStateDown.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateNotDesignatedRouter.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateLoopback.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ospfv2/interface/OSPFInterfaceStatePointToPoint.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateDown.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/interface/OSPFInterfaceState.h \
	networklayer/ospfv2/interface/OSPFInterfaceStateWaiting.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.o: networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/messagehandler/HelloHandler.o: networklayer/ospfv2/messagehandler/HelloHandler.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/messagehandler/MessageHandler.o: networklayer/ospfv2/messagehandler/MessageHandler.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.o: networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.o: networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/messagehandler/LinkStateRequestHandler.o: networklayer/ospfv2/messagehandler/LinkStateRequestHandler.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/neighbor/OSPFNeighborStateTwoWay.o: networklayer/ospfv2/neighbor/OSPFNeighborStateTwoWay.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateDown.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateExchangeStart.h \
	networklayer/ospfv2/neighbor/OSPFNeighborState.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateTwoWay.h \
	base/INETDefs.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateInit.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/neighbor/OSPFNeighborStateExchangeStart.o: networklayer/ospfv2/neighbor/OSPFNeighborStateExchangeStart.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateDown.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateExchangeStart.h \
	networklayer/ospfv2/neighbor/OSPFNeighborState.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateTwoWay.h \
	base/INETDefs.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateInit.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateExchange.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/neighbor/OSPFNeighborStateAttempt.o: networklayer/ospfv2/neighbor/OSPFNeighborStateAttempt.cc \
	networklayer/ospfv2/neighbor/OSPFNeighborStateDown.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighborState.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateAttempt.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateInit.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/neighbor/OSPFNeighborStateInit.o: networklayer/ospfv2/neighbor/OSPFNeighborStateInit.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateDown.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateExchangeStart.h \
	networklayer/ospfv2/neighbor/OSPFNeighborState.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateTwoWay.h \
	base/INETDefs.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateInit.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/neighbor/OSPFNeighbor.o: networklayer/ospfv2/neighbor/OSPFNeighbor.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateDown.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighborState.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/neighbor/OSPFNeighborStateFull.o: networklayer/ospfv2/neighbor/OSPFNeighborStateFull.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateDown.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateFull.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateExchangeStart.h \
	networklayer/ospfv2/neighbor/OSPFNeighborState.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateTwoWay.h \
	base/INETDefs.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateInit.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/neighbor/OSPFNeighborStateDown.o: networklayer/ospfv2/neighbor/OSPFNeighborStateDown.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateDown.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighborState.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateAttempt.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateInit.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/neighbor/OSPFNeighborStateLoading.o: networklayer/ospfv2/neighbor/OSPFNeighborStateLoading.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateDown.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateFull.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateExchangeStart.h \
	networklayer/ospfv2/neighbor/OSPFNeighborState.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateLoading.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateTwoWay.h \
	base/INETDefs.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateInit.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/neighbor/OSPFNeighborState.o: networklayer/ospfv2/neighbor/OSPFNeighborState.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighborState.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/neighbor/OSPFNeighborStateExchange.o: networklayer/ospfv2/neighbor/OSPFNeighborStateExchange.cc \
	networklayer/ospfv2/neighbor/OSPFNeighborStateDown.h \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateFull.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateExchangeStart.h \
	networklayer/ospfv2/neighbor/OSPFNeighborState.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateLoading.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateTwoWay.h \
	base/INETDefs.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateInit.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighborStateExchange.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/router/OSPFArea.o: networklayer/ospfv2/router/OSPFArea.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/router/NetworkLSA.o: networklayer/ospfv2/router/NetworkLSA.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/LSA.h \
	base/INETDefs.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/contract/IPAddress.h
$O/networklayer/ospfv2/router/SummaryLSA.o: networklayer/ospfv2/router/SummaryLSA.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/LSA.h \
	base/INETDefs.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/contract/IPAddress.h
$O/networklayer/ospfv2/router/OSPFRouter.o: networklayer/ospfv2/router/OSPFRouter.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/OSPFArea.h \
	networklayer/ospfv2/router/LSA.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ospfv2/messagehandler/LinkStateUpdateHandler.h \
	networklayer/ospfv2/router/OSPFRouter.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/ospfv2/interface/OSPFInterface.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ospfv2/OSPFTimer_m.h \
	networklayer/ospfv2/messagehandler/LinkStateRequestHandler.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ospfv2/messagehandler/DatabaseDescriptionHandler.h \
	networklayer/ospfv2/messagehandler/IMessageHandler.h \
	networklayer/ospfv2/neighbor/OSPFNeighbor.h \
	networklayer/ospfv2/messagehandler/HelloHandler.h \
	networklayer/ospfv2/router/OSPFRoutingTableEntry.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ospfv2/messagehandler/LinkStateAcknowledgementHandler.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/ospfv2/messagehandler/MessageHandler.h \
	base/ModuleAccess.h
$O/networklayer/ospfv2/router/ASExternalLSA.o: networklayer/ospfv2/router/ASExternalLSA.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/LSA.h \
	base/INETDefs.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/contract/IPAddress.h
$O/networklayer/ospfv2/router/RouterLSA.o: networklayer/ospfv2/router/RouterLSA.cc \
	networklayer/ospfv2/OSPFPacket_m.h \
	networklayer/ospfv2/router/LSA.h \
	base/INETDefs.h \
	networklayer/ospfv2/router/OSPFcommon.h \
	networklayer/contract/IPAddress.h
$O/networklayer/queue/DropTailQueue.o: networklayer/queue/DropTailQueue.cc \
	base/IPassiveQueue.h \
	base/INETDefs.h \
	networklayer/queue/DropTailQueue.h \
	base/PassiveQueueBase.h
$O/networklayer/queue/BasicDSCPClassifier.o: networklayer/queue/BasicDSCPClassifier.cc \
	networklayer/ipv6/IPv6Datagram.h \
	networklayer/queue/BasicDSCPClassifier.h \
	networklayer/ipv4/IPDatagram.h \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	networklayer/ipv4/IPDatagram_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	networklayer/queue/IQoSClassifier.h
$O/networklayer/queue/DropTailQoSQueue.o: networklayer/queue/DropTailQoSQueue.cc \
	networklayer/queue/DropTailQoSQueue.h \
	base/IPassiveQueue.h \
	base/INETDefs.h \
	base/PassiveQueueBase.h \
	networklayer/queue/IQoSClassifier.h
$O/networklayer/queue/REDQueue.o: networklayer/queue/REDQueue.cc \
	base/IPassiveQueue.h \
	base/INETDefs.h \
	base/PassiveQueueBase.h \
	networklayer/queue/REDQueue.h
$O/networklayer/rsvp_te/IntServ_m.o: networklayer/rsvp_te/IntServ_m.cc \
	networklayer/rsvp_te/IntServ_m.h \
	base/INETDefs.h \
	networklayer/contract/IPAddress.h
$O/networklayer/rsvp_te/RSVPPathMsg_m.o: networklayer/rsvp_te/RSVPPathMsg_m.cc \
	networklayer/rsvp_te/RSVPPacket.h \
	networklayer/rsvp_te/RSVPPacket_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	base/INETDefs.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/contract/IPAddress.h \
	networklayer/rsvp_te/RSVPPathMsg_m.h
$O/networklayer/rsvp_te/Utils.o: networklayer/rsvp_te/Utils.cc \
	networklayer/rsvp_te/IntServ_m.h \
	networklayer/rsvp_te/Utils.h \
	base/INETDefs.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/contract/IPAddress.h
$O/networklayer/rsvp_te/RSVPHello_m.o: networklayer/rsvp_te/RSVPHello_m.cc \
	networklayer/rsvp_te/RSVPPacket.h \
	networklayer/rsvp_te/RSVPPacket_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	base/INETDefs.h \
	networklayer/contract/IPAddress.h \
	networklayer/rsvp_te/RSVPHello_m.h
$O/networklayer/rsvp_te/SimpleClassifier.o: networklayer/rsvp_te/SimpleClassifier.cc \
	base/NotifierConsts.h \
	networklayer/rsvp_te/RSVPResvMsg.h \
	networklayer/rsvp_te/RSVPAccess.h \
	base/NotificationBoard.h \
	base/INotifiable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/contract/IPAddress.h \
	base/IScriptable.h \
	networklayer/mpls/LIBTableAccess.h \
	networklayer/rsvp_te/RSVPPacket_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/SimpleClassifier.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/IPDatagram_m.h \
	networklayer/rsvp_te/RSVP.h \
	util/XMLUtils.h \
	networklayer/rsvp_te/RSVPPathMsg_m.h \
	networklayer/rsvp_te/IRSVPClassifier.h \
	networklayer/rsvp_te/RSVPPacket.h \
	networklayer/mpls/ConstType.h \
	networklayer/mpls/IClassifier.h \
	networklayer/rsvp_te/IntServ_m.h \
	networklayer/rsvp_te/RSVPHelloMsg.h \
	networklayer/ipv4/IPDatagram.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/mpls/LIBTable.h \
	networklayer/rsvp_te/RSVPHello_m.h \
	base/ModuleAccess.h \
	networklayer/rsvp_te/RSVPResvMsg_m.h \
	networklayer/rsvp_te/SignallingMsg_m.h \
	networklayer/rsvp_te/RSVPPathMsg.h
$O/networklayer/rsvp_te/SignallingMsg_m.o: networklayer/rsvp_te/SignallingMsg_m.cc \
	networklayer/rsvp_te/IntServ_m.h \
	base/INETDefs.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/contract/IPAddress.h \
	networklayer/rsvp_te/SignallingMsg_m.h
$O/networklayer/rsvp_te/RSVPPacket_m.o: networklayer/rsvp_te/RSVPPacket_m.cc \
	networklayer/rsvp_te/RSVPPacket_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	base/INETDefs.h \
	networklayer/contract/IPAddress.h
$O/networklayer/rsvp_te/RSVPResvMsg_m.o: networklayer/rsvp_te/RSVPResvMsg_m.cc \
	networklayer/rsvp_te/RSVPPacket.h \
	networklayer/rsvp_te/RSVPPacket_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	base/INETDefs.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/contract/IPAddress.h \
	networklayer/rsvp_te/RSVPResvMsg_m.h
$O/networklayer/rsvp_te/RSVP.o: networklayer/rsvp_te/RSVP.cc \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/rsvp_te/RSVPResvMsg.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	networklayer/rsvp_te/Utils.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/common/InterfaceEntry.h \
	base/INotifiable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	util/common.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	base/IScriptable.h \
	networklayer/mpls/LIBTableAccess.h \
	networklayer/rsvp_te/RSVPPacket_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/IPDatagram_m.h \
	networklayer/ted/TEDAccess.h \
	networklayer/ted/TED.h \
	networklayer/rsvp_te/RSVP.h \
	networklayer/common/InterfaceTableAccess.h \
	util/XMLUtils.h \
	networklayer/rsvp_te/RSVPPathMsg_m.h \
	networklayer/rsvp_te/IRSVPClassifier.h \
	networklayer/mpls/ConstType.h \
	networklayer/rsvp_te/RSVPPacket.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/mpls/IClassifier.h \
	networklayer/ted/TED_m.h \
	networklayer/rsvp_te/RSVPHelloMsg.h \
	networklayer/rsvp_te/IntServ_m.h \
	networklayer/contract/IPAddressResolver.h \
	networklayer/ipv4/IPDatagram.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/mpls/LIBTable.h \
	networklayer/rsvp_te/RSVPHello_m.h \
	base/ModuleAccess.h \
	networklayer/rsvp_te/RSVPResvMsg_m.h \
	networklayer/rsvp_te/SignallingMsg_m.h \
	networklayer/rsvp_te/RSVPPathMsg.h
$O/networklayer/ted/TED_m.o: networklayer/ted/TED_m.cc \
	networklayer/ted/TED_m.h \
	base/INETDefs.h \
	networklayer/contract/IPAddress.h
$O/networklayer/ted/LinkStateRouting.o: networklayer/ted/LinkStateRouting.cc \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	base/NotificationBoard.h \
	networklayer/ted/LinkStateRouting.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/common/InterfaceToken.h \
	base/INotifiable.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ted/TEDAccess.h \
	networklayer/ted/TED.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ted/LinkStatePacket_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	networklayer/ted/TED_m.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	base/ModuleAccess.h
$O/networklayer/ted/TED.o: networklayer/ted/TED.cc \
	networklayer/ipv4/IPRoute.h \
	base/NotifierConsts.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ted/TED.h \
	base/NotificationBoard.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	networklayer/ted/TED_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/common/InterfaceEntry.h \
	base/INotifiable.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/contract/IPAddress.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h
$O/networklayer/ted/LinkStatePacket_m.o: networklayer/ted/LinkStatePacket_m.cc \
	networklayer/ted/TED_m.h \
	networklayer/ted/LinkStatePacket_m.h \
	base/INETDefs.h \
	networklayer/contract/IPAddress.h
$O/transport/contract/TCPSocketAPI_Base.o: transport/contract/TCPSocketAPI_Base.cc \
	base/InternetTypeDefsWithStandardTypes.h \
	transport/contract/TCPSocketAPI_Base.h
$O/transport/contract/ActiveTCPSocketPool.o: transport/contract/ActiveTCPSocketPool.cc \
	base/InternetTypeDefsWithStandardTypes.h \
	transport/contract/TCPSocketAPI_Base.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	base/INETDefs.h \
	transport/tcp/TCPPortRangeDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	transport/contract/TCPSocketAPI_Inet.h \
	transport/contract/ActiveTCPSocketPool.h
$O/transport/contract/TCPCommand_m.o: transport/contract/TCPCommand_m.cc \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h
$O/transport/contract/UDPControlInfo_m.o: transport/contract/UDPControlInfo_m.cc \
	transport/contract/UDPControlInfo_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h
$O/transport/contract/TCPSocketMgr.o: transport/contract/TCPSocketMgr.cc \
	transport/observer/TCPConnInfoMappingObserver.h \
	transport/contract/TCPSocketMap.h \
	httptools/base/httptLogdefs.h \
	transport/observer/TCPConnInfoDatagram.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/EnforceSingleClassInstanceDefs.h \
	httptools/messages/observer/DuplicateRecord.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	networklayer/contract/IPv6Address.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/sim/cmessageeventobserver.h \
	transport/contract/SocketTimeoutMsg_m.h \
	transport/contract/TCPSocketAPI_Inet.h \
	base/InternetTypeDefsWithStandardTypes.h \
	transport/contract/TCPSocketAPI_Base.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/simunits.h \
	transport/contract/TCPSocketExtension.h \
	networklayer/contract/IPAddressResolver.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/sim/cobserver.h \
	base/INETDefs.h \
	transport/contract/TCPSocketMgr.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	httptools/messages/observer/DuplicateHttpMessageNameObserver.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/omnetppextension.h
$O/transport/contract/TCPSocket.o: transport/contract/TCPSocket.cc \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h
$O/transport/contract/SCTPSocket.o: transport/contract/SCTPSocket.cc \
	transport/contract/SCTPCommand_m.h \
	networklayer/ipv4/RoutingTable.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	transport/sctp/SCTP.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTPAssociation.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/common/InterfaceEntry.h \
	base/INotifiable.h \
	transport/sctp/SCTPMessage.h \
	networklayer/ipv4/RoutingTableAccess.h \
	util/common.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	transport/contract/SCTPCommand.h \
	transport/contract/SCTPSocket.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	transport/sctp/SCTPQueue.h \
	networklayer/common/InterfaceTableAccess.h \
	transport/sctp/SCTPMessage_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/contract/UDPControlInfo_m.h \
	transport/sctp/SCTPSendStream.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h
$O/transport/contract/TCPSocketMap.o: transport/contract/TCPSocketMap.cc \
	transport/contract/TCPSocketMap.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h
$O/transport/contract/SocketTimeoutMsg_m.o: transport/contract/SocketTimeoutMsg_m.cc \
	transport/contract/SocketTimeoutMsg_m.h
$O/transport/contract/SCTPCommand_m.o: transport/contract/SCTPCommand_m.cc \
	networklayer/ipv4/RoutingTable.h \
	transport/contract/SCTPCommand_m.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	transport/sctp/SCTP.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTPAssociation.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/common/InterfaceEntry.h \
	base/INotifiable.h \
	transport/sctp/SCTPMessage.h \
	util/common.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	transport/contract/SCTPCommand.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/common/InterfaceTableAccess.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPMessage_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/contract/UDPControlInfo_m.h \
	transport/sctp/SCTPSendStream.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h
$O/transport/contract/TCPSocketAPI_Inet.o: transport/contract/TCPSocketAPI_Inet.cc \
	base/InternetTypeDefsWithStandardTypes.h \
	transport/contract/TCPSocketAPI_Base.h \
	transport/tcp/TCPSegment_m.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/simunits.h \
	transport/tcp/queues/MsgByteBuffer.h \
	transport/tcp/TCPSegment.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/EnforceSingleClassInstanceDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	base/INETDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	transport/tcp/queues/MsgByteBuffer_m.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/omnetppextension.h \
	transport/contract/TCPSocketAPI_Inet.h
$O/transport/contract/TCPSocketExtension.o: transport/contract/TCPSocketExtension.cc \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/EnforceSingleClassInstanceDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	transport/contract/TCPCommand_m.h \
	transport/contract/TCPSocket.h \
	networklayer/contract/IPv6Address.h \
	transport/contract/SocketTimeoutMsg_m.h \
	transport/contract/TCPSocketAPI_Inet.h \
	base/InternetTypeDefsWithStandardTypes.h \
	transport/contract/TCPSocketAPI_Base.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/simunits.h \
	transport/contract/TCPSocketExtension.h \
	networklayer/contract/IPAddressResolver.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/omnetppextension.h
$O/transport/contract/UDPSocket.o: transport/contract/UDPSocket.cc \
	transport/contract/UDPControlInfo_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/contract/UDPSocket.h
$O/transport/observer/TCPConnInfoMappingObserver.o: transport/observer/TCPConnInfoMappingObserver.cc \
	transport/observer/TCPConnInfoMappingObserver.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/simunits.h \
	transport/observer/TCPConnInfoDatagram.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/sim/cobserver.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/EnforceSingleClassInstanceDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/omnetppextension.h
$O/transport/observer/TCPConnInfoDatagram.o: transport/observer/TCPConnInfoDatagram.cc \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/simunits.h \
	transport/observer/TCPConnInfoDatagram.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/sim/cobserver.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/EnforceSingleClassInstanceDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/omnetppextension.h
$O/transport/rtp/RTPParticipantInfo.o: transport/rtp/RTPParticipantInfo.cc \
	transport/rtp/RTPPacket.h \
	transport/rtp/RTCPPacket.h \
	base/INETDefs.h \
	transport/rtp/reports.h \
	transport/rtp/RTPParticipantInfo.h \
	networklayer/contract/IPAddress.h \
	transport/rtp/sdes.h
$O/transport/rtp/RTPProfile.o: transport/rtp/RTPProfile.cc \
	transport/rtp/RTPPayloadSender.h \
	transport/rtp/RTPInnerPacket.h \
	transport/rtp/RTPPacket.h \
	transport/rtp/RTCPPacket.h \
	base/INETDefs.h \
	transport/rtp/reports.h \
	transport/rtp/RTPProfile.h \
	transport/rtp/RTPSenderControlMessage_m.h \
	transport/rtp/RTPParticipantInfo.h \
	networklayer/contract/IPAddress.h \
	transport/rtp/sdes.h \
	transport/rtp/RTPSenderStatusMessage_m.h \
	transport/rtp/RTPPayloadReceiver.h
$O/transport/rtp/RTPSenderStatusMessage_m.o: transport/rtp/RTPSenderStatusMessage_m.cc \
	base/INETDefs.h \
	transport/rtp/RTPSenderStatusMessage_m.h
$O/transport/rtp/RTPSenderControlMessage_m.o: transport/rtp/RTPSenderControlMessage_m.cc \
	base/INETDefs.h \
	transport/rtp/RTPSenderControlMessage_m.h
$O/transport/rtp/RTPSenderInfo.o: transport/rtp/RTPSenderInfo.cc \
	transport/rtp/RTPPacket.h \
	transport/rtp/RTCPPacket.h \
	base/INETDefs.h \
	transport/rtp/reports.h \
	transport/rtp/RTPParticipantInfo.h \
	networklayer/contract/IPAddress.h \
	transport/rtp/sdes.h \
	transport/rtp/RTPSenderInfo.h
$O/transport/rtp/sdes.o: transport/rtp/sdes.cc \
	base/INETDefs.h \
	transport/rtp/sdes.h
$O/transport/rtp/RTPInterfacePacket.o: transport/rtp/RTPInterfacePacket.cc \
	transport/rtp/RTPInterfacePacket.h \
	base/INETDefs.h \
	transport/rtp/RTPSenderControlMessage_m.h \
	networklayer/contract/IPAddress.h \
	transport/rtp/RTPSenderStatusMessage_m.h
$O/transport/rtp/reports.o: transport/rtp/reports.cc \
	base/INETDefs.h \
	transport/rtp/reports.h \
	networklayer/contract/IPAddress.h
$O/transport/rtp/RTCPPacket.o: transport/rtp/RTCPPacket.cc \
	transport/rtp/RTCPPacket.h \
	base/INETDefs.h \
	transport/rtp/reports.h \
	networklayer/contract/IPAddress.h \
	transport/rtp/sdes.h
$O/transport/rtp/RTPInnerPacket.o: transport/rtp/RTPInnerPacket.cc \
	transport/rtp/RTPInnerPacket.h \
	transport/rtp/RTPPacket.h \
	base/INETDefs.h \
	transport/rtp/RTPSenderControlMessage_m.h \
	networklayer/contract/IPAddress.h \
	transport/rtp/RTPSenderStatusMessage_m.h
$O/transport/rtp/RTPReceiverInfo.o: transport/rtp/RTPReceiverInfo.cc \
	transport/rtp/RTPReceiverInfo.h \
	transport/rtp/RTPPacket.h \
	transport/rtp/RTCPPacket.h \
	base/INETDefs.h \
	transport/rtp/reports.h \
	transport/rtp/RTPParticipantInfo.h \
	networklayer/contract/IPAddress.h \
	transport/rtp/sdes.h
$O/transport/rtp/RTP.o: transport/rtp/RTP.cc \
	transport/rtp/RTPInterfacePacket.h \
	transport/rtp/RTPInnerPacket.h \
	transport/rtp/RTPPacket.h \
	transport/contract/UDPControlInfo_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/rtp/RTPProfile.h \
	transport/rtp/RTPSenderControlMessage_m.h \
	networklayer/contract/IPv6Address.h \
	transport/rtp/RTP.h \
	networklayer/contract/IPAddress.h \
	transport/contract/UDPSocket.h \
	transport/rtp/RTPSenderStatusMessage_m.h
$O/transport/rtp/RTPPayloadReceiver.o: transport/rtp/RTPPayloadReceiver.cc \
	transport/rtp/RTPInnerPacket.h \
	transport/rtp/RTPPacket.h \
	base/INETDefs.h \
	transport/rtp/RTPSenderControlMessage_m.h \
	networklayer/contract/IPAddress.h \
	transport/rtp/RTPSenderStatusMessage_m.h \
	transport/rtp/RTPPayloadReceiver.h
$O/transport/rtp/RTPPacket.o: transport/rtp/RTPPacket.cc \
	transport/rtp/RTPPacket.h \
	base/INETDefs.h
$O/transport/rtp/RTCP.o: transport/rtp/RTCP.cc \
	transport/rtp/RTPReceiverInfo.h \
	transport/rtp/RTCPPacket.h \
	transport/rtp/RTCP.h \
	transport/rtp/RTPSenderControlMessage_m.h \
	networklayer/contract/IPv6Address.h \
	transport/rtp/sdes.h \
	transport/contract/UDPSocket.h \
	transport/rtp/RTPSenderInfo.h \
	transport/rtp/RTPInnerPacket.h \
	transport/rtp/RTPPacket.h \
	transport/contract/UDPControlInfo_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/rtp/reports.h \
	transport/rtp/RTPParticipantInfo.h \
	networklayer/contract/IPAddress.h \
	transport/rtp/RTPSenderStatusMessage_m.h
$O/transport/rtp/RTPPayloadSender.o: transport/rtp/RTPPayloadSender.cc \
	transport/rtp/RTPPayloadSender.h \
	transport/rtp/RTPInnerPacket.h \
	transport/rtp/RTPPacket.h \
	base/INETDefs.h \
	transport/rtp/RTPSenderControlMessage_m.h \
	networklayer/contract/IPAddress.h \
	transport/rtp/RTPSenderStatusMessage_m.h
$O/transport/rtp/profiles/avprofile/RTPAVProfilePayload32Receiver.o: transport/rtp/profiles/avprofile/RTPAVProfilePayload32Receiver.cc \
	transport/rtp/profiles/avprofile/RTPAVProfilePayload32Receiver.h \
	transport/rtp/RTPPacket.h \
	base/INETDefs.h \
	transport/rtp/profiles/avprofile/RTPMpegPacket_m.h \
	transport/rtp/RTPPayloadReceiver.h
$O/transport/rtp/profiles/avprofile/RTPMpegPacket_m.o: transport/rtp/profiles/avprofile/RTPMpegPacket_m.cc \
	base/INETDefs.h \
	transport/rtp/profiles/avprofile/RTPMpegPacket_m.h
$O/transport/rtp/profiles/avprofile/RTPAVProfile.o: transport/rtp/profiles/avprofile/RTPAVProfile.cc \
	transport/rtp/profiles/avprofile/RTPAVProfile.h \
	transport/rtp/RTPInnerPacket.h \
	transport/rtp/RTPPacket.h \
	base/INETDefs.h \
	transport/rtp/RTPProfile.h \
	transport/rtp/RTPSenderControlMessage_m.h \
	networklayer/contract/IPAddress.h \
	transport/rtp/RTPSenderStatusMessage_m.h
$O/transport/rtp/profiles/avprofile/RTPAVProfilePayload32Sender.o: transport/rtp/profiles/avprofile/RTPAVProfilePayload32Sender.cc \
	transport/rtp/RTPPayloadSender.h \
	transport/rtp/profiles/avprofile/RTPAVProfilePayload32Sender.h \
	transport/rtp/RTPInnerPacket.h \
	transport/rtp/RTPPacket.h \
	base/INETDefs.h \
	transport/rtp/RTPSenderControlMessage_m.h \
	transport/rtp/profiles/avprofile/RTPMpegPacket_m.h \
	networklayer/contract/IPAddress.h \
	transport/rtp/RTPSenderStatusMessage_m.h
$O/transport/sctp/SCTPAssociationBase.o: transport/sctp/SCTPAssociationBase.cc \
	transport/contract/SCTPCommand_m.h \
	networklayer/ipv4/RoutingTable.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	transport/sctp/SCTPAlgorithm.h \
	transport/sctp/SCTP.h \
	base/NotificationBoard.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTPAssociation.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/contract/IPControlInfo.h \
	base/INotifiable.h \
	transport/sctp/SCTPMessage.h \
	networklayer/ipv4/RoutingTableAccess.h \
	util/common.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	transport/contract/SCTPCommand.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	transport/sctp/SCTPQueue.h \
	networklayer/common/InterfaceTableAccess.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	transport/sctp/SCTPMessage_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/contract/UDPControlInfo_m.h \
	transport/sctp/SCTPSendStream.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h
$O/transport/sctp/SCTPQueue.o: transport/sctp/SCTPQueue.cc \
	networklayer/ipv4/RoutingTable.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	transport/sctp/SCTP.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTPAssociation.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/common/InterfaceEntry.h \
	base/INotifiable.h \
	transport/sctp/SCTPMessage.h \
	networklayer/ipv4/RoutingTableAccess.h \
	util/common.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	transport/sctp/SCTPQueue.h \
	networklayer/common/InterfaceTableAccess.h \
	transport/sctp/SCTPMessage_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/contract/UDPControlInfo_m.h \
	transport/sctp/SCTPSendStream.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h
$O/transport/sctp/SCTPCCFunctions.o: transport/sctp/SCTPCCFunctions.cc \
	networklayer/ipv4/RoutingTable.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	transport/sctp/SCTP.h \
	base/NotificationBoard.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTPAssociation.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	base/INotifiable.h \
	transport/sctp/SCTPMessage.h \
	networklayer/ipv4/RoutingTableAccess.h \
	util/common.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	networklayer/contract/IPControlInfo_m.h \
	linklayer/contract/MACAddress.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	transport/sctp/SCTPQueue.h \
	networklayer/common/InterfaceTableAccess.h \
	transport/sctp/SCTPMessage_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/contract/UDPControlInfo_m.h \
	transport/sctp/SCTPSendStream.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h
$O/transport/sctp/SCTPAssociationEventProc.o: transport/sctp/SCTPAssociationEventProc.cc \
	networklayer/ipv4/RoutingTable.h \
	transport/contract/SCTPCommand_m.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	transport/sctp/SCTPAlgorithm.h \
	transport/sctp/SCTP.h \
	base/NotificationBoard.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTPAssociation.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/contract/IPControlInfo.h \
	base/INotifiable.h \
	transport/sctp/SCTPMessage.h \
	networklayer/ipv4/RoutingTableAccess.h \
	util/common.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	transport/contract/SCTPCommand.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/common/InterfaceTableAccess.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPMessage_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/contract/UDPControlInfo_m.h \
	transport/sctp/SCTPSendStream.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h
$O/transport/sctp/SCTPAssociationRcvMessage.o: transport/sctp/SCTPAssociationRcvMessage.cc \
	transport/contract/SCTPCommand_m.h \
	networklayer/ipv4/RoutingTable.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	transport/sctp/SCTPAlgorithm.h \
	transport/sctp/SCTP.h \
	base/NotificationBoard.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTPAssociation.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/contract/IPControlInfo.h \
	base/INotifiable.h \
	transport/sctp/SCTPMessage.h \
	networklayer/ipv4/RoutingTableAccess.h \
	util/common.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	transport/contract/SCTPCommand.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/common/InterfaceTableAccess.h \
	transport/sctp/SCTPQueue.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	transport/sctp/SCTPMessage_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/contract/UDPControlInfo_m.h \
	transport/sctp/SCTPSendStream.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h
$O/transport/sctp/SCTP.o: transport/sctp/SCTP.cc \
	transport/contract/SCTPCommand_m.h \
	networklayer/ipv4/RoutingTable.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	transport/sctp/SCTP.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTPAssociation.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPControlInfo.h \
	base/INotifiable.h \
	transport/sctp/SCTPMessage.h \
	util/common.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	transport/contract/SCTPCommand.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/IPDatagram_m.h \
	networklayer/common/InterfaceTableAccess.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPMessage_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/contract/UDPControlInfo_m.h \
	networklayer/ipv4/IPDatagram.h \
	transport/sctp/SCTPSendStream.h \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h
$O/transport/sctp/SCTPAlg.o: transport/sctp/SCTPAlg.cc \
	transport/sctp/SCTPAlg.h \
	networklayer/ipv4/RoutingTable.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	transport/sctp/SCTPAlgorithm.h \
	transport/sctp/SCTP.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTPAssociation.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/contract/IPControlInfo.h \
	base/INotifiable.h \
	transport/sctp/SCTPMessage.h \
	util/common.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/common/InterfaceTableAccess.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPMessage_m.h \
	transport/sctp/SCTPReceiveStream.h \
	networklayer/rsvp_te/IntServ_m.h \
	transport/sctp/SCTPSendStream.h \
	transport/contract/UDPControlInfo_m.h \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h
$O/transport/sctp/SCTPAssociationSendAll.o: transport/sctp/SCTPAssociationSendAll.cc \
	networklayer/ipv4/RoutingTable.h \
	transport/contract/SCTPCommand_m.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	transport/sctp/SCTP.h \
	transport/sctp/SCTPAlgorithm.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTPAssociation.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/contract/IPControlInfo.h \
	base/INotifiable.h \
	transport/sctp/SCTPMessage.h \
	networklayer/ipv4/RoutingTableAccess.h \
	util/common.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	transport/contract/SCTPCommand.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	transport/sctp/SCTPQueue.h \
	networklayer/common/InterfaceTableAccess.h \
	transport/sctp/SCTPMessage_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/contract/UDPControlInfo_m.h \
	transport/sctp/SCTPSendStream.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h
$O/transport/sctp/SCTPSSFunctions.o: transport/sctp/SCTPSSFunctions.cc \
	networklayer/ipv4/RoutingTable.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	transport/sctp/SCTP.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTPAssociation.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/common/InterfaceEntry.h \
	base/INotifiable.h \
	transport/sctp/SCTPMessage.h \
	util/common.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	transport/sctp/SCTPQueue.h \
	networklayer/common/InterfaceTableAccess.h \
	transport/sctp/SCTPMessage_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/contract/UDPControlInfo_m.h \
	transport/sctp/SCTPSendStream.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h
$O/transport/sctp/SCTPAssociationUtil.o: transport/sctp/SCTPAssociationUtil.cc \
	networklayer/ipv4/RoutingTable.h \
	transport/contract/SCTPCommand_m.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	transport/sctp/SCTPAlgorithm.h \
	transport/sctp/SCTP.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTPAssociation.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	base/INotifiable.h \
	transport/sctp/SCTPMessage.h \
	util/common.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	networklayer/ipv6/IPv6InterfaceData.h \
	transport/contract/SCTPCommand.h \
	networklayer/contract/IPControlInfo_m.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/common/InterfaceTableAccess.h \
	transport/sctp/SCTPQueue.h \
	networklayer/ipv4/IPv4InterfaceData.h \
	transport/sctp/SCTPMessage_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/sctp/SCTPSendStream.h \
	transport/contract/UDPControlInfo_m.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h
$O/transport/sctp/SCTPMessage_m.o: transport/sctp/SCTPMessage_m.cc \
	transport/sctp/SCTPMessage_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h
$O/transport/sctp/SCTPMessage.o: transport/sctp/SCTPMessage.cc \
	networklayer/ipv4/RoutingTable.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	transport/sctp/SCTP.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTPAssociation.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/common/InterfaceEntry.h \
	base/INotifiable.h \
	transport/sctp/SCTPMessage.h \
	networklayer/ipv4/RoutingTableAccess.h \
	util/common.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	transport/sctp/SCTPQueue.h \
	networklayer/common/InterfaceTableAccess.h \
	transport/sctp/SCTPMessage_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/contract/UDPControlInfo_m.h \
	transport/sctp/SCTPSendStream.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h
$O/transport/sctp/SCTPReceiveStream.o: transport/sctp/SCTPReceiveStream.cc \
	networklayer/ipv4/RoutingTable.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	transport/sctp/SCTP.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTPAssociation.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/contract/IPControlInfo.h \
	base/INotifiable.h \
	transport/sctp/SCTPMessage.h \
	networklayer/ipv4/RoutingTableAccess.h \
	util/common.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	transport/sctp/SCTPQueue.h \
	networklayer/common/InterfaceTableAccess.h \
	transport/sctp/SCTPMessage_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/contract/UDPControlInfo_m.h \
	transport/sctp/SCTPSendStream.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h
$O/transport/sctp/SCTPSendStream.o: transport/sctp/SCTPSendStream.cc \
	networklayer/ipv4/RoutingTable.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	transport/sctp/SCTP.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTPAssociation.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/common/InterfaceEntry.h \
	base/INotifiable.h \
	transport/sctp/SCTPMessage.h \
	util/common.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/common/InterfaceTableAccess.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPMessage_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/sctp/SCTPSendStream.h \
	transport/contract/UDPControlInfo_m.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h
$O/transport/tcp/TCPConnectionEventProc.o: transport/tcp/TCPConnectionEventProc.cc \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPSegment.h \
	transport/tcp/TCPConnection.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/contract/TCPCommand_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/tcp/TCPSendQueue.h \
	transport/tcp/TCPReceiveQueue.h
$O/transport/tcp/TCPConnectionUtil.o: transport/tcp/TCPConnectionUtil.cc \
	transport/tcp/TCPSegment.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	httptools/messages/observer/DuplicateRecord.h \
	networklayer/contract/IPv6Address.h \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCP.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPControlInfo.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/sim/cobserver.h \
	networklayer/contract/IPAddress.h \
	transport/tcp/TCPSendQueue.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	httptools/messages/observer/DuplicateHttpMessageNameObserver.h \
	networklayer/contract/IPControlInfo_m.h \
	transport/tcp/TCPSegment_m.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/EnforceSingleClassInstanceDefs.h \
	transport/tcp/TCPConnection.h \
	transport/contract/TCPCommand_m.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/sim/cmessageeventobserver.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/simunits.h \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPvXAddress.h \
	transport/tcp/TCPSACKRexmitQueue.h \
	transport/tcp/TCPReceiveQueue.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/omnetppextension.h
$O/transport/tcp/TCP.o: transport/tcp/TCP.cc \
	transport/tcp/TCPSegment_m.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	transport/tcp/TCPSegment.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/EnforceSingleClassInstanceDefs.h \
	transport/tcp/TCPConnection.h \
	httptools/messages/observer/DuplicateRecord.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	transport/contract/TCPCommand_m.h \
	networklayer/contract/IPv6Address.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/sim/cmessageeventobserver.h \
	networklayer/icmpv6/ICMPv6Message_m.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/simunits.h \
	transport/tcp/TCP.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPv6ControlInfo.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/sim/cobserver.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/omnetppextension.h \
	networklayer/ipv4/ICMPMessage_m.h \
	httptools/messages/observer/DuplicateHttpMessageNameObserver.h \
	networklayer/contract/IPControlInfo_m.h
$O/transport/tcp/TCPSACKRexmitQueue.o: transport/tcp/TCPSACKRexmitQueue.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPSegment.h \
	transport/tcp/TCPConnection.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/tcp/TCPSACKRexmitQueue.h
$O/transport/tcp/TCPSegment_m.o: transport/tcp/TCPSegment_m.cc \
	transport/tcp/TCPSegment_m.h \
	base/INETDefs.h
$O/transport/tcp/TCPSegment.o: transport/tcp/TCPSegment.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCPSegment.h \
	base/INETDefs.h
$O/transport/tcp/TCPConnectionRcvSegment.o: transport/tcp/TCPConnectionRcvSegment.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCPSegment.h \
	transport/tcp/TCPConnection.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	transport/contract/TCPCommand_m.h \
	networklayer/contract/IPv6Address.h \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCP.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPAddress.h \
	transport/tcp/TCPSACKRexmitQueue.h \
	transport/tcp/TCPSendQueue.h \
	transport/tcp/TCPReceiveQueue.h
$O/transport/tcp/TCPConnectionBase.o: transport/tcp/TCPConnectionBase.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCPSegment.h \
	transport/tcp/TCPConnection.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	transport/contract/TCPCommand_m.h \
	networklayer/contract/IPv6Address.h \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCP.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPAddress.h \
	transport/tcp/TCPSACKRexmitQueue.h \
	transport/tcp/TCPSendQueue.h \
	transport/tcp/TCPReceiveQueue.h
$O/transport/tcp/flavours/TCPBaseAlg.o: transport/tcp/flavours/TCPBaseAlg.cc \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPSegment.h \
	transport/tcp/TCPConnection.h \
	base/INETDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	networklayer/contract/IPvXAddress.h \
	transport/tcp/flavours/TCPBaseAlg.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/tcp/TCPSACKRexmitQueue.h
$O/transport/tcp/flavours/DumbTCP.o: transport/tcp/flavours/DumbTCP.cc \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPSegment.h \
	transport/tcp/TCPConnection.h \
	base/INETDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	networklayer/contract/IPvXAddress.h \
	transport/tcp/flavours/DumbTCP.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h
$O/transport/tcp/flavours/TCPTahoeRenoFamily.o: transport/tcp/flavours/TCPTahoeRenoFamily.cc \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPSegment.h \
	transport/tcp/TCPConnection.h \
	base/INETDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	transport/tcp/flavours/TCPBaseAlg.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/tcp/flavours/TCPTahoeRenoFamily.h
$O/transport/tcp/flavours/TCPReno.o: transport/tcp/flavours/TCPReno.cc \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPSegment.h \
	transport/tcp/TCPConnection.h \
	base/INETDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	transport/tcp/flavours/TCPBaseAlg.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	transport/tcp/flavours/TCPReno.h \
	networklayer/contract/IPAddress.h \
	transport/tcp/flavours/TCPTahoeRenoFamily.h
$O/transport/tcp/flavours/TCPTahoe.o: transport/tcp/flavours/TCPTahoe.cc \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCP.h \
	transport/tcp/flavours/TCPTahoe.h \
	transport/tcp/TCPSegment.h \
	transport/tcp/TCPConnection.h \
	base/INETDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	transport/tcp/flavours/TCPBaseAlg.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/tcp/flavours/TCPTahoeRenoFamily.h
$O/transport/tcp/flavours/TCPNewReno.o: transport/tcp/flavours/TCPNewReno.cc \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/flavours/TCPNewReno.h \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPSegment.h \
	transport/tcp/TCPConnection.h \
	base/INETDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	transport/tcp/flavours/TCPBaseAlg.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/tcp/flavours/TCPTahoeRenoFamily.h
$O/transport/tcp/flavours/TCPNoCongestionControl.o: transport/tcp/flavours/TCPNoCongestionControl.cc \
	transport/tcp/TCPAlgorithm.h \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCP.h \
	transport/tcp/flavours/TCPNoCongestionControl.h \
	transport/tcp/TCPSegment.h \
	transport/tcp/TCPConnection.h \
	base/INETDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	transport/tcp/flavours/TCPBaseAlg.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h
$O/transport/tcp/queues/TCPMsgBasedSendQueue.o: transport/tcp/queues/TCPMsgBasedSendQueue.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPSegment.h \
	transport/tcp/TCPConnection.h \
	base/INETDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/tcp/TCPSendQueue.h \
	transport/tcp/queues/TCPMsgBasedSendQueue.h
$O/transport/tcp/queues/TCPVirtualDataSendQueue.o: transport/tcp/queues/TCPVirtualDataSendQueue.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPSegment.h \
	transport/tcp/TCPConnection.h \
	base/INETDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/tcp/TCPSendQueue.h \
	transport/tcp/queues/TCPVirtualDataSendQueue.h
$O/transport/tcp/queues/MsgByteBuffer_m.o: transport/tcp/queues/MsgByteBuffer_m.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCPSegment.h \
	base/INETDefs.h \
	transport/tcp/queues/MsgByteBuffer_m.h
$O/transport/tcp/queues/TCPMsgByteBufferSendQueue.o: transport/tcp/queues/TCPMsgByteBufferSendQueue.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCPSegment.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/EnforceSingleClassInstanceDefs.h \
	transport/tcp/TCPConnection.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	networklayer/contract/IPv6Address.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/simunits.h \
	transport/tcp/TCP.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/tcp/queues/TCPMsgByteBufferSendQueue.h \
	networklayer/contract/IPAddress.h \
	transport/tcp/TCPSendQueue.h \
	transport/tcp/queues/TCPMsgBasedSendQueue.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/omnetppextension.h
$O/transport/tcp/queues/TCPMsgBasedRcvQueue.o: transport/tcp/queues/TCPMsgBasedRcvQueue.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPSegment.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/queues/TCPVirtualDataRcvQueue.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/tcp/queues/TCPMsgBasedRcvQueue.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/tcp/TCPReceiveQueue.h
$O/transport/tcp/queues/MsgByteBuffer.o: transport/tcp/queues/MsgByteBuffer.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/queues/MsgByteBuffer.h \
	transport/tcp/TCPSegment.h \
	base/INETDefs.h \
	transport/tcp/queues/MsgByteBuffer_m.h
$O/transport/tcp/queues/TCPVirtualDataRcvQueue.o: transport/tcp/queues/TCPVirtualDataRcvQueue.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCP.h \
	transport/tcp/TCPSegment.h \
	transport/tcp/TCPConnection.h \
	transport/tcp/queues/TCPVirtualDataRcvQueue.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/tcp/TCPReceiveQueue.h
$O/transport/tcp/queues/TCPMsgByteBufferRcvQueue.o: transport/tcp/queues/TCPMsgByteBufferRcvQueue.cc \
	transport/tcp/queues/TCPMsgByteBufferRcvQueue.h \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/queues/MsgByteBuffer.h \
	transport/tcp/TCPSegment.h \
	transport/tcp/TCPConnection.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	transport/tcp/queues/TCPMsgBasedRcvQueue.h \
	networklayer/contract/IPv6Address.h \
	transport/tcp/queues/MsgByteBuffer_m.h \
	transport/tcp/TCP.h \
	transport/tcp/queues/TCPVirtualDataRcvQueue.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPAddress.h \
	transport/tcp/TCPReceiveQueue.h
$O/transport/tcp/queues/test/ByteBufferServer.o: transport/tcp/queues/test/ByteBufferServer.cc \
	transport/tcp/queues/test/ByteBufferServer.h \
	transport/tcp/queues/MsgByteBuffer.h \
	transport/tcp/TCPSegment.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	networklayer/contract/IPv6Address.h \
	base/InternetTypeDefsWithStandardTypes.h \
	transport/contract/TCPSocketExtension.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	transport/contract/TCPSocketMgr.h \
	httptools/messages/httptMessages_m.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	httptools/base/httptUtils.h \
	transport/contract/TCPSocketMap.h \
	transport/tcp/TCPSegment_m.h \
	httptools/base/httptLogdefs.h \
	httptools/base/httptController.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/EnforceSingleClassInstanceDefs.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPCommand_m.h \
	transport/tcp/TCPPortRangeDefs.h \
	applications/tcpapp/socketapi/TCPSocketMgrAppUtils.h \
	httptools/messages/HTTPMsgDefs.h \
	transport/contract/SocketTimeoutMsg_m.h \
	transport/tcp/queues/MsgByteBuffer_m.h \
	transport/contract/TCPSocketAPI_Inet.h \
	transport/tcp/queues/test/ByteBufferNode.h \
	transport/contract/TCPSocketAPI_Base.h \
	httptools/base/httptServerBase.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/envir/dynamicresultrecorder.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/simunits.h \
	networklayer/contract/IPAddressResolver.h \
	httptools/base/httptNodeBase.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/omnetppextension.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/envir/dynamicresultrecorders.h
$O/transport/tcp/queues/test/ByteBufferNode.o: transport/tcp/queues/test/ByteBufferNode.cc \
	transport/tcp/queues/test/ByteBufferNode.h
$O/transport/tcp/queues/test/ByteBufferClient.o: transport/tcp/queues/test/ByteBufferClient.cc \
	transport/tcp/queues/MsgByteBuffer.h \
	transport/tcp/TCPSegment.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	networklayer/contract/IPv6Address.h \
	base/InternetTypeDefsWithStandardTypes.h \
	transport/contract/TCPSocketExtension.h \
	httptools/base/httptRandom.h \
	httptools/messages/httptEventMessages_m.h \
	transport/contract/TCPSocketMgr.h \
	httptools/messages/httptMessages_m.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	httptools/base/httptUtils.h \
	transport/contract/TCPSocketMap.h \
	transport/tcp/TCPSegment_m.h \
	httptools/base/httptLogdefs.h \
	httptools/base/httptController.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/EnforceSingleClassInstanceDefs.h \
	transport/contract/TCPSocket.h \
	transport/contract/TCPCommand_m.h \
	applications/tcpapp/socketapi/TCPSocketMgrAppUtils.h \
	httptools/messages/HTTPMsgDefs.h \
	transport/contract/SocketTimeoutMsg_m.h \
	transport/tcp/queues/MsgByteBuffer_m.h \
	transport/contract/TCPSocketAPI_Inet.h \
	transport/tcp/queues/test/ByteBufferNode.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/envir/dynamicresultrecorder.h \
	transport/contract/TCPSocketAPI_Base.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/simunits.h \
	networklayer/contract/IPAddressResolver.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	transport/tcp/queues/test/ByteBufferClient.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/omnetppextension.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/src/envir/dynamicresultrecorders.h
$O/transport/tcp_nsc/TCP_NSC_Connection.o: transport/tcp_nsc/TCP_NSC_Connection.cc \
	transport/tcp_nsc/TCP_NSC.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	transport/tcp/TCPSegment_m.h \
	util/headerserializers/headers/tcp.h \
	transport/tcp/TCPSegment.h \
	util/headerserializers/headers/defs.h \
	transport/contract/TCPCommand_m.h \
	networklayer/contract/IPv6Address.h \
	transport/tcp_nsc/queues/TCP_NSC_Queues.h \
	util/headerserializers/TCPSerializer.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPProtocolId_m.h \
	util/headerserializers/TCPIPchecksum.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/tcp_nsc/TCP_NSC_Connection.h \
	networklayer/contract/IPAddress.h \
	networklayer/contract/IPControlInfo_m.h
$O/transport/tcp_nsc/TCP_NSC.o: transport/tcp_nsc/TCP_NSC.cc \
	transport/tcp_nsc/TCP_NSC.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	transport/tcp/TCPSegment_m.h \
	util/headerserializers/headers/tcp.h \
	transport/tcp/TCPSegment.h \
	util/headerserializers/headers/defs.h \
	transport/contract/TCPCommand_m.h \
	networklayer/contract/IPv6Address.h \
	transport/tcp_nsc/queues/TCP_NSC_Queues.h \
	util/headerserializers/TCPSerializer.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPProtocolId_m.h \
	util/headerserializers/TCPIPchecksum.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/tcp_nsc/TCP_NSC_Connection.h \
	networklayer/contract/IPAddress.h \
	networklayer/contract/IPControlInfo_m.h
$O/transport/tcp_nsc/queues/TCP_NSC_VirtualDataQueues.o: transport/tcp_nsc/queues/TCP_NSC_VirtualDataQueues.cc \
	transport/tcp/TCPSegment_m.h \
	util/headerserializers/headers/tcp.h \
	transport/tcp/TCPSegment.h \
	transport/tcp/TCPConnection.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DebugDef.h \
	util/headerserializers/headers/defs.h \
	transport/contract/TCPCommand_m.h \
	networklayer/contract/IPv6Address.h \
	transport/tcp_nsc/queues/TCP_NSC_Queues.h \
	util/headerserializers/TCPSerializer.h \
	transport/tcp/TCP.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/tcp_nsc/TCP_NSC_Connection.h \
	networklayer/contract/IPAddress.h \
	transport/tcp_nsc/queues/TCP_NSC_VirtualDataQueues.h
$O/transport/tcp_old/TCPConnectionRcvSegment.o: transport/tcp_old/TCPConnectionRcvSegment.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp_old/TCPSendQueue_old.h \
	transport/tcp/TCPSegment.h \
	base/INETDefs.h \
	transport/tcp_old/TCPAlgorithm_old.h \
	networklayer/contract/IPvXAddress.h \
	transport/tcp_old/TCPConnection_old.h \
	transport/contract/TCPCommand_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/tcp_old/TCPReceiveQueue_old.h \
	transport/tcp_old/TCP_old.h
$O/transport/tcp_old/TCP.o: transport/tcp_old/TCP.cc \
	networklayer/contract/IPv6ControlInfo_m.h \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCPSegment.h \
	transport/contract/TCPCommand_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/icmpv6/ICMPv6Message_m.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/tcp_old/TCPConnection_old.h \
	networklayer/contract/IPAddress.h \
	transport/tcp_old/TCP_old.h \
	networklayer/ipv4/ICMPMessage_m.h \
	networklayer/contract/IPControlInfo_m.h
$O/transport/tcp_old/TCPConnectionBase.o: transport/tcp_old/TCPConnectionBase.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp_old/TCPSendQueue_old.h \
	transport/tcp/TCPSegment.h \
	base/INETDefs.h \
	transport/tcp_old/TCPAlgorithm_old.h \
	networklayer/contract/IPvXAddress.h \
	transport/tcp_old/TCPConnection_old.h \
	transport/contract/TCPCommand_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/tcp_old/TCPReceiveQueue_old.h \
	transport/tcp_old/TCP_old.h
$O/transport/tcp_old/TCPConnectionEventProc.o: transport/tcp_old/TCPConnectionEventProc.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp_old/TCPSendQueue_old.h \
	transport/tcp/TCPSegment.h \
	base/INETDefs.h \
	transport/tcp_old/TCPAlgorithm_old.h \
	networklayer/contract/IPvXAddress.h \
	transport/tcp_old/TCPConnection_old.h \
	transport/contract/TCPCommand_m.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/tcp_old/TCPReceiveQueue_old.h \
	transport/tcp_old/TCP_old.h
$O/transport/tcp_old/TCPConnectionUtil.o: transport/tcp_old/TCPConnectionUtil.cc \
	networklayer/contract/IPv6ControlInfo_m.h \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCPSegment.h \
	transport/contract/TCPCommand_m.h \
	networklayer/contract/IPv6Address.h \
	transport/tcp_old/TCPSendQueue_old.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	transport/tcp_old/TCPAlgorithm_old.h \
	networklayer/contract/IPvXAddress.h \
	transport/tcp_old/TCPConnection_old.h \
	networklayer/contract/IPAddress.h \
	transport/tcp_old/TCP_old.h \
	transport/tcp_old/TCPReceiveQueue_old.h \
	networklayer/contract/IPControlInfo_m.h
$O/transport/tcp_old/flavours/DumbTCP.o: transport/tcp_old/flavours/DumbTCP.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCPSegment.h \
	transport/tcp_old/TCPAlgorithm_old.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/tcp_old/TCPConnection_old.h \
	networklayer/contract/IPv6Address.h \
	transport/tcp_old/flavours/DumbTCP_old.h \
	networklayer/contract/IPAddress.h \
	transport/tcp_old/TCP_old.h
$O/transport/tcp_old/flavours/TCPTahoe.o: transport/tcp_old/flavours/TCPTahoe.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp_old/flavours/TCPBaseAlg_old.h \
	transport/tcp/TCPSegment.h \
	transport/tcp_old/TCPAlgorithm_old.h \
	base/INETDefs.h \
	transport/tcp_old/TCPConnection_old.h \
	transport/tcp_old/flavours/TCPTahoeRenoFamily_old.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/tcp_old/TCP_old.h \
	transport/tcp_old/flavours/TCPTahoe_old.h
$O/transport/tcp_old/flavours/TCPNoCongestionControl.o: transport/tcp_old/flavours/TCPNoCongestionControl.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp_old/flavours/TCPBaseAlg_old.h \
	transport/tcp/TCPSegment.h \
	transport/tcp_old/TCPAlgorithm_old.h \
	base/INETDefs.h \
	transport/tcp_old/TCPConnection_old.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/tcp_old/TCP_old.h \
	transport/tcp_old/flavours/TCPNoCongestionControl_old.h
$O/transport/tcp_old/flavours/TCPTahoeRenoFamily.o: transport/tcp_old/flavours/TCPTahoeRenoFamily.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp_old/flavours/TCPBaseAlg_old.h \
	transport/tcp/TCPSegment.h \
	base/INETDefs.h \
	transport/tcp_old/TCPAlgorithm_old.h \
	transport/tcp_old/TCPConnection_old.h \
	networklayer/contract/IPvXAddress.h \
	transport/tcp_old/flavours/TCPTahoeRenoFamily_old.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/tcp_old/TCP_old.h
$O/transport/tcp_old/flavours/TCPBaseAlg.o: transport/tcp_old/flavours/TCPBaseAlg.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp_old/flavours/TCPBaseAlg_old.h \
	transport/tcp/TCPSegment.h \
	base/INETDefs.h \
	transport/tcp_old/TCPAlgorithm_old.h \
	transport/tcp_old/TCPConnection_old.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/tcp_old/TCP_old.h
$O/transport/tcp_old/flavours/TCPReno.o: transport/tcp_old/flavours/TCPReno.cc \
	transport/tcp_old/flavours/TCPReno_old.h \
	transport/tcp/TCPSegment_m.h \
	transport/tcp_old/flavours/TCPBaseAlg_old.h \
	transport/tcp/TCPSegment.h \
	base/INETDefs.h \
	transport/tcp_old/TCPAlgorithm_old.h \
	transport/tcp_old/TCPConnection_old.h \
	networklayer/contract/IPvXAddress.h \
	transport/tcp_old/flavours/TCPTahoeRenoFamily_old.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/tcp_old/TCP_old.h
$O/transport/tcp_old/queues/TCPVirtualDataSendQueue.o: transport/tcp_old/queues/TCPVirtualDataSendQueue.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp_old/TCPSendQueue_old.h \
	transport/tcp/TCPSegment.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/tcp_old/TCPConnection_old.h \
	networklayer/contract/IPv6Address.h \
	transport/tcp_old/queues/TCPVirtualDataSendQueue_old.h \
	networklayer/contract/IPAddress.h \
	transport/tcp_old/TCP_old.h
$O/transport/tcp_old/queues/TCPVirtualDataRcvQueue.o: transport/tcp_old/queues/TCPVirtualDataRcvQueue.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCPSegment.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/tcp_old/TCPConnection_old.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/tcp_old/queues/TCPVirtualDataRcvQueue_old.h \
	transport/tcp_old/TCP_old.h \
	transport/tcp_old/TCPReceiveQueue_old.h
$O/transport/tcp_old/queues/TCPMsgBasedSendQueue.o: transport/tcp_old/queues/TCPMsgBasedSendQueue.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp_old/TCPSendQueue_old.h \
	transport/tcp/TCPSegment.h \
	transport/tcp_old/queues/TCPMsgBasedSendQueue_old.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/tcp_old/TCPConnection_old.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/tcp_old/TCP_old.h
$O/transport/tcp_old/queues/TCPMsgBasedRcvQueue.o: transport/tcp_old/queues/TCPMsgBasedRcvQueue.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCPSegment.h \
	transport/tcp_old/queues/TCPMsgBasedRcvQueue_old.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	transport/tcp_old/TCPConnection_old.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	transport/tcp_old/queues/TCPVirtualDataRcvQueue_old.h \
	transport/tcp_old/TCP_old.h \
	transport/tcp_old/TCPReceiveQueue_old.h
$O/transport/udp/UDP.o: transport/udp/UDP.cc \
	transport/udp/UDP.h \
	networklayer/ipv6/IPv6Datagram.h \
	transport/udp/UDPPacket.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	base/NotificationBoard.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPv6ControlInfo.h \
	networklayer/contract/IPControlInfo.h \
	base/INotifiable.h \
	networklayer/ipv6/RoutingTable6Access.h \
	networklayer/icmpv6/ICMPv6.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	networklayer/icmpv6/ICMPv6Access.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	networklayer/ipv6/RoutingTable6.h \
	networklayer/ipv4/ICMP.h \
	networklayer/contract/IPv6ControlInfo_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/IPDatagram_m.h \
	transport/udp/UDPPacket_m.h \
	networklayer/icmpv6/ICMPv6Message_m.h \
	networklayer/ipv4/ICMPMessage.h \
	transport/contract/UDPControlInfo_m.h \
	networklayer/ipv4/ICMPAccess.h \
	base/INETDefs.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/ipv4/ICMPMessage_m.h
$O/transport/udp/UDPPacket_m.o: transport/udp/UDPPacket_m.cc \
	base/INETDefs.h \
	transport/udp/UDPPacket_m.h
$O/util/XMLUtils.o: util/XMLUtils.cc \
	networklayer/contract/IPAddressResolver.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	util/XMLUtils.h
$O/util/NetAnimTrace.o: util/NetAnimTrace.cc \
	util/NetAnimTrace.h \
	base/INETDefs.h
$O/util/NAMTraceWriter.o: util/NAMTraceWriter.cc \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	world/NAMTrace.h \
	base/NotificationBoard.h \
	networklayer/common/InterfaceTableAccess.h \
	linklayer/contract/TxNotifDetails.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	base/INotifiable.h \
	base/INETDefs.h \
	util/NAMTraceWriter.h \
	base/ModuleAccess.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h
$O/util/opp_utils.o: util/opp_utils.cc \
	base/INETDefs.h \
	util/opp_utils.h
$O/util/common.o: util/common.cc \
	networklayer/rsvp_te/IntServ_m.h \
	networklayer/rsvp_te/IntServ.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	networklayer/contract/IPv6Address.h \
	util/common.h \
	networklayer/contract/IPAddress.h
$O/util/TCPDump.o: util/TCPDump.cc \
	transport/tcp/TCPSegment.h \
	networklayer/ipv4/RoutingTable.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	transport/sctp/SCTP.h \
	base/NotificationBoard.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTPAssociation.h \
	util/TCPDump.h \
	networklayer/common/InterfaceToken.h \
	networklayer/contract/IPControlInfo.h \
	networklayer/common/InterfaceEntry.h \
	base/INotifiable.h \
	networklayer/ipv6/IPv6Datagram_m.h \
	transport/sctp/SCTPMessage.h \
	util/common.h \
	networklayer/ipv4/RoutingTableAccess.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	transport/tcp/TCPSegment_m.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/ipv4/IPDatagram_m.h \
	transport/udp/UDPPacket_m.h \
	networklayer/common/InterfaceTableAccess.h \
	transport/sctp/SCTPQueue.h \
	util/headerserializers/IPSerializer.h \
	transport/sctp/SCTPMessage_m.h \
	networklayer/rsvp_te/IntServ_m.h \
	transport/sctp/SCTPReceiveStream.h \
	networklayer/ipv4/ICMPMessage.h \
	transport/contract/UDPControlInfo_m.h \
	transport/sctp/SCTPSendStream.h \
	networklayer/ipv4/IPDatagram.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h \
	networklayer/ipv4/ICMPMessage_m.h
$O/util/ThruputMeteringChannel.o: util/ThruputMeteringChannel.cc \
	base/INETDefs.h \
	util/ThruputMeteringChannel.h
$O/util/headerserializers/IPSerializer.o: util/headerserializers/IPSerializer.cc \
	transport/udp/UDPPacket.h \
	transport/tcp/TCPSegment.h \
	networklayer/contract/IPv6Address.h \
	util/headerserializers/TCPSerializer.h \
	transport/sctp/SCTPMessage.h \
	networklayer/contract/IPAddress.h \
	util/headerserializers/SCTPSerializer.h \
	transport/tcp/TCPSegment_m.h \
	util/headerserializers/headers/bsdint.h \
	util/headerserializers/headers/tcp.h \
	util/headerserializers/headers/defs.h \
	networklayer/ipv4/IPDatagram_m.h \
	util/headerserializers/UDPSerializer.h \
	transport/udp/UDPPacket_m.h \
	util/headerserializers/IPSerializer.h \
	util/headerserializers/headers/ip.h \
	transport/sctp/SCTPMessage_m.h \
	util/headerserializers/ICMPSerializer.h \
	networklayer/ipv4/IPDatagram.h \
	networklayer/contract/IPProtocolId_m.h \
	util/headerserializers/headers/in_systm.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	util/headerserializers/headers/in.h \
	networklayer/ipv4/ICMPMessage_m.h
$O/util/headerserializers/TCPSerializer.o: util/headerserializers/TCPSerializer.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCPSegment.h \
	util/headerserializers/headers/tcp.h \
	util/headerserializers/headers/bsdint.h \
	base/INETDefs.h \
	util/headerserializers/headers/in_systm.h \
	util/headerserializers/TCPIPchecksum.h \
	networklayer/contract/IPProtocolId_m.h \
	networklayer/contract/IPvXAddress.h \
	util/headerserializers/headers/defs.h \
	util/headerserializers/headers/in.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h \
	util/headerserializers/TCPSerializer.h
$O/util/headerserializers/ICMPSerializer.o: util/headerserializers/ICMPSerializer.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCPSegment.h \
	util/headerserializers/headers/tcp.h \
	util/headerserializers/headers/bsdint.h \
	util/headerserializers/headers/ip_icmp.h \
	util/headerserializers/headers/defs.h \
	networklayer/ipv4/IPDatagram_m.h \
	networklayer/contract/IPv6Address.h \
	util/headerserializers/IPSerializer.h \
	util/headerserializers/headers/ip.h \
	util/headerserializers/ICMPSerializer.h \
	networklayer/ipv4/IPDatagram.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	util/headerserializers/headers/in_systm.h \
	util/headerserializers/TCPIPchecksum.h \
	networklayer/contract/IPvXAddress.h \
	util/headerserializers/headers/in.h \
	applications/pingapp/PingPayload_m.h \
	networklayer/contract/IPAddress.h \
	networklayer/ipv4/ICMPMessage_m.h
$O/util/headerserializers/UDPSerializer.o: util/headerserializers/UDPSerializer.cc \
	transport/tcp/TCPSegment_m.h \
	transport/udp/UDPPacket.h \
	util/headerserializers/headers/bsdint.h \
	util/headerserializers/headers/tcp.h \
	transport/tcp/TCPSegment.h \
	util/headerserializers/headers/defs.h \
	networklayer/contract/IPv6Address.h \
	util/headerserializers/UDPSerializer.h \
	transport/udp/UDPPacket_m.h \
	util/headerserializers/headers/udp.h \
	util/headerserializers/headers/in_systm.h \
	util/headerserializers/TCPIPchecksum.h \
	base/INETDefs.h \
	networklayer/contract/IPvXAddress.h \
	util/headerserializers/headers/in.h \
	networklayer/contract/IPAddress.h
$O/util/headerserializers/TCPIPchecksum.o: util/headerserializers/TCPIPchecksum.cc \
	transport/tcp/TCPSegment_m.h \
	transport/tcp/TCPSegment.h \
	util/headerserializers/headers/tcp.h \
	base/INETDefs.h \
	util/headerserializers/TCPIPchecksum.h \
	networklayer/contract/IPvXAddress.h \
	util/headerserializers/headers/defs.h \
	networklayer/contract/IPv6Address.h \
	networklayer/contract/IPAddress.h
$O/util/headerserializers/SCTPSerializer.o: util/headerserializers/SCTPSerializer.cc \
	networklayer/ipv4/RoutingTable.h \
	base/NotifierConsts.h \
	networklayer/common/IInterfaceTable.h \
	networklayer/contract/IPv6Address.h \
	transport/sctp/SCTP.h \
	base/NotificationBoard.h \
	transport/contract/UDPSocket.h \
	transport/sctp/SCTPAssociation.h \
	networklayer/common/InterfaceToken.h \
	networklayer/common/InterfaceEntry.h \
	networklayer/contract/IPControlInfo.h \
	base/INotifiable.h \
	transport/sctp/SCTPMessage.h \
	networklayer/ipv4/RoutingTableAccess.h \
	util/common.h \
	networklayer/contract/IPAddress.h \
	$(OMNET_EXTENSION_MASTER_PROJ)/include/DeleteSafeDefs.h \
	util/headerserializers/SCTPSerializer.h \
	linklayer/contract/MACAddress.h \
	networklayer/contract/IPControlInfo_m.h \
	util/headerserializers/headers/bsdint.h \
	networklayer/ipv4/IPRoute.h \
	networklayer/rsvp_te/IntServ.h \
	util/headerserializers/headers/defs.h \
	networklayer/ipv4/IRoutingTable.h \
	networklayer/common/InterfaceTableAccess.h \
	transport/sctp/SCTPQueue.h \
	transport/sctp/SCTPMessage_m.h \
	util/headerserializers/headers/ip.h \
	networklayer/rsvp_te/IntServ_m.h \
	transport/sctp/SCTPReceiveStream.h \
	transport/contract/UDPControlInfo_m.h \
	transport/sctp/SCTPSendStream.h \
	networklayer/contract/IPProtocolId_m.h \
	base/INETDefs.h \
	util/headerserializers/headers/in_systm.h \
	networklayer/contract/IPvXAddress.h \
	util/headerserializers/headers/sctp.h \
	util/headerserializers/headers/in.h \
	base/ModuleAccess.h \
	networklayer/common/InterfaceTable.h
$O/world/NAMTrace.o: world/NAMTrace.cc \
	base/INETDefs.h \
	world/NAMTrace.h
$O/world/ScenarioManager.o: world/ScenarioManager.cc \
	base/IScriptable.h \
	base/INETDefs.h \
	world/ScenarioManager.h
$O/world/ChannelInstaller.o: world/ChannelInstaller.cc \
	base/INETDefs.h \
	world/ChannelInstaller.h
$O/world/ChannelAccess.o: world/ChannelAccess.cc \
	world/ChannelControl.h \
	world/ChannelAccess.h \
	base/BasicModule.h \
	util/FWMath.h \
	base/INotifiable.h \
	base/NotifierConsts.h \
	base/INETDefs.h \
	linklayer/mfcore/AirFrame_m.h \
	base/NotificationBoard.h \
	base/ModuleAccess.h \
	base/Coord.h
$O/world/ChannelControl.o: world/ChannelControl.cc \
	world/ChannelControl.h \
	util/FWMath.h \
	base/INETDefs.h \
	linklayer/mfcore/AirFrame_m.h \
	base/Coord.h

