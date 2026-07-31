#include <iostream>
#include <string>

class ACharacter
{
	public:
		virtual void	attack(std::string const &target) = 0;
		void			sayHello(std::string const &target);
};

class Warrior: public ACharacter
{
	public:
		virtual void	attack(std::string const &target);
};

void ACharacter::sayHello(std::string const &target)
{
	std::cout << "Hello " << target << " !" << std::endl;
}

void Warrior::attack(std::string const &target)
{
	std::cout << "*attack " << target << " with a sword!" << std::endl;
}
