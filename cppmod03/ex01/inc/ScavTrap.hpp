//
// Created by rdas-nev on 17-03-2023.
//

#ifndef EX01_SCAVTRAP_H
#define EX01_SCAVTRAP_H

#include "../inc/ClapTrap.hpp"
#include "iostream"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string const &name);
        ScavTrap(ScavTrap const &other);
        ScavTrap &operator=(ScavTrap const &other);
        ~ScavTrap();

        void attack(std::string const &target);
        void guardGate();
};


#endif //EX01_SCAVTRAP_H
