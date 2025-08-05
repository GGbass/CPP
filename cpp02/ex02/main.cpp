#include "Fixed.hpp"

int	main( void)
{
	Fixed	a; // Default constructor
	Fixed const b(Fixed( 5.05f ) * Fixed(2)); // Copy constructor and multiplication operator
	std::cout << a << " here is 0 " << std::endl;
	std::cout << ++a << " and here i s ? "<< std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return (0);
}
