//
// Created by rdas-nev on 3/23/23.
//

#ifndef INC_42_CPP_MODULES_MATERIASOURCE_H
#define INC_42_CPP_MODULES_MATERIASOURCE_H

#include "IMateriaSource.h"
#include "AMateria.h"
#include <iostream>

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *materia[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &other);
		MateriaSource &operator=(MateriaSource const &other);
		~MateriaSource();
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif //INC_42_CPP_MODULES_MATERIASOURCE_H
