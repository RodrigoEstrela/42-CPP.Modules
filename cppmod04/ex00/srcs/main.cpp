//
// Created by rdas-nev on 3/21/23.
//

#include"../inc/Animal.hpp"
#include"../inc/Cat.hpp"
#include"../inc/Dog.hpp"
#include"../inc/WrongAnimal.hpp"
#include"../inc/WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	meta->makeSound();
	std::cout << meta->getType() << " " << std::endl;
	delete meta;
	std::cout << std::endl;

	const Animal *i = new Cat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	delete i;
	std::cout << std::endl;

	const Animal *j = new Dog();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	delete j;
	std::cout << std::endl;

	const WrongAnimal *w = new WrongAnimal();
	w->makeSound();
	std::cout << w->getType() << " " << std::endl;
	delete w;
	std::cout << std::endl;

	const WrongCat *wc = new WrongCat();
	wc->makeSound();
	std::cout << wc->getType() << " " << std::endl;
	delete wc;

	return 0;
}
