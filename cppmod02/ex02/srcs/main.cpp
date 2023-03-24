//
// Created by rdas-nev on 3/15/23.
//

#include "../inc/Fixed.hpp"

int main()
{
    Fixed a(5.0f);
    Fixed const b(5);
    Fixed c(10.0f);
    Fixed const d(10);

    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "a: " << a << std::endl; // a: 5.05
    std::cout << "b: " << b << std::endl; // b: 5.05
    std::cout << "c: " << c << std::endl; // c: 10
    std::cout << "d: " << d << std::endl; // d: 10

    std::cout << "COMPARISON OPERATORS" << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl; // equal operator
    std::cout << "a != b: " << (a != b) << std::endl; // different operator
    std::cout << "a > c: " << (a > c) << std::endl; // greater than operator
    std::cout << "a < c: " << (a < c) << std::endl; // less than operator
    std::cout << "c >= a: " << (c >= a) << std::endl; // greater than or equal operator
    std::cout << "c <= a: " << (c <= a) << std::endl; // less than or equal operator

    std::cout << "ARITHMETIC OPERATORS" << std::endl;
    std::cout << "a + b: " << (a + b) << std::endl; // addition operator
    std::cout << "a - b: " << (a - b) << std::endl; // subtraction operator
    std::cout << "b * c: " << (b * c) << std::endl; // multiplication operator
    std::cout << "c / a: " << (c / a) << std::endl; // division operator

    std::cout << "INCREMENT OPERATORS" << std::endl;
    std::cout << "++a: " << (++a) << std::endl; // prefix increment operator
    std::cout << "--a: " << (--a) << std::endl; // postfix increment operator
    a++; std::cout << "a after increment: " << a << std::endl; // prefix decrement operator
    a--; std::cout << "a after decrement: " << a << std::endl; // postfix decrement operator

    std::cout << "MIN AND MAX" << std::endl;
    std::cout << "min(a, c): " << Fixed::min(a, c) << std::endl; // min function
    std::cout << "max(a, c): " << Fixed::max(a, c) << std::endl; // max function
    std::cout << "min(b, d): " << Fixed::min(b, d) << std::endl; // min function
    std::cout << "max(b, d): " << Fixed::max(d, d) << std::endl; // max function

    return 0;
}
