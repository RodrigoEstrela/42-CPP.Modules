//
// Created by rdas-nev on 3/21/23.
//

#include "../inc/Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "A Dog enters running into the room." << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
    std::cout << "Animal " << this->getType() << " copied." << std::endl;
}

Dog &Dog::operator=(Dog const &other)
{
    std::cout << "Dog assignation operator called" << std::endl;
	type = other.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "The " << this->getType() << " barks out of the room." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << this->getType() << " barks ~ao ~ao!" << std::endl;
}