//
// Created by rdas-nev on 3/23/23.
//

#ifndef INC_42_CPP_MODULES_CURE_H
#define INC_42_CPP_MODULES_CURE_H

#include <iostream>
#include "AMateria.h"

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

#endif //INC_42_CPP_MODULES_CURE_H
