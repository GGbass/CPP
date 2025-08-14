#include "Animal.hpp"

/* Animal::Animal()
{
	this->type = "Default";
	std::cout << "Animal default constructor called\n";
} */

Animal::Animal() : type("Default")
{
	//this->type = "Default";
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(std::string type) : type(type)
{
	//this->type = type;
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
	std::cout << "Default Destructor from " << getType() << " Animal Class\n";
}

void	Animal::makeSound() const
{
	std::cout << this->type << " It's making a weird sound\n";
}
