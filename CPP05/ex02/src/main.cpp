#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/AForm.hpp"

int main(void)
{
	std::cout << "\nTEST 1: The CEO (Grade 1)" << std::endl;
	{
		try
		{
			Bureaucrat Bert("Bert", 1);
			Bureaucrat Allan("Allan", 150);
			ShrubberyCreationForm home("home");
			ShrubberyCreationForm car("car");
			
			Bert.signForm(home);
			home.execute(Bert);

			Allan.signForm(car);
			car.execute(Allan);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
//   std::cout << "\nTEST 2: The Employee (Grade 150)" << std::endl;
//   {
//     try {
//       Bureaucrat Bert("Bert", 150);
//       ShrubberyCreationForm shrubbery("Shrubbery");
//       Bert.signAForm(shrubbery);
//       Bert.executeForm(shrubbery);
//       RobotomyRequestForm robotomy("Robotomy");
//       Bert.signAForm(robotomy);
//       Bert.executeForm(robotomy);
//       PresidentialPardonForm pardon("Person");
//       Bert.signAForm(pardon);
//       Bert.executeForm(pardon);

//     } catch (std::exception &e) {
//       std::cerr << e.what() << std::endl;
//     }
//   }
	return 0;
}
