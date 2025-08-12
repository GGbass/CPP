#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->name = "Default";
	this->hitPoints = 10; //HEALTH
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap " << this->name << " created." << std::endl;
}


ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10; //HEALTH
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap " << this->name << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " destroyed." << std::endl;
}

int ClapTrap::getAttackDamage() const
{
	return (this->attackDamage);
}

bool ClapTrap::canAttack() const
{
	if (this->hitPoints <= 0 || this->energyPoints == 0 ||  this->getAttackDamage() <= 0)
	{
		std::cout << "ClapTrap " << this->name << " cannot attack, not enough hit points or attack damage." << std::endl;
		return (false);
	}
	return (true);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->canAttack())
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target
		<< ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints > 0 && amount > 0)
	{
		this->hitPoints -= amount;
		if (this->hitPoints < 0)
			this->hitPoints = 0;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!\n";
		if (!this->hitPoints)
			std::cout << "ClapTrap " << this->name << " has been destroyed!" << std::endl;
		else
			std::cout << "Current hit points: " << this->hitPoints << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " repairs itself for " << amount << " hit points! \n"
		<< "Current hit points: " << this->hitPoints << std::endl;
	}
}
