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
	delete bob;
	std::cout << "\n";
	delete me;
	std::cout << "\n";
	delete src;
	
	
	/* AMateria* tmp;
	Character* me = new Character("me");
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	Character*	m2 = new Character();
	std::cout << "\n";
	*m2 = *me;
	std::cout << "after assigning \n";
	m2->equip(src->createMateria("ice"));
	std::cout << "after equiping \n";
	delete src;
	std::cout << "\n";
	delete me;
	m2->use(2, *m2);

	delete m2; */
	return (0);
}