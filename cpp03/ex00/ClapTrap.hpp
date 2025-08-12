#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other); // Copy constructor
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();
		/* atributes functions */
		void attack(const std::string& target);
		bool canAttack() const;
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName();
		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;
};

#endif