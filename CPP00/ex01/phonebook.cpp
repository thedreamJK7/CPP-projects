#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	_numContacts = 0;
};

PhoneBook::~PhoneBook() {};

void PhoneBook::display_contact(int index)
{
	const size_t DisplayWidth = 10;

	std::cout << "|         " << index + 1;
	std::cout << "|" << std::setw(DisplayWidth)
            << truncate(contacts[index].get_f_name());
	std::cout << "|" << std::setw(DisplayWidth)
            << truncate(contacts[index].get_l_name());
	std::cout << "|" << std::setw(DisplayWidth)
            << truncate(contacts[index].get_n_name()) << "|" << std::endl;
}

void PhoneBook::display_phonebook()
{
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|     Index| FirstName|  LastName|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < MAX_CONTACTS && i < _numContacts; i++)
		display_contact(i);
	std::cout << "|----------|----------|----------|----------|" << std::endl;
};


void PhoneBook::add_contact()
{
	contacts[_numContacts % MAX_CONTACTS].set_contact();
	_numContacts++;
	std::cout << "Contact added!" << std::endl;
}

std::string PhoneBook::truncate(const std::string& str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void PhoneBook::search_contact()
{
	std::string input;
	int index;

	if (_numContacts == 0) {
		std::cout << "No contacts found!" << std::endl;
		return;
	}
	display_phonebook();
	std::cout << "Enter an index: ";
	if (!std::getline(std::cin, input))
		return;
	index = std::atoi(input.c_str());
	if (index > 0 && index <= MAX_CONTACTS && _numContacts >= index)
	{
		contacts[index - 1].display_all_info();
		return;
	}
	std::cout << "Index invalid." << std::endl;
}
