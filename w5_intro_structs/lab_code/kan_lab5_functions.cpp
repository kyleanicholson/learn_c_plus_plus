

#include "kan_lab5_functions.hpp"
// Function to call when sorting by Lnumber
bool compareLastName(const Student &a, const Student &b) {
  // TODO: implement function
  // Function will evaluate if the last name of a is less than the last name of b
  return false;// Return value use for testing purposes
}

// Helper Functions
void insertArray(Student* students, Student newStudent, int& count, int size) {
  //TODO: implement function
  std::cout << "Inserting student into array" << std::endl;
  //  pass in the array containing the new item in the last location
  //  pass in the current count of items and the size of the array
  //  insert the new item in the proper location in the array
  //  update the array via reference
  //  no return values
}


// Main Functions
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
  std::string str = "test";
  std::cout << "Getting " << prompt << std::endl;
  return str;
}

std::string getLnumber() {
  //TODO: implement function

  // Get Lnumber from the user
  std::string lNumber;
  lNumber = "L00000000"; // test value
  // Input validation for lNumber will happen here
  std::cout << "Getting Lnumber" << std::endl;
  return lNumber;
}

float getGPA() {
  //TODO: implement function
  float gpa = 0.0;
  // Gets a GPA input from a user which must be in the format of
  // 0.0 to 4.0
  std::cout << "Getting GPA" << std::endl;
  return gpa;
}

Student *createArray(int numStudents) {
  //TODO: implement function

  // Create a dynamic array of students
  Student *students = new Student[numStudents];

  for (int i = 0; i < numStudents; i++) {
    //get an Lnumber, firstName, lastName, GPA
    std::string lnumber = getLnumber();
    std::string firstName = getString("First Name");
    std::string lastName = getString("Last Name");
    float gpa = getGPA();

    //create a struct with the data
    Student newStudent = {lnumber, firstName, lastName, gpa};

    //Using the Lnumber, insert the struct in the proper location in the array
    insertArray(students, newStudent, i, numStudents);

  }
  //Return the array when done

  return students;
}

void displayArrays(const Student *students, int count) {
  //TODO: implement function
  // pass in the array and number of items
  // display the arrays in columns `firstName`, `lastName`, `Lnumber`, and `GPA`
  // no return values
  std::cout << "Displaying " << count << " students" << std::endl;
}

bool binSearch(Student *arr, int count, std::string value) {
  // TODO: implement function
  //pass in an array and a string for a name to search for
  // perform a binary search
  // return true if the name is present, false otherwise
//  int min = 0;
//  int max = count - 1;
  bool found = false;
//  while (max >= min && !found) {
//    int mid = (min + max) / 2;
//    if (arr[mid] == value) {
//      found = true;
//    } else if (arr[mid] > value) {
//      min = mid + 1;
//    } else {
//      max = mid - 1;
//    }
//  }
  std::cout << "Searching for name "<< std::endl;
  return found;

}





