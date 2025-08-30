#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP
# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Bureaucrat
{
	private:
		std::string	name;
		int			grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
		int			signForm(Form &form);
	
	class	GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);



#endif // Bureaucrat_HPP
