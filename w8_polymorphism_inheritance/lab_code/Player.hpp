// The Player class is an abstract class.
// It includes an instance of a Person, which should be created dynamically and deleted when Player goes away, this is an example of class composition.
//•	Constructor – default constructor creates a default Person, overloaded constructor has parameters firstName, lastName, and age and creates Person using those values.
//•	Destructor – deletes the Person.
//•	getPlayerName – returns a single string that is firstName, space, lastName
//•	getPlayerAge – returns the age
//•	getClassName, getAction – pure virtual functions with return type string.

#ifndef LAB_CODE_PLAYER_HPP
#define LAB_CODE_PLAYER_HPP

#include "Person.hpp"
#include "helper.hpp"
#include <string>
#include <iostream>


class Player {
private:
    Person *person;
protected:
    // String variable for class name
    std::string className;
    // String variable for action
    std::string action;
public:
    // Default constructor - default constructor creates a default Person
    Player();

    // Overloaded constructor has parameters firstName, lastName, and age and creates Person using those values
    Player(const std::string &firstName, const std::string &lastName, int age);

    // Make sure the copy constructor, assignment, and equality use all use four values (first name, last name, age, and className)
    // Copy constructor
    Player(const Player &player);

    // Destructor - deletes the person
    ~Player();

    // Assignment operator
    Player &operator=(const Player &player);

    // Equality operator
    bool operator==(const Player &player) const;

    // Insertion operator
    friend std::ostream &operator<<(std::ostream &os, const Player &player);

    // Method to get player name
    std::string getPlayerName() const;

    // Method to get player age
    int getPlayerAge() const;
    // Methods to get class name and action
    std::string getClassName() const;
    std::string getAction() const;

};



//The four different character classes all inherit from Player.

//	Class Ranger – “shoots arrows”
class Ranger : public Player {
public:
    Ranger(const std::string &firstName, const std::string &lastName, int age);
    std::string getClassName() const;
    std::string getAction() const;
};
//	Class Wizard – “casts fireballs”
class Wizard : public Player {
public:
    Wizard(const std::string &firstName, const std::string &lastName, int age);
    std::string getClassName() const;
    std::string getAction() const;
};
//	Class Rogue – “picks pockets”
class Rogue : public Player {
public:
    Rogue(const std::string &firstName, const std::string &lastName, int age);
    std::string getClassName() const;
    std::string getAction() const;
};
//	Class Priest – “heals”
class Priest : public Player {
public:
    Priest(const std::string &firstName, const std::string &lastName, int age);
    std::string getClassName() const;
    std::string getAction() const;
};


Player *createPlayer();

void displayPlayers(Player *players[], int size);


#endif //LAB_CODE_PLAYER_HPP
