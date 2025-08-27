#include "Animal.hpp"

Animal::Animal() : type("Default")
{
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal constructor called from " << this->type <<  std::endl;
}

Animal::Animal(const Animal &other)
{
	this->type = other.type;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

std::string Animal::getType()const { return (this->type);}

Animal::~Animal()
{
	std::cout << "Default Destructor from " << getType() << " Animal\n";
}

void	Animal::makeSound() const
{
	std::cout << this->type << " Is making a weird sound\n";
}
