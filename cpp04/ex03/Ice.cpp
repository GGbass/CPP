#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice"), type("ice")
{
	std::cout << "Default Ice Materia \n";
}

Ice::Ice(std::string const &name) : AMateria("ice"), type(name)
{
	std::cout << "Creating an Ice Materia \n";
}

Ice::Ice(const Ice &other) : AMateria(other), type(other.type)
{
	std::cout << "Copying an Ice Materia\n";
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
	if (target.getName() != "")
		std::cout << "Shoots an ice bolt at " << target.getName() << "\n";
}
