#include "QuizGame.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

QuizGame::QuizGame(string playerName) : player(playerName) {
    loadQuestions();
    srand(time(0));
}

void QuizGame::loadQuestions() {
    // Science
    questions.push_back(Question(
        "What is H2O?",
        {"Oxygen", "Water", "Hydrogen", "Salt"},
        2, "H2O is the chemical formula for water."
    ));
    
    questions.push_back(Question(
        "How many planets in our solar system?",
        {"7", "8", "9", "10"},
        2, "There are 8 planets in our solar system."
    ));
    
    // Math
    questions.push_back(Question(
        "What is 5 x 6?",
        {"25", "30", "35", "40"},
        2, "5 multiplied by 6 equals 30."
    ));
    
    questions.push_back(Question(
        "What is 100 - 25?",
        {"70", "75", "80", "85"},
        2, "100 minus 25 equals 75."
    ));
    
    // General
    questions.push_back(Question(
        "Capital of Japan?",
        {"Osaka", "Tokyo", "Kyoto", "Nagoya"},
        2, "Tokyo is the capital city of Japan."
    ));
    
    questions.push_back(Question(
        "Largest continent?",
        {"Africa", "Asia", "Europe", "America"},
        2, "Asia is the largest continent by area."
    ));
    
    questions.push_back(Question(
        "How many days in a week?",
        {"6", "7", "8", "5"},
        2, "There are 7 days in a week."
    ));
    
    questions.push_back(Question(
        "Color of the sun?",
        {"Red", "Yellow", "Blue", "Green"},
        2, "The sun appears yellow from Earth."
    ));
}

int QuizGame::getRandomQuestion() {
    return rand() % questions.size();
}

void QuizGame::playGame() {
    cout << "\nStarting quiz for " << player.name << "!" << endl;
    cout << "You will answer 5 questions." << endl;
    cout << "Each correct answer = 10 points!" << endl;
    
    vector<int> usedQuestions;
    
    for (int i = 0; i < 5; i++) {
        int questionIndex;
        bool alreadyUsed;
        
        // Get unused question
        do {
            questionIndex = getRandomQuestion();
            alreadyUsed = false;
            for (int j = 0; j < usedQuestions.size(); j++) {
                if (usedQuestions[j] == questionIndex) {
                    alreadyUsed = true;
                    break;
                }
            }
        } while (alreadyUsed);
        
        usedQuestions.push_back(questionIndex);
        
        cout << "\n--- Question " << (i + 1) << " ---";
        questions[questionIndex].display();
        
        int answer;
        cin >> answer;
        
        // Check valid input
        if (answer < 1 || answer > 4) {
            cout << "Invalid input!" << endl;
            answer = 0; // Wrong answer
        }
        
        bool correct = questions[questionIndex].checkAnswer(answer);
        questions[questionIndex].showResult(answer);
        
        player.updateStats(correct);
        if (correct) {
            player.addScore(10);
        }
        
        cout << "Current score: " << player.score << endl;
    }
    
    cout << "\n=== GAME FINISHED ===" << endl;
    cout << "Final score: " << player.score << "/50" << endl;
    
    if (player.getAccuracy() >= 80) {
        cout << "Excellent!" << endl;
    } else if (player.getAccuracy() >= 60) {
        cout << "Good job!" << endl;
    } else {
        cout << "Keep practicing!" << endl;
    }
}

void QuizGame::showMenu() {
    int choice;
    do {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Play Game" << endl;
        cout << "2. View Stats" << endl;
        cout << "3. Quit" << endl;
        cout << "Choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                player.showStats();
                break;
            case 3:
                cout << "Goodbye " << player.name << "!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);
}

void QuizGame::start() {
    showMenu();
}