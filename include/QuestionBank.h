#ifndef QUESTIONBANK_H
#define QUESTIONBANK_H

#include "Question.h"
#include <map>
#include <vector>
#include <random>

class QuestionBank {
private:
    std::map<Category, std::vector<Question>> questionDatabase;
    std::map<Category, std::string> categoryNames;
    std::mt19937 randomEngine;

    void initializeCategories();
    void loadDefaultQuestions();

public:
    QuestionBank();

    Question selectQuestion(Category category, Difficulty difficulty);
    void displayCategories() const;
    std::string getCategoryName(Category category) const;
    int getQuestionCount(Category category) const;
};

#endif
