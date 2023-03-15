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
		Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		int getRawBits() const;
		void setRawBits(int const raw);
		~Fixed();
};


#endif //EX00_FIXED_H
