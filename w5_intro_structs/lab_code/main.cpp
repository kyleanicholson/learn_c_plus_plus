/*
Lab No: 5a
Name: Kyle Nicholson
Date: 5/3/2023
Revision: 1.0
Description: This program will create a dynamic array of students, sort the array by last name,
and search for a students by last name.

 Student data to use for testing
L00765432: First Name: Samantha, Last Name: Lee, GPA: 3.7
L00234567: First Name: Emily, Last Name: Johnson, GPA: 3.8
L00987654: First Name: John, Last Name: Doe, GPA: 4.0
L00543210: First Name: Michael, Last Name: Brown, GPA: 3.2
L00111111: First Name: Jane, Last Name: Smith, GPA: 3.5
L00999999: First Name: Robert, Last Name: Wilson, GPA: 3.9
*/
#include "kan_lab5_functions.hpp"

int main() {
  std::cout << "Number of students:";
  int numStudents = getInteger(1, 100); // get number of students to enter
  Student* students = createArray(numStudents); // create dynamic array of students

  // display the array (sorted by Lnumber by default)
  std::cout << std::endl;
  std::cout << "Students sorted by Lnumber:" << std::endl;
  std::cout << std::endl;
  displayArrays(students, numStudents);

  // sort the array by last name using std::sort
  std::cout << std::endl;
  std::cout << "Students sorted by last name:" << std::endl;
  std::cout << std::endl;
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