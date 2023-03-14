//
// Created by rdas-nev on 14-03-2023.
//

#ifndef EX03_WEAPON_H
#define EX03_WEAPON_H

#include <iostream>

class Weapon
{
        std::string type;
    public:
        Weapon();
        explicit Weapon(std::string type);
        const std::string &getType();
        void setType(std::string type);
};

#endif //EX03_WEAPON_H
