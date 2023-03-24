//
// Created by rdas-nev on 3/21/23.
//

#ifndef INC_42_CPP_MODULES_ANIMAL_HPP
#define INC_42_CPP_MODULES_ANIMAL_HPP

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

#endif //INC_42_CPP_MODULES_ANIMAL_HPP
