//
// Created by rdas-nev on 4/5/23.
//

#ifndef INC_42_CPP_MODULES_WHATEVER_HPP
#define INC_42_CPP_MODULES_WHATEVER_HPP

#include <iostream>

template<typename T> void swap(T &var1, T &var2)
{
	T tmp = var1;
	var1 = var2;
	var2 = tmp;
}

template<typename T> T min(T var1, T var2)
{
	if (var1 == var2)
		return var2;
	else if (var1 > var2)
		return var2;
	else
		return var1;
}

template<typename T> T max(T var1, T var2)
{
	if (var1 == var2)
		return var2;
	else if (var1 > var2)
		return var1;
	else
		return var2;
}
#endif //INC_42_CPP_MODULES_WHATEVER_HPP
