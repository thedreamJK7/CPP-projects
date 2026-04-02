#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

// A class representing a Contact with personal information.
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

		// setters (pass by const ref to avoid copies)
		void set_f_name(const std::string& v);
		void set_l_name(const std::string& v);
		void set_n_name(const std::string& v);
		void set_p_number(const std::string& v);
		void set_d_secret(const std::string& v);

		// getters (returning const ref avoids copies)
		const std::string& get_f_name() const;
		const std::string& get_l_name() const;
		const std::string& get_n_name() const;
		const std::string& get_p_number() const;
		const std::string& get_d_secret() const;

		void set_contact();
		void display_all_info();
};


#endif