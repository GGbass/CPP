#include "Bureaucrat.hpp"

void	tryCopyTest()
{
	std::cout << "\n=== Test 5: Copy test ===" << std::endl;
	Bureaucrat* weber = new Bureaucrat("Weber", 42);
	try
	{
		Bureaucrat* copyW = new Bureaucrat(*weber);
		Bureaucrat* assignW = new Bureaucrat();

		*assignW = *weber;

		delete weber;
		weber = NULL;
		assignW->incrementGrade();
		copyW->decrementGrade();
		std::cout << *copyW;
		std::cout << *assignW;
		delete assignW;
		delete copyW;

	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	if (weber)
		delete weber;
	std::cout << "\n";
}

void	tryLowGrade()
{
	std::cout << "\n=== Test 4: Grade Too Low ===" << std::endl;
	try
	{
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
	std::cout << "\n";
}

void	tryHighGrade()
{
	std::cout << "\n=== Test 3: Grade Too High ===" << std::endl;
	Bureaucrat* topGrade = new Bureaucrat("TopGuy", 1);
	try
	{
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
	std::cout << "\n";
}

void	tryInvalidCreation()
{
	std::cout << "\n=== Test 2: Invalid Grade Creation ===" << std::endl;
	try
	{
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
	std::cout << "\n";
}

void	tryValid()
{
	std::cout << "=== Test 1: Valid Operations ===" << std::endl;
	try
	{
		Bureaucrat* bureaucrat = new Bureaucrat("Johnny", 42);
		std::cout << std::endl;
		std::cout << *bureaucrat;
		bureaucrat->incrementGrade();
		std::cout << *bureaucrat;
		bureaucrat->decrementGrade();
		std::cout << *bureaucrat;

		delete bureaucrat;
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
	tryInvalidCreation();
	tryHighGrade();
	tryLowGrade();
	//tryCopyTest();
	return (0);
}
