#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called\n";
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "Intern copy constructor called\n";
}

Intern::~Intern()
{
	std::cout << "Intern destructor called\n";
}


AForm* Intern::createForm(const std::string& formType, const std::string& target)
{
	if (formType == "shrubbery creation")
		return (new ShrubberyCreationForm(target));
	else if (formType == "robotomy request")
		return (new RobotomyRequestForm(target));
	else if (formType == "presidential pardon")
		return (new PresidentialPardonForm(target));
	else
	{
		std::cerr << "Unknown form type: " << formType << std::endl;
		return (NULL);
	}
}
