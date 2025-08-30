#ifndef Form_HPP
# define Form_HPP
# include "Bureaucrat.hpp"

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
		bool				getIsSigned(Bureaucrat const &b) const;
		int					getExecuteGrade() const;
		int					beSigned(Bureaucrat const& bureaucrat);

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