#ifndef Point_HPP
#define Point_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		Point &operator=(const Point &other);
		~Point();

	private:
		Fixed	const _x;
		Fixed	const _y;
};
