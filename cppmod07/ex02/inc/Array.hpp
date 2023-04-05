//
// Created by rdas-nev on 4/5/23.
//

#ifndef INC_42_CPP_MODULES_ARRAY_HPP
#define INC_42_CPP_MODULES_ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T> class Array
{
	private:
		T *_array;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &other);
		Array &operator=(Array const &other);
		~Array();
		T &operator[](unsigned int index);
		unsigned int size() const;
};

#endif //INC_42_CPP_MODULES_ARRAY_HPP
