
#ifndef LAB_CODE_KAN_LAB5_FUNCTIONS_HPP
#define LAB_CODE_KAN_LAB5_FUNCTIONS_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>

struct Student{
    std::string first_name;
    std::string last_name;
    std::string l_number;
    float gpa;
};


bool compareLastName(const Student& a, const Student& b);;
int getInteger(int min, int max);
std::string getString(std::string prompt);
std::string getLnumber();
float getGPA();
Student* createArray(int numStudents);
void displayArrays(const Student *students, int count);
bool binSearch(Student *arr, int count, std::string value);


#endif //LAB_CODE_KAN_LAB5_FUNCTIONS_HPP
