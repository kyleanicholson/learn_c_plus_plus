
#ifndef LAB_CODE_LAB1_KAN_HPP
#define LAB_CODE_LAB1_KAN_HPP

#include <string>
#include <iostream>

using namespace std;

// Function prototypes
int getNumber(int min, int max);
bool yesNo(string prompt);
void displayInstructions();
void initBoard(char board[9]);
void showBoard(const char board[]);
void getMove(char board[], int player);
bool checkWin(const char board[]);
bool checkDraw(const char board[]);
bool playAgain();


#endif //LAB_CODE_LAB1_KAN_HPP
