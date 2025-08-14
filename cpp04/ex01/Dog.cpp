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

