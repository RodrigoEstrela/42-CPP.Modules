//
// Created by rdas-nev on 17-03-2023.
//

#include "../inc/ClapTrap.h"
#include "../inc/ScavTrap.h"
#include "../inc/FragTrap.h"

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

    FragTrap fragTrap1("AmazingFragThatTraps");

    fragTrap1.attack("Some other other random dude");
    fragTrap1.takeDamage(100);
    fragTrap1.takeDamage(100);
    fragTrap1.beRepaired(100);
    for (int i = 0; i < 100; i++)
    {
        std::cout << i << ": ";
        fragTrap1.beRepaired(100);
    }

    fragTrap1.highFivesGuys();
}
