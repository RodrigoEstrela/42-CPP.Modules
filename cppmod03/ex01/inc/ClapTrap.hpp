//
// Created by rdas-nev on 17-03-2023.
//

#ifndef EX00_CLAPTRAP_H
#define EX00_CLAPTRAP_H

#include <iostream>

class ClapTrap
{
    protected:
        std::string name;
        int hitPoints,
            energyPoints,
            attackDamage;
    public:
        ClapTrap();

        ClapTrap(std::string const &name);
        ClapTrap(ClapTrap const &other);
        ClapTrap &operator=(ClapTrap const &other);
        ~ClapTrap();

        virtual void attack(std::string const &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};


#endif //EX00_CLAPTRAP_H
