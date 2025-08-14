#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Default WrongAnimal")
{
	std::cout << "Default Wrong Animal Created\n";
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	this->type = other.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

std::string WrongAnimal::getType() const {return (this->type);}


WrongAnimal::~WrongAnimal()
{
	std::cout << "Deleting WrongAnimal\n";
}

void WrongAnimal::makeSound() const
{
	std::cout << "Making WrongAnimals sounds !! wtf\n";
}
