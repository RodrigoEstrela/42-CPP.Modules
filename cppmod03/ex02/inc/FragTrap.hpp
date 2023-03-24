//
// Created by rdas-nev on 17-03-2023.
//

#ifndef EX02_FRAGTRAP_H
#define EX02_FRAGTRAP_H

#include "../inc/ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string const &name);
        FragTrap(FragTrap const &other);
        FragTrap &operator=(FragTrap const &other);
        ~FragTrap();

        void highFivesGuys();
};


#endif //EX02_FRAGTRAP_H
