#include "Character.hpp"

Character::Character() : ICharacter(), name("Unnamed")
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	std::cout << "Creating a default Character\n";
}

Character::Character(std::string name) : ICharacter(), name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	std::cout << "Creating a Character with name: " << this->name << "\n";
}

Character::Character(const Character &other) : ICharacter(other), name(other.name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
		{
			this->inventory[i] = other.inventory[i]->clone();
		}
		else
			this->inventory[i] = NULL;
	}
	std::cout << "Copying the Character " << this->name << "\n";
}

Character	&Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->name = other.name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	std::cout << "Assigning a Character\n";
	return (*this);
}

Character::~Character()
{
	std::cout << "Deleting the Character " << this->name << "\n";
	for (int i = 0; i < 4; i++)
	{
		delete this->inventory[i];
	}
}

std::string const &Character::getName() const {return (this->name);}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			std::cout << "Equipping " << m->getType() << " to " << this->name << "\n";
			return;
		}
	}
	std::cout << "Inventory full, cannot equip " << m->getType() << " to " << this->name << "\n";
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !this->inventory[idx])
		return;
	std::cout << "Unequipping a " << this->inventory[idx]->getType() << " from " << this->name << "\n";
	//delete this->inventory[idx];
	this->inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || !this->inventory[idx])
		return;
	std::cout << "Using " << this->inventory[idx]->getType() << " on " << target.getName() << "\n";
	this->inventory[idx]->use(target);
}

