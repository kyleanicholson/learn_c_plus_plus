/*
Lab No:
Name: Kyle Nicholson
Date:
Revision: 1.0
Description: This program implements
*/

#include <iostream>
#include "lab2_kan.hpp"

int main() {
    // Create am array of strings
    string names[20];
    cout << "How many names would you like to enter? (minimum of five, maximum of twenty)";
    int num_names = getInteger(5, 20);

    // Using an input function, enter that many names, inserting them into the array in sorted order
    fillArray(names, num_names);

    //Display the array
    displayArray(names, num_names);

    // Ask the user for five names individually and search for each name in array
    for (int i = 0; i < 5; i++) {
        string name;
        cout << "Enter a name to search for: ";
        cin >> name;
        // Search the array for that name
        bool found = binSearch(names, num_names, name);
        // Display if it is there or not
        if (found) {
            cout << "Name found" << endl;
        } else {
            cout << "Name not found" << endl;
        }
    }

    return 0;
}
