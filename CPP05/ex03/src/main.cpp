#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"


int main(void)
{
	std::cout << "\nTEST 1: The CEO (Grade 1)" << std::endl;
	{
		try
		{
			AForm	*president;
			Intern	randomIntern;
			Bureaucrat	Tom("Tom", 1);
			
			president = randomIntern.makeForm("pardon", "home");
			Tom.signForm(*president);
			Tom.executeForm(*president);

			delete president;
		}
		catch (std::exception const &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "\nTEST 2: The Employee (Grade 150)" << std::endl;
	{
		try
		{
			AForm *shrubbery;
			Intern randomIntern;
			Bureaucrat Jon("Jon", 150);

			shrubbery = randomIntern.makeForm("shrubbery creation", "car");
			Jon.signForm(*shrubbery);
			Jon.executeForm(*shrubbery);

			delete shrubbery;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
