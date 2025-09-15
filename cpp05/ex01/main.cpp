#include "Bureaucrat.hpp"
#include "Form.hpp"

void	tryInvalidSign()
{
	Bureaucrat* weber = NULL;
	Form* form = NULL;
	try
	{
		std::cout << "\n=== Test 2: Invalid Grade Creation ===\n\n";
		weber = new Bureaucrat("Weber", 42);
		form = new Form("The Protestant Ethic and the Spirit of Capitalism", 41, 2);
		weber->signForm(*form);
		std::cout << *form;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cerr << "Form Error: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Bureaucrat Error: " << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cerr << "Form Error: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Bureaucrat Error: " << e.what() << std::endl;
	}
	if (weber)
		delete weber;
	if (form)
		delete form;
}

void	tryValidSign()
{
	Bureaucrat* max = NULL;
	Form* form = NULL;
	try 
	{
		std::cout << "=== Test 1: Valid Operations ===\n\n";
		form = new Form("Form of bureaucracy", 145, 2);
		max = new Bureaucrat("Max", 145);
		max->signForm(*form);
		std::cout << *form << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cerr << "Form Error: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Bureaucrat Error: " << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cerr << "Form Error: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Bureaucrat Error: " << e.what() << std::endl;
	}
	if (max)
		delete max;
	if (form)
		delete form;
}

int	main(void)
{
	tryValidSign();
	tryInvalidSign();
	return (0);
}
