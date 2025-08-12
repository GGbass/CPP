#ifndef DiamondTrap_HPP
#define DiamondTrap_HPP
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"



class	DiamondTrap : public ScavTrap, public FragTrap, public ClapTrap
{
	public:
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap (const DiamondTrap &other)//copy constructor
		DiamondTrap &operator=(const DiamondTrap &other); //assignment operator

		private:
		std::string	name;
};

#endif // DiamondTrap_HPP
	