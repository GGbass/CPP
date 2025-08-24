#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(void)
{
	//std::cout << "Creating an IMateriaSource\n";
}

IMateriaSource::IMateriaSource(const IMateriaSource &other)
{
	*this = other;
	//std::cout << "Copying an IMateriaSource\n";
}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource &other)
{
	if (this != &other)
		std::cout << "Assigning an IMateriaSource\n";
	return (*this);
}

IMateriaSource::~IMateriaSource()
{
	//std::cout << "Deleting an IMateriaSource\n";
}

void	IMateriaSource::learnMateria(AMateria* m)
{
	(void)m;
	//std::cout << "Learning a materia\n";
}

AMateria*	IMateriaSource::createMateria(std::string const &type)
{
	//std::cout << "Creating a materia of type: " << type << "\n";
	(void)type;
	return (NULL);
}
