
#include "helper.hpp"

int getInteger(int min, int max) {
    // Get a number between min and max from the user
    int num;
    bool valid;
    do {
        std::cin >> num;
        std::cin.ignore(100, '\n');
        // set the input flag
        valid = true;
        // check if valid integer between min and max
        if (std::cin.fail() || num < min || num > max) {
            if (std::cin.fail()) {
                std::cout << "Invalid input, please try again" << std::endl;
                // clear error flags and flush input buffer
                std::cin.clear();
                std::cin.ignore(100, '\n');
            } else if (num < min || num > max) {
                std::cout << "Please choose a different number (must choose between " << min << " and " << max << ") ";
            }
            valid = false;
        }
    } while (!valid);
    return num;
}

std::string getString(std::string prompt) {
    // Get a string from the user
    std::string str;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, str);
        if (!std::cin.fail()) {
            break;
        }
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
    }
    return str;
}

Student *createStudent() {
    // create a new student
    std::string name;
    int age;
    // get name and age, age validated as being positive integer
    name = getString("Please enter the student's name: ");
    std::cout << "Please enter the student's age: ";
    age = getInteger(10, 90);
    // use name and age to dynamically create a student
    Student *student = new Student(name, age);
    // return a pointer to the student
    return student;

};

void displayStudents(const Student *students, int numStudents) {
    // Display the array of students with columns for name and age
    std::cout << std::left << std::setw(25) << "Name"
              << std::setw(5) << "Age" << std::endl;
    for (int i = 0; i < numStudents; i++) {
        std::cout << std::left << std::setw(20) << students[i].getName() << std::setw(5) << students[i].getAge()
                  << std::endl;
    }
}

