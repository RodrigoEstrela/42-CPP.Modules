//
// Created by rdas-nev on 4/5/23.
//

#ifndef INC_42_CPP_MODULES_CLASSES_HPP
#define INC_42_CPP_MODULES_CLASSES_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
	public:
		virtual ~Base();
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

Base * generate();
void identify_from_pointer(Base * p);
void identify_from_reference(Base & p);

#endif //INC_42_CPP_MODULES_CLASSES_HPP
