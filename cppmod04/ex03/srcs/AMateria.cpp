//
// Created by rdas-nev on 3/23/23.
//

#include "../inc/AMateria.h"

AMateria::AMateria(std::string const &type) : type(type)
{
}

AMateria::AMateria(AMateria const &other)
{
	*this = other;
}

AMateria &AMateria::operator=(AMateria const &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
	return type;
}
