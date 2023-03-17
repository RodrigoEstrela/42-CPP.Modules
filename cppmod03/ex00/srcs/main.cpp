//
// Created by rdas-nev on 17-03-2023.
//

#include "../inc/ClapTrap.h"

int main()
{
    ClapTrap clapTrap1("AmazingClapThatTraps");

    clapTrap1.attack("Some random dude");
    clapTrap1.takeDamage(10);
    clapTrap1.beRepaired(10);
}