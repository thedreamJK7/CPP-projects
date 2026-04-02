#include "contact.hpp"

/* 
** The std::string members are default-constructed to empty strings, 
** so no explicit initialization is needed here.
*/
Contact::Contact() {};
Contact::~Contact() {};

void Contact::set_f_name(const std::string& v) { first_name = v;};
void Contact::set_l_name(const std::string& v) { last_name = v; };
void Contact::set_n_name(const std::string& v) { nick_name = v; };
void Contact::set_p_number(const std::string& v) { phone_number = v; };
void Contact::set_d_secret(const std::string& v) { darkest_secret = v; };

// getters (returning const ref avoids copies)
const std::string& Contact::get_f_name() const {return first_name; };
const std::string& Contact::get_l_name() const { return last_name; };
const std::string& Contact::get_n_name() const { return nick_name; };
const std::string& Contact::get_p_number() const { return phone_number; };
const std::string& Contact::get_d_secret() const { return darkest_secret; };

void Contact::set_contact()
{
	std::string input;

	std::cout << "First Name: ";
	do
	{
		if (!std::getline(std::cin, input))
			break;
		if (input.empty())
		{
			std::cout << "Field cannot be empty" << std::endl;
			std::cout << "First Name: ";
		}
	}
	while (input.empty());
	set_f_name(input);
	
	std::cout << "Last Name: ";
	do
	{
		if (!std::getline(std::cin, input))
			break;
		if (input.empty())
		{
			std::cout << "Field cannot be empty" << std::endl;
			std::cout << "Last Name: ";
		}
	}
	while (input.empty());
	set_l_name(input);

	std::cout << "Nick Name: ";
	do
	{
		if (!std::getline(std::cin, input))
			break;
		if (input.empty())
		{
			std::cout << "Field cannot be empty" << std::endl;
			std::cout << "Nick Name: ";
		}
	}
	while (input.empty());
	set_n_name(input);

	std::cout << "Phone Number: ";
	do
	{
		if (!std::getline(std::cin, input))
			break;
		if (input.empty())
		{
			std::cout << "Field cannot be empty" << std::endl;
			std::cout << "Phone Number: ";
		}
	}
	while (input.empty());
	set_p_number(input);

	std::cout << "Darkest secret: ";
	do
	{
		if (!std::getline(std::cin, input))
			break;
		if (input.empty())
		{
			std::cout << "Field cannot be empty" << std::endl;
			std::cout << "Darkest secret: ";
		}
	}
	while (input.empty());
	set_d_secret(input);
}

void Contact::display_all_info()
{
	std::cout << "First Name: " << get_f_name() << std::endl;
	std::cout << "Last Name: " << get_l_name() << std::endl;
	std::cout << "Nick Name: " << get_n_name() << std::endl;
	std::cout << "Phone Number: " << get_p_number() << std::endl;
	std::cout << "Darkest Secret: " << get_d_secret() << std::endl;
};
