#include "./include/common.h"

#include <iostream>
#include <iomanip>
#include <vector>
// для работы с потоками
#include <thread>
using namespace std;
using namespace std::chrono_literals;
using namespace std::this_thread;

//Для запуска браузера
#include <cstdlib>
#include <string>

// объявляем функцию для выбора действия
void choosingOption();
void launchOptions();

int main() {;
    const string WHITE_TEXT = "\033[37m";
    const string RESET = "\033[0m";
    const string WHITE = "\033[97m";
    const string BLACK = "\033[40m";

    cout << BLACK << WHITE <<  "⣿⣿⣿⣿⣿⡿⠿⠿⠿⠿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    cout << BLACK << WHITE <<  "⣿⣿⣿⣿⣿⣿⠿⠒⠒⠒⠲⢶⣤⣄⠀⠀⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    cout << BLACK << WHITE <<  "⣿⣿⣿⣿⡟⠁⠀⠀⠀⠀⠀⣀⠈⠻⣿⣦⡀⠀⠀⠙⠋⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    cout << BLACK << WHITE <<  "⣿⣿⣿⣿⡇⠀⠀⠀⠀⠔⠺⣿⠷⠀⢹⣿⣿⡧⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    cout << BLACK << WHITE <<  "⣿⣿⣿⣿⠇⠀⠀⠀⢸⠀⠀⣽⠀⡆⠀⣿⡿⠃⢀⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    cout << BLACK << WHITE <<  "⣿⣿⣿⣷⣤⣤⡀⠀⠀⠁⠷⠷⠎⠀⣸⡿⠇⠀⣸⣷⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;   
    cout << BLACK << WHITE <<  "⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀⠊⠉⠀⣄⣴⣿⣿⣿⣿⣿⣿"<< BLACK << "     U D P i l o t   " << WHITE <<"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl; 
    cout << BLACK << WHITE <<  "⣿⣿⣿⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠐⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    cout << BLACK << WHITE <<  "⣿⣿⣿⣿⣿⣿⡀⠀⠀⠠⢀⠀⠀⠀⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    cout << BLACK << WHITE <<  "⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    cout << BLACK << WHITE <<  "⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    cout << BLACK << WHITE <<  "⣿⣿⣿⣶⣤⣀⠀⠀⠀⠀⠀⠀⠀⣤⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    cout << BLACK << WHITE <<  "⣿⣿⣿⣿⣿⣿⣷⣶⣦⣤⣤⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << RESET << endl;
    sleep_for(3s);
    
    // Запускаем Функцию выбора действий
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

//Функция, где запускать программу TUI или GUI
void launchOptions(){
    while(true){
        // Очистка экрана (работает на большинстве систем)
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        int option;
        cout << left
            << "\033[93m----------------------------------------------------------------------------------------------\033[0m" << endl
            << "\033[101m|💻Запуск TUI|           |🌐Запуск GUI|\033[0m" << endl
            << "\033[102m|      1     |           |     2      |\033[0m" << endl
            << "\033[93m----------------------------------------------------------------------------------------------\033[0m" << endl;
        if (!(cin >> option)) {
                cin.clear(); // очищаем флаги ошибок
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // игнорируем неправильный ввод
                cout << "Invalid input! Please enter a number." << endl;
                sleep_for(2s);
                continue;
        }
        switch (option) {
            case 1:
                choosingOption();
            case 2:
                cout << "Запускаем сервера и GUI" << endl;
                openBrowser("http://localhost:5173/menu");
            default:
                cout << "Ошибка" << endl;
                break;
        }
    }
}


// Функция для выбора действия
void choosingOption() {
    int option;
    
    while (true) {
        // Очистка экрана (работает на большинстве систем)
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        
        cout << left
             << "\033[93m----------------------------------------------------------------------------------------------\033[0m" << endl
             << "\033[101m|UDPilot|\033[0m" << endl
             << "\033[102m|   1   |\033[0m" << endl
             << "\033[93m----------------------------------------------------------------------------------------------\033[0m" << endl
             << "Please choose one option (0 to exit): ";
        
        if (!(cin >> option)) {
            cin.clear(); // очищаем флаги ошибок
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // игнорируем неправильный ввод
            cout << "Invalid input! Please enter a number." << endl;
            sleep_for(2s);
            continue;
        }
        
        switch (option) {
            case 0: {
                cout << "Exiting program..." << endl;
                sleep_for(1s);
                return;
            }
            case 1: {
                int variant;
                while (true) {
                    #ifdef _WIN32
                        system("cls");
                    #else
                        system("clear");
                    #endif
                    cout << left
                        << "\033[93m----------------------------------------------------------------------------------------------\033[0m" << endl
                        << "\033[101m|Свои сервера |\033[0m" << "   "
                        << "\033[101m|UDP-тюнинг |\033[0m" << "   "
                        << "\033[101m|Логи |\033[0m" << "   "
                        << "\033[101m|Телеграм |\033[0m" << "   "
                        << "\033[101m|GitHub |\033[0m" << "   " << endl
                        << "\033[102m|      1      |\033[0m" << "   "
                        << "\033[102m|     2     |\033[0m" << "   "
                        << "\033[102m|  3  |\033[0m" << "   "
                        << "\033[102m|    4    |\033[0m" << "   "
                        << "\033[102m|   5   |\033[0m" << "   " << endl
                        << "\033[93m----------------------------------------------------------------------------------------------\033[0m" << endl
                        << "Please choose one option (0 to go back): ";
                    
                    if (!(cin >> variant)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input! Please enter a number." << endl;
                        sleep_for(2s);
                        continue;
                    }
                    
                    switch (variant) {
                        case 0:
                            return; // Возврат в главное меню
                        case 1: {
                        }
                        case 2: {
                        }
                        case 3:{
                        }
                        case 4:{
                        }
                        default:
                            cout << "Invalid option! Please choose again." << endl;
                            sleep_for(2s);
                            break;
                    }
                }
                break;
            }
            default: {
                cout << "Invalid option! Please choose again." << endl;
                sleep_for(2s);
                break;
            }
        }
    }
}