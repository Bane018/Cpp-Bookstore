#pragma once
#include "Person.h"
#include <string>
#include <ostream>

class Author : public Person
{
private:
    std::string placeOfBirth;
public:
    Author() {
        this->placeOfBirth = "";
    }
    Author(std::string firstName, std::string lastName, std::string placeOfBirth)
        : Person(firstName, lastName), placeOfBirth(placeOfBirth) {}

    void setFirstName(std::string firstName) {
        this->firstName = firstName;
    }
    std::string getFirstName() {
        return this->firstName = firstName;
    }

    void setLastName(std::string lastName) {
        this->lastName = lastName;
    }
    std::string getLastName() {
        return this->lastName = lastName;
    }

    void setPlaceOfBirth(std::string placeOfBirth) {
        this->placeOfBirth = placeOfBirth;
    }
    std::string getPlaceOfBirth() {
        return this->placeOfBirth = placeOfBirth;
    }

    void info();
    friend std::ostream& operator<<(std::ostream& out, const Author& a);

    ~Author() {}
};