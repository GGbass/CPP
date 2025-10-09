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

	/* Class case */
/* 	{
		std::cout << "Class cases " << std::endl;
		int	tab[5] = {0 ,1 , 2, 3, 4};
		Awesome tab2[5];

		::iter(tab, 5, ::printer<int>);
		::iter(tab2, 5, ::printer<Awesome>);

	} */
	return (0);
}
