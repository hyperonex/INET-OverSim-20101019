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

package inet.httptools.videocomponents.client.modules;

//
// TODO auto-generated module
//
simple AdditiveClient like IAdaptiveClient
{
    parameters:
        string socketapi;
        string controller = default("controller");
        string serverwww = default("server.omnet.net");
        string address = default("");
        int port = default(2000);
        int httpProtocol = default(11);
 		int logLevel = default(2);
 		string logFile = default("");
 		
 		int numSockets = default(1);
 		double segmentDuration @unit(s) = default(2s); // seconds per chunk
 		//string policy = default("vertical");
 		int policy = default(0); // enumerated
 		double diagPolicySlope = default(-1.0);
 		int blockSize @unit(Byte) = default(10000B); // assumed linear increase in bytes per quality.
 		int numSegments = default(7); // duration of video
 		double startTime @unit(s) = uniform(0s,10s);
 		double rateMeasurementInterval @unit(s) = default(0.125s);
 		double rateMeasurementAlpha = default(0.125);
 		double rttMeasurementAlpha = default(0.6);
 		double epsilon @unit(s) = default(0.5s);
 		double meanRateAlpha = default(0.02);
 		bool useRealMean = default(false); // for meanVertical (rate est. for larger timescales of about 1 minute)
 		int maxBufferSizeKB = default(5000000); // maximum buffer size.
}
