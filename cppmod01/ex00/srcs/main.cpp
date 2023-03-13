//
// Created by rdas-nev on 3/13/23.
//

#include "../inc/Zombie.hpp"

int main()
{
	Zombie zombie1 = Zombie("Zombie1");
	zombie1.announce();
	std::cout << std::endl;

	Zombie *zombie2 = zombie1.newZombie("Zombie2");
	zombie2->announce();
	delete zombie2;
	std::cout << std::endl;

	zombie1.randomChump("Zombie3");
	std::cout << std::endl;
	return 0;
}
