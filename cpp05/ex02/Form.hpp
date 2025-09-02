#ifndef Form_HPP
# define Form_HPP
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

// Forward declaration to break circular dependency
class Bureaucrat;

class Form
{
	private:
		std::string const	name;
		bool				isSigned;
		int const			signGrade;
		int const			executeGrade;

	public:
		Form();
		Form(std::string const& name, int signGrade, int executeGrade);
		Form(Form const& other);
		Form& operator=(Form const& other);
		~Form();

		std::string const&	getName() const;
		int					getSignGrade() const;
	bool				getIsSigned() const;
		int					getExecuteGrade() const;
	void					beSigned(Bureaucrat const& bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, Form const& form);

#endif // Form_HPP