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

int generateRandomInt(int min, int max) {
    // Generate a random integer between min and max
    // Code used from stackoverflow post:
    // https://stackoverflow.com/questions/5008804/generating-a-random-integer-from-a-range
    /* initialize random seed: */
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min,max);
    return uni(rng);
};


// Main Functions
void displayInstructions() {
    static int counter = 0;
    const std::string full_instructions = "This is a memory game. The board is a 4x4 grid of cards. Each card has a symbol on it. The goal is to find all the matching pairs of cards. On each turn, you may flip over two cards. If they match, they stay flipped over. If they don't match, they are flipped back over. The game is over when all the cards are flipped over.";
    const std::string short_instructions = "On each turn, you may flip over two cards. If they match, they stay flipped over. If they don't match, they are flipped back over. The game is over when all the cards are flipped over.";
    // Display the instructions (detailed first time, simplified all later times
    if (counter == 0) {
        std::cout << full_instructions << std::endl;
        counter++;
    } else {
        std::cout << short_instructions << std::endl;
    }
};

char* createBoard(int difficulty) {
    //dynamically creates a board of the proper size of characters
    //the board is a flattened 2D array
    char easy_symbols[] = {'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'E', 'E', 'F', 'F', 'G', 'G', 'H', 'H'};
    char hard_symbols[] = {'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'E', 'E', 'F', 'F', 'G', 'G', 'H', 'H', 'I', 'I', 'J','J', 'K', 'K', 'L', 'L', 'M', 'M', 'N', 'N', 'O', 'O'};

    int rowLength, colLength, boardLength;

    if (difficulty == 1) { // easy mode
        boardLength = EASY_ROW * EASY_COL;


    } else { // hard mode
        boardLength = HARD_ROW * HARD_COL;
    }

    char* board = new char[boardLength];

    // Create board based on difficulty
    if (difficulty == 1) { // easy mode
        // copy the easy symbols into the board array
        for (int i = 0; i < boardLength; i++) {
            board[i] = easy_symbols[i];
        }
    } else { // hard mode
        // copy the hard symbols into the board array
        for (int i = 0; i < boardLength; i++) {
            board[i] = hard_symbols[i];
        }
    }
    // Shuffle the board
    shuffleBoardArray(board, boardLength);
    return board;

};

void shuffleBoardArray(char* board, int boardLength) {
    // Randomly swaps the elements of the board array (in place)
    for (int i = 0; i < boardLength; i++) {
        // generate a random number between 0 and boardLength
        int random = generateRandomInt(0, boardLength);
        // swap the current element with the random element
        char temp = board[i];
        board[i] = board[random];
        board[random] = temp;
    }
    std::cout << "Shuffling board array of length " << boardLength << std::endl;
};

void getMove(char board[], int rowLength, int colLength, int move[]) {
    // gets a move from the player
    std::cout << "Getting move 1" << std::endl;
    std::cout << "Enter row: ";
    move[0] = getInteger(1, rowLength);
    std::cout << "Enter column: ";
    move[1] = getInteger(1, colLength);

}

void getMove(char board[], int rowLength, int colLength, int move1[], int move2[]) {
    // gets a second move and verifies that the moves is to a different location than move1
    std::cout << "Getting move 2" << std::endl;
    std::cout << "Enter row: ";
    move2[0] = getInteger(1, rowLength);
    std::cout << "Enter column: ";
    move2[1] = getInteger(1, colLength);
    // check that move2 is not the same as move1
    while (move1[0] == move2[0] && move1[1] == move2[1]) {
        std::cout << "That is the same location as move 1, please try again" << std::endl;
        std::cout << "Enter row: ";
        move2[0] = getInteger(1, rowLength);
        std::cout << "Enter column: ";
        move2[1] = getInteger(1, colLength);
    }


}

void showBoard(char board[], int rowLength, int colLength) {
    // displays the board as a 4x4 or 5x6 grid using nested for loops
    for (int i = 0; i < rowLength; i++) {
        for (int j = 0; j < colLength; j++) {
            int index = getIndex(i, j, colLength);
            // if it is SPACE show it
            if(board[index] == SPACE) {
                std::cout << std::setw(3) << board[index];}
            // if it is not SPACE show UNKNOWN
            else {
                std::cout << UNKNOWN;
            }
        }
        std::cout << std::endl;
    }
}

void showBoard(char board[], int rowLength, int colLength, int move1[]) {
    // display the board as a 4x4 (or 5x6 for hard) grid using nested for loops
    // for each cell other than move1, same as regular showBoard
    for (int i = 0; i < rowLength; i++) {
        for (int j = 0; j < colLength; j++) {
            int index = getIndex(i, j, colLength);
            // for move1 display that location of board
            if (i == move1[0] && j == move1[1]) {
                std::cout << board[index];
            }
            // if it is SPACE show it
            else if(board[index] == SPACE) {
                std::cout << board[index];}
            // if it is not SPACE show UNKNOWN
            else {
                std::cout << UNKNOWN;
            }
        }
        std::cout << std::endl;
    }
    std::cout << "Showing move 1 location" << std::endl;
}

void showBoard(char board[], int rowLength, int colLength, int move1[], int move2[]) {
    // display the board as a 4x4 (or 5x6 for hard) grid using nested for loops

    for (int i = 0; i < rowLength; i++) {
        for (int j = 0; j < colLength; j++) {
            int index = getIndex(i, j, colLength);
            // for move1 and move2 display that location of board
            if ((i == move1[0] && j == move1[1]) || (i == move2[0] && j == move2[1])) {
                std::cout << board[index];
            }
                // if it is SPACE show it
            else if(board[index] == SPACE) {
                std::cout << board[index];}
                // if it is not SPACE show UNKNOWN
            else {
                std::cout << UNKNOWN;
            }
        }
        std::cout << std::endl;
    }
    std::cout << "Showing move 1 and move 2 location" << std::endl;
}

bool checkMatch(char board[], int rowLength, int colLength, int move1[], int move2[]) {
    //if the board at move1 has the same value as the board at move2 return true
    if (board[getIndex(move1[0], move1[1], colLength)] == board[getIndex(move2[0], move2[1], colLength)]) {
        std::cout << "Match found" << std::endl;
        return true;
    }//else return false
    else {
        std::cout << "No match found" << std::endl;
        return false;
    }
}

void updateBoard(char board[], int rowLength, int colLength, int move1[], int move2[]) {
    //update the locations at move1 and move2 by storing SPACE in those locations
    board[getIndex(move1[0], move1[1], colLength)] = SPACE;
    board[getIndex(move2[0], move2[1], colLength)] = SPACE;
    std::cout << "Updating the board" << std::endl;
}

bool checkDone(char board[], int rowLength, int colLength) {
    //if all board location matches have been made, return true
    int count = 0;
    for (int i = 0; i < rowLength * colLength; i++) {
        if (board[i] == SPACE) {
            count++;
        }
    }
    if (count == rowLength * colLength) {
        std::cout << "All matches found" << std::endl;
        return true;
    }
    else {
        return false;
    }
    std::cout << "Checking if done" << std::endl;
}

