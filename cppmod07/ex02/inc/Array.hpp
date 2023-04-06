//
// Created by rdas-nev on 4/5/23.
//

#ifndef INC_42_CPP_MODULES_ARRAY_HPP
#define INC_42_CPP_MODULES_ARRAY_HPP

#include <iostream>
#include <stdexcept>

// Class template to create an array of any type ==============================
template <typename T>
class Array
{
    private:
        T *_arr;
        unsigned int _size;
    public:
    // Constructor with no parameters -----------------------------------------
        Array(void) : _arr(NULL), _size(0) {}
    // Constructor with an unsigned int parameter -----------------------------
        Array(unsigned int n) : _arr(new T[n]()), _size(n) {}
    // Copy constructor -------------------------------------------------------
        Array(const Array &src) : _arr(new T[src._size]()), _size(src._size)
        {
            for (unsigned int i = 0; i < _size; i++)
                _arr[i] = src._arr[i];
        }
    // Assignment operator overload -------------------------------------------
        Array &operator=(const Array &src)
        {
            if (this != &src)
            {
                delete[] _arr;
                _arr = new T[src._size]();
                _size = src._size;
                for (unsigned int i = 0; i < _size; i++)
                    _arr[i] = src._arr[i];
            }
            return *this;
        }
    // Destructor -------------------------------------------------------------
        ~Array(void) { delete[] _arr; }
    // Index operator overload ------------------------------------------------
    T &operator[](unsigned int index)
        {
            if (index >= _size)
                throw std::out_of_range("Index is out of range");
            return _arr[index];
        }
        // Getters ------------------------------------------------------------
        unsigned int size(void) const { return _size; }
};
// ============================================================================

#endif //INC_42_CPP_MODULES_ARRAY_HPP
