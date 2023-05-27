
#ifndef LAB_CODE_PERSON_HPP
#define LAB_CODE_PERSON_HPP

#include <string>


class Person {
private:
    std::string firstName;
    std::string lastName;
    int age;
public:
    // Default constructor
    Person() : firstName(""), lastName(""), age(0) {}

    // Overloaded constructor
    Person(const std::string &firstName, const std::string &lastName, int age)
            : firstName(firstName), lastName(lastName), age(age) {}

    // Destructor (does nothing)
    ~Person() {}

    // Getters
    const std::string &getFirstName() const { return firstName; }

    const std::string &getLastName() const { return lastName; }

    int getAge() const { return age; }

    // Setters
    void setFirstName(const std::string &firstName) { this->firstName = firstName; }

    void setLastName(const std::string &lastName) { this->lastName = lastName; }

    void setAge(int age) { this->age = age; }

};

#endif //LAB_CODE_PERSON_HPP
