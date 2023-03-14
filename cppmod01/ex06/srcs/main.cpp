//
// Created by rdas-nev on 14-03-2023.
//

#include "../inc/Harl.h"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        Harl karen; std::cout << std::endl;
        std::string level = av[1];

        karen.complain(level);
        std::cout << std::endl; return 0;
    }
    else
    {
        std::cout << "Usage: ./ex05 [DEBUG|INFO|WARNING|ERROR]" << std::endl; return 1;
    }
}
