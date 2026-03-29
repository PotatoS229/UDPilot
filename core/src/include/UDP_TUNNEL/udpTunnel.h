#pragma once 
#include <string>
#include <vector> 
#include <iostream>
#include <iomanip>

namespace udpTunnel {
    struct udpTunnelStruct {
        std::vector<std::string> udpTunnelData{};
        void startUdpTunnel();  
    };
}