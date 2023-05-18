/*
 Lab No: 7
 Name: Kyle Nicholson
 Date: 5/21/2023
 Revision: 1.0
 Description: This program will create a dynamic array of students and sort the array by last name.
 */

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
    std::sort(students, students + numStudents, compareName);
    // Display students in alphabetical order.
    displayStudents(students, numStudents);
    return 0;
}
