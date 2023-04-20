

#include "lab3_kan_dungeon.hpp"

void createDungeon( char dungeon[][MAX_SIZE], int traps, int treasures, int player_loc[2]) {
    // initialize a new dungeon
    //  randomly place that many traps and treasures in the dungeon in empty locations
    //  randomly place the player and exit, each in an empty location
    // make sure that each item placed is in a separate location
    // pass back player starting location via the player location parameter
 std::cout << "Creating dungeon" << std::endl;
}

void displayDungeon(char dungeon[][MAX_SIZE]) {
    // Display dungeon
    std::cout << "Displaying dungeon" << std::endl;

}

void getMove(int player_loc[2], int new_player_loc[2]) {

    // pass in the current player_loc location and empty new player_loc location as 2-element arrays
    // gets and validates a move (L, R, U, D)
    std::cout << "Getting a move" << std::endl;

    // pass back new player_loc location using parameter
}

bool checkLose(int player_loc[2], char dungeon[][MAX_SIZE]) {
    // pass in the player location and the dungeon
    // check if the player has stepped on a trap
    // return true if the player has lost
    std::cout << "Checking if player has lost" << std::endl;
    return false;
}

bool checkWin(int player_loc[2], char dungeon[][MAX_SIZE]) {
    // pass in the player location and the dungeon
    // check if the player has stepped on a treasure
    // return true if the player has won
    std::cout << "Checking if player has won" << std::endl;
    return true;
}

void updateDungeon(char dungeon[][MAX_SIZE], int player_loc[2], int new_player_loc[2]) {
    // update dungeon for the next cycle
    // pass in the dungeon, previous player location, new player location
    std::cout << "Updating dungeon" << std::endl;
}

bool playAgain() {
    // ask the player if they want to play again
    // return true if they want to play again
    std::cout << "Asking if player wants to play again" << std::endl;
    return false;
}