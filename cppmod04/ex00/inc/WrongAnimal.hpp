//
// Created by rdas-nev on 3/21/23.
//

#ifndef INC_42_CPP_MODULES_WRONGANIMAL_HPP
#define INC_42_CPP_MODULES_WRONGANIMAL_HPP

#include<iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &other);
		WrongAnimal &operator=(WrongAnimal const &other);
		~WrongAnimal();

		std::string getType() const;
		void makeSound() const;
};

#endif //INC_42_CPP_MODULES_WRONGANIMAL_HPP
