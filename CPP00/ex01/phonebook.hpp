#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "contact.hpp"
#include <bits/stdc++.h>

class PhoneBook
{
	private:
		static const int	MAX_CONTACTS = 2;
		Contact				contacts[MAX_CONTACTS];
		int					sizeof_contacts;

		void				display_phonebook();
		void				display_all_info(int index);
		void				display_contact(int index);
		void				set_contact(int index);
		std::string			truncate(std::string str);

	public:
							PhoneBook();
							~PhoneBook();

		void				add_contact();
		void				search_contact();
		void				exit();
};

#endif