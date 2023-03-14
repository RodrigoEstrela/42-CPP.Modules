//
// Created by rdas-nev on 13-03-2023.
//

#include "../inc/Zombie.hpp"

Zombie::Zombie()
{
    name = "default";
    std::cout << "Zombie created" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::set_name(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
}
