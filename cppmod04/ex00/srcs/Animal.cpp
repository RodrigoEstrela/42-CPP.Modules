//
// Created by rdas-nev on 3/21/23.
//

#include "../inc/Animal.hpp"

Animal::Animal()
{
	this->type = "Default";
	std::cout << "Base Animal created." << std::endl;
}

Animal::Animal(Animal const &other)
{
    std::cout << "Animal " << type << " copied." << std::endl;
	*this = other;
}

Animal &Animal::operator=(Animal const &other)
{
    std::cout << "Animal " << type << " copied with operator." << std::endl;
	type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal " << type << " leaves with no special sound." << std::endl;
}

void Animal::makeSound() const
{
	std::cout << type << " makes no special sound." << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}
