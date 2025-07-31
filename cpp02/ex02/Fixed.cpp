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

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits  member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return this->_value >> _fractionalBits;
}

Fixed&::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}
Fixed&::min(Fixed& const a, Fixed& const b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed&::max(Fixed& const a, Fixed& const b)
{
	if (a > b)
		return (a);
	return (b);
}

bool Fixed::operator<(const Fixed& fixed){return (this->_value < fixed._value);}
bool Fixed::operator<=(const Fixed& fixed){return (this->_value <= fixed._value);}
bool Fixed::operator>(const Fixed& fixed){return (this->_value > fixed._value);}
bool Fixed::operator>=(const Fixed& fixed){return (this->_value >= fixed._value);}
bool Fixed::operator==(const Fixed& fixed){return (this->_value == fixed._value);}
bool Fixed::operator!=(const Fixed& fixed){return (this->_value != fixed._value);}

