
#ifndef LAB_CODE_LAB3_KAN_DUNGEON_HPP
#define LAB_CODE_LAB3_KAN_DUNGEON_HPP
#include <iostream>
// Game Constants

const int MAX_SIZE = 10;

// Function prototypes
void createDungeon(char dungeon[][MAX_SIZE], int traps, int treasures, int player_loc[2]);
void displayDungeon(char dungeon[][MAX_SIZE]);
void getMove(int player[2], int newPlayer[2]);
bool checkLose(int player[2], char dungeon[][MAX_SIZE]);
bool checkWin(int player[2], char dungeon[][MAX_SIZE]);
void updateDungeon(char dungeon[][10], int player[2], int newPlayer[2]);
bool playAgain();


#endif //LAB_CODE_LAB3_KAN_DUNGEON_HPP
