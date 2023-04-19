# Part A

For Part A of this lab, you are to create an empty project with a main, dungeon.cpp, and
dungeon.hpp. You will use these to create a stubbed, pseudocode version of the dungeon lab.
Main should consist of comments that lay out your program flow along with calls to the function
stubs.

Your header file (dungeon.hpp) should have any constants that you will need along with function
declarations. Each function should have the proper return type and parameters.

Your function source file (dungeon.cpp) should consist of stubs for the functions along with
comments (pseudocode style) that describe what that function will do.

Remember that all functions need proper return types and parameters as described in the Lab 3 document and compile and run
with your main

# Part B

### Program Specification

While the program is an introduction to two-dimensional arrays, it also reviews functions and input validation. For this, as in all assignments, you are expected to follow the course programming style guidelines and to properly implement both header and source files for your functions.

Create a program that displays a simple dungeon and allows the player to explore it. For example, in the following example @ is the player, # is a trap, $ is a treasure, and X is the exit. If you hit a trap you fail. If you reach the treasure, you get gold. When you get to X you exit the dungeon and win.

```code
. . . . . . . . . .
. @ . . . . . . . .
. . . . . . # . . .
. . $ . . . . . . .
. . . . # . . . . .
. . . . . . X . . .
. # . . . . . . . .

```

For each move in the game, the user will enter a character for Left, Right, Up, or Down. You need to move the player accordingly and update the dungeon. (You can use LRUD or WASD, arrow keys are system dependent and should not be used).

Define the size of your dungeon with a constant MAX_SIZE. Then create the dungeon as a MAX_SIZE x MAX_SIZE 2D array. When passing the dungeon and player location, you need to safely pass themso that the array contents cannot get modified

The minimum functions you are required to implement are:

For each move in the game, the user will enter a character for Left, Right, Up, or Down. You need to move the player accordingly and update the dungeon. (You can use LRUD or WASD, arrow keys are system dependent and should not be used). Define the size of your dungeon with a constant MAX_SIZE. Then create the dungeon as a MAX_SIZE x MAX_SIZE 2D array. When passing the dungeon and player location, you need to safely pass them so that the array contents cannot get modified.

The minimum functions you are required to implement are:

- `createDungeon` – initialize a new dungeon
  - pass in the dungeon, the number of traps and treasures, and an empty player location as a 2-element array (or as a struct with row and col members if you prefer)
  - randomly place that many traps and treasures in the dungeon in empty locations
  - randomly place the player and exit, each in an empty location
  - make sure that each item placed is in a separate location
  - pass back player starting location via the player location parameter
  - no return values
- `displayDungeon` – displays a dungeon
  - pass in the dungeon
  - display the dungeon
  - no return values
- `getMove` – gets and validates a move (L, R, U, D)
  - pass in the current player location and empty new player location, both as 2-element arrays (or as structs with row and col members)
  - get a move from the user and validate it
    - legal move
    - valid location inside the dungeon
  - does not update the dungeon
  - pass back the new player location using the parameter
  - no return values
- `checkLose` – sees if the move is onto a trap
  - pass in the dungeon and the new player location
  - check the move to see if it is onto a trap; if so, return true, otherwise false
- `checkWin` – sees if the move is onto the exit
  - pass in the dungeon and the new player location
  - check the move to see if onto the exit; if so, return true, otherwise false
- `updateDungeon` – updates the dungeon for the next cycle
  - pass in the dungeon, the previous player location, and the new player location
  - update the dungeon moving the player marker (place a new player and clear the old spot)
- `playAgain` - ask if the user wants to play again
  - nothing is passed in
  - return true to play again, false otherwise

### Enhancements

For a more advanced version add 1-10 monsters (shown as A, B, C, etc. on the dungeon map) that randomly move one step in any direction each turn. They must not go outside the limits of the dungeon. If the player moves onto an occupied square, they lose.

### Suggestions

As with the previous labs, the best approach is to create an outline in main of the overall game and use stubs for the various functions. Then implement the functions, createDungeon and displayDungeon should be first. Then getmove and updateDungeon. Finally, checkMove and playAgain. You are not inputting any integers, so there is no need for an integer input/validation function. Using helper functions is a good practice. Define constants and pass them in your header file since they are needed both in main and in the functions
