#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Default")
{
	this->name = "Default";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "Default constructor of ScavTrap\n";
}

//ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{

	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->getName() << " created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "ScavTrap " << this->getName() << " Copy constructor." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
		std::cout << "ScavTrap " << this->getName() << " assigned." << std::endl;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->getName() << " destroyed." << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->getName();
		std::cout << " cannot guard gate, not enough hit points." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->getName() << " is now in Gate Keeper mode." << std::endl;
}
void	ScavTrap::attack(const std::string& target)
{
	if (this->canAttack())
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target
				  << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}

