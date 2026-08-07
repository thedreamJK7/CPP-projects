#include "../includes/ClapTrap.hpp"

int main()
{
	{
        ClapTrap a("A");
        ClapTrap b("B");

        a.attack("B");
        b.takeDamage(0);

        b.attack("A");
        a.takeDamage(0);

        a.beRepaired(5);
    }

    {
        ClapTrap	trapA("Hugo Boss");
        ClapTrap	trapB("John Dirty");

        trapA.attack(trapB.getName());
        trapB.takeDamage(2);
        trapB.attack(trapA.getName());
        trapA.takeDamage(5);
        trapB.attack(trapA.getName());
        trapA.takeDamage(2);

        trapA.attack(trapB.getName());
        trapB.takeDamage(2);
        trapB.attack(trapA.getName());

        trapA.takeDamage(5);
        trapA.attack(trapB.getName());
        trapA.beRepaired(1);
        
        trapB.attack(trapA.getName());
        trapA.takeDamage(2);

        trapB.attack(trapA.getName());
        trapA.takeDamage(2);

        trapB.attack(trapA.getName());
        trapA.takeDamage(2);
        
        trapB.attack(trapA.getName());
        trapA.takeDamage(2);

        trapB.attack(trapA.getName());
        trapA.takeDamage(2);
        
        trapB.beRepaired(3);
        trapB.beRepaired(3);
        trapB.beRepaired(3);
        trapA.beRepaired(3);
    }
	return 0;
}
