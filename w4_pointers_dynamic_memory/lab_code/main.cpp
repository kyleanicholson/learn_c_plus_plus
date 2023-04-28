/*
Lab No: 4
Name: Kyle Nicholson
Date: 4/26/2023
Revision: 1.0
Description: This program implements a memory game using pointers and arrays.

*/
#include "kan_lab4_memory.hpp"


int main() {

    // For a hard game, the board will be 30 squares (5 x 6) and for an easy game it will be 16 (4 x 4).
    do {
        //Declare game variables
        int rowLength, colLength, difficulty, tries = 0;
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
        //Display game instructions
        displayInstructions();
        do {
            int move1[2], move2[2];
            //Display board
            showBoard(board, rowLength, colLength);

            //For each turn, display the current state of the board, showing an UNKNOWN or a SPACE at each
            //location.
            // Each location starts being shown as UNKNOWN. Once the value at a location has been
            //discovered, a SPACE will be shown there.
            //After showing the current state, get a move.
            //Get move 1
            getMove(board, rowLength, colLength, move1);
            //Then redisplay the state, but at the move’s location,
            //show the correct symbol instead of UNKNOWN.
            showBoard(board, rowLength, colLength, move1);
            //Then get a second move and display the board with
            //each of the two locations showing the correct symbol instead of UNKNOWN. A move is stored as a
            //two-element array containing the row and column of the move.
            getMove(board, rowLength, colLength, move1, move2);
            showBoard(board, rowLength, colLength, move1, move2);

            bool match = checkMatch(board, rowLength, colLength, move1, move2);

            // if there is a match update the board replacing the matched characters with SPACE at the two locations that were compared.
            if (match) {
                updateBoard(board, rowLength, colLength, move1, move2);
            }
            //Check if done
            done = checkDone(board, rowLength, colLength);
            //If not done, increment tries and repeat
            if (!done) {
                tries++;
            }

        } while (!done);
        //Ask user if they want to play again
        delete[] board;
    } while (yesNo("Would you like to play again?"));
    return 0;
}
