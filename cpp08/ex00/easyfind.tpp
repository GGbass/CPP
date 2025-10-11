#ifndef EASYFIND_TPP
#define EASYFIND_TPP
#include "easyfind.hpp"

void	printFounded(int indx, int toFind)
{
	std::cout << "Element: "
			 << toFind << " founded in Index: " 
			 << indx << std::endl;
}

template <typename T>
void	easyfind(T x, int toFind)
{
	if (x.size() < 1)
		return (std::cout << "Empty container" << std::endl, void());
	for (int element: x)
	{
		if (element == toFind)
			return (printFounded(element + 1, toFind), void());
	}
	throw NotFoundException();
}


const char* NotFoundException::what() const throw()
{
	return ("Element it's not inside of the container");
}
#endif
