#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap*	troopy = new DiamondTrap("Troopy");

	troopy->highFiveGuys();

	troopy->whoAmI();
	troopy->attack("target");
	troopy->guardGate();
	troopy->beRepaired(10);
	troopy->takeDamage(5);
	troopy->attack("target2");
	delete troopy;
	return (0);
}
