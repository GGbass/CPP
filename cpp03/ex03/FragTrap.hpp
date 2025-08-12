#ifndef FragTrap_HPP
#define FragTrap_HPP
#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(std::string name);
		~FragTrap();

	protected:
		void highFiveGuys();
};

#endif // FragTrap_HPP
