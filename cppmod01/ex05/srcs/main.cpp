//
// Created by rdas-nev on 14-03-2023.
//

#include "../inc/Harl.h"

int main()
{
    Harl karen; std::cout << std::endl;

    std::cout << "DEBUG" << std::endl; karen.complain("DEBUG");
    std::cout << "INFO" << std::endl; karen.complain("INFO");
    std::cout << "WARNING" << std::endl; karen.complain("WARNING");
    std::cout << "ERROR" << std::endl; karen.complain("ERROR");
    return 0;
}
