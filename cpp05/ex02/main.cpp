#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void	tryShrubberyCreationForm(void)
{
	Bureaucrat* weber = new Bureaucrat("Weber", 132);
	ShrubberyCreationForm* form = new ShrubberyCreationForm("home2");
	try
	{
		form->beSigned(*weber);
		form->execute(*weber);
		delete form;
		delete weber;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}


int	main(void)
{
	tryShrubberyCreationForm();
	return (0);
}
