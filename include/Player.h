#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
public:
    string name;
    int score;
    int totalQuestions;
    int correctAnswers;
    
    Player(string playerName);
    void addScore(int points);
    void updateStats(bool isCorrect);
    void showStats();
    double getAccuracy();
    void saveStats(const string &filename) const;
    void loadStats(const string &filename);
};

#endif