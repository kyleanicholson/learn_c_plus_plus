//
// Created by kanicholson on 5/17/2023.
//

#ifndef LAB_CODE_HELPER_HPP
#define LAB_CODE_HELPER_HPP

#include "Student.hpp"
#include <iostream>
#include <iomanip>


int getInteger(int min, int max);

std::string getString(std::string prompt);

Student *createStudent();

void displayStudents(const Student *students, int numStudents);


#endif //LAB_CODE_HELPER_HPP
