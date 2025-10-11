#include "easyfind.hpp"

void	notFounded(void)
{
	try
	{
		std::cout << "Starting point" << std::endl;
		std::vector<int>	*vect =  new std::vector<int>{0, 1, 2, 3, 4};
		::easyfind(vect, -1);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void	foundCase(void)
{
	try
	{
		std::cout << "Starting point" << std::endl;
		std::vector<int>	vect = {0, 1, 2, 3, 4};
		::easyfind(vect, 2);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

int	main(void)
{

	std::vector<std::string>	*vect = new std::vector<std::string>{"Hello","World"};

	foundCase();
	notFounded();
	return (0);
}
