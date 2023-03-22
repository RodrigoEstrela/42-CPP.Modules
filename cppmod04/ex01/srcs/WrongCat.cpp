//
// Created by rdas-nev on 3/21/23.
//

#include "../inc/WrongCat.h"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat enters the room wrongly." << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other)
{
	*this = other;
	std::cout << "Animal " << this->getType() << " copied." << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{
	type = other.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "Animal " << this->getType() << " mauis out of the room." << std::endl;
}