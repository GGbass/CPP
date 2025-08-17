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

		std::string getType() const;
		Ice* clone(void);
};

#endif // Ice_HPP
