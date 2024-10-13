
#include <chrono>
#include <iostream>
#include <random>
#include <string>
using namespace std;


int difficulty_level() {


    while (true) {

        string choice;
        int choice_number;

        cout << "Enter your choice (1, 2, or 3): ";
        cin >> choice;

        if (all_of(choice.begin(), choice.end(), ::isdigit)) {
            // Converting a string to a number
            choice_number = stoi(choice);
        }else{
            cout << "Invalid choice. Please try again." << '\n';
            continue;
        }

        switch (choice_number)
        {
        case 1:
            cout << "Great! You have selected the Easy difficulty level." << "\n";
            cout << "Let's start the game!" << "\n";
            return 10;
        case 2:
            cout << "Great! You have selected the Medium difficulty level." << "\n";
            cout << "Let's start the game!" << "\n";
            return 5;
        case 3:
            cout << "Great! You have selected the Hard difficulty level." << "\n";
            cout << "Let's start the game!" << "\n";
            return 3;
        default:
            cout << "Invalid choice. Please try again." << "\n";
        }
    }
}

int generate_random_number() {
    // The generator is initialized using time as the seed
    static default_random_engine generator(static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count()));
    uniform_int_distribution<int> distribution(1,100);
    return distribution(generator);
}

int game_main(const int number_of_attempts, const int random_number) {

    string guess;
    int guess_number;

    for (int attempt = 0; attempt < number_of_attempts; attempt++) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (all_of(guess.begin(), guess.end(), ::isdigit)) {
            // Converting a string to a number
            guess_number = stoi(guess);
        }else{
            cout << "Invalid guess. Please try again." << "\n";
            attempt -= 1;
            continue;
        }

        if (guess_number == random_number) {
            if (attempt == 0) {
                attempt = 1;
            }
            cout << "Congratulations! You guessed the correct number in " << attempt << " attempts." << "\n";
            return 0;
        }
        if (guess_number > random_number) {
            cout << "Incorrect! The number is less than " << guess_number << "!" << "\n";
            continue;
        }
        if (guess_number < random_number) {
            cout << "Incorrect! The number is greater than  " << guess_number << "!" << "\n";
        }
    }
    cout << "Sorry you lose. Try agan!" << "\n";
    return 0;
}

int main(int argc, char* argv[])
{

    // Greetings before the game
    cout << "Welcome to the Number Guessing Game!" << "\n" << "I'm thinking of a number between 1 and 100." << "\n" << "\n";
    cout << "Please select the difficulty level: " << "\n" << "1. Easy (10 chances)" << "\n" << "2. Medium (5 chances)" << "\n" << "3. Hard (3 chances)" << "\n" << "\n";

    // Select difficulty level and create a random number
    const int number_of_attempts = difficulty_level();
    const int random_number = generate_random_number();

    // Main game
    game_main(number_of_attempts,random_number);

    return 0;

}

