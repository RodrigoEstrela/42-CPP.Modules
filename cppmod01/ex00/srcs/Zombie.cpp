//
// Created by rdas-nev on 3/13/23.
//

#include "../inc/Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " is really dead now" << std::endl;
}
