#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	std::cout << "Bureaucrat " << this->name << " called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const& name, int grade): name(name), grade(grade)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	std::cout << "Bureaucrat " << this->name << " called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->grade = other.grade;
	}
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Deleting this " << this->getName() << " Bureaucrat" << std::endl;
}

std::string	Bureaucrat::getName() const {return this->name;}

int			Bureaucrat::getGrade() const {return this->grade;}

void		Bureaucrat::incrementGrade()
{
	if (this->grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
	return (os);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Invalid grade: Grade cannot be higher than 1.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Invalid grade: Grade cannot be lower than 150.");
}
int	Bureaucrat::signForm(AForm &form)
{
	form.beSigned(*this);
	std::cout << this->name << " signs " << form.getName() << std::endl;
	return (1);
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	form.execute(*this);
	//std::cout << this->name << " executed " << form.getName() << std::endl;
}