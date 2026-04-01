#!/bin/bash

cd /
cd /home/${USER}

git clone https://github.com/seladb/PcapPlusPlus
cd ./PcapPlusPlus

# Detect OS
if [ -f /etc/os-release ]; then
    . /etc/os-release
    case "$ID" in
        debian|ubuntu|linuxmint|pop|elementary)
            echo "Debian-based system (Debian/Ubuntu/Mint etc.)"
            sudo apt update
            sudo apt-get install libpcap-dev
            cmake -S . -B build
            cd build
            cmake --build . -j$(nproc)  # Build the project
            sudo cmake --install .
            ;;
        arch|manjaro|endeavouros)
            echo "Arch-based system (Arch/Manjaro etc.)"
            sudo pacman -Syu --noconfirm
            sudo pacman -S --noconfirm git base-devel cmake libpcap
            cmake -S . -B build
            cd build
            cmake --build . -j$(nproc)  # Build the project
            sudo cmake --install .
            ;;
        *)
            echo "Unknown Linux distribution: $ID"
            ;;
    esac
elif [[ "$OSTYPE" == "darwin"* ]]; then
    echo "macOS system detected"
    # Check if Homebrew is installed
    if ! command -v brew &> /dev/null; then
        echo "Installing Homebrew..."
        /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    fi
    
    # Install libpcap via Homebrew
    brew install libpcap
    
    # Install cmake if not present
    if ! command -v cmake &> /dev/null; then
        brew install cmake
    fi
    
    # Build and install PcapPlusPlus
    cmake -S . -B build
    cd build
    cmake --build . -j$(sysctl -n hw.ncpu)  # Build the project
    sudo cmake --install .
    
elif [[ "$OSTYPE" == "msys" ]] || [[ "$OSTYPE" == "cygwin" ]] || [[ "$OSTYPE" == "win32" ]] || [[ "$OSTYPE" == "mingw" ]]; then
    echo "Windows system detected"
    
    # Check if vcpkg is installed (recommended for Windows)
    if [ ! -d "C:/vcpkg" ]; then
        echo "vcpkg not found. Installing vcpkg..."
        cd /
        git clone https://github.com/Microsoft/vcpkg.git
        cd vcpkg
        ./bootstrap-vcpkg.bat
        ./vcpkg integrate install
        cd ..
    fi
    
    # Install libpcap via vcpkg
    C:/vcpkg/vcpkg install libpcap
    # Build with Visual Studio or MinGW
    echo "Building for Windows..."
    
    # Detect compiler
    if command -v cmake &> /dev/null; then
        # For Visual Studio
        if [ -d "/c/Program Files/Microsoft Visual Studio" ]; then
            cmake -S . -B build -G "Visual Studio 17 2022" -A x64
            cd build
            cmake --build . --config Release
            # Install (may need admin privileges)
            cmake --install . --config Release
        # For MinGW
        elif command -v mingw32-make &> /dev/null; then
            cmake -S . -B build -G "MinGW Makefiles"
            cd build
            mingw32-make -j$(nproc)
            mingw32-make install
        else
            echo "No suitable build system found for Windows"
            echo "Please install Visual Studio or MinGW"
        fi
    else
        echo "CMake not found. Please install CMake for Windows"
    fi
else
    echo "Unsupported operating system: $OSTYPE"
fi