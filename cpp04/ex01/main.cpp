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
	delete j; //should not create a leak
	(void)i;
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

	/* Deep copies  and printing ideas*/

/* 	Animal* doggy = new Dog();
	Animal* kitty = new Cat();
	std::cout << "\n\n";
	doggy->makeSound();
	std::cout << "\n\n";
	kitty->makeSound();
	std::cout << "\n\n";

	doggy->setIdeas();
	kitty->setIdeas();
	std::cout << doggy->getIdea(0) << std::endl;
	std::cout << kitty->getIdea(0) << std::endl;
	std::cout << "\n\n";

	Animal* doggyCopy = new Dog(*dynamic_cast<Dog*>(doggy));
	Animal* kittyCopy = new Cat(*dynamic_cast<Cat*>(kitty));
	std::cout << doggyCopy->getIdea(0) << std::endl;
	std::cout << kittyCopy->getIdea(0) << std::endl;
	delete doggy;
	delete kitty;
	delete doggyCopy;
	delete kittyCopy; */
	return (0);
}