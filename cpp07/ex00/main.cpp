#include "whatever.hpp"

int	main(void)
{
	int	a = 4;
	int	b = 2;
	std::string str1 = "Hello";
	std::string str2 = "Worldd";

	::swap(a, b);
	::swap(str1, str2);
	std::cout << "min value str between " <<  ::min(str1, str2) << std::endl;
	std::cout << "max value str between " <<  ::max(str1, str2) << std::endl;
	std::cout << "str2: = " << str2 << " and str1: = " << str1 << std::endl;
	std::cout << "a: = " << a << " and b: = " << b << std::endl;
	std::cout << "min value between a: = " << a << " and b: = " << b << " -> " << ::min(a,b) << std::endl;
	std::cout << "max value between a: = " << a << " and b: = " << b << " -> " << ::max(a,b) << std::endl;

	float	c = 4.02f;
	float	d = 2.02f;

	::swap(c, d);
	std::cout << "c: = " << c << " and d: = " << d << std::endl;
	std::cout << "min value between c: = " << c << " and d: = " << d << " -> " << ::min(c,d) << std::endl;
	std::cout << "max value between c: = " << c << " and d: = " << d << " -> " << ::max(c,d) << std::endl;

	double e = 5.1;
	double f = 3.1;
	::swap(e, f);
	std::cout << "e: = " << e << " and f: = " << f << std::endl;
	std::cout << "min value between e: = " << e << " and f: = " << f << " -> " << ::min(e,f) << std::endl;
	std::cout << "max value between e: = " << e << " and f: = " << f << " -> " << ::max(e,f) << std::endl;
	return (0);
}
