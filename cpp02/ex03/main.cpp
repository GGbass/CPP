#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.cpp"

int	main(void)
{
	/* inside of the triangle */
	Point	a(Fixed(0), Fixed(0));
	Point	b(Fixed(4), Fixed(0));
	Point	c(Fixed(0), Fixed(7));
	Point	point(Fixed(2), Fixed(3));
	if (bsp(a, b, c, point))
		std::cout << "Point is inside the triangle\n" << std::endl;
	else
		std::cout << "Point is outside the triangle\n" << std::endl;
	
	/* is on edge case */
	point = Point(Fixed(2.5f), Fixed(3.5f));
	//point = Point(Fixed(), Fixed(0));
	if (bsp(a, b, c, point))
		std::cout << "Point is on the edge of the triangle\n" << std::endl;
	else
		std::cout << "Point is outside the triangle\n" << std::endl;

	/* outside of the triangle */
	point = Point(Fixed(-44), Fixed(5));
	if (bsp(a, b, c, point))
		std::cout << "Point is inside the triangle\n" << std::endl;
	else
		std::cout << "Point is outside the triangle\n" << std::endl;
	return (0);
}
