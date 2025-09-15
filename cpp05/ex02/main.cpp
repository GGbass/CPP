#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void	tryPresidentialPardonForm(void) // PresidentialPardon 25 5 
{
	std::cout << "-----------Starting PresidentialPardonForm test-----------\n";
	Bureaucrat* zaphod = new Bureaucrat("Zaphod", 5);
	PresidentialPardonForm* form = new PresidentialPardonForm("Bender");
	try
	{
		std::cout << "\n";
		form->beSigned(*zaphod);
		std::cout << "\n";
		zaphod->executeForm(*form);
		std::cout << "\n";
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete form;
	delete zaphod;
	std::cout << "\n";
}

void	tryRobotomyRequestForm(void) // RobotomyRequest 72 45
{
	std::cout << "-----------Starting RobotomyRequestForm test-----------\n";
	Bureaucrat* weber = new Bureaucrat("Weber", 45);
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

void	tryShrubberyCreationForm(void) /* Shrubbery 145 137 */
{
	std::cout << "-----------Starting ShrubberyCreationForm test-----------\n";
	Bureaucrat* weber = new Bureaucrat("Weber", 137);
	ShrubberyCreationForm* form = new ShrubberyCreationForm("home2");
	try
	{
		std::cout << "\n";
		std::cout << *form;
		std::cout << "\n";
		form->beSigned(*weber);
		std::cout << "\n";
		weber->executeForm(*form);
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

int	main(void)
{
	tryShrubberyCreationForm();
	tryRobotomyRequestForm();
	tryPresidentialPardonForm();
	return (0);
}
