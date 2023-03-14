//
// Created by rdas-nev on 13-03-2023.
//

#ifndef EX01_ZOMBIE_HPP
#define EX01_ZOMBIE_HPP

#include <iostream>

class Zombie
{
        std::string name;
    public:
        Zombie();
        void announce();
        void set_name(std::string name);
        ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif //EX01_ZOMBIE_HPP
