#ifndef CONTACT_HPP
#define CONTACT_HPP

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

		void set_f_name(std::string v);
		void set_l_name(std::string v);
		void set_n_name(std::string v);
		void set_p_number(std::string v);
		void set_d_secret(std::string v);
		std::string get_f_name() const;
		std::string get_l_name() const;
		std::string get_n_name() const;
		std::string get_p_number() const;
		std::string get_d_secret() const;
};


#endif