//
// Created by rdas-nev on 3/21/23.
//

#include "../inc/WrongAnimal.h"

WrongAnimal::WrongAnimal()
{
	this->type = "WrongDefault";
	std::cout << "WrongDefault created." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
	*this = other;
	std::cout << "WrongAnimal " << type << " copied." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
	this->type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal " << type << " leaves with the WRONG sound." << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << type << " makes the WRONG sound." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}
