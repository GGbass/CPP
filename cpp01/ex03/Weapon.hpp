#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon
{
	private: 
		std::string type;

	public:
		Weapon(const std::string& type);
		std::string getType(void) const;
		void	setType(std::string newType);
};
#endif