CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pthread
LDFLAGS = -pthread
INCLUDES = -I./include -I. -I/usr/include/pcapplusplus

# Try different library paths
LIBS = -lPcap++ -lPacket++ -lCommon++ -lpcap -lpthread
# Add library search paths
LIB_PATHS = -L/usr/local/lib -L/usr/lib/x86_64-linux-gnu -L/usr/lib

# Find all source files recursively
SRCS := $(shell find src -name "*.cpp")
OBJS := $(SRCS:src/%.cpp=../release_project/%.o)

# Target executable
TARGET = ../release_project/main

all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p ../release_project
	$(CXX) $(LDFLAGS) -o $@ $^ $(LIB_PATHS) $(LIBS)

../release_project/%.o: src/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf ../release_project

.PHONY: all clean