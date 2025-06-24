#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "includes.hpp"


class HumanA
{
	private:
		std::string name;
		std::string weapon;

	public:
		HumanaA(std::string name, Weapon::weapon);
	void attack(void);
};

#endif