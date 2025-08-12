#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap*	troopy = new DiamondTrap("Troopy");

	//troopy->highFiveGuys();
	delete troopy;
	return (0);
}
