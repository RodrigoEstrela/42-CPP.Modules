//
// Created by rdas-nev on 3/23/23.
//

#ifndef INC_42_CPP_MODULES_ICE_HPP
#define INC_42_CPP_MODULES_ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const& other);
		Ice &operator=(Ice const &other);
		~Ice();
		AMateria* clone() const;
		void use(ICharacter& target);
};


#endif //INC_42_CPP_MODULES_ICE_HPP
