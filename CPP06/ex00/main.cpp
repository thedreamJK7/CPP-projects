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
