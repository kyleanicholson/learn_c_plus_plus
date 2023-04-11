
/*
Lab No: 1A
Name: Kyle Nicholson
Date: 4/3/2023
Revision: 1.0
Description: This program implements an array-based tic-tac-toe game. The program
             will display the game board, prompt the user for a move, check if
             the game has been won or ended in a draw, and switch players.
*/

#include <iostream>
#include "lab1_kan.hpp"

using namespace std;


int main() {
    // Declare game variables
    char board[9]; // The tic-tac-toe board
    int currentPlayer = 1; // The current player (1 or 2)
    bool systemActive = true; // Whether the game system is active

    do {
        // Display instructions
        displayInstructions();

        // Initialize the board
        initBoard(board);

        // Declare a variable to keep track of whether the game is active
        bool gameActive = true;

        // Loop until the game is over
        do {
            // Display the board
            showBoard(board);
            // Get the current player's move
            getMove(board, 1);
            // Check if the game has been won
            checkWin(board);
            // Check if the game has ended in a draw
            checkDraw(board);
            // Switch players
            if (currentPlayer == 1) {
                currentPlayer = 2;
            } else {
                currentPlayer = 1;
            }
            gameActive = false; // Used for stub testing only

        } while (gameActive);

        // Check if the user wants to play again
        if (playAgain()) {
            systemActive = true;
        } else {
            systemActive = false;
        };
    } while (systemActive);

    return 0;
}