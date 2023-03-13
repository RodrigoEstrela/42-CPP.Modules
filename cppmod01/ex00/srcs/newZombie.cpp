//
// Created by rdas-nev on 3/13/23.
//

#include "../inc/Zombie.hpp"

Zombie* Zombie::newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name);
	return zombie;
}
