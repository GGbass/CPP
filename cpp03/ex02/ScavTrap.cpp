#include "ScavTrap.hpp"

//ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->getName() << " created." << std::endl;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->getName() << " destroyed." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " is now in Gate Keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->canAttack())
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target
		<< ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}
