#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "contact.hpp"

class PhoneBook
{
	private:
		static const int	MAX_CONTACTS = 8;
		Contact				contacts[MAX_CONTACTS];
		int					_numContacts;

		void				display_phonebook();
		void				display_contact(int index);
		std::string			truncate(const std::string& str);

	public:
							PhoneBook();
							~PhoneBook();

		void				add_contact();
		void				search_contact();
};

#endif