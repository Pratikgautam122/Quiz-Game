#include "GameManager.h"
#include <iostream>

GameManager::GameManager(const std::string& playerName)
    : player(playerName), state(GameState::MENU) {}

void GameManager::displayMenu() {
    std::cout << "\n=== QUIZ GAME MENU ===\n";
    std::cout << "1. Start New Game\n";
    std::cout << "2. View Statistics\n";
    std::cout << "3. Quit\n";
}

Category GameManager::selectCategory() {
    questionBank.displayCategories();

    int choice;
    std::cout << "Select category: ";
    std::cin >> choice;

    switch (choice) {
        case 1: return Category::SCIENCE;
        case 2: return Category::HISTORY;
        case 3: return Category::SPORTS;
        case 4: return Category::GENERAL;
        case 5: return Category::MATHEMATICS;
        default: return Category::GENERAL;
    }
}

Difficulty GameManager::selectDifficulty() {
    std::cout << "\nSelect Difficulty:\n";
    std::cout << "1. Easy\n";
    std::cout << "2. Medium\n";
    std::cout << "3. Hard\n";

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1: return Difficulty::EASY;
        case 2: return Difficulty::MEDIUM;
        case 3: return Difficulty::HARD;
        default: return Difficulty::EASY;
    }
}

void GameManager::run() {
    while (state != GameState::QUIT) {
        displayMenu();

        int choice;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                state = GameState::PLAYING;
                Category cat = selectCategory();
                Difficulty diff = selectDifficulty();

                QuizGame game(player, questionBank);
                GameSession session = game.play(cat, diff);

                player.updateSession(session);
                std::cout << "\nGame Over! Your Score: " << session.score
                          << " | Accuracy: " << session.accuracy << "%\n";
                state = GameState::MENU;
                break;
            }
            case 2:
                player.displayStats();
                break;
            case 3:
                state = GameState::QUIT;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
