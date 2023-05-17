//


#ifndef LAB_CODE_STUDENT_HPP
#define LAB_CODE_STUDENT_HPP

#include <string>
#include <iostream>


class Student {
private:
    // The Student class should include two private variables, string name and int age.
    std::string name;
    int age;
public:

    // Constructor
    Student();

    // Overloaded constructor
    Student(const std::string &studentName, int studentAge);

    // Destructor
    ~Student();

    // Setter for name
    void setName(const std::string &studentName);
    // Getter for name
    std::string getName() const;
    // Setter for age
    void setAge(int age);
    // Getter for age
    int getAge() const;
};

//Inline function to compare last names of two students
inline bool compareLastName(const Student &a, const Student &b) {
    // used to compare two students by last name
    // return true if a's last name is less than b's last name
    // return false otherwise
    return false;
}

#endif //LAB_CODE_STUDENT_HPP
