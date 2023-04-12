#include "lab2_kan.hpp"


// Helper Functions
void insertArray(string arr[], int size, int &count, string value) {
    if (count >= size) {
        // throw an exception
        throw out_of_range("Array is full");
    }
    // Find the index where the new value should be inserted
    int index = count - 1;
    while (index >= 0 && arr[index] < value) {
        arr[index + 1] = arr[index];
        index -= 1;
    }
    // Insert the new value at the correct index
    arr[index + 1] = value;
    count++;
};

// Main Functions
int getInteger(int min, int max) {
    // Get a number between min and max from the user
    int num;
    bool valid;
    do {
        cin >> num;
        // set the input flag
        valid = true;
        // check if valid integer between min and max
        if (cin.fail() || num < min || num > max) {
            if (cin.fail()) {
                cout << "Invalid input, please try again" << endl;
                // clear error flags and flush input buffer
                cin.clear();
                cin.ignore(100, '\n');
            } else if (num < min || num > max) {
                cout << "Please choose a different number (must choose between " << min << " and " << max << ") ";
            }
            valid = false;
        }
    } while (!valid);
    return num;
};

void fillArray(string arr[], int size) {
    //updates the array via reference
    int count = 0;
    string name;
    while (count < size) {
        cout << "Enter a name: ";
        cin >> name;
        insertArray(arr, size, count, name);
    }
};

void displayArray(const string arr[], int count) {
    // display items in the array
    for (int i = 0; i < count; i++) {
        cout << arr[i] << endl;
    }
};

bool binSearch(const string arr[], int count, string value) {
    int min = 0;
    int max = count - 1;
    bool found = false;

    while (max >= min && !found) {
        int mid = (min + max) / 2;
        if (arr[mid] == value) {
            found = true;
        } else if (arr[mid] > value) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }
    return found;

};