//
// Created by rdas-nev on 14-03-2023.
//

#include "../inc/replace_to_file.h"

int main(int ac, char **av)
{
    if (ac == 4)
    {
        std::ifstream infile(av[1]);
        if (!infile.is_open())
        {
            std::cout << "Error: File not found or wrong permissions" << std::endl;
            return 1;
        }
        if (infile.peek() == std::ifstream::traits_type::eof())
        {
            std::cout << "Error: File is empty" << std::endl;
            return 1;
        }
        std::string line;
        std::ofstream ofs; ofs.open(((std::string)av[1] + ".replace").c_str());
        if (ofs.is_open())
        {
            while (std::getline(infile, line))
            {
                while (line.find(av[2]) != std::string::npos)
                {
                    replace_to_file(line, av[2], av[3]);
                }
                ofs << line << std::endl;
            }
        }
    }
    else
        std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;

    return 0;
}
