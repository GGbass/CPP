#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice"), type("ice")
{
	std::cout << "Default Ice Materia\n";
}

Ice::Ice("ice") : AMateria("ice"), type("ice")
{
	std::cout << "Creating an Ice Materia\n";
}

Ice::Ice(const Ice &other)
{
	this->type = other.type;
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
		this->type = other.getType();
	std::cout << "Coppy assigning operator called\n";
	return (*this);
}

std::string Ice::getType() const {return (this->type);}

AMateria *Ice::clone(void) const { return (new Ice(*this));}

Ice::~Ice()
{
	std::cout << "Deleting this Ice Materia!\n";
}
void Ice::use(ICharacter &target)
{
	std::cout << "Shoots an ice bolt at " << target.getName() << "\n";
}
