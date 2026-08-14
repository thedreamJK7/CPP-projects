#include "AForm.hpp"
#include <string>

#ifndef Intern_H
#define Intern_H

class Intern {

	public:
		Intern();                          // empty constructor
		Intern(Intern const &);            // copy constructor
		Intern &operator=(Intern const &); // copy assignment operator
		~Intern();                         // destructor

		AForm *makeForm(std::string formType, std::string target);
};

#endif