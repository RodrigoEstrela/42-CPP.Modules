//
// Created by rdas-nev on 13-03-2023.
//

#include "../inc/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *zombies = new Zombie[N];
    for (int i = 0; i < N; i++)
        zombies[i].set_name(name);
    return zombies;
}
