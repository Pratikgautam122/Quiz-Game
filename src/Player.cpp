#include "Player.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/stat.h>   // for checking if file exists

using namespace std;

static bool fileExists(const string &filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

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
    if (isCorrect) correctAnswers++;
}

void Player::showStats() {
    cout << "\n==== PLAYER STATS ====\n";
    cout << "Name: " << name << endl;
    cout << "Score: " << score << endl;
    cout << "Questions: " << totalQuestions << endl;
    cout << "Correct: " << correctAnswers << endl;
    cout << "Accuracy: " << getAccuracy() << "%" << endl;
    cout << "======================\n";
}

double Player::getAccuracy() {
    if (totalQuestions == 0) return 0.0;
    return (double)correctAnswers / totalQuestions * 100.0;
}

/* ----------- NEW: save with header & append ----------- */
void Player::saveStats(const string &filename) const {
    bool alreadyExists = fileExists(filename);
    ofstream out(filename, ios::app);
    if (!out) return;

    // Write a header only once
    if (!alreadyExists) {
        out << "Name,Score,TotalQuestions,CorrectAnswers\n";
    }
    out << name << ',' << score << ','
        << totalQuestions << ',' << correctAnswers << '\n';
}

/* ----------- NEW: load player's previous line ----------- */
void Player::loadStats(const string &filename) {
    ifstream in(filename);
    if (!in) return;

    string line;
    getline(in, line); // skip header if present

    while (getline(in, line)) {
        stringstream ss(line);
        string pname;
        string scoreStr, tqStr, caStr;

        getline(ss, pname, ',');
        getline(ss, scoreStr, ',');
        getline(ss, tqStr, ',');
        getline(ss, caStr, ',');

        if (pname == name) {
            score = stoi(scoreStr);
            totalQuestions = stoi(tqStr);
            correctAnswers = stoi(caStr);
            return;
        }
    }

    
}
