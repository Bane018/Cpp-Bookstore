#pragma once
#include <string>
#include <iostream>

class Util
{
public:
    static bool onlyLetters(std::string& str) {
        for (char c : str) {
            if (!isalpha(c)) {
                return false;
            }
        }
        return true;
    }
    static bool onlyNumbers(std::string& str) {
        for (char c : str) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }
};