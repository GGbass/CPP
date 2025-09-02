#ifndef AForm_HPP
# define AForm_HPP
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

// Forward declaration to break circular dependency
class Bureaucrat;

class AForm
{
	private:
		std::string const	name;
		bool				isSigned;
		int const			signGrade;
		int const			executeGrade;

	public:
		AForm();
		AForm(std::string const& name, int signGrade, int executeGrade);
		AForm(AForm const& other);
		AForm& operator=(AForm const& other);
		virtual ~AForm();

		virtual std::string const&	getName() const = 0;
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