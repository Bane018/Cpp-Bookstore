#pragma once
#include<iostream>
#include<exception>
class PhoneNumberExc : public std::exception {
	virtual const char* what() const throw() {
		return "Phone number must contain only numbers";
	}
}exb;