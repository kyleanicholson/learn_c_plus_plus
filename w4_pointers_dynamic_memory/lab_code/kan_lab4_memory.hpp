

#ifndef LAB_CODE_KAN_LAB4_MEMORY_HPP
#define LAB_CODE_KAN_LAB4_MEMORY_HPP

#include <iostream>
#include <iomanip>
#include <random>

//Program constants
const int HARD_ROW = 5, HARD_COL = 6, EASY_ROW = 4, EASY_COL = 4;
const char SPACE = '.', UNKNOWN = 'X';
//Function prototypes and declarations

// Helper functions
bool yesNo(const std::string& prompt);
int getInteger(int min, int max);
int generateRandomInt(int min, int max);

// Inline functions (full declarations)
inline int getIndex(int move[], int colLength){
    //converts the row and column of the move into a 1D index
    int row = move[0];
    int col = move[1];
    return row * colLength + col;

};
inline int getIndex(int rowIndex, int colIndex, int colLength) {
    //Overloaded version of getIndex
    //converts the row and column of the move into a 1D index
    //returns the index (0-15 for an easy game, 0-29 for a hard game)
    return rowIndex * colLength + colIndex;
};

// Main Functions
void displayInstructions();
char* createBoard(int difficulty);
void shuffleBoardArray(char* board, int boardLength);
void getMove(const char board[], int rowLength, int colLength, int move[]);
void getMove(char board[], int rowLength, int colLength, int move1[], int move2[]);
void showBoard(char board[], int rowLength, int colLength);
void showBoard(char board[], int rowLength, int colLength, int move1[]);
void showBoard(char board[], int rowLength, int colLength, const int move1[], const int move2[]);
bool checkMatch(char board[], int rowLength, int colLength, int move1[], int move2[]);
void updateBoard(char board[], int rowLength, int colLength, int move1[], int move2[]);
bool checkDone(char board[], int rowLength, int colLength);



#endif //LAB_CODE_KAN_LAB4_MEMORY_HPP