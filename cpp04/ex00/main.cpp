#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int	main(void)
{
	std::cout << "\n\n";
	const Animal* meta = new Animal();
	std::cout << "\n\n";
	const Animal* j = new Dog();
	std::cout << "\n\n";
	const Animal* i = new Cat();
	std::cout << "\n\n";
	std::cout << j->getType() << " \n" << std::endl;
	std::cout << i->getType() << " \n" << std::endl;

	std::cout << "\n\n";
	i->makeSound(); //will output the cat sound!
	std::cout << "\n\n";
	j->makeSound();
	std::cout << "\n\n";
	meta->makeSound();
	std::cout << "\n\n";

	delete meta;
	delete j;
	delete i;

	/* Dog a;
	Cat	b;

	a.makeSound();
	b.makeSound(); */

		/* 
	const WrongAnimal* meta = new WrongAnimal();

	std::cout << "\n\n";
	const WrongAnimal* i = new WrongCat();
	
	std::cout << "\n\n";
	std::cout << i->getType() << " \n" << std::endl;
	std::cout << "\n\n";
	meta->makeSound();
	std::cout << "\n\n";
	i->makeSound();

	delete meta;
	delete i; */

	return (0);
}