#include "./include/common.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <thread>
#include <cstdlib>
#include <string>
#include <limits>

using namespace std;
using namespace std::chrono_literals;
using namespace std::this_thread;

// Function declarations
void choosingOption();
void launchOptions();
void openBrowser(const std::string& url);
void startTUIMode();
void startGUIMode();

//My function
#include "./include/UDP_TUNNEL/udpTunnel.h"

int main() {
    const string WHITE_TEXT = "\033[37m";
    const string RESET = "\033[0m";
    const string WHITE = "\033[97m";
    const string BLACK = "\033[40m";

    // Display ASCII art
    cout << BLACK << WHITE << "⣿⣿⣿⣿⣿⡿⠿⠿⠿⠿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    cout << BLACK << WHITE << "⣿⣿⣿⣿⣿⣿⠿⠒⠒⠒⠲⢶⣤⣄⠀⠀⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    cout << BLACK << WHITE << "⣿⣿⣿⣿⡟⠁⠀⠀⠀⠀⠀⣀⠈⠻⣿⣦⡀⠀⠀⠙⠋⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    cout << BLACK << WHITE << "⣿⣿⣿⣿⡇⠀⠀⠀⠀⠔⠺⣿⠷⠀⢹⣿⣿⡧⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    cout << BLACK << WHITE << "⣿⣿⣿⣿⠇⠀⠀⠀⢸⠀⠀⣽⠀⡆⠀⣿⡿⠃⢀⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    cout << BLACK << WHITE << "⣿⣿⣿⣷⣤⣤⡀⠀⠀⠁⠷⠷⠎⠀⣸⡿⠇⠀⣸⣷⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;   
    cout << BLACK << WHITE << "⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀⠊⠉⠀⣄⣴⣿⣿⣿⣿⣿⣿" << BLACK << "     U D P i l o t   " << WHITE << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl; 
    cout << BLACK << WHITE << "⣿⣿⣿⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠐⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    cout << BLACK << WHITE << "⣿⣿⣿⣿⣿⣿⡀⠀⠀⠠⢀⠀⠀⠀⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    cout << BLACK << WHITE << "⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    cout << BLACK << WHITE << "⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    cout << BLACK << WHITE << "⣿⣿⣿⣶⣤⣀⠀⠀⠀⠀⠀⠀⠀⣤⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    cout << BLACK << WHITE << "⣿⣿⣿⣿⣿⣿⣷⣶⣦⣤⣤⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    sleep_for(3s);
    
    // Launch options menu
    launchOptions();
    return 0;
}

void openBrowser(const std::string& url) {
    #ifdef _WIN32
        std::string command = "start " + url;
    #elif __APPLE__
        std::string command = "open " + url;
    #else
        std::string command = "xdg-open " + url;
    #endif
    
    system(command.c_str());
}

void startTUIMode() {
    cout << "Starting TUI mode..." << endl;
    // Add your TUI mode implementation here
    // This could be a console-based interface for server management
    sleep_for(2s);
    choosingOption(); // Return to main menu after TUI mode
}

void startGUIMode() {
    cout << "Starting GUI mode..." << endl;
    
    // Navigate to the app directory and start Electron
    #ifdef _WIN32
        system("cd ../app && npm run start");
    #else
        system("cd ../app && npm run start");
    #endif
    
    sleep_for(2s);
}

void launchOptions() {
    while(true) {
        // Clear screen
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        
        int option;
        cout << left
             << "\033[93m----------------------------------------------------------------------------------------------\033[0m" << endl
             << "\033[101m|💻 Launch TUI |           |🌐 Launch GUI |\033[0m" << endl
             << "\033[102m|      1       |           |      2       |\033[0m" << endl
             << "\033[93m----------------------------------------------------------------------------------------------\033[0m" << endl
             << "Choose option (0 to exit): ";
        
        if (!(cin >> option)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            sleep_for(2s);
            continue;
        }
        
        switch (option) {
            case 0:
                cout << "Exiting program..." << endl;
                sleep_for(1s);
                return;
            case 1:
                startTUIMode();
                break;
            case 2:
                startGUIMode();
                break;
            default:
                cout << "Invalid option! Please choose 0, 1, or 2." << endl;
                sleep_for(2s);
                break;
        }
    }
}

void choosingOption() {
    int option;
    
    while (true) {
        // Clear screen
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        
        cout << left
             << "\033[93m----------------------------------------------------------------------------------------------\033[0m" << endl
             << "\033[101m|                         UDPilot - Main Menu                           |\033[0m" << endl
             << "\033[93m----------------------------------------------------------------------------------------------\033[0m" << endl
             << "\033[102m| 1 | Custom Servers |\033[0m" << endl
             << "\033[102m| 2 | UDP Tuning    |\033[0m" << endl
             << "\033[102m| 3 | Logs          |\033[0m" << endl
             << "\033[102m| 4 | Telegram      |\033[0m" << endl
             << "\033[102m| 5 | GitHub        |\033[0m" << endl
             << "\033[93m----------------------------------------------------------------------------------------------\033[0m" << endl
             << "Choose option (0 to go back): ";
        
        if (!(cin >> option)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            sleep_for(2s);
            continue;
        }
        
        switch (option) {
            case 0:
                return; // Return to launch options
            case 1:
                cout << "Custom Servers feature coming soon..." << endl;
                sleep_for(2s);
                break;
            case 2:
                udpTunnel::udpTunnelStruct udps;
                udps.startUdpTunnel();
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                cout << "UDP Tuning feature coming soon..." << endl;
                this_thread::sleep_for(2s);
                        case 3:
                cout << "Logs feature coming soon..." << endl;
                sleep_for(2s);
                break;
            case 4:
                openBrowser("https://t.me/@PotatoS229");
                break;
            case 5:
                openBrowser("https://github.com/PotatoS229/UDPilot");
                break;
            default:
                cout << "Invalid option! Please choose again." << endl;
                sleep_for(2s);
                break;
        }
    }
}