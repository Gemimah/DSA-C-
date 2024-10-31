#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <cstdlib>

using namespace std;


unordered_map<string, vector<string>> word_categories = {
    {"Animals", {"elephant", "giraffe", "kangaroo", "zebra", "alligator"}},
    {"Teams", {"lakers", "warriors", "bulls", "celtics", "yankees"}},
    {"Districts", {"manhattan", "queens", "brooklyn", "bronx", "harlem"}},
    {"Films", {"inception", "gladiator", "avatar", "titanic", "jaws"}},
    {"Books", {"dune", "it", "frankenstein", "dracula", "hamlet"}}
};


pair<string, string> chooseCategory() {
    int index = 0;
    cout << "\nCategories:\n";
    for (const auto& [category, _] : word_categories) {
        cout << ++index << ". " << category << endl;
    }

    cout << "Choose a category by number: ";
    int choice;
    cin >> choice;
    while (choice < 1 || choice > word_categories.size()) {
        cout << "Invalid choice. Please try again: ";
        cin >> choice;
    }

    auto it = next(word_categories.begin(), choice - 1);
    const string& category_name = it->first;
    const vector<string>& words = it->second;
    string word = words[rand() % words.size()];
    return make_pair(category_name, word);
}


string displayWord(const string& word, const unordered_set<char>& guessed_letters) {
    string display;
    for (char c : word) {
        display += (guessed_letters.count(c) ? c : '_');
    }
    return display;
}


void playGame() {
    cout << "\nWelcome to the Word Guessing Game!" << endl;
    auto [category, word] = chooseCategory();
    cout << "\nYou selected the '" << category << "' category. Let's start guessing!" << endl;

    unordered_set<char> guessed_letters;
    int attempts_remaining = 6;

    while (attempts_remaining > 0) {
        cout << "\nWord to guess: " << displayWord(word, guessed_letters) << endl;
        cout << "Guessed letters: ";
        for (char c : guessed_letters) cout << c << ' ';
        cout << "\nRemaining attempts: " << attempts_remaining << endl;

        cout << "Guess a letter (or type 'exit' to quit): ";
        string input;
        cin >> input;

        if (input == "exit") {
            cout << "Thanks for playing! Goodbye." << endl;
            return;
        }

        if (input.length() != 1 || !isalpha(input[0])) {
            cout << "Please enter a single alphabetical letter." << endl;
            continue;
        }

        char guess = tolower(input[0]);
        if (guessed_letters.count(guess)) {
            cout << "You've already guessed that letter. Try a different one." << endl;
            continue;
        }

        guessed_letters.insert(guess);
        if (word.find(guess) != string::npos) {
            cout << "Good guess!" << endl;
        } else {
            cout << "Wrong guess." << endl;
            attempts_remaining--;
        }

        if (displayWord(word, guessed_letters) == word) {
            cout << "\nCongratulations! You've guessed the word: " << word << endl;
            break;
        }
    }

    if (attempts_remaining == 0) {
        cout << "\nSorry, you've run out of attempts. The word was: " << word << endl;
    }

    cout << "Do you want to play again? (yes/no): ";
    string play_again;
    cin >> play_again;
    if (play_again == "yes") {
        playGame();
    } else {
        cout << "Thanks for playing! See you next time." << endl;
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    playGame();
    return 0;
}
