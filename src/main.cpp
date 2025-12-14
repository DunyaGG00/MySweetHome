#include "HomeController.h"
#include <iostream>

int main() {
    std::cout << std::endl;
    std::cout << "  __  __        ____                 _     _   _                      " << std::endl;
    std::cout << " |  \\/  |_   _ / ___|_      _____  _| |_  | | | | ___  _ __ ___   ___ " << std::endl;
    std::cout << " | |\\/| | | | |\\___ \\ \\ /\\ / / _ \\/ _ __| | |_| |/ _ \\| '_ ` _ \\ / _ \\" << std::endl;
    std::cout << " | |  | | |_| | ___) \\ V  V /  __/  |_   |  _  | (_) | | | | | |  __/" << std::endl;
    std::cout << " |_|  |_|\\__, ||____/ \\_/\\_/ \\___|\\____|_| |_| |_|\\___/|_| |_| |_|\\___|" << std::endl;
    std::cout << "         |___/                                                        " << std::endl;
    std::cout << std::endl;
    std::cout << "                    Smart Home Management System                      " << std::endl;
    std::cout << "                         Version 1.0.0                                " << std::endl;
    std::cout << std::endl;
    
    // Create and start the home controller
    HomeController* home = new HomeController();
    
    home->start();
    home->run();
    
    delete home;
    
    return 0;
}
