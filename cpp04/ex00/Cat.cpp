#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "A cat is created\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->type = other.type;
	std::cout << "Copy Constructor\n";
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat: Deleting this " << this->type << " Class \n";
}

void	Cat::makeSound() const {std::cout << this->type << " Meeeowww \n";}
