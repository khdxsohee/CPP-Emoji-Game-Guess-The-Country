#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for transform()

using namespace std;

// Structure to store each quiz round
struct Quiz {
    string emojis;
    string answer;
};

// Convert string to lowercase for comparison
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    cout << "🎮 Welcome to 'Guess the Country from Emoji' Game! 🎮\n";
    cout << "-----------------------------------------------------\n\n";

    // Emoji and corresponding country list
    vector<Quiz> quizList = {
        {"🇯🇵 🍣 🎌", "japan"},
        {"🇫🇷 🥖 🗼", "france"},
        {"🇮🇹 🍕 🎭", "italy"},
        {"🇮🇳 🕌 🍛", "india"},
        {"🇺🇸 🍔 🎬", "usa"},
        {"🇩🇪 🍺 🏰", "germany"},
        {"🇧🇷 ⚽ 🥥", "brazil"},
        {"🇪🇬 🐫 🏜️", "egypt"},
        {"🇨🇳 🐉 🍜", "china"},
        {"🇵🇰 🕌 🍗", "pakistan"}
    };

    int score = 0;

    for (int i = 0; i < quizList.size(); i++) {
        cout << "Round " << (i + 1) << ":\n";
        cout << "Guess the country: " << quizList[i].emojis << endl;
        cout << "Your Answer: ";
        string userAnswer;
        getline(cin, userAnswer);

        if (toLower(userAnswer) == quizList[i].answer) {
            cout << "✅ Correct!\n\n";
            score++;
        } else {
            cout << "❌ Wrong! Correct answer was: " << quizList[i].answer << "\n\n";
        }
    }

    cout << "🎉 Game Over! Your Final Score: " << score << " / " << quizList.size() << endl;
    if (score == quizList.size()) {
        cout << "🏆 Amazing! You're a world emoji champion!\n";
    } else if (score >= quizList.size() / 2) {
        cout << "👍 Good job! Try again to improve your score.\n";
    } else {
        cout << "😅 Better luck next time!\n";
    }

    return 0;
}
