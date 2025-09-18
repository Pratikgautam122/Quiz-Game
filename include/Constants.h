#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

const int MAX_QUESTIONS_PER_QUIZ = 15;
const int EASY_TIME_LIMIT = 30;
const int MEDIUM_TIME_LIMIT = 20;
const int HARD_TIME_LIMIT = 15;
const int BASE_SCORE = 100;
const int TIME_BONUS_MAX = 50;
const int STREAK_BONUS = 25;

enum class GameState {
    MENU,
    PLAYING,
    FINISHED,
    QUIT
};

enum class Difficulty {
    EASY,
    MEDIUM,
    HARD
};

enum class Category {
    SCIENCE,
    HISTORY,
    SPORTS,
    GENERAL,
    MATHEMATICS
};

#endif