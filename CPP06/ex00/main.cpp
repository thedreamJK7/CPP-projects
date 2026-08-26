#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout	<< "Argument count error, hint: this program takes 1 arguments!"
					<< std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}

/*
Supported Input Examples

ScalarConverter::convert("42");        // int
ScalarConverter::convert("42.0");      // double
ScalarConverter::convert("42.0f");     // float
ScalarConverter::convert("a");         // char
ScalarConverter::convert("nan");       // special
ScalarConverter::convert("+inf");      // special
ScalarConverter::convert("-inff");     // special
ScalarConverter::convert("2147483648"); // overflow handling
ScalarConverter::convert("127");       // DEL (non-printable)
ScalarConverter::convert("65");        // 'A' (printable)

*/
