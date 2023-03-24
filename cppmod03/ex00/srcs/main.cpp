//
// Created by rdas-nev on 17-03-2023.
//

#include "../inc/ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap1("AmazingClapThatTraps");

    clapTrap1.attack("Some random dude");
    clapTrap1.takeDamage(10);
    clapTrap1.takeDamage(10);
    clapTrap1.beRepaired(10);
    for (int i = 0; i < 10; i++)
	{
		clapTrap1.beRepaired(10);
	}
	clapTrap1.takeDamage(10);
}