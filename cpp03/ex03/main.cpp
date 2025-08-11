#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap*	troopy = new FragTrap("Troopy");

	troopy->highFiveGuys();
	delete troopy;
	return (0);
}
