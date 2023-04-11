
#include <iostream>
#include <string>
#include "lab1_kan.hpp"


using namespace std;

void displayInstructions(){
    cout << "Welcome to Tic Tac Toe!" << endl;
//    cout << "To play, enter a number 1-9 corresponding to the position on the board." << endl;
//    cout << "The board is laid out as follows:" << endl;
//    cout << "1 | 2 | 3" << endl;
//    cout << "---------" << endl;
//    cout << "4 | 5 | 6" << endl;
//    cout << "---------" << endl;
//    cout << "7 | 8 | 9" << endl;
//    cout << "Good luck!" << endl;

}

void initBoard(char board[]) {
    // Set every element of the board array to a default value (e.g. ' ')
    cout << "Initializing board..." << endl;
}

void showBoard(const char board[]) {
    // Output the board array to the console, formatted as a tic-tac-toe grid
    cout << "Displaying board..." << endl;
}

void getMove(char board[], int player) {
    cout << "Getting move..." << endl;
    // Prompt the user for a move
    // Check if the move is valid
    // If the move is valid, update the board array
}

bool checkWin(const char board[]) {
    cout << "Checking for win..." << endl;
    // Check if the game has been won
    // Return true if the game has been won, false otherwise
}

bool checkDraw(const char board[]) {
    cout << "Checking for draw..." << endl;
    // Check if the game has ended in a draw
    // Return true if the game has ended in a draw, false otherwise
}

bool playAgain() {
    cout << "Checking if user wants to play again..." << endl;
    // Prompt the user to play again
    // Return true if the user wants to play again, false otherwise
}

