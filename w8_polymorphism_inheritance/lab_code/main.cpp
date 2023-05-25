/*
 Lab No: 8
 Name: Kyle Nicholson
 Date: 5/25/2023
 Revision: 1.0
 Description: This program implements a Person class and a Player class with a Person object as a member variable.
 The main function creates a default Person and an overloaded Person. It then shows that all setters and getters work.
 It then creates a default Player and an overloaded Player. It then shows that getPlayerName and getPlayerAge work
    */

#include <iostream>
#include "Person.hpp"
#include "Player.hpp"

int main() {
    // Create a default Person and an overloaded Person.
    Person person1;
    Person person2("Jane", "Doe", 34);
    // Show that all setters and getters work.
    person1.setFirstName("John");
    person1.setLastName("Doe");
    person1.setAge(34);

    std::cout << "Default Person: " << person1.getFirstName() << " " << person1.getLastName()
              << ", Age: " << person1.getAge() << std::endl;

    std::cout << "Overloaded Person: " << person2.getFirstName() << " " << person2.getLastName()
              << ", Age: " << person2.getAge() << std::endl;

    //Create a default Player and an overloaded Player
    Player player1;
    Player player2("Art", "Vandelay", 25);

    // show that getPlayerName and getPlayerAge work properly for both.
    std::cout << "Default Player: " << player1.getPlayerName() << ", Age: " << player1.getPlayerAge() << std::endl;
    std::cout << "Overloaded Player: " << player2.getPlayerName() << ", Age: " << player2.getPlayerAge() << std::endl;

    return 0;
}
