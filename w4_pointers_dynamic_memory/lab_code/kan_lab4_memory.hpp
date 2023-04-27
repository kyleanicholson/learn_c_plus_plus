

#ifndef LAB_CODE_KAN_LAB4_MEMORY_HPP
#define LAB_CODE_KAN_LAB4_MEMORY_HPP

#include <iostream>
//Program constants
const int HARD_ROW = 5, HARD_COL = 6, EASY_ROW = 4, EASY_COL = 4;
const char SPACE = ' ', UNKNOWN = 'X';

//Function prototypes and declarations

// Helper functions
bool yesNo(const std::string& prompt);
int getInteger(int min, int max);

// Inline functions (full declarations)
inline int getIndex(int move[], int colLength){
    //input parameters are a move (two element integer array) and colLength
    //converts the row and column of the move into a 1D index
    //returns the index (0-15 for an easy game, 0-29 for a hard game)
    return 10; // return value for testing
}
inline int getIndex(int rowIndex, int colIndex, int colLength) {
    //Overloaded version of getIndex
    //input parameters are a rowIndex, colIndex, and colLength
    //converts the row and column of the move into a 1D index
    //returns the index (0-15 for an easy game, 0-29 for a hard game)
    return 10; // return value for testing
}

// Main Functions
void displayInstructions();
char* createBoard(int difficulty);
void shuffleBoardArray(char* board, int boardLength);
void getMove(char board[], int rowLength, int colLength, int move[]);
void getMove(char board[], int rowLength, int colLength, int move1[], int move2[]);
void showBoard(char board[], int rowLength, int colLength);
void showBoard(char board[], int rowLength, int colLength, int move1[]);
void showBoard(char board[], int rowLength, int colLength, int move1[], int move2[]);
bool checkMatch(char board[], int rowLength, int colLength, int move1[], int move2[]);
void updateBoard(char board[], int rowLength, int colLength, int move1[], int move2[]);
bool checkDone(char board[], int rowLength, int colLength);



#endif //LAB_CODE_KAN_LAB4_MEMORY_HPP