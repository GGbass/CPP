#include "iter.hpp"

int	main(void)
{
	{
		std::string	arrStr[4] = {"A", "Couple", "of", "things"};
		::iter(arrStr, 4, ::printer<std::string>);
	}

	{
		int	intArr[4] = { 4, 2, 4, 2};
		::iter(intArr, 4, ::printer<int>);
	}
	return (0);
}
