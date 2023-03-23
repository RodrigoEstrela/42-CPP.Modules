//
// Created by rdas-nev on 3/23/23.
//

#include"../inc/interfaces.h"

int main()
{
	// create sources for materia concrete classes Ice and Cure
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl;

	// create a character and equip him with materia
	ICharacter* me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice"); me->equip(tmp);
	AMateria *tmp2 = tmp;
	tmp = src->createMateria("cure"); me->equip(tmp);
	std::cout << std::endl;

	// create another character as a target
	ICharacter* bob = new Character("bob");
	std::cout << "me: "; me->use(0, *bob);
	std::cout << "me: "; me->use(1, *bob);
	std::cout << std::endl;

	// unequip, delete and test use() again
	me->unequip(0);
	delete tmp2;
	me->use(0, *bob);
	std::cout << std::endl;

	// use and unequip out of range
	me->use(10, *bob);
	me->unequip(10);
	std::cout << std::endl;

	// copy of bob
	Character original("original");
	{
		Character copy = original;
	}
	std::cout << std::endl;

	// delete all the allocated memory
	delete bob;
	delete me;
	delete src;
	return 0;
}
