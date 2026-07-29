# include <iostream>
# include <string>

class Character
{
	public:
		virtual void sayHello(std::string const &target);
};

class Warrior: public Character
{
	public:
		virtual void sayHello(std::string const &target);
};

void Character::sayHello(std::string const &target)
{
	std::cout << "Hello " << target << " !" << std::endl;
}

void Warrior::sayHello(std::string const &target)
{
	std::cout << "F*** off " << target << " !" << std::endl;
}

int main(int argc, char const *argv[])
{
	// This is Ok, because Warrior is a Warrior
	Warrior*	a = new Warrior();

	// This is Ok, because Warrior is a Character
	// we can only use the methods of character here not method of warrior. we have a limited access. 
	Character*	b = new Warrior();

	// This is not Ok, because Warrior can not be a character 
	// Warrior* c = new Character();

	a->sayHello("Students");
	b->sayHello("Students");
	return (0);
}


