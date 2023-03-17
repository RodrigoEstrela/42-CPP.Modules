//
// Created by rdas-nev on 17-03-2023.
//

#include "../inc/ClapTrap.h"
#include "../inc/ScavTrap.h"

int main()
{
    ClapTrap clapTrap1("AmazingClapThatTraps");

    clapTrap1.attack("Some random dude");
    clapTrap1.takeDamage(10);
    clapTrap1.takeDamage(10);
    clapTrap1.beRepaired(10);
    for (int i = 0; i < 10; i++)
        clapTrap1.beRepaired(10);

    ScavTrap scavTrap1("AmazingScavThatTraps");

    scavTrap1.attack("Some other random dude");
    scavTrap1.takeDamage(100);
    scavTrap1.takeDamage(100);
    scavTrap1.beRepaired(100);
    for (int i = 0; i < 50; i++)
    {
        std::cout << i << ": ";
        scavTrap1.beRepaired(100);
    }
    scavTrap1.guardGate();
}