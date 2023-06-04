
#include "Player.hpp"
#include "helper.hpp"
// Default constructor - default constructor creates a default Person and sets className and action to “unknown”
Player::Player() : person(new Person()),className("unknown"), action("unknown") {}
// Overloaded constructor has parameters firstName, lastName, and age and creates Person using those values
Player::Player(const std::string &firstName, const std::string &lastName, int age)
        : person(new Person(firstName, lastName, age)) {}

// Copy constructor
Player::Player(const Player &player)
        : person(new Person(player.person->getFirstName(), player.person->getLastName(), player.person->getAge())),
          className(player.className) {}
// Destructor - deletes the person
Player::~Player() {
    delete person;
}
// Assignment operator
Player &Player::operator=(const Player &player) {
    if (this != &player) {
        delete person;
        person = new Person(player.person->getFirstName(), player.person->getLastName(), player.person->getAge());
        className = player.className;
    }
    return *this;
}
//Equality operator
bool Player::operator==(const Player &player) const {
    return person->getFirstName() == player.person->getFirstName() &&
           person->getLastName() == player.person->getLastName() &&
           person->getAge() == player.person->getAge() &&
           className == player.className;
}

// Insertion operator
 std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << player.person->getFirstName() << " " << player.person->getLastName() << " aged " << player.person->getAge()
       << " playing " << player.className << " " << player.action;
    return os;
}

std::string Player::getPlayerName() const {
    return person->getFirstName() + " " + person->getLastName();
}

std::string Player::getClassName() const {
    return className;
}

std::string Player::getAction() const {
    return action;
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

Wizard::Wizard(const std::string& firstName, const std::string& lastName, int age)
        : Player(firstName, lastName, age) {
    className = "Wizard";
    action = "casts fireballs";
}

std::string Wizard::getClassName() const {
    return className;
}

std::string Wizard::getAction() const {
    return action;
}

Rogue::Rogue(const std::string& firstName, const std::string& lastName, int age)
        : Player(firstName, lastName, age) {
    className = "Rogue";
    action = "picks pockets";
}

std::string Rogue::getClassName() const {
    return className;
}

std::string Rogue::getAction() const {
    return action;
}

Priest::Priest(const std::string& firstName, const std::string& lastName, int age)
        : Player(firstName, lastName, age) {
    className = "Priest";
    action = "heals";
}

std::string Priest::getClassName() const {
    return className;
}

std::string Priest::getAction() const {
    return action;
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
