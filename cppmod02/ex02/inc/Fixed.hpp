//
// Created by rdas-nev on 3/15/23.
//

#ifndef EX00_FIXED_H
#define EX00_FIXED_H

#include <iostream>
#include <iomanip>
#include <cmath>

class Fixed
{
		int fixed_point;
		static const int fractional_bits = 8;
	public:
		Fixed(); // default constructor
		Fixed(const Fixed &copy); // copy constructor
		Fixed(int const n); // int constructor
		Fixed(float const f); // float constructor
		Fixed &operator=(const Fixed &copy); // copy assignment operator
        int getRawBits() const;
        void setRawBits(int const raw);
        float toFloat() const;
        int toInt() const;

        bool operator==(const Fixed &other) const; // comparison "equal" operator
        bool operator!=(const Fixed &copy) const; // comparison "different" operator
        bool operator>(const Fixed &copy) const; // comparison "greater than" operator
        bool operator<(const Fixed &copy) const; // comparison "less than" operator
        bool operator>=(const Fixed &copy) const; // comparison "greater than or equal" operator
        bool operator<=(const Fixed &copy) const; // comparison "less than or equal" operator
        Fixed operator+(const Fixed &copy) const; // arithmetic "addition" operator
        Fixed operator-(const Fixed &copy) const; // arithmetic "subtraction" operator
        Fixed operator*(const Fixed &copy) const; // arithmetic "multiplication" operator
        Fixed operator/(const Fixed &copy) const; // arithmetic "division" operator
        Fixed& operator++(); // prefix "increment" operator
        Fixed& operator--(); // prefix "decrement" operator
        Fixed operator++(int); // postfix "increment" operator
        Fixed operator--(int); // postfix "decrement" operator
        static Fixed &min(Fixed &a, Fixed &b); // static "minimum" function
        static const Fixed &min(const Fixed &a, const Fixed &b); // static "minimum" function
        static Fixed &max(Fixed &a, Fixed &b); // static "maximum" function
        static const Fixed &max(const Fixed &a, const Fixed &b); // static "maximum" function

        ~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif //EX00_FIXED_H
