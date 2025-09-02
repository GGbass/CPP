#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), isSigned(false), signGrade(150), executeGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string const& name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form constructor called from: " << this->name << std::endl;
}

Form::Form(Form const& other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
	std::cout << "Form copy constructor called from: " << this->name << std::endl;
}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->~Form();
		new (this) Form(other);
	}
	std::cout << "Form assignment operator called from: " << this->name << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor from: " << this->name << " called\n";
}

std::string const& Form::getName() const {return (this->name);}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

int	Form::getSignGrade() const { return (this->signGrade);}

int	Form::getExecuteGrade() const { return (this->executeGrade);}

void	Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->signGrade)
	{
		std::cout << "Bureaucrat " << b.getName() << " cannot sign form : " << this->name << " because grade is too low." << std::endl;
		throw GradeTooHighException();
	}
	this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low");
}

std::ostream& operator<<(std::ostream& os, Form const& form)
{
	os	<< "Form Name: " << form.getName() << "\n"
		<< "Sign Grade: " << form.getSignGrade() << "\n"
		<< "Execute Grade: " << form.getExecuteGrade() << "\n";
		if (form.getIsSigned())
			os << "Form is signed\n";
		else
			os << "Form is not signed\n";
	return (os);
}
