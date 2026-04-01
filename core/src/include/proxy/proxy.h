#pragma once 
#include <string>
#include <vector> 
#include <iostream>
#include <iomanip>
#if defined (linux)
    #include <libnetfilter_queue/libnetfilter_queue.h>
    #include "pcapplusplus/PcapFileDevice.h"
    #include "pcapplusplus/IPv4Layer.h"
    #include "pcapplusplus/Packet.h"
#endif
#if defined(_WIN32)
    #include "pcapplusplus/PcapFileDevice.h"
    #include "pcapplusplus/IPv4Layer.h"
    #include "pcapplusplus/Packet.h"
#endif
namespace proxy {
    struct proxyStruct {
        void startProxy();  
    };
}