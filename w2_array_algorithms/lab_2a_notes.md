## Program Specification

Create an array of strings in `main`, ask the user how many names to input, then using an input function enter that many names, inserting them into the array in sorted order. Then display the array, ask the user for five names, and for each name, search the array and display if it is there or not.

For this, as in all assignments, you are expected to follow the course programming style guidelines and to properly implement both header and source files for your functions.

The minimum functions you are required to implement are:

- `getInteger`
  - min and max value
  - gets and validates an integer between min and max
  - returns the value
- `fillArray`
  - pass in an array and how many items to get
  - reads a name and inserts the name in the array
  - updates the arrays via reference
  - no return values
- `displayArray`
  - pass the array safely and item count
  - display the array
  - no return values
- `binSearch`
  - pass the array safely, item count, and value to search for
  - perform a binary search
  - return true if the value is present in the array, false otherwise

Main will define the string array (of size 20), find out how many names will be input using `getInteger` (between 5 and 20), and then, using the defined functions, fill the array, display it, and then search for five names and display the results, terminating when done.

Helper function

To make `fillArray` simpler, you could add a method `insertArray`

- `insertArray`
  - pass array, size, count, value
  - insert value in proper location in array
  - updates array by reference
  - no return values
