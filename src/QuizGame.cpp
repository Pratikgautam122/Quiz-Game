#include "QuizGame.h"
#include <iostream>

QuizGame::QuizGame(Player& p, QuestionBank& qb)
    : player(p), questionBank(qb) {}

int QuizGame::calculateScore(bool correct, Difficulty diff, int timeRemaining, int streak) {
    if (!correct) return 0;

    int base = BASE_SCORE;
    switch (diff) {
        case Difficulty::EASY: base = 50; break;
        case Difficulty::MEDIUM: base = 100; break;
        case Difficulty::HARD: base = 150; break;
    }

    int timeBonus = std::min(TIME_BONUS_MAX, timeRemaining);
    int streakBonus = (streak > 1) ? (streak - 1) * STREAK_BONUS : 0;

    return base + timeBonus + streakBonus;
}

GameSession QuizGame::play(Category category, Difficulty difficulty) {
    GameSession session;
    session.category = category;
    session.difficulty = difficulty;

    int streak = 0;
    int timeLimit = EASY_TIME_LIMIT;
    if (difficulty == Difficulty::MEDIUM) timeLimit = MEDIUM_TIME_LIMIT;
    else if (difficulty == Difficulty::HARD) timeLimit = HARD_TIME_LIMIT;

    for (int i = 0; i < MAX_QUESTIONS_PER_QUIZ; i++) {
        Question q = questionBank.selectQuestion(category, difficulty);
        q.display();

        Timer timer(timeLimit);
        timer.start();

        std::string answer;
        std::cout << "Enter your answer (A, B, C, D): ";
        std::cin >> answer;

        int playerAnswer = -1;
        if (!answer.empty()) {
            playerAnswer = toupper(answer[0]) - 'A';
        }

        int remainingTime = timer.getRemainingSeconds();

        bool correct = q.isCorrect(playerAnswer);
        q.displayResult(playerAnswer);

        int points = calculateScore(correct, difficulty, remainingTime, streak);
        if (correct) {
            streak++;
            session.correctAnswers++;
        } else {
            streak = 0;
        }

        session.score += points;
        session.questionsAnswered++;
        session.accuracy = (session.questionsAnswered > 0)
            ? (static_cast<double>(session.correctAnswers) / session.questionsAnswered) * 100.0
            : 0.0;
    }

    return session;
}
