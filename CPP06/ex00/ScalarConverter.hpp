#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <cmath> // isNan
#include <iostream>
#include <limits> // limits
#include <cctype> //  
#include <sstream>
#include <iomanip>
#include <cstdlib>


class ScalarConverter
{
	// no instantiation - private constructors
	private:
		ScalarConverter(); // default constructor
		ScalarConverter(const ScalarConverter &rhs); // copy constructor
		ScalarConverter & operator=(const ScalarConverter &rhs); // assignment operator
		~ScalarConverter();

	public:
		static void	convert(const std::string &);
};

#endif