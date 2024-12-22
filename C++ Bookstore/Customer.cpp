#include "Customer.h"
#include <string>
#include <iostream>

void Customer::info()
{
    std::cout << "Customer's first name: " << this->firstName
        << " Customer's last name: " << this->lastName
        << " Customer's age: " << this->age
        << " Customer's phone number: " << this->phoneNumber
        << std::endl;
}