#include "AMateria.hpp"

AMateria::AMateria(void) : type("")
{
	std::cout << "Default AMateria constructor\n";
}

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "AMateria constructor  type: " << this->type << "Created\n";
}
AMateria::AMateria(const AMateria &other)
{
	this->type = other.type;
	std::cout << "Copy AMateria constructor called\n";
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		this->type = other.getType();
		std::cout << " Copy assigment operator\n";
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout "Destroying AMateria\n";
}

std::string const & AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}