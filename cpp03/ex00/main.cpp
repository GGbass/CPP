#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap claptrap("Clappy");
	claptrap.attack("target1");
	claptrap.takeDamage(3);
	claptrap.beRepaired(2);
	return (0);
}