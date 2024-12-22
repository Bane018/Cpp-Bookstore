#pragma once
#include "Person.h"
#include <string>

class Customer : public Person
{
private:
    int age;
    std::string phoneNumber;
public:
    Customer() {
        this->age = 0;
        this->phoneNumber = "";
    }
    Customer(std::string firstName, std::string lastName, int age, std::string phoneNumber)
        : Person(firstName, lastName), age(age), phoneNumber(phoneNumber) {}

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

    void setAge(int age) {
        this->age = age;
    }
    int getAge() {
        return this->age = age;
    }

    void setPhoneNumber(std::string phoneNumber) {
        this->phoneNumber = phoneNumber;
    }
    std::string getPhoneNumber() {
        return this->phoneNumber = phoneNumber;
    }

    void info();
    ~Customer() {};
};
