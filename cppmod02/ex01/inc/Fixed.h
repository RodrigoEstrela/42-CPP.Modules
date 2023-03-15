//
// Created by rdas-nev on 3/15/23.
//

#ifndef EX00_FIXED_H
#define EX00_FIXED_H

#include <iostream>

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
	~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif //EX00_FIXED_H
