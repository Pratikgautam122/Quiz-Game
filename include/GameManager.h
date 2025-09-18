#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.h"
#include "QuestionBank.h"
#include "QuizGame.h"

class GameManager {
private:
    Player player;
    QuestionBank questionBank;
    GameState state;

    void displayMenu();
    Category selectCategory();
    Difficulty selectDifficulty();

public:
    GameManager(const std::string& playerName);

    void run();
};

#endif
