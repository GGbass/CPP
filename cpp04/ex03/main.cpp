#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"


int	main(void)
{
	std::cout << "\n";
	IMateriaSource* src = new MateriaSource();
	std::cout << "\n";
	src->learnMateria(new Ice());
	std::cout << "\n";
	src->learnMateria(new Cure());
	std::cout << "\n";
	ICharacter* me = new Character("me");
	std::cout << "\n";
	AMateria* tmp;
	tmp = src->createMateria("ice");
	std::cout << "\n";
	me->equip(tmp);
	std::cout << "\n";
	tmp = src->createMateria("cure");
	std::cout << "\n";
	me->equip(tmp);
	std::cout << "\n";
	ICharacter* bob = new Character("bob");
	std::cout << "\n";
	me->use(0, *bob);
	std::cout << "\n";
	me->use(1, *bob);
	std::cout << "\n";

	//me->unequip(0);
	//std::cout << "\n";
	//me->unequip(1);
	//std::cout << "\n";

	delete bob;
	std::cout << "\n";
	delete me;
	std::cout << "\n";
	delete src;


/* 	IMateriaSource* src = new MateriaSource();
	std::cout << "\n";
	src->learnMateria(new Ice());
	std::cout << "\n";
	src->learnMateria(new Cure());
	std::cout << "\n";
	
	delete src;
	std::cout << " end of program \n"; */
	return (0);
}