#include "QuizGame.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

QuizGame::QuizGame(string playerName) : player(playerName) {
    player.loadStats("player_stats.txt");  // Load previous stats
    loadQuestions();
    srand(time(0));
}

void QuizGame::loadQuestions() {
    // ===== Science =====
    questions.push_back(Question(
        "What is H2O?",
        {"Water", "Oxygen", "Hydrogen", "Salt"},
        1, "H2O is the chemical formula for water."
    ));

    questions.push_back(Question(
        "How many planets in our solar system?",
        {"7", "8", "9", "10"},
        2, "There are 8 planets in our solar system."
    ));

    questions.push_back(Question(
        "Which gas do humans exhale?",
        {"Oxygen", "Carbon Dioxide", "Nitrogen", "Hydrogen"},
        2, "Humans exhale mainly carbon dioxide."
    ));

    questions.push_back(Question(
        "Which part of the cell contains genetic material?",
        {"Mitochondria", "Ribosome", "Nucleus", "Cytoplasm"},
        3, "DNA is stored inside the nucleus."
    ));

    // ===== Math =====
    questions.push_back(Question(
        "What is 5 x 6?",
        {"25", "30", "35", "40"},
        2, "5 multiplied by 6 equals 30."
    ));

    questions.push_back(Question(
        "What is 100 - 25?",
        {"75", "80", "70", "85"},
        1, "100 minus 25 equals 75."
    ));

    questions.push_back(Question(
        "What is the square root of 81?",
        {"7", "8", "9", "10"},
        3, "The square root of 81 is 9."
    ));

    questions.push_back(Question(
        "What is 12 ÷ 3?",
        {"2", "3", "4", "6"},
        3, "12 divided by 3 equals 4."
    ));

    // ===== General Knowledge =====
    questions.push_back(Question(
        "Capital of Japan?",
        {"Osaka", "Kyoto", "Tokyo", "Nagoya"},
        3, "Tokyo is the capital city of Japan."
    ));

    questions.push_back(Question(
        "Largest continent?",
        {"Asia", "Africa", "Europe", "America"},
        1, "Asia is the largest continent by area."
    ));

    questions.push_back(Question(
        "How many days in a week?",
        {"5", "6", "7", "8"},
        3, "There are 7 days in a week."
    ));

    questions.push_back(Question(
        "Color of the sun?",
        {"Yellow", "Red", "Blue", "Green"},
        1, "The sun appears yellow from Earth."
    ));

    questions.push_back(Question(
        "Who wrote 'Hamlet'?",
        {"Charles Dickens", "William Shakespeare", "Leo Tolstoy", "Mark Twain"},
        2, "'Hamlet' was written by William Shakespeare."
    ));

    questions.push_back(Question(
        "Fastest land animal?",
        {"Cheetah", "Horse", "Lion", "Leopard"},
        1, "The cheetah is the fastest land animal."
    ));

    questions.push_back(Question(
        "How many colors in a rainbow?",
        {"6", "7", "8", "9"},
        2, "There are 7 distinct colors in a rainbow."
    ));
}

int QuizGame::getRandomQuestion() {
    return rand() % questions.size();
}

void QuizGame::playGame() {
    cout << "\nStarting quiz for " << player.name << "!\n";
    cout << "You will answer 5 questions.\n";
    cout << "Each correct answer = 10 points!\n";

    vector<int> usedQuestions;

    for (int i = 0; i < 5; i++) {
        int questionIndex;
        bool alreadyUsed;

        // Pick unused question
        do {
            questionIndex = getRandomQuestion();
            alreadyUsed = false;
            for (int j : usedQuestions) {
                if (j == questionIndex) { alreadyUsed = true; break; }
            }
        } while (alreadyUsed);

        usedQuestions.push_back(questionIndex);

        cout << "\n--- Question " << (i + 1) << " ---";
        questions[questionIndex].display();

        int answer;
        cin >> answer;

        if (answer < 1 || answer > 4) {
            cout << "Invalid input!\n";
            answer = 0; // mark wrong
        }

        bool correct = questions[questionIndex].checkAnswer(answer);
        questions[questionIndex].showResult(answer);

        player.updateStats(correct);
        if (correct) player.addScore(10);

        cout << "Current score: " << player.score << endl;
    }

    cout << "\n=== GAME FINISHED ===\n";
    cout << "Final score: " << player.score << "/50\n";

    if (player.getAccuracy() >= 80)
        cout << "Excellent!\n";
    else if (player.getAccuracy() >= 60)
        cout << "Good job!\n";
    else
        cout << "Keep practicing!\n";
}

void QuizGame::showMenu() {
    int choice;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Play Game\n";
        cout << "2. View Stats\n";
        cout << "3. Quit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: playGame(); break;
            case 2: player.showStats(); break;
            case 3: cout << "Goodbye " << player.name << "!\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 3);
}

void QuizGame::start() {
    showMenu();
    player.saveStats("player_stats.txt"); // Save on exit
}
