#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cctype>
#include <cmath>
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