#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main(void)
{
	/* const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;  //should not create a leak
	delete i; */

	Animal* animals[10];

	for (int i = 0; i < 5; i++)
		animals[i] = new Cat();
	std::cout << "\n\n";
	for (int i = 5; i < 10; i++)
		animals[i] = new Dog();
	std::cout << "\n\n";
	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();


	std::cout << "\n\n";
	for (int i = 0; i < 10; i++)
		delete animals[i];
	return (0);
}