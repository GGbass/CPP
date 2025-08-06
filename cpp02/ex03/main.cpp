#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.cpp"

int	main(void)
{
	/* inside of the triangle */
	Point	a(Fixed(1), Fixed(1));
	Point	b(Fixed(4), Fixed(2));
	Point	c(Fixed(3), Fixed(5));
	Point	point(Fixed(3), Fixed(5));
	if (bsp(a, b, c, point))
		std::cout << "Point is inside the triangle\n" << std::endl;
	else
		std::cout << "Point is outside the triangle\n" << std::endl;
	
	/* is on edge case */
	point = Point(Fixed(2.5f), Fixed(3.5f));
	if (bsp(a, b, c, point))
		std::cout << "Point is on the edge of the triangle\n" << std::endl;
	else
		std::cout << "Point is outside the triangle\n" << std::endl;

	/* outside of the triangle */
	point = Point(Fixed(5), Fixed(5));
	if (bsp(a, b, c, point))
		std::cout << "Point is inside the triangle\n" << std::endl;
	else
		std::cout << "Point is outside the triangle\n" << std::endl;
	return (0);
}
