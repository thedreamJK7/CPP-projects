#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/AForm.hpp"
#include <cstdlib>

int main(void)
{
	std::srand(time(NULL));
	std::cout << "\nTEST 1: The CEO (Grade 1)" << std::endl;
	{
		try
		{
			Bureaucrat Bert("Bert", 1);
			Bureaucrat Allan("Allan", 150);
			ShrubberyCreationForm home("home");
			ShrubberyCreationForm car("car");
			RobotomyRequestForm roboto("roboto");
			
			Bert.signForm(home);
			Bert.executeForm(home);
			Bert.signForm(roboto);
			Bert.executeForm(roboto);

			Allan.signForm(car);
			Allan.executeForm(home);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "\nTEST 2: The Employee (Grade 150)" << std::endl;
	{
		try {
			Bureaucrat Bert("Bert", 150);
			ShrubberyCreationForm shrubbery("Shrubbery");

			Bert.signForm(shrubbery);
			Bert.executeForm(shrubbery);

			RobotomyRequestForm robotomy("Robotomy");
			Bert.signForm(robotomy);
			Bert.executeForm(robotomy);

			PresidentialPardonForm pardon("Person");
			Bert.signForm(pardon);
			Bert.executeForm(pardon);

		}	
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
