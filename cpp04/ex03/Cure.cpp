#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Creating a Cure Materia\n";
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	this->type = other.type;
	std::cout << "Copying a Cure Materia\n";
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
		this->type = other.getType();
	std::cout << "Copy assigning operator called\n";
	return (*this);
}

AMateria* Cure::clone(void) const {return (new Cure(*this));}

std::string Cure::getType() const {return (this->type);}

void Cure::use(ICharacter &target)
{
	std::cout << "Heals " << target.getName() << "'s wounds with a Cure spell\n";
}

Cure::~Cure()
{
	std::cout << "Deleting this Cure Materia!\n";
}