//
// Created by rdas-nev on 3/23/23.
//

#include "../inc/Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice created." << std::endl;
}

Ice::Ice(Ice const &other) : AMateria(other)
{
}

Ice &Ice::operator=(Ice const &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return *this;
}

Ice::~Ice()
{
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
//	AMateria::use(target);
}
