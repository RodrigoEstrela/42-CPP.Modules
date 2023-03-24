//
// Created by rdas-nev on 3/23/23.
//

#ifndef INC_42_CPP_MODULES_IMATERIASOURCE_HPP
#define INC_42_CPP_MODULES_IMATERIASOURCE_HPP

#include<iostream>
#include"AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};


#endif //INC_42_CPP_MODULES_IMATERIASOURCE_HPP
