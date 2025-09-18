#ifndef QUIZGAME_H
#define QUIZGAME_H

#include "Player.h"
#include "Question.h"
#include <vector>
using namespace std;

class QuizGame {
private:
    Player player;
    vector<Question> questions;

    void loadQuestions();
    void playGame();
    void showMenu();
    int getRandomQuestion();

public:
    QuizGame(string playerName);
    void start();
};

#endif // QUIZGAME_H
