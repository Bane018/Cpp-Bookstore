#include "Author.h"
#include <string>
#include <iostream>

void Author::info()
{
    std::cout << "Author's first name: " << this->firstName
        << " Author's last name: " << this->lastName
        << " Author's place of birth: " << this->placeOfBirth
        << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Author& a)
{
    out << a.firstName << " " << a.lastName;
    return out;
}
