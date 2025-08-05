#include "Point.hpp"

Point::Point() // default constructor
{
	this->_x = Fixed(0);
	this->_y = Fixed(0);
	std::cout << "Point default constructor called" << std::endl;
}

Point::Point(constfloat x, const float y)
{
	this->_x = Fixed(x);
	this->_y = Fixed(y);
	std::cout << "Point with float parameterized constructor called" << std::endl;
}

Point::Point(const Point &other) // copy constructor
{
	this->_x = other._x;
	this->_y = other._y;
	std::cout << "Point copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &other) // assignment operator
{
	if (this != &other)
	{
		this->_x = other._x;
		this->_y = other._y;
		std::cout << "Point assignment operator called" << std::endl;
	}
	return *this;
}

Point::~Point()
{
	std::cout << "Point destructor called" << std::endl;
}