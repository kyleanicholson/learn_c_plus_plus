
#include "Player.hpp"
#include "helper.hpp"

Player::Player() : person(new Person()) {}

Player::Player(const std::string &firstName, const std::string &lastName, int age)
        : person(new Person(firstName, lastName, age)) {}

Player::~Player() {
    delete person;
}

std::string Player::getPlayerName() const {
    return person->getFirstName() + " " + person->getLastName();
}

int Player::getPlayerAge() const {
    return person->getAge();
}

Ranger::Ranger(const std::string &firstName, const std::string &lastName, int age)
        : Player(firstName, lastName, age) {}

std::string Ranger::getClassName() const {
    return "Ranger";
}

std::string Ranger::getAction() const {
    return "shoots arrows";
}

Wizard::Wizard(const std::string &firstName, const std::string &lastName, int age)
        : Player(firstName, lastName, age) {}

std::string Wizard::getClassName() const {
    return "Wizard";
}

std::string Wizard::getAction() const {
    return "casts fireballs";
}

Rogue::Rogue(const std::string &firstName, const std::string &lastName, int age)
        : Player(firstName, lastName, age) {}

std::string Rogue::getClassName() const {
    return "Rogue";
}

std::string Rogue::getAction() const {
    return "picks pockets";
}

Priest::Priest(const std::string &firstName, const std::string &lastName, int age)
        : Player(firstName, lastName, age) {}

std::string Priest::getClassName() const {
    return "Priest";
}

std::string Priest::getAction() const {
    return "heals";
}

Player *createPlayer() {
// used to dynamically create a new character class
    std::string firstName, lastName;
    int age;
    // get both names and age, age validated as between 5 and 90.
    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    std::cout << "Enter age: ";
    age = getInteger(5, 90);

    std::string className;
    // get character class, validated to be in one of the above classes
    std::cout << "Enter character class (Ranger, Wizard, Rogue, or Priest): ";
    std::cin >> className;
    while (className != "Ranger" && className != "Wizard" && className != "Rogue" && className != "Priest") {
        std::cout << "Invalid character class. Please enter a valid class: ";
        std::cin >> className;
    }
    // dynamically create proper character using a Player pointer
    if (className == "Ranger") {
        return new Ranger(firstName, lastName, age);
    } else if (className == "Wizard") {
        return new Wizard(firstName, lastName, age);
    } else if (className == "Rogue") {
        return new Rogue(firstName, lastName, age);
    } else {
        return new Priest(firstName, lastName, age);
    }
}

void displayPlayers(Player *players[], int numPlayers) {
    // Display array of players - for each player display full name, age, and class
    for (int i = 0; i < numPlayers; i++) {
        std::cout << players[i]->getPlayerName() << " aged " << players[i]->getPlayerAge() << " playing a "
                  << players[i]->getClassName() << " " << players[i]->getAction() << std::endl;
    }
}
