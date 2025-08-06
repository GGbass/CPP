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
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;
	return (0);
}
