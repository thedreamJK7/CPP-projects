#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(const std::string & name, int grade); // constructor
		Bureaucrat(Bureaucrat const &rhs); // copy constructor
		Bureaucrat & operator = (Bureaucrat const &rhs); // assignemnt operator
		~Bureaucrat(); // destructor

		// getters
		const std::string &getName(void) const;
		const int &getGrade(void) const;

		// exception classes
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw ();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw ();
		};

		// Increment, decrement
		void	incrementGrade();
		void	decrementGrade();

		// member function
		void	signForm(AForm &form);

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &member);

#endif