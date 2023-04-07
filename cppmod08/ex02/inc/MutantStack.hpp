//
// Created by rdas-nev on 07-04-2023.
//

#ifndef INC_42_CPP_MODULES_MUTANTSTACK_HPP
#define INC_42_CPP_MODULES_MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
    // Orthodox Canonical Form
        MutantStack() : std::stack<T>() {}
        MutantStack(MutantStack const &src) : std::stack<T>(src) {}
        MutantStack &operator=(MutantStack const &rhs)
        {
            if (this != &rhs)
                std::stack<T>::operator=(rhs);
            return *this;
        }
        ~MutantStack() {}
    // Adding iterators to the stack container
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin() { return std::stack<T>::c.begin(); }
        iterator end() { return std::stack<T>::c.end(); }
};

#endif //INC_42_CPP_MODULES_MUTANTSTACK_HPP
