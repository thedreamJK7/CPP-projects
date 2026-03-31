//#include "phonebook.hpp"
#include <iostream>
#include <string>

int main()
{
	std::string input;
	std::cout << "Welcome to My PhoneBook: ADD, SEARCH, EXIT" << std::endl;
	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (input == "EXIT")
		{
			std::cout << "Chao-chao" << std::endl;
			break;
		}
		std::cout << "I am input: " << input << std::endl;
	}	
	return (0);
}
