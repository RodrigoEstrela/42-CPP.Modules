//
// Created by rdas-nev on 3/13/23.
//

#include "../inc/Zombie.hpp"

void Zombie::randomChump(std::string name)
{
	Zombie zombie = Zombie(name);
	zombie.announce();
}
