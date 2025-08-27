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
	/* Animal* a = new Animal();

	delete a; */
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


	/* Abstract class example */
/* Animal* anima = new Animal();

	anima->makeSound();

	delete anima; */

	/* Deep copies  and printing ideas*/

/* 	Animal*	doggy;
	Animal*	kitty;

	doggy= new Dog();
	std::cout << "\n";
	kitty = new Cat();

	std::cout << "\n";
	doggy->makeSound();
	std::cout << "\n";
	kitty->makeSound();
	std::cout << "\n";
	doggy->setIdeas();
	std::cout << "\n";
	kitty->setIdeas();
	std::cout << "\n";
	std::cout << kitty->getIdea(11) << std::endl;
	std::cout << "\n";
	kitty->setIdea(11, "I will scratch the door !!");
	std::cout << "\n";
	std::cout << kitty->getIdea(11) << std::endl;
	std::cout << "\n";
	std::cout << doggy->getIdea(0) << std::endl;
	std::cout << "\n";
	std::cout << kitty->getIdea(0) << std::endl;
	std::cout << "\n";
	Animal* doggyCopy = new Dog(*dynamic_cast<Dog*>(doggy));
	std::cout << "\n";
	Animal* kittyCopy = new Cat(*dynamic_cast<Cat*>(kitty));
	std::cout << "\n";
	delete doggy;
	std::cout << doggyCopy->getIdea(0) << std::endl;
	std::cout << "\n";
	delete kitty;
	std::cout << "\n";
	std::cout << kittyCopy->getIdea(11) << std::endl;
	std::cout << "\n";
	delete doggyCopy;
	std::cout << "\n";
	delete kittyCopy; */
	return (0);
}