#include "Form.hpp"

Form::Form() : name("Default"), isSigned(false), signGrade(150), executeGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string const& name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	std::cout << "Form parameterized constructor called" << std::endl;
}

Form::Form(Form const& other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade), status(other.status)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->isSigned = other.isSigned;
		this->signGrade = other.signGrade;
		this->executeGrade = other.executeGrade;
		this->status = other.status;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Default's Form constructor called\n";
}

std::string const& Form::getName() const {return (this->name);}

bool Form::getIsSigned(Bureaucrat const &b) const
{
	if (b.getGrade() <= this->signGrade)
		return (true);
	return (false);
}

int	Form::getSignGrade() const { return (this->signGrade);}

int	Form::getExecuteGrade() const { return (this->executeGrade);}

void	Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->signGrade)
	{
		throw GradeTooLowException();
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
	os << "Form Name: " << form.getName() << "\n"
	   << "Sign Grade: " << form.getSignGrade() << "\n"
	   << "Execute Grade: " << form.getExecuteGrade() << "\n"
	return (os);
}
