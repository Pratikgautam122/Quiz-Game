#include "Player.h"
#include <iostream>
#include <iomanip>

Player::Player(const std::string& playerName)
    : name(playerName), totalScore(0), totalQuestions(0), totalCorrect(0) {}

void Player::updateSession(const GameSession& session) {
    sessions.push_back(session);
    totalScore += session.score;
    totalQuestions += session.questionsAnswered;
    totalCorrect += session.correctAnswers;
}

void Player::displayStats() const {
    std::cout << "\n" << std::string(40, '=') << "\n";
    std::cout << "PLAYER STATISTICS\n";
    std::cout << std::string(40, '=') << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Total Score: " << totalScore << "\n";
    std::cout << "Total Questions: " << totalQuestions << "\n";
    std::cout << "Correct Answers: " << totalCorrect << "\n";
    std::cout << "Overall Accuracy: " << std::fixed << std::setprecision(1)
              << getAccuracy() << "%\n";
    std::cout << "Sessions Played: " << sessions.size() << "\n";

    if (!sessions.empty()) {
        int bestScore = 0;
        for (const auto& session : sessions) {
            if (session.score > bestScore) {
                bestScore = session.score;
            }
        }
        std::cout << "Best Session Score: " << bestScore << "\n";
    }
    std::cout << std::string(40, '=') << "\n";
}

double Player::getAccuracy() const {
    return totalQuestions > 0 ? (static_cast<double>(totalCorrect) / totalQuestions) * 100.0 : 0.0;
}
