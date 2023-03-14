//
// Created by rdas-nev on 13-03-2023.
//

#include "../inc/Zombie.hpp"

int main()
{
    int N = 10;
    Zombie *zombies = zombieHorde(N, "Hamalestat");
    for (int i = 0; i < N; i++)
    {
        std::cout << i << ": "; zombies[i].announce();
    }
    delete[] zombies;
    return 0;
}
