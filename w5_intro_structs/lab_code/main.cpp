/*
Lab No: 5a
Name: Kyle Nicholson
Date: 5/3/2023
Revision: 1.0
Description: This program will create a dynamic array of students, sort the array by last name,
and search for a students by last name.
*/
#include "kan_lab5_functions.hpp"

int main() {
  std::cout << "Please enter the number of students:" << std::endl;
  int numStudents = getInteger(1, 100); // get number of students to enter
  Student* students = createArray(numStudents); // create dynamic array of students

  // display the array (sorted by Lnumber by default)
  displayArrays(students, numStudents);

  // sort the array by last name using std::sort
  std::sort(students, students + numStudents, compareLastName);

  // display the sorted array
  displayArrays(students, numStudents); // display the array sorted by lastName

  // search for five students by last name
  for (int i = 0; i < 5; i++) {
    std::string last_name = getString("Enter a last name to search for: ");
    bool found = binSearch(students, numStudents, last_name);
    if (found) {
      std::cout << last_name << " was found" << std::endl;
    } else {
      std::cout << last_name << " was not found" << std::endl;
    }
  }

  // free dynamically allocated memory
  delete[] students;


  return 0;
}