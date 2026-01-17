#ifndef DiamondTrap_HPP
#define DiamondTrap_HPP
#include "ScavTrap.hpp"
#include "FragTrap.hpp"



class	DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap (const DiamondTrap &other);//copy constructor
		DiamondTrap &operator=(const DiamondTrap &other); //assignment operator
		// using ScavTrap::attack; // Use ScavTrap's attack method
		void whoAmI() const;
		void	attack(const std::string& target);

	private:
		std::string	name;
		std::string	getName() const;
		


};

#endif // DiamondTrap_HPP
