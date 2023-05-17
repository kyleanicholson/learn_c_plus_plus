//
// class method source file (Student.cpp) should include all methods for the class, including constructor and destructor.
//

#include "Student.hpp"

Student::Student() : name(""), age(0) {
// Default Constructor
}

// Overloaded constructor
Student::Student(const std::string &studentName, int studentAge) : name(studentName), age(studentAge) {
}

Student::~Student() {
  // Destructor
}

void Student::setAge(int studentAge) {
  age = studentAge;
}

int Student::getAge() const {
  return age;
}

std::string Student::getName() const {
  return name;
}

void Student::setName(const std::string &studentName) {
  name = studentName;
}


