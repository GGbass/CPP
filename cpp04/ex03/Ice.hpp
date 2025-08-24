#ifndef Ice_HPP
#define Ice_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

class Ice : public AMateria
{
	protected:
		std::string	type;
	public:
		Ice(void);
		Ice(std::string const &name);
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
		~Ice();

		std::string	getType() const;
		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif // Ice_HPP
