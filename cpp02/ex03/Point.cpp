#include "Point.hpp"
#include <iostream>

Point::Point():_x(0), _y(0)
{
	//std::cout << "Point default constructor called" << std::endl;
}

Point::Point(const Fixed x, const Fixed y): _x(x), _y(y)
{
	//std::cout << "Point with Fixed parameterized constructor called" << std::endl;
}

Point::Point(const float x, const float y): _x(Fixed(x)), _y(Fixed(y))
{
	//std::cout << "Point with float parameterized constructor called" << std::endl;
}

Point::Point(const Point &other): _x(other._x), _y(other._y)
{
	//std::cout << "Point copy constructor called" << std::endl;
}
/* Point::Point(const Point &other) // copy constructor
{
	this->_x = other._x;
	this->_y = other._y;
	std::cout << "Point copy constructor called" << std::endl;
} */

Point &Point::operator=(const Point &other) // assignment operator
{
	(void)other;
/* 	if (this != &other)
	{
		this->_x = other._x;
		this->_y = other._y;
		std::cout << "Point assignment operator called" << std::endl;
	} */
	//std::cout << "Point assignment operator called" << std::endl;
	return (*this);
}

Point::~Point()
{
	//std::cout << "Point destructor called" << std::endl;
}

Fixed Point::getX()const {return (this->_x);}
Fixed Point::getY()const {return (this->_y);}


/* Overload to << operator for Point */
std::ostream& operator<<(std::ostream& os, const Point& pt)
{
	os << "(" << pt.getX() << ", " << pt.getY() << ")\n";
	return (os);
}