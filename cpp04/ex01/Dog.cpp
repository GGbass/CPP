#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
	std::cout << "A dog is created\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	this->type = other.type;
	this->brain = other.brain;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->type = other.type;
		this->brain = other.brain;
	}
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog: deleting this  " << this->type << "class\n";
}

void	Dog::makeSound() const {std::cout << this->type << " Woof Woof!!\n";}

Brain* Dog::getBrain() {return (this->brain);}

void	Dog::setIdeas()
{
	std::string ideas[10] = 
	{
		"Fetch the ball",
		"Bark at strangers",
		"Dig a hole",
		"Chase my tail",
		"Guard the house",
		"Play with a stick",
		"Sniff everything",
		"Lick my owner",
		"Roll in the grass",
		"Beg for treats"
	};
	for (int i = 0; i < 10; i++)
		this->brain->setIdea(i, ideas[i]);
	for (int i = 11; i < 100; i++)
		this->brain->setIdea(i, "Empty idea");
	std::cout << "Dog: Ideas set in the brain\n";
}
