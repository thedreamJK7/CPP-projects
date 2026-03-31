//#include "phonebook.hpp"
#include <iostream>
#include <string>
#include "phonebook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string input;
	
	std::cout << "Welcome to My PhoneBook: ADD, SEARCH, EXIT" << std::endl;
	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (input == "EXIT")
		{
			phonebook.exit();
			break;
		}
		else if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
		else
			std::cout << "Invalid Input!" << std::endl;
	}
	return (0);
}
