//
// Created by rdas-nev on 3/21/23.
//

#include "../inc/Cat.hpp"

Cat::Cat()
{
    Brn = new Brain();
	this->type = "Cat";
	std::cout << "Cat enters the room subtly." << std::endl;
}

Cat::Cat(Cat const &other) : Animal()
{
	*this = other;
	std::cout << "Animal " << this->getType() << " copied." << std::endl;
}

Cat &Cat::operator=(Cat const &other)
{
	type = other.type;
    Brn = other.Brn;
	return *this;
}

Cat::~Cat()
{
    delete Brn;
    std::cout << "Animal " << this->getType() << " miaus out of the room." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << this->getType() << " miaus." << std::endl;
}
