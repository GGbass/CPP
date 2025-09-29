#include "Base.hpp"

Base::~Base()
{
	std::cout << "Base destructor called" << std::endl;
}
Base* Base::generate(void)
{

	return (NULL);
}

void	Base::identify(Base* p)
{
	(void)p;
	std::cout << "Identify from pointer called" << std::endl;
}

void	Base::identify(Base& p)
{
	(void)p;
	std::cout << "Identify from reference called" << std::endl;
}