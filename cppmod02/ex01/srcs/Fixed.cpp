//
// Created by rdas-nev on 3/15/23.
//

#include "../inc/Fixed.hpp"

Fixed::Fixed() : fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point = integer << this->fractional_bits;
}

Fixed::Fixed(const float floating_point)
{
	std::cout << "Float constructor called" << std::endl;
 	this->fixed_point = roundf(floating_point * (1 << this->fractional_bits));
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point = copy.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
	return this->fixed_point;
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}

float Fixed::toFloat() const
{
	return roundf(this->fixed_point) / (1 << this->fractional_bits);
}

int Fixed::toInt() const
{
	return this->fixed_point >> this->fractional_bits;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return out;
}
