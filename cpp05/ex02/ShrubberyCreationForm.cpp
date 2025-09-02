#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default_target")
{
	std::cout << "ShrubberyCreationForm default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target)
{
	if (this != &other)
	{
		if (other.target != "")
			this->target = other.target;
	}
	std::cout << "ShrubberyCreationForm copy constructor called\n";
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		if (other.target != "")
			this->target = other.target;
	}
	std::cout << "ShrubberyCreationForm copy assignment operator called\n";
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called\n";
}

const std::string& ShrubberyCreationForm::getTarget() const { return (this->target); }

std::string const& ShrubberyCreationForm::getName() const { return AForm::getName(); }

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	/* if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException(); */
	(void)executor;
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