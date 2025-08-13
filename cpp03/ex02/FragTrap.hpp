#ifndef FragTrap_HPP
#define FragTrap_HPP
#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		FragTrap &operator=(const FragTrap &other);
		~FragTrap();
		void highFiveGuys();
};

#endif // FragTrap_HPP
