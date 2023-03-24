//
// Created by rdas-nev on 3/23/23.
//

#ifndef INC_42_CPP_MODULES_AMATERIA_HPP
#define INC_42_CPP_MODULES_AMATERIA_HPP

#include<iostream>
#include"ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria(AMateria const& other);
		AMateria &operator=(AMateria const &other);

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;
};


#endif //INC_42_CPP_MODULES_AMATERIA_HPP
