#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->getName() << " created." << std::endl;
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

