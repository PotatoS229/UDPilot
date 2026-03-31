#pragma once 
#include <string>
#include <vector> 
#include <iostream>
#include <iomanip>
#if defined (linux)
    #include <libnetfilter_queue/libnetfilter_queue.h>
#else
    #include <PcapPlusPlus>
#endif
namespace proxy {
    struct proxyStruct {
        std::vector<std::string> udpTunnelData{};
        void startProxy();  
    };
}