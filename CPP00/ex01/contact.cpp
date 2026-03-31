#include "contact.hpp"

// I am not initializing the string objects since we already know that string then cpp thinks that has null initialized
Contact::Contact() {};
Contact::~Contact() {};

std::string Contact::get_f_name() const
{
	return (first_name);
}

std::string Contact::get_l_name() const
{
	return (last_name);
}

std::string Contact::get_n_name() const
{
	return (nick_name);
}

std::string Contact::get_p_number() const
{
	return (phone_number);
}

std::string Contact::get_d_secret() const
{
	return (darkest_secret);
}

void Contact::set_f_name(std::string v)
{
	first_name = v;
}

void Contact::set_l_name(std::string v)
{
	last_name = v;
}

void Contact::set_n_name(std::string v)
{
	nick_name = v;
}

void Contact::set_p_number(std::string v)
{
	phone_number = v;
}

void Contact::set_d_secret(std::string v)
{
	darkest_secret = v;
}

