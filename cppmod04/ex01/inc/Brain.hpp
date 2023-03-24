//
// Created by rdas-nev on 3/21/23.
//

#ifndef INC_42_CPP_MODULES_BRAIN_HPP
#define INC_42_CPP_MODULES_BRAIN_HPP

#include<iostream>

class Brain
{
		std::string *ideas;
	public:
		Brain();
		Brain(Brain const& other);
		Brain &operator=(Brain const &other);
		~Brain();
};

#endif //INC_42_CPP_MODULES_BRAIN_HPP
