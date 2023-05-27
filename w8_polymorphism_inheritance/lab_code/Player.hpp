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

class Player {
private:
    Person *person;
public:
    // Default constructor - default constructor creates a default Person
    Player();

    // Overloaded constructor has parameters firstName, lastName, and age and creates Person using those values
    Player(const std::string &firstName, const std::string &lastName, int age);

    // Destructor - deletes the person
    ~Player();
    // Method to get player name
    std::string getPlayerName() const;

    // Method to get player age
    int getPlayerAge() const;
    // Pure virtual functions with return type string for getClassName and getAction
    virtual std::string getClassName() const = 0;
    virtual std::string getAction() const = 0;
};


//The four different character classes all inherit from Player.

//	Class Ranger – “shoots arrows”
class Ranger : public Player {
public:
    Ranger(const std::string &firstName, const std::string &lastName, int age);
    std::string getClassName() const override;
    std::string getAction() const override;
};
//	Class Wizard – “casts fireballs”
class Wizard : public Player {
public:
    Wizard(const std::string &firstName, const std::string &lastName, int age);
    std::string getClassName() const override;
    std::string getAction() const override;
};
//	Class Rogue – “picks pockets”
class Rogue : public Player {
public:
    Rogue(const std::string &firstName, const std::string &lastName, int age);
    std::string getClassName() const override;
    std::string getAction() const override;
};
//	Class Priest – “heals”
class Priest : public Player {
public:
    Priest(const std::string &firstName, const std::string &lastName, int age);
    std::string getClassName() const override;
    std::string getAction() const override;
};


Player *createPlayer();

void displayPlayers(Player *players[], int size);


#endif //LAB_CODE_PLAYER_HPP
