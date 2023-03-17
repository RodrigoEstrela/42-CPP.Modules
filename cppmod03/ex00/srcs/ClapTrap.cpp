//
// Created by rdas-nev on 17-03-2023.
//

#include "../inc/ClapTrap.h"

ClapTrap::ClapTrap()
{
    name = "Default";
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
    std::cout << "ClapTrap Default created." << std::endl;
}

ClapTrap::ClapTrap(std::string const &name)
{
    this->name = name;
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
    std::cout << "ClapTrap " << name << " created." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
    *this = other;
    std::cout << "ClapTrap " << name << " copied." << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destroyed." << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << name << " is repaired by " << amount << " points!" << std::endl;
}
