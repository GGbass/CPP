#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <iostream>

class ClapTrap
{
	/* private:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage; */
	protected:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;

	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other); // Copy constructor
		ClapTrap &operator=(const ClapTrap &other);
		virtual ~ClapTrap();
		/* atributes functions */
		void attack(const std::string& target);
		bool canAttack() const;
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName() const;
		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;
};

#endif