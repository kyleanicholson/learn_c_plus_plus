

#include "lab3_kan_dungeon.hpp"

int generateRandomInt(int min, int max) {
    // Generate a random integer between min and max
    // Code used from stackoverflow post:
    // https://stackoverflow.com/questions/5008804/generating-a-random-integer-from-a-range
    /* initialize random seed: */
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min,max);
    return uni(rng);
}

void createDungeon(char dungeon[][MAX_SIZE], int traps, int treasures, int (&player_loc)[2]) {
    // initialize a new dungeon
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            dungeon[i][j] = '.';
        }
    }
    //  randomly place traps
    for (int i = 0; i < traps; i++) {
        int x = generateRandomInt(0, MAX_SIZE - 1);
        int y = generateRandomInt(0, MAX_SIZE - 1);
        if (dungeon[x][y] == '.') {
            dungeon[x][y] = '#';
        } else {
            i--;
        }
    }
    // randomly place treasures
    for (int i = 0; i < treasures; i++) {
        int x = generateRandomInt(0, MAX_SIZE - 1);
        int y = generateRandomInt(0, MAX_SIZE - 1);
        if (dungeon[x][y] == '.') {
            dungeon[x][y] = '$';
        } else {
            i--;
        }
    }
    //  randomly place the player in an empty location
    int x = generateRandomInt(0, MAX_SIZE - 1);
    int y = generateRandomInt(0, MAX_SIZE - 1);
    do{
        if (dungeon[x][y] == '.') {
            dungeon[x][y] = '@';
            player_loc[0] = x;
            player_loc[1] = y;
        } else {
            x = generateRandomInt(0, MAX_SIZE - 1);
            y = generateRandomInt(0, MAX_SIZE - 1);
        }
    } while (dungeon[x][y] != '@');

    // randomly place the exit in an empty location
    x = generateRandomInt(0, MAX_SIZE - 1);
    y = generateRandomInt(0, MAX_SIZE - 1);
    do{
        if (dungeon[x][y] == '.') {
            dungeon[x][y] = 'X';
        } else {
            x = generateRandomInt(0, MAX_SIZE - 1);
            y = generateRandomInt(0, MAX_SIZE - 1);
        }
    } while (dungeon[x][y] != 'X');
 std::cout << "Dungeon created successfully!" << std::endl;
 std::cout << "The player is located at: " << player_loc[0] << ", " << player_loc[1] << std::endl;
}

void displayDungeon(char dungeon[][MAX_SIZE]) {
    // Display dungeon
    for (int i=0; i < MAX_SIZE; i++) {
        for (int j=0; j < MAX_SIZE; j++) {
            std::cout << std::setw(3) << dungeon[i][j];
        }
        std::cout << std::endl;
    }
}

void getMove(const int player_loc[2], int (&new_player_loc)[2]) {
    char move;
    bool valid;
    // gets and validates a move (L, R, U, D)
    std::cout << "Please choose a direction to move in" << std::endl;
    std::cout << "L = Left" << std::endl;
    std::cout << "R = Right" << std::endl;
    std::cout << "U = Up" << std::endl;
    std::cout << "D = Down" << std::endl;
    std::cout << "Enter your choice: ";
    do {
        std::cin >> move;
        std::cin.ignore(100, '\n');
        valid = false;
        switch (move) {
            case 'L':
            case 'l':
                if (player_loc[1] == 0) {
                    std::cout << "Invalid input, please try again" << std::endl;
                    break;
                }
                // Move the player left
                new_player_loc[0] = player_loc[0];
                new_player_loc[1] = player_loc[1] - 1;
                valid = true;
                break;
            case 'R':
            case 'r':
                if (player_loc[1] == MAX_SIZE - 1) {
                    std::cout << "Invalid input, please try again" << std::endl;
                    break;
                }
                // Move the player right
                new_player_loc[0] = player_loc[0];
                new_player_loc[1] = player_loc[1] + 1;

                valid = true;
                break;
            case 'U':
            case 'u':
                if (player_loc[0] == 0) {
                    std::cout << "Invalid input, please try again" << std::endl;
                    break;
                }
                // Move the player up
                new_player_loc[0] = player_loc[0] - 1;
                new_player_loc[1] = player_loc[1];

                valid = true;
                break;
            case 'D':
            case 'd':
                if (player_loc[0] == MAX_SIZE - 1) {
                    std::cout << "Invalid input, please try again" << std::endl;
                    break;
                }
                // Move the player down
                new_player_loc[0] = player_loc[0] + 1;
                new_player_loc[1] = player_loc[1];

                valid = true;
                break;
            default:
                std::cout << "Invalid input, please try again" << std::endl;
                break;
        }
    } while (!valid);
}

bool checkLose(const int player_loc[2], char dungeon[][MAX_SIZE]) {
    // check if the player has stepped on a trap
    if (dungeon[player_loc[0]][player_loc[1]] == '#') {
        std::cout << "Oh No! You stepped into a Trap!!!" << std::endl;
        std::cout << GAME_OVER_TEXT << std::endl;
        return true;
    }
    // return true if the player has lost
    std::cout << "Player has not lost" << std::endl;
    return false;
}

bool checkWin(const int player_loc[2], char dungeon[][MAX_SIZE]) {
    // check if the player has stepped on the exit
    if (dungeon[player_loc[0]][player_loc[1]] == 'X') {
        std::cout << "Congratulations! You have found the exit!" << std::endl;
        std::cout << WIN_TEXT << std::endl;
        return true; // Player has found the exit
    }

    std::cout << "Player has not won..." << std::endl;
    return false;
}

void updateDungeon(char dungeon[][MAX_SIZE], const int player_loc[2], const int new_player_loc[2]) {

    // Set the player's previous location to a floor tile
    dungeon[player_loc[0]][player_loc[1]] = '.';
    // Set the player's new location to the player symbol
    dungeon[new_player_loc[0]][new_player_loc[1]] = '@';

    std::cout << "Dungeon updated successfully!" << std::endl;
}

bool yesNo(const std::string& prompt) {
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

bool playAgain() {
// Returns true if user wants to restart game and false if not
    return yesNo("Would you like to play again?");
}

