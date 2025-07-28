#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = other._value;
}
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		/* std::cout << "Assignation operator called" << std::endl; */
		this->_value = other._value;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called " << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits  member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}