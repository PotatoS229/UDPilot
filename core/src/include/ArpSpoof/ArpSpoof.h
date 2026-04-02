#include <iostream>
#include <fstream>
#include "pcapplusplus/MacAddress.h"
#include "pcapplusplus/IpAddress.h"
#include "pcapplusplus/PcapPlusPlusVersion.h"
#include "pcapplusplus/SystemUtils.h"
#include "pcapplusplus/PcapLiveDeviceList.h"
#include "pcapplusplus/PcapLiveDevice.h"
#include "pcapplusplus/Packet.h"
#include "pcapplusplus/EthLayer.h"
#include "pcapplusplus/ArpLayer.h"
#include <getopt.h>
namespace ArpSpoof {
    struct ArpSpoofStruct {
        void startArpSpoof(int argc, char *argv[]);  
    };
}