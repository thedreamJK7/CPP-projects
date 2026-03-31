#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	sizeof_contacts = 0;
};

PhoneBook::~PhoneBook() {};

void PhoneBook::display_all_info(int index)
{
	std::cout << "First Name: " << contacts[index].get_f_name() << std::endl;
	std::cout << "Last Name: " << contacts[index].get_l_name() << std::endl;
	std::cout << "Nick Name: " << contacts[index].get_n_name() << std::endl;
	std::cout << "Phone Number: " << contacts[index].get_p_number() << std::endl;
	std::cout << "Darcest Secret: " << contacts[index].get_d_secret() << std::endl;
};

void PhoneBook::display_contact(int index)
{
	std::cout << "|         " << index + 1;
	std::cout << "|" << std::setw(10)
            << truncate(contacts[index].get_f_name());
	std::cout << "|" << std::setw(10)
            << truncate(contacts[index].get_l_name());
	std::cout << "|" << std::setw(10)
            << truncate(contacts[index].get_n_name()) << "|" << std::endl;
}

void PhoneBook::display_phonebook()
{
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|     Index| FirstName|  LastName|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < MAX_CONTACTS && i < sizeof_contacts; i++)
		display_contact(i);
	std::cout << "|----------|----------|----------|----------|" << std::endl;
};

void PhoneBook::set_contact(int index)
{
	std::string input;

	std::cout << "First Name: ";
	do
	{
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Field cannot be empty" << std::endl;
			std::cout << "First Name: ";
		}
	}
	while (input.empty());
	contacts[index].set_f_name(input);
	
	std::cout << "Last Name: ";
	do
	{
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Field cannot be empty" << std::endl;
			std::cout << "Last Name: ";
		}
	}
	while (input.empty());
	contacts[index].set_l_name(input);

	std::cout << "Nick Name: ";
	do
	{
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Field cannot be empty" << std::endl;
			std::cout << "Nick Name: ";
		}
	}
	while (input.empty());
	contacts[index].set_n_name(input);

	std::cout << "Phone Number: ";
	do
	{
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Field cannot be empty" << std::endl;
			std::cout << "Phone Number: ";
		}
	}
	while (input.empty());
	contacts[index].set_p_number(input);

	std::cout << "Darcest secret: ";
	do
	{
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Field cannot be empty" << std::endl;
			std::cout << "Darcest secret: ";
		}
	}
	while (input.empty());
	contacts[index].set_d_secret(input);
}

void PhoneBook::add_contact()
{
	set_contact(sizeof_contacts % MAX_CONTACTS);
	sizeof_contacts++;
	std::cout << "Contact added!" << std::endl;
}

std::string PhoneBook::truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void PhoneBook::search_contact()
{
	std::string input;
	int index;

	if (sizeof_contacts == 0) {
		std::cout << "No contacts found!" << std::endl;
		return;
	}
	display_phonebook();
	std::cout << "Enter an index: ";
	std::getline(std::cin, input);
	index = std::atoi(input.c_str());
	if (index > 0 && index <= MAX_CONTACTS && sizeof_contacts >= index)
	{
		display_all_info(index - 1);
		return;
	}
	std::cout << "Index invalid." << std::endl;
}

void PhoneBook::exit()
{
	std::cout << "Phonebook exited!" << std::endl;
}
