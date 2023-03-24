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

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point = copy.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixed_point;
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
