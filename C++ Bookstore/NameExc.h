#pragma once
#include<iostream>
#include<exception>
class NameExc : public std::exception {
	virtual const char* what() const throw() {
		return "Name and surname must contain only letters";
	}
}ex;