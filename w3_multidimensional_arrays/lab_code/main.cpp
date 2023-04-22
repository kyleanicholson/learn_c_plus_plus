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
        bool game_active = true;
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
            // Check if player has found a treasure
            if (checkTreasure(player_new_loc, dungeon)) {
                std::cout << TREASURE_TEXT << std::endl;
            }
            // Check if player has won
            if (checkWin(player_new_loc, dungeon)) {
                std::cout << WIN_TEXT << std::endl;
                game_active = false;
            }
            // Check if player has lost
            else if (checkLose(player_new_loc, dungeon)) {
                std::cout << GAME_OVER_TEXT << std::endl;
                game_active = false;
            }
            else{
                // Update the dungeon
                updateDungeon(dungeon, player_loc, player_new_loc);

                // Update player's location
                player_loc[0] = player_new_loc[0];
                player_loc[1] = player_new_loc[1];
                // Display the dungeon
                displayDungeon(dungeon);
            }




        } while (game_active);

    // Clear the console

    } while (playAgain());
    return 0;
}
