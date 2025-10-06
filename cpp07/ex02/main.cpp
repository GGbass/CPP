#include "Array.hpp"

void	arrString(void)
{
	Array<std::string> *ar = new Array<std::string>(5);
	ar->arr[0] = "Hello";
	ar->arr[1] = "world";
	std::cout << ar->arr[0] << " " << ar->arr[1] << std::endl;
	delete ar;
}

void	arrInt(void)
{
	Array<int> *arrInt = new Array<int>(5);

	arrInt->arr[0] = 42;
	arrInt->arr[1] = 45;
	std::cout << arrInt->arr[0] << " " << arrInt->arr[1] << std::endl;
	Array<int> *arrIntCopy = new Array<int>(*arrInt);
	delete arrInt;
	std::cout << arrIntCopy->arr[0] << " " << arrIntCopy->arr[1] << std::endl;
	delete arrIntCopy;

}

int	main(void)
{
	arrString();
	arrInt();
	return (0);
}
