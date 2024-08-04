#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Question {
public:
    string questionText;
    vector<string> options;
    int correctOption;

    Question(const string& text, const vector<string>& opts, int correctOpt)
        : questionText(text), options(opts), correctOption(correctOpt) {}
};

class Quiz {
private:
    vector<Question> questions;
    map<string, int> userScores;

public:
    void addQuestion(const Question& question) {
        questions.push_back(question);
    }

    void startQuiz(const string& username) {
        int score = 0;
        for (size_t i = 0; i < questions.size(); ++i) {
            cout << "Q" << i + 1 << ": " << questions[i].questionText << endl;
            for (size_t j = 0; j < questions[i].options.size(); ++j) {
                cout << j + 1 << ". " << questions[i].options[j] << endl;
            }
            int answer;
            cout << "Enter your answer (1-" << questions[i].options.size() << "): ";
            cin >> answer;
            if (answer == questions[i].correctOption) {
                ++score;
            }
        }
        userScores[username] = score;
    }

    void displayScores() const {
        for (const auto& pair : userScores) {
            cout << pair.first << ": " << pair.second << " points" << endl;
        }
    }

    void displayCorrectAnswers() const {
        for (size_t i = 0; i < questions.size(); ++i) {
            cout << "Q" << i + 1 << ": " << questions[i].questionText << endl;
            cout << "Correct answer: " << questions[i].options[questions[i].correctOption - 1] << endl;
        }
    }
};

class QuizGame {
private:
    Quiz quiz;
    string username;

public:
    void registerUser() {
        cout << "Enter your username: ";
        cin >> username;
    }

    void start() {
        quiz.addQuestion(Question("What is the capital of France?", { "Berlin", "Madrid", "Paris", "Rome" }, 3));
        quiz.addQuestion(Question("What is the chemical formula of Glucose?", { "C6H5O6", "C6H12O6", "H20", "C5H7O6" }, 2));
        quiz.addQuestion(Question("Who wrote 'Harry Potter'?", { "Harper Lee", "Mark Twain", "J.K. Rowling", "Ernest Hemingway" }, 3));
        quiz.addQuestion(Question("What is the capital of Japan?", { "Seoul", "Beijing", "Tokyo", "Bangkok" }, 3));
        quiz.addQuestion(Question("Who wrote the play 'Romeo and Juliet'?", { "Charles Dickens", "George Orwell", "William Shakespeare", "Mark Twain" }, 3));
        quiz.addQuestion(Question("Which planet is known as the Red Planet?", { "Earth", "Mars", "Jupiter", "Venus" }, 2));
        quiz.addQuestion(Question("What is the largest ocean on Earth?", { "Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Pacific Ocean" }, 4));
        quiz.addQuestion(Question("In which year did the Titanic sink?", { "1912", "1921", "1918", "1905" }, 1));
        quiz.addQuestion(Question("Who painted the Mona Lisa?", { "Vincent van Gogh", "Pablo Picasso", "Leonardo da Vinci", "Claude Monet" }, 3));
        quiz.addQuestion(Question("What is the chemical symbol for gold?", { "Au", "Ag", "Fe", "Hg" }, 1));
        quiz.addQuestion(Question("Which country is known as the Land of the Rising Sun?", { "China", "Japan", "Australia", "Thailand" }, 2));
        quiz.addQuestion(Question("What is the smallest continent by land area?", { "Europe", "Australia", "Antarctica", "South America" }, 2));
        quiz.addQuestion(Question("Who developed the theory of relativity?", { "Isaac Newton", "Galileo Galilei", "Nikola Tesla", "Albert Einstein" }, 4));
        quiz.addQuestion(Question("What is the hardest natural substance on Earth?", { "Gold", "Iron", "Diamond", "Platinum" }, 3));
        quiz.addQuestion(Question("Which country hosted the 2016 Summer Olympics?", { "China", "UK", "Brazil", "Russia" }, 3));
        quiz.addQuestion(Question("What is the largest mammal in the world?", { "Elephant", "Blue Whale", "Great White Shark", "Giraffe" }, 2));
        quiz.addQuestion(Question("Which element is said to keep bones strong?", { "Iron", "Calcium", "Magnesium", "Potassium" }, 2));
        quiz.addQuestion(Question("Which country is known as the Land of Maple Leaf?", { "USA", "Canada", "New Zealand", "Sweden" }, 2));

        registerUser();
        quiz.startQuiz(username);
        quiz.displayCorrectAnswers();
        quiz.displayScores();
    }
};

int main() {
    cout << "\t\t\tWelcome to Quiz Game." << endl << endl;
    cout << "Here are some instructions." << endl;
    cout << "1. This game consist of 18 general knowledge questions." << endl << "2. Each correct answer adds 1 to your score." << endl << "3. Correct answers and score will display at the end of game." << endl << endl;
    QuizGame game;
    cout << endl;
    game.start();
    return 0;
}
