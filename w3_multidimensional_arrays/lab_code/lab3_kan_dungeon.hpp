
#ifndef LAB_CODE_LAB3_KAN_DUNGEON_HPP
#define LAB_CODE_LAB3_KAN_DUNGEON_HPP
#include <iostream>
#include <iomanip>
#include <random>

// Game Constants

const int MAX_SIZE = 10; // Maximum size of the dungeon
const int NUM_TRAPS = 5; // Number of traps in the dungeon
const int NUM_TREASURES = 3; // Number of treasures in the dungeon

// Game Text
const std::string WELCOME_TEXT =
        R"(
    ____                                        ______           __
   / __ \__  ______  ____ ____  ____  ____     / ____/  ______  / /___  ________  _____
  / / / / / / / __ \/ __ `/ _ \/ __ \/ __ \   / __/ | |/_/ __ \/ / __ \/ ___/ _ \/ ___/
 / /_/ / /_/ / / / / /_/ /  __/ /_/ / / / /  / /____>  </ /_/ / / /_/ / /  /  __/ /
/_____/\__,_/_/ /_/\__, /\___/\____/_/ /_/  /_____/_/|_/ .___/_/\____/_/   \___/_/
                  /____/                              /_/
)";

const std::string GAME_OVER_TEXT =
        R"(
_____ _____ _____ _____    _____ _____ _____ _____
|   __|  _  |     |   __|  |     |  |  |   __| __  |
|  |  |     | | | |   __|  |  |  |  |  |   __|    -|
|_____|__|__|_|_|_|_____|  |_____|\___/|_____|__|__|

)";

const std::string WIN_TEXT =
        R"(
   _____ __  ______________________________ __
  / ___// / / / ____/ ____/ ____/ ___/ ___// /
  \__ \/ / / / /   / /   / __/  \__ \\__ \/ /
 ___/ / /_/ / /___/ /___/ /___ ___/ /__/ /_/
/____/\____/\____/\____/_____//____/____(_)

)";



// Function prototypes
int generateRandomInt(int min, int max);
void createDungeon(char dungeon[][MAX_SIZE], int traps, int treasures, int (&player_loc)[2]);
void displayDungeon(char dungeon[][MAX_SIZE]);
void getMove(const int player_loc[2], int (&new_player_loc)[2]);
bool checkLose(const int player_loc[2], char dungeon[][MAX_SIZE]);
bool checkWin(const int player_loc[2], char dungeon[][MAX_SIZE]);
void updateDungeon(char dungeon[][MAX_SIZE], const int player_loc[2], const int new_player_loc[2]);
bool yesNo(const std::string& prompt);
bool playAgain();



#endif //LAB_CODE_LAB3_KAN_DUNGEON_HPP
