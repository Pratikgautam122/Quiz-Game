#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(string playerName) {
    name = playerName;
    score = 0;
    totalQuestions = 0;
    correctAnswers = 0;
}

void Player::addScore(int points) {
    score += points;
}

void Player::updateStats(bool isCorrect) {
    totalQuestions++;
    if (isCorrect) {
        correctAnswers++;
    }
}

void Player::showStats() {
    cout << "\n==== PLAYER STATS ====" << endl;
    cout << "Name: " << name << endl;
    cout << "Score: " << score << endl;
    cout << "Questions: " << totalQuestions << endl;
    cout << "Correct: " << correctAnswers << endl;
    cout << "Accuracy: " << getAccuracy() << "%" << endl;
    cout << "======================" << endl;
}

double Player::getAccuracy() {
    if (totalQuestions == 0) return 0.0;
    return (double)correctAnswers / totalQuestions * 100.0;
}