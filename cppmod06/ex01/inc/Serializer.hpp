//
// Created by rdas-nev on 4/4/23.
//

#ifndef INC_42_CPP_MODULES_SERIALIZER_HPP
#define INC_42_CPP_MODULES_SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>
#include <iostream>

class Serializer
{
	// Orthodox Canonical Form
		Serializer();
		Serializer(Serializer const &other);
		Serializer &operator=(Serializer const &other);
		~Serializer();
	public:
	// Convert pointer to uintptr_t
		static uintptr_t serialize(Data* ptr);
	// Convert uintptr_t to pointer
		static Data *deserialize(uintptr_t raw);
};

#endif //INC_42_CPP_MODULES_SERIALIZER_HPP
