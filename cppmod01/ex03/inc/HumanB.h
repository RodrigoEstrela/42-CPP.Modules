//
// Created by rdas-nev on 14-03-2023.
//

#ifndef EX03_HUMANB_H
#define EX03_HUMANB_H

#include "Weapon.h"
#include <iostream>

class HumanB
{
        std::string name;
        Weapon *weapon;
    public:
        explicit HumanB(std::string name);
        void setWeapon(Weapon &weapon);
        void attack();
};


#endif //EX03_HUMANB_H
