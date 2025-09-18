#include "QuestionBank.h"
#include <iostream>
#include <algorithm>

QuestionBank::QuestionBank() : randomEngine(std::random_device{}()) {
    initializeCategories();
    loadDefaultQuestions();
}

void QuestionBank::initializeCategories() {
    categoryNames[Category::SCIENCE] = "Science";
    categoryNames[Category::HISTORY] = "History";
    categoryNames[Category::SPORTS] = "Sports";
    categoryNames[Category::GENERAL] = "General Knowledge";
    categoryNames[Category::MATHEMATICS] = "Mathematics";
}

void QuestionBank::loadDefaultQuestions() {
    // Example question
    questionDatabase[Category::SCIENCE].push_back(
        Question("What is the chemical symbol for water?",
                 {"H2O", "O2", "CO2", "NaCl"}, 0,
                 "Water's chemical formula is H2O.",
                 Difficulty::EASY, Category::SCIENCE));

    questionDatabase[Category::HISTORY].push_back(
        Question("Who was the first President of the USA?",
                 {"Abraham Lincoln", "Thomas Jefferson", "George Washington", "John Adams"}, 2,
                 "George Washington was the first U.S. President (1789–1797).",
                 Difficulty::EASY, Category::HISTORY));
        }
    // Add more questions as needed...
// (keep loadDefaultQuestions() code from your version unchanged)

Question QuestionBank::selectQuestion(Category category, Difficulty difficulty) {
    auto categoryIt = questionDatabase.find(category);
    if (categoryIt == questionDatabase.end() || categoryIt->second.empty()) {
        return Question();
    }

    std::vector<Question> filteredQuestions;
    for (const auto& question : categoryIt->second) {
        if (question.getDifficulty() == difficulty) {
            filteredQuestions.push_back(question);
        }
    }

    if (filteredQuestions.empty()) {
        filteredQuestions = categoryIt->second;
    }

    std::uniform_int_distribution<> dis(0, filteredQuestions.size() - 1);
    return filteredQuestions[dis(randomEngine)];
}

void QuestionBank::displayCategories() const {
    std::cout << "\nAvailable Categories:\n";
    int index = 1;
    for (const auto& pair : categoryNames) {
        std::cout << index++ << ". " << pair.second << " ("
                  << getQuestionCount(pair.first) << " questions)\n";
    }
}

std::string QuestionBank::getCategoryName(Category category) const {
    auto it = categoryNames.find(category);
    return (it != categoryNames.end()) ? it->second : "Unknown";
}

int QuestionBank::getQuestionCount(Category category) const {
    auto it = questionDatabase.find(category);
    return (it != questionDatabase.end()) ? it->second.size() : 0;
}
