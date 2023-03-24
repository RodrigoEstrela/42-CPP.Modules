//
// Created by rdas-nev on 3/21/23.
//

#ifndef INC_42_CPP_MODULES_CAT_HPP
#define INC_42_CPP_MODULES_CAT_HPP

#include"Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const &other);
		Cat &operator=(Cat const &other);
		~Cat();

		void makeSound() const;
};

#endif //INC_42_CPP_MODULES_CAT_HPP
