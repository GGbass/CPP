#ifndef Cure_HPP
# define Cure_HPP
# include "AMateria.hpp"
class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);
		~Cure();

		AMateria*	clone(void) const;
		void		use(ICharacter& target);
		std::string	getType() const;
};

#endif // Cure_HPP
