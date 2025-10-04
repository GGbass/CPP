#include "whatever.hpp"

int	main(void)
{
	int	const a = 4;
	int	const b = 2;
	swap(a, b);
	std::cout << "a: = " << a << " and b: = " << b << std::endl;

	float	c = 4.02f;
	float	d = 2.02f;
	swap(c, d);
	std::cout << "c: = " << c << " and d: = " << d << std::endl;

	double e = 5.1;
	double f = 3.1;
	swap(e, f);
	std::cout << "e: = " << e << " and f: = " << f << std::endl;
	return (0);
}
