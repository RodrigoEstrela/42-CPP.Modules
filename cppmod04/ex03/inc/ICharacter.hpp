//
// Created by rdas-nev on 3/23/23.
//

#ifndef INC_42_CPP_MODULES_ICHARACTER_HPP
#define INC_42_CPP_MODULES_ICHARACTER_HPP

#include<iostream>
#include"AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif //INC_42_CPP_MODULES_ICHARACTER_HPP
