#include "../includes/ClapTrap.hpp"

int main()
{
	ClapTrap a("A");
    ClapTrap b("B");

    a.attack("B");
    b.takeDamage(0);

    b.attack("A");
    a.takeDamage(0);

    a.beRepaired(5);
	return 0;
}
