#include "ICharacter.hpp"

ICharacter::ICharacter()
{
	//std::cout << "Creating an ICharacter\n";
}


ICharacter::ICharacter(const ICharacter &other)
{
	*this = other;
	//std::cout << "Copying an ICharacter\n";
}

ICharacter &ICharacter::operator=(const ICharacter &other)
{
	if (this != &other)
		std::cout << "Assigning an ICharacter\n";
	return (*this);
}

ICharacter::~ICharacter()
{
	//std::cout << "Deleting an ICharacter\n";
}

