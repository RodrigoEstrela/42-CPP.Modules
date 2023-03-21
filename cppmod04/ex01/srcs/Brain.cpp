//
// Created by rdas-nev on 3/21/23.
//

#include "../inc/Brain.h"

Brain::Brain()
{
	ideas = new std::string[100];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < i; j++)
			ideas[i] = (std::string)"A" + (std::string)"a";
	std::cout << "Brain emerges!" << std::endl;
}

Brain::Brain(Brain const& other)
{
	*this = other;
	std::cout << "Brain copied!" << std::endl;
}

Brain &Brain::operator=(Brain const &other)
{
	ideas = other.ideas;
	return *this;
}

Brain::~Brain()
{
	delete ideas;
	std::cout << "Brain dilutes himself..." << std::endl;
}