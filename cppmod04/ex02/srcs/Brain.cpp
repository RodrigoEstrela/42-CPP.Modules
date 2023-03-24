//
// Created by rdas-nev on 3/21/23.
//

#include "../inc/Brain.hpp"

Brain::Brain()
{
	ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
			ideas[i] = (std::string)"A" + (std::string)"a";
	std::cout << "Brain emerges!" << std::endl;
}

Brain::Brain(Brain const& other)
{
    ideas = new std::string[100];
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(Brain const &other)
{
    if (this != &other)
    {
        delete[] ideas;
        ideas = new std::string[100];
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
	delete[] ideas;
	std::cout << "Brain dilutes himself..." << std::endl;
}

