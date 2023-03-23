//
// Created by rdas-nev on 3/21/23.
//

#include "../inc/Cat.h"

Cat::Cat()
{
    Brn = new Brain();
	this->type = "Cat";
	std::cout << "Cat enters the room subtly." << std::endl;
}

Cat::Cat(Cat const &other) : Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->Brn = NULL;
	*this = other;
	std::cout << "Animal " << this->getType() << " copied." << std::endl;
}

Cat &Cat::operator=(Cat const &other)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
		if (this->Brn)
			delete Brn;
		this->Brn = new Brain(*other.Brn);
	}
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
