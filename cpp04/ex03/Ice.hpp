#ifndef Ice_HPP
#define Ice_HPP
# include "AMateria.hpp"

class Ice : public AMateria
{
	protected:
		std::string type;

	public:
		Ice(void);
		Ice(std::string const string);
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
		~Ice();

		std::string	getType() const;
		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif // Ice_HPP
