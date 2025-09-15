#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default_target")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm constructor called with target:" << this->target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target)
{
	if (this != &other)
	{
		if (other.target != "")
			this->target = other.target;
		else
			this->target = "Default_target";
	}
	std::cout << "ShrubberyCreationForm copy constructor called with target:" << this->target << std::endl;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		if (other.target != "")
			this->target = other.target;
		this->AForm::operator=(other);
		std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

const std::string& ShrubberyCreationForm::getTarget() const { return (this->target); }

std::string const& ShrubberyCreationForm::getName() const { return AForm::getName(); }

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);

	std::ofstream outfile((this->target + "_shrubbery").c_str());
	if (!outfile)
	{
		std::cerr << "Error creating file: " << this->target + "_shrubbery" << std::endl;
		return ;
	}
	outfile << "       _-_\n"
			   "    /~~   ~~\\\n"
			   " /~~         ~~\\\n"
			   "{               }\n"
			   " \\  _-     -_  /\n"
			   "   ~  \\\\ //  ~\n"
			   "_- -   | | _- _\n"
			   "  _ -  | |   -_\n"
			   "      // \\\\\n";
	outfile.close();
}


std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm const& form)
{
	AForm const & base = static_cast<AForm const&>(form);
	os << base;
	os << "Target: " << form.getTarget() << std::endl;
	return (os);
}