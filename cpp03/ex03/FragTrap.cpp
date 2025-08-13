#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap ("Default")
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->getName() << " created." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->getName() << " created." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
		std::cout << "FragTrap " << this->getName() << " assigned." << std::endl;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->getName() << " destroyed.\n";
}

void	FragTrap::highFiveGuys()
{
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
	{
		std::cout << "FragTrap " << this->getName() << " cannot high five, not enough hit points." << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->getName() << "  says: High five, guys! ✋😄" << std::endl;
	this->energyPoints--;
}

