#include "Question.h"
#include <iostream>
using namespace std;

Question::Question(string q, vector<string> options, int answer, string explain) {
    text = q;
    choices = options;
    correct = answer;
    explanation = explain;
}

void Question::display() {
    cout << "\n" << text << endl;
    for (int i = 0; i < choices.size(); i++) {
        cout << (i + 1) << ". " << choices[i] << endl;
    }
    cout << "Your answer (1-" << choices.size() << "): ";
}

bool Question::checkAnswer(int answer) {
    return answer == correct;
}

void Question::showResult(int playerAnswer) {
    if (playerAnswer == correct) {
        cout << "\nCorrect!" << endl;
    } else {
        cout << "\nWrong! Correct answer: " << correct 
             << ". " << choices[correct-1] << endl;
    }
    cout << explanation << endl;
}