#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"


class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name);
		//ScavTrap(const ScavTrap &other); // Copy constructor
		//ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();

		void guardGate();

};
#endif