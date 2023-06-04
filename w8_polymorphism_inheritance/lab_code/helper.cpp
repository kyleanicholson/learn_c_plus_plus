//
//  Helper.cpp
//  Player List
//
//  Created by jim bailey on 3/3/21.
//

#include "Helper.hpp"

// create a random person
void makePersonInfo(string & fName, string & lName, int & age)
{
    const int FIRSTS = 8;
    const int LASTS = 7;
    const int MIN_AGE = 10;
    const int MAX_AGE = 90;

    string firstNames[FIRSTS] = {"Bill", "Mary", "John", "Nancy", "Paul", "George", "Frodo", "Linda"};
    string lastNames[LASTS] = {"Jones", "Smith", "Green", "White", "Baggins", "Dunhill", "Scarlet"};

    fName = firstNames[rand() % FIRSTS];
    lName = lastNames[rand() % LASTS];

    age = rand() % (MAX_AGE - MIN_AGE + 1) + MIN_AGE;
}

// create a specified player with random person
Player * makePlayer(Characters choice)
{
    string lName, fName;
    int age;
    Player * theCharacter;

    makePersonInfo(fName, lName, age);

    switch(choice)
    {
        case ePlayer:
            theCharacter = new Player(fName, lName, age);
            break;
        case ePriest:
            theCharacter = new Priest(fName, lName, age);
            break;
        case eRanger:
            theCharacter = new Ranger(fName, lName, age);
            break;
        case eRogue:
            theCharacter = new Rogue(fName, lName, age);
            break;
        case eWizard:
            theCharacter = new Wizard(fName, lName, age);
            break;
        case eNUM_CHARS:
        default:
            // should never get here, so make a priest
            theCharacter = new Priest(fName, lName, age);
    }
    return theCharacter;
}

int getInteger(int min, int max){
    int input;
    std::cin >> input;
    while (input < min || input > max){
        std::cout << "Invalid input, please enter a number between " << min << " and " << max << ": ";
        std::cin >> input;
    }
    return input;
}