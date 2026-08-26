#ifndef EASYFIND_H
#define EASYFIND_H

#include <exception>
#include <iostream>
#include <list>
#include <vector>

class notFoundException: public std::exception
{
	public:
		virtual const char *what() const throw() {
			return "Not found!";
		} 
};

#include "easyfind.tpp"

#endif