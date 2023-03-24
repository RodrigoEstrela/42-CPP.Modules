//
// Created by rdas-nev on 3/21/23.
//

#ifndef INC_42_CPP_MODULES_DOG_HPP
#define INC_42_CPP_MODULES_DOG_HPP

#include"Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog const &other);
		Dog &operator=(Dog const &other);
		~Dog();

		void makeSound() const;
};

#endif //INC_42_CPP_MODULES_DOG_HPP
