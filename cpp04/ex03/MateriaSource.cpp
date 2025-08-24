#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		materia[i] = NULL;
	std::cout << "Creating a MateriaSource\n";
}
MateriaSource::MateriaSource(const MateriaSource &other) : IMateriaSource(other)
{
	//*this = other;
	for (int i = 0; i < 4; i++)
	{
		if (other.materia[i])
			this->materia[i] = other.materia[i]->clone();
		else
			this->materia[i] = NULL;
	}
	std::cout << "Copying a MateriaSource\n";
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (other.materia[i])
				this->materia[i] = other.materia[i]->clone();
			else
				this->materia[i] = NULL;
		}
		std::cout << "Assigning a MateriaSource\n";
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i])
		{
			std::cout << "Deleting " << this->materia[i]->getType() << " Materia\n";
			delete this->materia[i];
		}
	}
	std::cout << "MateriaSource destructor called\n";
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!materia[i])
		{
			materia[i] = m;
			std::cout << "Learning " << materia[i]->getType() << " On " << i << " Materia \n";
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materia[i] && materia[i]->getType() == type)
			return (materia[i]->clone());
	}
	return (NULL);
}
