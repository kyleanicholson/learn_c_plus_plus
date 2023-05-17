//
// Your helper source file (helper.cpp) should consist of stubs for the helper functions along with comments
// (pseudocode style) that describe what that function will do.
// Remember that all functions need proper return types and parameters as described in the
// Lab 7 document and to compile and run with your main.
//


#include "helper.hpp"

int getInteger(int min, int max) {
  //used to get an input value
  //input parameters are min and max value
  //get and validates an integer between min and max
  //return the value
  std::cout << "Getting integer" << std::endl;
  return 1;
}

Student *createStudent() {
  // used to create a new student
  // get name and age, age validated as being positive integer
  // use name and age to dynamically create a student
  // When entering a student, any string is legal, and ages should be between 10 and 90.
  // return a pointer to the student
  std::cout << "Creating Student" << std::endl;
  return nullptr;
}

void displayStudents(Student *students, int numStudents) {
  // used to display array of students
  // array should be passed safely
  // no return values
}

