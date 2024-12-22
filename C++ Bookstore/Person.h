#pragma once
#include <string>

class Person
{
protected:
    std::string firstName;
    std::string lastName;
public:
    Person() {
        this->firstName = "";
        this->lastName = "";
    }
    Person(std::string firstName, std::string lastName) : firstName(firstName), lastName(lastName) {}

    virtual void info() = 0;
    ~Person() {};
};