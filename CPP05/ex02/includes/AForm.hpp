#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
	AForm(const std::string & name, 
		const int & gradeToSign, const int & gradeToExecute); // constructor
	AForm (AForm const &rhs); // copy constructor
	AForm & operator =  (AForm const &rhs); // assignemnt operator
	virtual ~AForm(); // destructor

	// getters
	const std::string	&getName(void) const;
	const int			&getGradeToSign(void) const;
	const int			&getGradeToExecute(void) const;
	bool				getIsSigned(void)	const;

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

	// member functions
	void	beSigned(const Bureaucrat &bureaucrat);

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

};

std::ostream	&operator<<(std::ostream &os, const AForm &member);

#endif