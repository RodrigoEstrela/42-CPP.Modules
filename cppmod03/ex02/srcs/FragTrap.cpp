//
// Created by rdas-nev on 17-03-2023.
//

#include "../inc/FragTrap.h"

FragTrap::FragTrap()
{
    name = "Default";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap Default created." << std::endl;
}

FragTrap::FragTrap(std::string const &name)
{
    this->name = name;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " created." << std::endl;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other)
{
    *this = other;
    std::cout << "FragTrap " << name << " copied." << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " destroyed." << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " gives high fives to everyone!" << std::endl;
}
