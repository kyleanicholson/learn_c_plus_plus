/*
Lab No: 3
Name: Kyle Nicholson
Date: 4/19/2023
Revision: 1.0
Description: This program implements a simple dungeon game.
 . = Empty
 $ = Treasure
 # = Trap
 @ = Player
 X = Exit
*/

#include "lab3_kan_dungeon.hpp"

int main() {

    do {
        //create the dungeon as a MAX_SIZE x MAX_SIZE 2D array
        char dungeon[MAX_SIZE][MAX_SIZE];
        int player_loc[2], player_new_loc[2];
        // Create the dungeon
        createDungeon(dungeon, NUM_TRAPS, NUM_TREASURES, player_loc);
        std::cout << WELCOME_TEXT << std::endl;
        // Display the dungeon
        displayDungeon(dungeon);
        do {

            // Get  and validate the player's move
            getMove(player_loc, player_new_loc);
            // Update the dungeon
            updateDungeon(dungeon, player_loc, player_new_loc);
            // Update player's location
            player_loc[0] = player_new_loc[0];
            player_loc[1] = player_new_loc[1];
            // Display the dungeon
            displayDungeon(dungeon);

        } while (!checkWin(player_loc, dungeon) && !checkLose(player_loc, dungeon));

    // Ask the player if they want to play again
    } while (playAgain());
    return 0;
}
