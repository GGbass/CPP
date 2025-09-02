#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main(void)
{
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
	/* Animal* a = new Animal();
	delete a; */
	return (0);
}