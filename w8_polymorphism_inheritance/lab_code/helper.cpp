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
