#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdexcept> // for std::bad_cast
//#include <exception> //?


int	getRandomNumber(void)
{
	srand(time(NULL));
	return (rand() % 3);
}

Base* generate(void)
{
	int random = getRandomNumber();

	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "NULL type" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	std::cout << "NULL type" << std::endl;
}

int	main(void)
{
	std::cout << "Random number generated: " << getRandomNumber() << std::endl;
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}
