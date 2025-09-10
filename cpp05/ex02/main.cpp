#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


void	tryRobotomyRequestForm(void)
{
	Bureaucrat* weber = new Bureaucrat("Weber", 70);
	RobotomyRequestForm* form = new RobotomyRequestForm("Bender");
	try
	{
		std::cout << "\n";
		form->beSigned(*weber);
		std::cout << "\n";
		form->execute(*weber);
		std::cout << "\n";
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete form;
	delete weber;
	std::cout << "\n";
}

/* Shrubbery 145 137 */

void	tryShrubberyCreationForm(void)
{
	Bureaucrat* weber = new Bureaucrat("Weber", 148);
	ShrubberyCreationForm* form = new ShrubberyCreationForm("home2");
	try
	{
		std::cout << "\n";
		std::cout << *form;
		std::cout << "\n";
		form->beSigned(*weber);
		std::cout << "\n";
		form->execute(*weber);
		std::cout << "\n";
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete form;
	delete weber;
}

int	main(void)
{
	tryShrubberyCreationForm();
	//tryPresidentialPardonForm();
	//tryRobotomyRequestForm();
	return (0);
}
