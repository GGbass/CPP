#include "easyfind.hpp"

int	main(void)
{
	try
	{

		std::cout << "Starting point" << std::endl;
		std::vector<int>	*vect[5] = new {0, 1, 2, 3, 4};
		
		::easyfind(vect, 4);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
