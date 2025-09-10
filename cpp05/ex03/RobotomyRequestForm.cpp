#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default_target")
{
	std::cout << "RobotomyRequestForm default constructor called\n";
}


RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm constructor constructor called with target:" << this->target << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target)
{
	if (this != &other)
	{
		if (other.target != "")
			this->target = other.target;
	}
	std::cout << "RobotomyRequestForm copy constructor called\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		if (other.target != "")
			this->target = other.target;
		else
			this->target = "Default_target";
	}
	std::cout << "RobotomyRequestForm copy assignment called\n";
	return (*this);
}

const std::string&	RobotomyRequestForm::getTarget() const { return (this->target); }

std::string const&	RobotomyRequestForm::getName() const { return (AForm::getName()); }

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::cout << "Bzzzz... Drilling noises... ";
	srand(time(NULL));
	//std::cout << "random number: " << rand()<< std::endl;
	if (rand() % 2 == 0)
		std::cout << this->target << " has been robotomized successfully!\n";
	else
		std::cout << "The robotomy failed on " << this->target << ".\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "This RobotomyRequestForm with target " << this->target << " deleted!\n";
}

AForm* RobotomyRequestForm::clone(std::string const& target) const
{
	return (new RobotomyRequestForm(target));
}

std::ostream& operator<<(std::ostream& os, RobotomyRequestForm const& form)
{
	AForm const & base = static_cast<AForm const&>(form);
	os << base;
	os << "Target: " << form.getTarget() << "\n";
	return (os);
}
