#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
	std::cout << "A cat it's created\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->type = other.type;
	this->brain = other.brain;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->type = other.type;
		this->brain = other.brain;
	}
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat: Deleting this " << this->type << " Class \n";
}

void	Cat::makeSound() const {std::cout << this->type << " Meeeowww \n";}

Brain* Cat::getBrain() {return (this->brain);}

void	Cat::setIdeas()
{
	std::cout << "Cat: Ideas set in the brain\n";
	std::string ideas[10] = {
		"Chase the mouse",
		"Climb the tree",
		"Scratch the furniture",
		"Sleep in the sun",
		"Meow at the door",
		"Play with a ball of yarn",
		"Watch birds from the window",
		"Hide in a box",
		"Lick my paws",
		"Demand food"
	};
	for (int i = 0; i < 10; i++)
		this->brain->setIdea(i, ideas[i]);
	for (int i = 11; i < 100; i++)
		this->brain->setIdea(i, "Empty idea");
	std::cout << "Cat: Ideas set in the brain\n";
}
