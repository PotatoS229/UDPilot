cmake_minimum_required(VERSION 3.10)
project(UDPilot)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "Source dir: ${CMAKE_SOURCE_DIR}")
message(STATUS "Output dir will be: ${CMAKE_SOURCE_DIR}/release_project")

# Use pkg-config for libnetfilter_queue
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBNETFILTER_QUEUE REQUIRED libnetfilter_queue)

if(NOT LIBNETFILTER_QUEUE_FOUND)
    message(FATAL_ERROR "libnetfilter_queue not found. Install: sudo apt-get install libnetfilter-queue-dev")
endif()

# PcapPlusPlus (custom find module)
find_path(PCAPPLUSPLUS_INCLUDE_DIR
    NAMES PcapPlusPlus.h
    PATHS /usr/local/include/pcapplusplus /usr/include/pcapplusplus
)

find_library(PCAPPLUSPLUS_LIBRARY
    NAMES Pcap++ PcapPlusPlus
    PATHS /usr/local/lib /usr/lib
)

find_library(LIBPCAP_LIBRARY NAMES pcap)

if(PCAPPLUSPLUS_INCLUDE_DIR AND PCAPPLUSPLUS_LIBRARY AND LIBPCAP_LIBRARY)
    set(PCAPPLUSPLUS_FOUND TRUE)
    message(STATUS "Found PcapPlusPlus")
else()
    message(WARNING "PcapPlusPlus not found. Some features may be disabled")
endif()

# Create executable
add_executable(
    main 
    core/src/main.cpp
    core/src/include/UDP_TUNNEL/udpTunnel.cpp
    core/src/include/proxy/proxy.cpp
)

# Link libnetfilter_queue using pkg-config variables
target_include_directories(main PRIVATE ${LIBNETFILTER_QUEUE_INCLUDE_DIRS})
target_link_libraries(main ${LIBNETFILTER_QUEUE_LIBRARIES})

# Link PcapPlusPlus if found
if(PCAPPLUSPLUS_FOUND)
    target_include_directories(main PRIVATE ${PCAPPLUSPLUS_INCLUDE_DIR})
    target_link_libraries(main ${PCAPPLUSPLUS_LIBRARY} ${LIBPCAP_LIBRARY})
endif()

target_link_libraries(main pthread)

set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/release_project"
)

get_target_property(OUTPUT_DIR main RUNTIME_OUTPUT_DIRECTORY)
message(STATUS "Target output directory: ${OUTPUT_DIR}")