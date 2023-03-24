//
// Created by rdas-nev on 3/23/23.
//

#ifndef INC_42_CPP_MODULES_IMATERIASOURCE_H
#define INC_42_CPP_MODULES_IMATERIASOURCE_H

#include<iostream>
#include"AMateria.h"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};


#endif //INC_42_CPP_MODULES_IMATERIASOURCE_H
