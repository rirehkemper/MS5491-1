//This includes the main function. The library includes the header file  that sources the function names
//Allen Rehkemper
//11/2/2024
//MS 549 Data Structures and Testing
//I expected to spend about 2 hours on this assignment. The assignment came out in about that much time with little error.

#include <iostream>
#include "functions.h"

using namespace std;

//main function
int main() {
    char choice;
    //the do/while statement allows the menu to remain displayed until a proper chooice is made until choice 3
    do {
        cout << "Menu:\n1. Play Hangman\n2. Instructions\n3. Exit\nChoose an option: ";
        cin >> choice;

        if (choice == '1') {
            playHangman();
        }
        else if (choice == '2') {
            showInstructions();
        }
        else if (choice == '3') {
            cout << "Exiting the program.\n";
        }
        else {
            cout <<"invalid choice.  You must choose 1,2, or 3.\n";
        }
    } while (choice != '3');

    return 0;
}
