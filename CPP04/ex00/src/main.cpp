#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	{
		std::cout << "=== TEST 1: Dog and Cat ===" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	{
		std::cout << "=== TEST 2: Base pointer to derived ===" << std::endl;
		const WrongAnimal* animal = new WrongCat();
		animal->makeSound();  // WrongAnimal sound (not virtual)
		delete animal;
	}
	return (0);
}

