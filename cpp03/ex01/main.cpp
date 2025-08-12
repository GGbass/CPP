#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap*	troopy = new ScavTrap("Troopy");

	troopy->guardGate();
	troopy->attack("Target1");
/* 	troopy->takeDamage(5);
	troopy->beRepaired(3); */


	ScavTrap test();
	delete troopy;
	return (0);
}
