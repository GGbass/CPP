#include <iostream>
#include "Array.hpp"
# define MAX_VAL 750


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
		std::cerr << "Error: -2 " << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: "<< e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	return (0);
}


/* void	arrString(void)
{
	try
	{
		Array<std::string> *ar = new Array<std::string>(3);
		ar->setIndex(0, "Hello");
		ar->setIndex(1, "World");
		ar->setIndex(2, "!!!");
		ar->printArray();

		// Copy string constructor
		Array<std::string> *ar2 = new Array<std::string>(*ar);
		delete (ar);
		ar2->printArray();
		// Assigning operator
		Array<std::string> *ar3 = new Array<std::string>();
		*ar3 = *ar2;
		delete (ar2);
		ar3->printArray();
		std::cout << std::endl;
		ar3->printIndex(1);
		delete (ar3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	arrInt(void)
{
	Array<int> *arrInt = new Array<int>(5);

	arrInt->setIndex(0, 42);
	arrInt->setIndex(1, 45);

	arrInt->printArray();
	// Copy int constructor
	Array<int> *arrIntCopy = new Array<int>(*arrInt);
	delete arrInt;
	arrIntCopy->printArray();
	// Assigning operator
	Array<int> *arrIntAssign = new Array<int>();
	*arrIntAssign = *arrIntCopy;
	delete arrIntCopy;
	arrIntAssign->printArray();
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
	std::cout << "----- STRING ARRAY -----" << std::endl;
	arrString();
	std::cout << "----- INT ARRAY -----" << std::endl;
	arrInt();
	std::cout << "----- WEIRD CASE -----" << std::endl;
	WeirdCaseFromSubject();
	return (0);
}
 */