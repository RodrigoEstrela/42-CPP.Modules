//
// Created by rdas-nev on 07-04-2023.
//

#ifndef INC_42_CPP_MODULES_EASYFIND_H
#define INC_42_CPP_MODULES_EASYFIND_H

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::exception();
    return it;
}

#endif //INC_42_CPP_MODULES_EASYFIND_H
