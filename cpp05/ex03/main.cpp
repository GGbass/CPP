#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

void	tryIntern()
{
	Intern* intern = new Intern();
	Bureaucrat* max = new Bureaucrat("Max", 5);
	AForm* form;
	form = intern->makeForm("shrubbery creation", "Bender");
	if (form)
	{
		std::cout << "\n\n";
		std::cout << *form;
		try
		{
			max->signForm(*form);
			max->executeForm(*form);
		
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n\n";
		
	}
	delete max;
	if (form)
		delete form;
	delete intern;
}

int	main(void)
{
	tryIntern();
	return (0);
}
