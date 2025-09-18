#include <iostream>
#include <string>
#include "QuizGame.h"
using namespace std;

int main() {
    cout << "Welcome to Simple Quiz Game!" << endl;
    cout << "Enter your name: ";
    
    string name;
    getline(cin, name);
    
    if (name.empty()) {
        name = "Player";
    }
    
    QuizGame game(name);
    game.start();
    
    return 0;
}