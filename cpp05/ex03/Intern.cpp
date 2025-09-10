#include "Intern.hpp"

Intern::Intern()
{
	this->formNames[0] = "shrubbery creation";
	this->formNames[1] = "presidential pardon";
	this->formNames[2] = "robotomy request";
	this->forms[0] = &Intern::createShrubberyForm;
	this->forms[1] = &Intern::createPresidentialForm;
	this->forms[2] = &Intern::createRobotomyForm;
	std::cout << "Intern default constructor called\n";
}

AForm* Intern::createShrubberyForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createPresidentialForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::createRobotomyForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}
Intern::Intern(const Intern& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 3; i++)
		{
			this->forms[i] = other.forms[i];
			this->formNames[i] = other.formNames[i];
		}
		std::cout << "Intern copy constructor called\n";
	}
}

Intern &Intern::operator=(const Intern& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 3; i++)
		{
			this->forms[i] = other.forms[i];
			this->formNames[i] = other.formNames[i];
		}
		std::cout << "Intern assigning operator called\n";
	}
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called\n";
}

int Intern::getIndex(const std::string& formType)
{
	for (int i = 0; i < 3; i++)
	{
		if (formType == this->formNames[i])
			return (i);
	}
	return (-1);
}

AForm* Intern::makeForm(const std::string& formType, const std::string& target)
{
	int	index = getIndex(formType);
	if (index == -1)
	{
		std::cerr << "Intern couldn't create form of type " << formType << "\n";
		return (NULL);
	}

	std::cout << "Intern creates " << formType << " form\n";
	return (this->*forms[index])(target);
}
