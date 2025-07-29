#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << " Default constructor " << std::endl;
	this->_value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&::min(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}