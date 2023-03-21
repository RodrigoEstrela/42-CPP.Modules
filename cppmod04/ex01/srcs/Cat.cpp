//
// Created by rdas-nev on 3/21/23.
//

#include "../inc/Cat.h"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat enters the room subtly." << std::endl;
}

Cat::Cat(Cat const &other)
{
	*this = other;
	std::cout << "Animal " << this->getType() << " copied." << std::endl;
}

Cat &Cat::operator=(Cat const &other)
{
	type = other.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Animal " << this->getType() << " miaus out of the room." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << this->getType() << " miaus." << std::endl;
}
