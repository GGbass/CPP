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
	
}