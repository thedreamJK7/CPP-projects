#include <iostream>
#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

static void separator(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
    separator("EX01: construction / destruction chaining");
    {
        ScavTrap a("SC4V-TP");
        std::cout << "(Leaving scope now: expect ScavTrap destructor then ClapTrap destructor)\n";
    }

    separator("EX01: ScavTrap required behavior (attack msg differs + guardGate)");
    {
        ScavTrap s("Guardian");

        s.attack("intruder");      // should print ScavTrap-style message (not ClapTrap's)
        s.takeDamage(30);          // should reduce HP from 100
        s.beRepaired(10);          // should repair if energy > 0
        s.guardGate();             // should print gatekeeper mode message
    }

    separator("EX01: damage until dead (should stop doing actions when HP is 0)");
    {
        ScavTrap d("Fragile?");

        // Should start with 100 HP; after 110 damage it should be "dead" (HP 0).
        d.takeDamage(60);
        d.takeDamage(60);

        // These should now fail / print appropriate messages if you block actions at 0 HP.
        d.attack("target");
        d.beRepaired(10);
        d.guardGate(); // depending on your rules, you may or may not allow this at 0 HP
    }

    return 0;
}