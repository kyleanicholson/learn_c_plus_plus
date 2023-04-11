
/*
Lab No: 1B
Name: Kyle Nicholson
Date: 4/7/2023
Revision: 1.0
Description: This program implements an array-based tic-tac-toe game for two players. The program
             will display the game board, prompt the user for a move, check if
             the game has been won or ended in a draw, and switch players.
*/

#include <iostream>
#include <string>
#include "lab1_kan.hpp"

// Helper Functions

int getNumber(int min, int max) {
    // Get a number between min and max from the user
    int num;
    bool valid;
    do {
        cin >> num;
        // set the input flag
        valid = true;
        // check if valid integer between min and max
        if (cin.fail() || num < min || num > max) {
            if (cin.fail()) {
                cout << "Invalid input, please try again" << endl;
                // clear error flags and flush input buffer
                cin.clear();
                cin.ignore(100, '\n');
            } else if (num < min || num > max) {
                cout << "Please choose a different number (must choose between " << min << " and " << max << ") ";
            }
            valid = false;
        }
    } while (!valid);
    return num;
}

bool yesNo(string prompt) {
    // Get a yes or no answer from the user
    char input;
    bool valid = false;
    do {
        cout << prompt << " ('y' or 'n')";
        cin >> input;
        input = tolower(input); // convert to lowercase
        // Ignore everything after the first character
        cin.ignore(100, '\n');
        switch (input) {
            case 'y':
            case 'n':
                valid = true;
                break;
            default:
                cout << "Invalid input, please try again" << endl;
                break;
        }
    } while (!valid);

    if (input == 'y')
        return true;
    else
        return false;
}

// Main Functions

void displayInstructions() {
// Display instructions for the game
    static int count;
    if (count == 0) {
        cout << "Welcome to Tic Tac Toe!" << endl;
        cout << "To play, enter a number 1-9 corresponding to the position on the board." << endl;
        cout << "The board is laid out as follows:" << endl;
        cout << "1 | 2 | 3" << endl;
        cout << "---------" << endl;
        cout << "4 | 5 | 6" << endl;
        cout << "---------" << endl;
        cout << "7 | 8 | 9" << endl;
        cout << "Player 1 will be 'X' and Player 2 will be 'O'" << endl;
        count++;
    } else {
        // reduced instructions for subsequent games
        cout << "To play, enter a number 1-9 corresponding to the position on the board." << endl;

    }

}

void initBoard(char board[9]) {
    // Set every element of the board array to blank for each new game

    for (int i = 0; i < 9; i++) {
        board[i] = ' ';
    }
}

void showBoard(const char board[]) {
    // Output the board array to the console, formatted as a tic-tac-toe grid
    cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---------" << endl;
    cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---------" << endl;
    cout << board[6] << " | " << board[7] << " | " << board[8] << endl;

}

void getMove(char board[], int currentPlayer) {
    int move;
    bool valid;
    cout << "Player " << currentPlayer << ", it's your turn: " << endl;
    cout << "Please choose a valid position on the board (1-9)" << endl;
    do {
        move = getNumber(1, 9);
        // Check if the move is valid
        if (board[move - 1] == ' ') {
            valid = true;
        } else {
            cout << "Invalid move - please choose an available space" << endl;
        }
    } while (!valid);
    // Update the board array with the player's move
    if (currentPlayer == 1) {
        board[move - 1] = 'X';
    } else {
        board[move - 1] = 'O';
    }
}

bool checkWin(const char board[]) {
    // Check if the game has been won
    for (int i = 0; i < 9; i++) {
        // Check for horizontal wins
        if (board[i] == board[i + 1] && board[i + 1] == board[i + 2] && board[i] != ' ') {
            return true;
        }
        // Check for vertical wins
        if (board[i] == board[i + 3] && board[i + 3] == board[i + 6] && board[i] != ' ') {
            return true;
        }
        // Check for first diagonal win
        if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ') {
            return true;
        }
        // Check for second diagonal win
        if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ') {
            return true;
        }
    }
    return false;
}

bool checkDraw(const char board[]) {
    // Check if the game has ended in a draw
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return false;
        }
    }
    return true;
}

bool playAgain() {
    // Returns true if user wants to restart game and false if not
    return yesNo("Would you like to play again?");
}


