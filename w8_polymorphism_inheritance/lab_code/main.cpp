/*
 Lab No: 8b
 Name: Kyle Nicholson
 Date: 5/27/2023
 Revision: 1.0
 Description: This program creates a dynamic array of Player pointers and fills it with Player objects.
    It then displays the full name, age, class, and action of each Player object.
    */

#include <iostream>
#include "Player.hpp"
#include "helper.hpp"

int main() {
    int numPlayers;
    std::cout << "How many players are in the game? ";
    numPlayers = getInteger(5, 10);
    Player *players[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        players[i] = createPlayer();
    }
    displayPlayers(players, numPlayers);

    return 0;
}
