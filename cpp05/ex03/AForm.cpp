#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdio>

AForm::AForm() : name("Default"), isSigned(false), signGrade(150), executeGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(std::string const& name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
	std::cout << "Form constructor called from: " << this->name << std::endl;
}

AForm::AForm(AForm const& other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
	std::cout << "Form copy constructor called from: " << this->name << std::endl;
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->~AForm();
		//new (this) AForm(other);
	}
	std::cout << "Form assignment operator called from: " << this->name << std::endl;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "Form destructor from: " << this->name << " called\n";
}

std::string const& AForm::getName() const {return (this->name);}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}

int	AForm::getSignGrade() const { return (this->signGrade);}

int	AForm::getExecuteGrade() const { return (this->executeGrade);}

void	AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->signGrade)
	{
		std::cout << "Bureaucrat " << b.getName() 
				 << " cannot sign Form : " << this->name 
				 << " because bureaucrat's grade is too low." << std::endl;
		throw GradeTooHighException();
	}
	std::cout << "Bureaucrat " << b.getName() 
			  << " signs Form : " << this->name << std::endl;
	this->isSigned = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned)
	{
		std::cout << "Form " << this->name << " is not signed." << std::endl;
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > this->executeGrade)
	{
		std::cout << "Bureaucrat " << executor.getName()
				  << " cannot execute Form : " << this->name
				  << " because bureaucrat's grade is too low." << std::endl;
		throw AForm::GradeTooHighException();
	}
	std::cout << "Bureaucrat " << executor.getName() << "executes " << this->name << std::endl;
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low");
}

std::ostream& operator<<(std::ostream& os, AForm const& AForm)
{
	os	<< "Form Name: " << AForm.getName() << "\n"
		<< "Sign Grade: " << AForm.getSignGrade() << "\n"
		<< "Execute Grade: " << AForm.getExecuteGrade() << "\n";
		if (AForm.getIsSigned())
			os << "Form is signed\n";
		else
			os << "Form is not signed\n";
	return (os);
}
