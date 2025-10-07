//#include <iostream>
#include "Array.hpp"
# define MAX_VAL 5

int	main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	return (0);
}



// void	arrString(void)
// {
// 	Array<std::string> *ar = new Array<std::string>(5);
// 	ar->arr[0] = "Hello";
// 	ar->arr[1] = "world";
// 	std::cout << ar->arr[0] << " " << ar->arr[1] << std::endl;
// 	delete ar;
// }

/* void	arrInt(void)
{
	Array<int> *arrInt = new Array<int>(5);

	arrInt->setIndex(0, 42);
	arrInt->setIndex(1, 45);
	
	std::cout << arrInt->printIndex(0) << " " << arrInt->printIndex(1) << std::endl;
	// Copy int constructor 
	Array<int> *arrIntCopy = new Array<int>(*arrInt);
	delete arrInt;
	std::cout << arrIntCopy->arr[0] << " " << arrIntCopy->arr[1] << std::endl;
	// Assigning operator 
	Array<int> *arrIntAssign = new Array<int>();
	*arrIntAssign = *arrIntCopy;
	delete arrIntCopy;
	std::cout << arrIntAssign->arr[0] << " " << arrIntAssign->arr[1] << std::endl;
	delete arrIntAssign;
}

void	WeirdCaseFromSubject()
{
	int * a = new int();
	std::cout << *a << std::endl;
	delete a;
}

int	main(void)
{
	//arrString();
	arrInt();
	WeirdCaseFromSubject();
	return (0);
}
 */