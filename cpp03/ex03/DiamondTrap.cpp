#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default _Clap_name"),
 ScavTrap(),
 FragTrap(), 
 name("Default DiamondTrap")
{
	this->hitPoints = FragTrap::getHitPoints(); // FragTrap has 100 hit points
	this->energyPoints = ScavTrap::getEnergyPoints(); // ScavTrap has 50 energy points
	this->attackDamage = FragTrap::getAttackDamage(); // FragTrap has 30 attack damage
	std::cout << "DiamondTrap " << this->name << " created." << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_Clap_name"),
 ScavTrap(name), FragTrap(name), name(name)
{
	this->hitPoints = FragTrap::getHitPoints(); // FragTrap has 100 hit points
	this->energyPoints = ScavTrap::getEnergyPoints(); // ScavTrap has 50 energy points
	this->attackDamage = FragTrap::getAttackDamage(); // FragTrap has 30 attack damage
	std::cout << "DiamondTrap " << this->name << " created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
}

std::string DiamondTrap::getName() const {return this->name;}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
		std::cout << "DiamondTrap " << this->getName() << " Copy assigned." << std::endl;
	}
	return (*this);
}


DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->getName() << " destroyed.\n";
}

void	DiamondTrap::whoAmI() const
{
	std::cout << "DiamondTrap name: " << this->name << ", and my ClapTrap name: " << ClapTrap::getName() << std::endl;
}