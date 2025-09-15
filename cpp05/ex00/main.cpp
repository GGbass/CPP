#include "Bureaucrat.hpp"

void	tryLowGrade()
{
	try
	{
		std::cout << "\n=== Test 4: Grade Too Low ===" << std::endl;
		Bureaucrat bottomGrade("BottomGuy", 150);
		std::cout << bottomGrade;
		bottomGrade.decrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void	tryHighGrade()
{
	Bureaucrat* topGrade = new Bureaucrat("TopGuy", 1);
	try
	{
		std::cout << "\n=== Test 3: Grade Too High ===" << std::endl;
		//Bureaucrat topGrade("TopGuy", 1);
		std::cout << *topGrade;
		topGrade->incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete topGrade;
}

void	tryInvalidCreation()
{
	try
	{
		std::cout << "\n=== Test 2: Invalid Grade Creation ===" << std::endl;
		Bureaucrat invalidBureaucrat("InvalidGuy", -42);
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Error: too high " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Error: too low " << e.what() << std::endl;
	}
}

void	tryValid()
{
	try
	{
		std::cout << "=== Test 1: Valid Operations ===" << std::endl;
		Bureaucrat* bureaucrat = new Bureaucrat("Johnny", 42);
		Bureaucrat* anotherBureaucrat = new Bureaucrat();
		std::cout << std::endl;
		std::cout << *bureaucrat;
		bureaucrat->incrementGrade();
		std::cout << *bureaucrat;
		bureaucrat->decrementGrade();
		std::cout << *bureaucrat;

		*anotherBureaucrat = *bureaucrat;
		delete bureaucrat;
		delete anotherBureaucrat;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

int	main(void)
{
	tryValid();
/* 	tryInvalidCreation();
	tryHighGrade();
	tryLowGrade(); */
	return (0);
}
