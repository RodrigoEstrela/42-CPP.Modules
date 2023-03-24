//
// Created by rdas-nev on 3/23/23.
//

#ifndef INC_42_CPP_MODULES_CURE_HPP
#define INC_42_CPP_MODULES_CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const& other);
		Cure &operator=(Cure const &other);
		~Cure();
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif //INC_42_CPP_MODULES_CURE_HPP
