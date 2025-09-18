#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>
using namespace std;

class Question {
public:
    string text;
    vector<string> choices;
    int correct;
    string explanation;

    Question(string q, vector<string> options, int answer, string explain);
    void display();
    bool checkAnswer(int answer);
    void showResult(int playerAnswer);
};

#endif // QUESTION_H
