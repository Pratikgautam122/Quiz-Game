#include "Question.h"
#include <iostream>
#include <iomanip>

Question::Question() : correctAnswer(0), difficulty(Difficulty::EASY), category(Category::GENERAL) {}

Question::Question(const std::string& text, const std::vector<std::string>& opts,
                  int correct, const std::string& explain, Difficulty diff, Category cat)
    : questionText(text), options(opts), correctAnswer(correct),
      explanation(explain), difficulty(diff), category(cat) {}

bool Question::isCorrect(int answer) const {
    return answer == correctAnswer;
}

void Question::display() const {
    std::cout << "\n" << std::string(50, '=') << "\n";
    std::cout << questionText << "\n\n";

    char label = 'A';
    for (size_t i = 0; i < options.size(); i++) {
        std::cout << label++ << ") " << options[i] << "\n";
    }
    std::cout << "\n";
}

void Question::displayResult(int playerAnswer) const {
    std::cout << "\n" << std::string(50, '-') << "\n";

    if (playerAnswer == correctAnswer) {
        std::cout << "CORRECT! ";
    } else {
        std::cout << "INCORRECT! ";
        std::cout << "The correct answer was " << static_cast<char>('A' + correctAnswer)
                  << ") " << options[correctAnswer] << "\n";
    }

    std::cout << "\nExplanation: " << explanation << "\n";
    std::cout << std::string(50, '-') << "\n";
}
