//


#ifndef LAB_CODE_STUDENT_HPP
#define LAB_CODE_STUDENT_HPP

#include <string>
#include <iostream>


class Student {
private:
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

//Inline function to compare names of two students
inline bool compareName(const Student &a, const Student &b) {
    return a.getName() < b.getName();
}

#endif //LAB_CODE_STUDENT_HPP
