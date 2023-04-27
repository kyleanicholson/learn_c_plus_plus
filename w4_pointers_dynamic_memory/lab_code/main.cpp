/*
Lab No: 4
Name: Kyle Nicholson
Date: 4/26/2023
Revision: 1.0
Description: This program implements a memory game using pointers and arrays.

*/
#include "kan_lab4_memory.hpp"
#include <iostream>
#include <iomanip>


int main() {

    // For a hard game, the board will be 30 squares (5 x 6) and for an easy game it will be 16 (4 x 4).
    do {
        //Declare game variables
        int move1, move2, rowLength, colLength, difficulty, tries = 0;
        char *board;
        bool done = false;
        //Ask user if they want to play a hard or easy game
        bool hardMode = yesNo("Enable hard mode?");
        if (hardMode) {
            rowLength = HARD_ROW;
            colLength = HARD_COL;
            difficulty = 2;
        } else {
            rowLength = EASY_ROW;
            colLength = EASY_COL;
            difficulty = 1;
        }
        //Create board array and shuffle
        board = createBoard(difficulty);
        //Display instructions
        displayInstructions();
        do {
            //Display board
            showBoard(board, rowLength, colLength);
            //Get move 1
            getMove(board, rowLength, colLength, &move1);
            //Get move 2 and compare with move 1
            getMove(board, rowLength, colLength, &move1, &move2);
            //Check match
            bool match = checkMatch(board, rowLength, colLength, &move1, &move2);
            //Update board
            updateBoard(board, rowLength, colLength, &move1, &move2);
            //Show board
            showBoard(board, rowLength, colLength, &move1, &move2);
            //Check if done
            done = checkDone(board, rowLength, colLength);
            //If not done, increment tries and repeat
            if (!done) {
                tries++;
            }

        } while (!done);
        //Ask user if they want to play again
    } while (yesNo("Would you like to play again?"));
    return 0;
}
