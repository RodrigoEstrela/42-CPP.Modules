//
// Created by rdas-nev on 14-03-2023.
//

#ifndef EX03_HUMANA_H
#define EX03_HUMANA_H

#include "Weapon.h"
#include <iostream>

class HumanA
{
        std::string name;
        Weapon &weapon;
    public:
        HumanA(std::string name, Weapon &weapon);
        void attack();
};


#endif //EX03_HUMANA_H
