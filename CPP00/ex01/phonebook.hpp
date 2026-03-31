#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
	
	public:
		Contact();
		~Contact();

		void setInfo(std::string value);
		std::string getInfo() const;
};

class PhoneBook
{
	private:
		std::string contacts[8];

	public:
		PhoneBook();
		~PhoneBook();
};

#endif