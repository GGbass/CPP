#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap*	troopy = new FragTrap("Troopy");

	troopy->highFiveGuys();
/* 	troopy->attack("Target");
	troopy->takeDamage(5); */
	delete troopy;
	return (0);
}
