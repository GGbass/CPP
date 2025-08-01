#include "Fixed.hpp"

const int Fixed:: _fractionalBits = 8; // Number of bits used for the fractional part

Fixed::Fixed()
{
	std::cout << " Default constructor " << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << _fractionalBits; // Convert int to fixed-point representation
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = static_cast<int>(roundf(value * (1 << _fractionalBits))); // Convert float to fixed-point representation
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = other._value;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
	{
		this->_value = other._value;
	}
	return *this;
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
	return (static_cast<float>(this->_value) / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	/* return (this->_value >> _fractionalBits); */
	return (this->_value / (1 << _fractionalBits));
}

Fixed& min(Fixed& a, Fixed& b)
{
	if (a._value < b._value)
		return (a);
	return (b);
}
Fixed& min(const Fixed& a, const Fixed& b)
{
	if (a._value < b._value)
		return (a);
	return (b);
}

Fixed& max(Fixed& a, Fixed& b)
{
	if (a._value > b._value)
		return (a);
	return (b);
}

Fixed& max(const Fixed& a, const Fixed& b)
{
	if (a._value > b._value)
		return (a);
	return (b);
}

bool Fixed::operator<(const Fixed& fixed){return (this->_value < fixed._value);}
bool Fixed::operator<=(const Fixed& fixed){return (this->_value <= fixed._value);}
bool Fixed::operator>(const Fixed& fixed){return (this->_value > fixed._value);}
bool Fixed::operator>=(const Fixed& fixed){return (this->_value >= fixed._value);}
bool Fixed::operator==(const Fixed& fixed){return (this->_value == fixed._value);}
bool Fixed::operator!=(const Fixed& fixed){return (this->_value != fixed._value);}

Fixed Fixed::operator+(const Fixed& fixed) const
{
	Fixed result;
	result.setRawBits(this->_value + fixed._value);
	return (result);
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
	Fixed result;
	result.setRawBits(this->_value - fixed._value);
	return (result);
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
	Fixed result;
	if (fixed._value == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return (result); // Return a default Fixed object
	}
	result.setRawBits((this->_value << _fractionalBits) / fixed._value);
	return (result);
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
	Fixed result;
	result.setRawBits((this->_value * fixed._value) >> _fractionalBits);
	return (result);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

Fixed& Fixed::operator++() // pre-increment
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int) // post-increment
{
	Fixed temp(*this);
	this->_value++;
	return (temp);
}

Fixed& Fixed::operator--() // pre-decrement
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator--(int) // post-decrement
{
	Fixed temp(*this);
	this->_value--;
	return (temp);
}

