//
// Created by kanicholson on 4/26/2023.
//

#include "kan_lab4_memory.hpp"

// Helper Functions
int getInteger(int min, int max) {
    // Get a number between min and max from the user
    int num;
    bool valid;
    do {
        std::cin >> num;
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
};

bool yesNo(const std::string &prompt) {
    // Get a yes or no answer from the user
    char input;
    bool valid = false;
    do {
        std::cout << prompt << " ('y' or 'n')";
        std::cin >> input;
        input = tolower(input); // convert to lowercase
        // Ignore everything after the first character
        std::cin.ignore(100, '\n');
        switch (input) {
            case 'y':
            case 'n':
                valid = true;
                break;
            default:
                std::cout << "Invalid input, please try again" << std::endl;
                break;
        }
    } while (!valid);

    if (input == 'y')
        return true;
    else
        return false;
}


// Main Functions
void displayInstructions() {
    static int counter = 0;
    const std::string instructions = "Displaying Game Instructions";
    // Display the instructions (detailed first time, simplified all later times
    std::cout << instructions << std::endl;
};

char* createBoard(int difficulty) {
    //dynamically creates a board of the proper size of characters
    char easy_symbols[] = {'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'E', 'E', 'F', 'F', 'G', 'G', 'H', 'H'};
    char hard_symbols[] = {'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'E', 'E', 'F', 'F', 'G', 'G', 'H', 'H', 'I', 'I', 'J','J', 'K', 'K', 'L', 'L', 'M', 'M', 'N', 'N', 'O', 'O'};

    static char board[16];
    //places two of each character into the board
    //calls shuffle, passing the board and board length, to randomize the locations
    shuffleBoardArray(board, 16);
    //returns the board
    std::cout << "Creating board array" << std::endl;
    return board; // returns an empty array for testing
};

void shuffleBoardArray(char* board, int boardLength) {
    // input parameter is board (passed by pointer, and the total board length)
    //shuffles the board array
    std::cout << "Shuffling board array of length " << boardLength << std::endl;
};

void getMove(char board[], int rowLength, int colLength, int move[]) {
    // gets a move from the player
    std::cout << "Getting move 1" << std::endl;
}

void getMove(char board[], int rowLength, int colLength, int move1[], int move2[]) {
    // gets a second move and verifies that the moves is to a different location than move1
    std::cout << "Getting move 2" << std::endl;
}

void showBoard(char board[], int rowLength, int colLength) {
    // displays the board as a 4x4 or 5x6 grid using nested for loops
    // for each cell in the board
    // if it is SPACE show it
    // if it is not SPACE show UNKNOWN
    std::cout << "Showing board" << std::endl;
}

void showBoard(char board[], int rowLength, int colLength, int move1[]) {
    // display the board as a 4x4 (or 5x6 for hard) grid using nested for loops
    // for each cell other than move1, same as regular showBoard
    // for move1 display that location of board
    std::cout << "Showing move 1 location" << std::endl;
}

void showBoard(char board[], int rowLength, int colLength, int move1[], int move2[]) {
    // input parameters are the board, rowLength, colLength, move1, and move2
    // display the board as a 4x4 (or 5x6 for hard) grid using nested for loops
    // for cells other than move1 and move2, same as regular showBoard
    // for move1 and move2 display that location of board
    std::cout << "Showing move 1 location" << std::endl;
    std::cout << "Showing move 2 location" << std::endl;
}

bool checkMatch(char board[], int rowLength, int colLength, int move1[], int move2[]) {
    //if the board at move1 has the same value as the board at move2 return true
    //else return false
    std::cout << "Checking for match" << std::endl;
    return true; // return value for testing
}

void updateBoard(char board[], int rowLength, int colLength, int move1[], int move2[]) {
    //update the locations at move1 and move2 by storing SPACE in those locations
    std::cout << "Updating the board" << std::endl;
}

bool checkDone(char board[], int rowLength, int colLength) {
    //if all board location matches have been made, return true
    //else return false
    std::cout << "Checking if done" << std::endl;
    return true; // return value for testing
};

