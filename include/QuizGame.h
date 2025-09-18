#ifndef QUIZGAME_H
#define QUIZGAME_H

#include "Player.h"
#include "QuestionBank.h"
#include "Timer.h"

class QuizGame {
private:
    Player& player;
    QuestionBank& questionBank;

    int calculateScore(bool correct, Difficulty diff, int timeRemaining, int streak);

public:
    QuizGame(Player& p, QuestionBank& qb);

    GameSession play(Category category, Difficulty difficulty);
};

#endif
