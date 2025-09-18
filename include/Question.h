#ifndef QUESTION_H
#define QUESTION_H

#include "Constants.h"
#include <string>
#include <vector>

class Question {
private:
    std::string questionText;
    std::vector<std::string> options;
    int correctAnswer;
    std::string explanation;
    Difficulty difficulty;
    Category category;

public:
    Question();
    Question(const std::string& text, const std::vector<std::string>& opts,
             int correct, const std::string& explain, Difficulty diff, Category cat);

    bool isCorrect(int answer) const;
    void display() const;
    void displayResult(int playerAnswer) const;

    std::string getQuestionText() const { return questionText; }
    std::vector<std::string> getOptions() const { return options; }
    int getCorrectAnswer() const { return correctAnswer; }
    std::string getExplanation() const { return explanation; }
    Difficulty getDifficulty() const { return difficulty; }
    Category getCategory() const { return category; }
};

#endif