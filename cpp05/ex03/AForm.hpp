#ifndef AForm_HPP
# define AForm_HPP
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"
# include <cstdlib>

#define BLUE "\033[0;34m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define DEFAULT "\033[0m"

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
		virtual void		beSigned(Bureaucrat const& bureaucrat);
		virtual void		execute(Bureaucrat const& executor) const = 0;

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
	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, AForm const& form);

#endif // AForm_HPP