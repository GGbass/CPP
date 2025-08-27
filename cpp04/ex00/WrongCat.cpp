#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "A WrongCat is created\n";
}

WrongCat::WrongCat(const WrongCat &other) :WrongAnimal(other)
{
	this->type = other.type;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Deleting this " << this->type << " Class \n";
}
void	WrongCat::makeSound() const {std::cout << this->type << " a Wrong Miaau !! \n";}
