#ifndef AMateria_HPP
# define AMateria_HPP
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		virtual ~AMateria();
		~AMateria();

		std::string const & getType() const;
		virtual AMateria* const clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif // AMateria_HPP
