#include <iostream>
#include <algorithm>
#include "helper.hpp"
#include "Student.hpp"


int main() {
  int numStudents;
  std::cout << "Please enter the number of students in the class: ";
  // Use getInteger to get the number of students in the class.
  numStudents = getInteger(1, 100);
  //Create a dynamic array of that many pointers to Student.
  Student *students = new Student[numStudents];
  //For loop that calls createStudent and saves the returned pointers in the array.
  for (int i = 0; i < numStudents; i++) {
    students[i] = *createStudent();
  }
  // Use std::sort to sort the Students alphabetically by name.
  // Since name is private, you will have to use the getName accessor method to accomplish this.
  std::sort(students, students + numStudents, compareLastName);
  //Finally, it should call displayStudents to list then in alphabetical order.
  displayStudents(students, numStudents);
  return 0;
}
