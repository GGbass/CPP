#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.cpp"

int	main(void)
{
	/* inside of the triangle */
	Point	a(Fixed(0), Fixed(0));
	Point	b(Fixed(0), Fixed(5));
	Point	c(Fixed(6), Fixed(0));
	Point	pointa(Fixed(2), Fixed(3));
	if (bsp(a, b, c, pointa))
		std::cout << "Point is inside the triangle\n" << std::endl;
	else
		std::cout << "Point is outside the triangle\n" << std::endl;
	
	/* is on edge case */
	//point = Point(Fixed(2.5f), Fixed(3.5f));
	Point pointb(Fixed(0), Fixed(1));
	if (bsp(a, b, c, pointb))
		std::cout << "Point is on the edge of the triangle\n" << std::endl;
	else
		std::cout << "Point is outside the triangle\n" << std::endl;

	/* outside of the triangle */
	Point pointc(Fixed(-44), Fixed(5));
	if (bsp(a, b, c, pointc))
		std::cout << "Point is inside the triangle\n" << std::endl;
	else
		std::cout << "Point is outside the triangle\n" << std::endl;
	return (0);
}
