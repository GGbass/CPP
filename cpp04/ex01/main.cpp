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
	delete j;
	delete i; */

/* 	Animal* animals[10];

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
		delete animals[i]; */

	/* Deep copies  and printing ideas*/

	Animal*	doggy;
	Animal*	kitty;

	doggy = new Dog();
	std::cout << "\n\n";
	kitty = new Cat();

	std::cout << "\n\n";
	doggy->makeSound();
	std::cout << "\n\n";
	kitty->makeSound();
	std::cout << "\n\n";
	doggy->setIdeas();
	std::cout << "\n\n";
	kitty->setIdeas();
	std::cout << "\n\n";
	std::cout << kitty->getIdea(11) << std::endl;
	kitty->setIdea(11, "I will scratch the door !!");
	std::cout << kitty->getIdea(11) << std::endl;
	std::cout << doggy->getIdea(0) << std::endl;
	std::cout << kitty->getIdea(0) << std::endl;
	std::cout << "\n\n";
	Animal* doggyCopy = new Dog(*dynamic_cast<Dog*>(doggy));

	std::cout << "\n\n";
	Animal* dog2 = new Dog(*dynamic_cast<Dog*>(doggyCopy));
	std::cout << "\n\n";
	dog2->setIdeas();
	std::cout << "\n\n";
	dog2->getIdea(0);
	Animal* kittyCopy = new Cat(*dynamic_cast<Cat*>(kitty));
	std::cout << "\n\n";
	std::cout << doggyCopy->getIdea(0) << std::endl;
	std::cout << "\n\n";
	std::cout << kittyCopy->getIdea(11) << std::endl;
	std::cout << "\n\n";
	delete doggy;
	std::cout << "\n\n";
	delete kitty;
	std::cout << "\n\n";
	delete doggyCopy;
	std::cout << "\n\n";
	delete kittyCopy;
	std::cout << "\n\n";
	delete dog2;

	return (0);
}