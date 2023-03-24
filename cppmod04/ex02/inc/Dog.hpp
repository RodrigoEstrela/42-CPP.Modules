//
// Created by rdas-nev on 3/21/23.
//

#ifndef INC_42_CPP_MODULES_DOG_H
#define INC_42_CPP_MODULES_DOG_H

#include"Animal.hpp"
#include"Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *Brn;
	public:
		Dog();
		Dog(Dog const &other);
		Dog &operator=(Dog const &other);
		virtual ~Dog();

		void makeSound() const;
};

#endif //INC_42_CPP_MODULES_DOG_H
