//This file contains the functions that are called by the source file. They are written here then referenced
//in the header file, which is further referenced by the source.cpp which contains the main method.
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "functions.h"

using namespace std;

void playHangman() {
    // Play again option
    char playAgain;
    do {
        try {
            // Declare Variables
            string randWord;
            string letGuess;
            int wrongGuess = 0;
            const int maxWrongGuesses = 10;

            // List of random words
            vector<string> words = { "hamburger", "licorice", "computer", "hardware", "software", "mountain" };

            // Seed and select a random word
            srand(time(0));
            randWord = words[rand() % words.size()];

            // Initialize the current guess display with underscores
            string currentGuess(randWord.size(), '_');

            cout << "A word has been selected. It's time for you to select your first letter!" << endl;

            while (currentGuess != randWord && wrongGuess < maxWrongGuesses) {
                // Display current guesses
                cout << "Current guesses: " << currentGuess << endl;
                cout << "Enter a guess: ";
                cin >> letGuess;

                // Ensure only a single character is used
                if (letGuess.size() != 1) {
                    throw invalid_argument("Please enter only one character.");
                }

                char guess = letGuess[0];
                bool correctGuess = false;

                // Check if the guessed letter is in the word
                for (int i = 0; i < randWord.size(); i++) {
                    if (randWord[i] == guess) {
                        currentGuess[i] = guess;
                        correctGuess = true;
                    }
                }

                // If guess is wrong
                if (!correctGuess) {
                    wrongGuess++;
                    cout << "Sorry, that letter is not part of the word. You have "
                        << (maxWrongGuesses - wrongGuess) << " guesses left." << endl;
                }
            }

            // Outcome of the game
            if (currentGuess == randWord) {
                cout << "Congratulations! You guessed the word! Your score is "
                    << (maxWrongGuesses - wrongGuess) << endl;
            }
            else {
                cout << "Game over! The correct word was: " << randWord << endl;
            }

            // Ask if the user wants to play again
            cout << "Do you want to play again? (Y/N): ";
            cin >> playAgain;

        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
            playAgain = 'Y';  // Set playAgain to 'Y' to restart the game on invalid input
        }

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for playing!" << endl;
}

void showInstructions() {
    cout << "Instructions:\n";
    cout << "1. A random word will be chosen for you to guess.\n";
    cout << "2. Enter one letter at a time.\n";
    cout << "3. If you guess wrong 10 times, you lose.\n";
    cout << "4. If you complete the word before 10 wrong guesses, you win!\n";
}
