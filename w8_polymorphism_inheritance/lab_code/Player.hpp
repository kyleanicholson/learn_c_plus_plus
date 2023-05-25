// Player class implementation

#ifndef LAB_CODE_PLAYER_HPP
#define LAB_CODE_PLAYER_HPP

#include "Person.hpp"

class Player {
private:
    Person person;
public:
    // Default constructor
    Player() : person() {}
    // Overloaded constructor
    Player(const std::string& firstName, const std::string& lastName, int age)
            : person(firstName, lastName, age) {}

    // Method to get player name
    std::string getPlayerName() const {
        return person.getFirstName() + " " + person.getLastName();
    }

    // Method to get player age
    int getPlayerAge() const {
        return person.getAge();
    }
};


#endif //LAB_CODE_PLAYER_HPP
