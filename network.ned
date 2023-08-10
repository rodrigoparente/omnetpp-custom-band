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

import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.node.inet.AdhocHost;
import inet.node.inet.WirelessHost;
import inet.physicallayer.ieee80211.packetlevel.Ieee80211DimensionalRadioMedium;
import inet.visualizer.contract.IIntegratedVisualizer;


network wirelessnetwork
{
    parameters:
        int interfaces = 2;

        @display("bgb=650,500;bgg=100,1,grey95");
        @figure[title](type=label; pos=0,-1; anchor=sw; color=darkblue);

    submodules:
        visualizer: <default("IntegratedCanvasVisualizer")> like IIntegratedVisualizer if hasVisualizer() {
            @display("p=580.60803,40.32");
        }
        configurator: IPv4NetworkConfigurator {
            @display("p=580.60803,102.816");
        }
        radioMedium: Ieee80211DimensionalRadioMedium {
            @display("p=579.60004,164.304");
        }
        hostAP1[interfaces]: AdhocHost {
            parameters:
                @display("p=117.936005,151.2;i=device/accesspoint");
        }
        hostAP2[interfaces]: AdhocHost {
            parameters:
                @display("p=479.808,431.424;i=device/accesspoint");
        }
        hostWifiA: AdhocHost {
            parameters:
                @display("p=145.15201,267.12;i=device/wifilaptop");
        }
        hostWifiB: AdhocHost {
            parameters:
                @display("p=235.87201,131.04001;i=device/wifilaptop");
        }
        hostWifiC: AdhocHost {
            parameters:
                @display("p=342.72,400.17603;i=device/wifilaptop");
        }
        hostZigbeeA: AdhocHost {
            parameters:
                @display("p=48.384003,61.488003;i=device/palm2");
        }
        hostZigbeeB: AdhocHost {
            parameters:
                @display("p=458.64,338.68802;i=device/palm2");
        }
        hostZigbeeC: AdhocHost {
            parameters:
                @display("p=571.536,363.888;i=device/palm2");
        }
}
