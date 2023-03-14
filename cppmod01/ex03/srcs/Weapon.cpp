//
// Created by rdas-nev on 14-03-2023.
//

#include "../inc/Weapon.h"

Weapon::Weapon()
{
    this->type = "default";
}

Weapon::Weapon(std::string type)
{
    this->type = type;
}

const std::string& Weapon::getType()
{
    return type;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}