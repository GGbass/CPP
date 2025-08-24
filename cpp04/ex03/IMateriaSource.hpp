#ifndef IMateriaSource_HPP
#define IMateriaSource_HPP
#include "AMateria.hpp"
#include <iostream>

class IMateriaSource
{
	public:
		IMateriaSource(void);
		IMateriaSource(const IMateriaSource &other);
		IMateriaSource &operator=(const IMateriaSource &other);
		virtual ~IMateriaSource();
	
		virtual void		learnMateria(AMateria* m) = 0;
		virtual AMateria*	createMateria(std::string const &type) = 0;
};

#endif // IMateriaSource_HPP
