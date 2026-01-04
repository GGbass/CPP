#ifndef Point_HPP
# define Point_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const Fixed x, const Fixed y);
		Point(const float x, const float y);
		Point(const Point &other); // copy constructor
		Point &operator=(const Point &other); // overload = operators
		~Point();
		/* getter */
		Fixed getX() const;
		Fixed getY() const;

	private:
		Fixed	const _x;
		Fixed	const _y;
};

std::ostream& operator<<(std::ostream& os, const Point& pt);

#endif