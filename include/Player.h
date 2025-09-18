#ifndef PLAYER_H
#define PLAYER_H

#include "Constants.h"
#include <string>
#include <vector>

struct GameSession {
    int score;
    int questionsAnswered;
    int correctAnswers;
    Category category;
    Difficulty difficulty;
    double accuracy;

    GameSession() : score(0), questionsAnswered(0), correctAnswers(0),
                   category(Category::GENERAL), difficulty(Difficulty::EASY), accuracy(0.0) {}
};

class Player {
private:
    std::string name;
    int totalScore;
    int totalQuestions;
    int totalCorrect;
    std::vector<GameSession> sessions;

public:
    Player(const std::string& playerName = "Player");

    void updateSession(const GameSession& session);
    void displayStats() const;
    double getAccuracy() const;

    std::string getName() const { return name; }
    int getTotalScore() const { return totalScore; }
    int getTotalQuestions() const { return totalQuestions; }
    int getTotalCorrect() const { return totalCorrect; }
    int getSessionCount() const { return sessions.size(); }
};

#endif
