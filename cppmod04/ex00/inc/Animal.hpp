//
// Created by rdas-nev on 3/21/23.
//

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include<iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(Animal const &other);
		Animal &operator=(Animal const &other);
		virtual ~Animal();

		virtual void makeSound() const;
		std::string getType() const;
};

#endif //ANIMAL_HPP
