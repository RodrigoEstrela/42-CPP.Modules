//
// Created by rdas-nev on 3/23/23.
//

#ifndef INC_42_CPP_MODULES_CHARACTER_HPP
#define INC_42_CPP_MODULES_CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *inventory[4];
	public:
		Character(std::string const &name);
		Character(Character const &other);
		Character &operator=(Character const &other);
		~Character();
		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};


#endif //INC_42_CPP_MODULES_CHARACTER_HPP
