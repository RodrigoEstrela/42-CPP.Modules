//
// Created by rdas-nev on 3/23/23.
//

#include "../inc/Cure.h"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(Cure const &other) : AMateria(other)
{
}

Cure &Cure::operator=(Cure const &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return *this;
}

Cure::~Cure()
{
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
//	AMateria::use(target);
}
