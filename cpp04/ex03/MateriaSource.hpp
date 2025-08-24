#ifndef MateriaSource_HPP
#define MateriaSource_HPP
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* materia[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource &operator=(const MateriaSource &other);
		~MateriaSource();

		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const &type);
};

#endif // MateriaSource_HPP
