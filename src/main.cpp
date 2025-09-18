#include "GameManager.h"
#include <iostream>

int main() {
    std::cout << "Enter your name: ";
    std::string playerName;
    std::getline(std::cin, playerName);

    GameManager manager(playerName);
    manager.run();

    return 0;
}
