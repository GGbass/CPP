#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default_target")
{
	std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm constructor called with target:" << this->target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target)
{
	if (this != &other)
	{
		if (other.target != "")
			this->target = other.target;
	}
	std::cout << "PresidentialPardonForm copy constructor called\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		if (other.target != "")
			this->target = other.target;
		else
			this->target = "default_target";
	}
	std::cout << "PresidentialPardonForm copy assigment called\n";
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "This PresidentialPardonForm with target" << this->target << "deleted!\n";
}

const std::string&	PresidentialPardonForm::getTarget() const { return (this->target);}

std::string const&	PresidentialPardonForm::getName() const { return (AForm::getName());}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::cout << "The pardon for " << this->target << "was approved! by Zaphod Beeblebrox\n";
}

std::ostream& operator<<(std::ostream& os, PresidentialPardonForm const& form)
{
	AForm const & base = static_cast<AForm const&>(form);
	os << base;
	os << "Target: " << form.getTarget() << "\n";
	return (os);
}

