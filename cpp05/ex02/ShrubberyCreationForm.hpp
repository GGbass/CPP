#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP
# include "Bureaucrat.hpp"
# include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{

	private:
		std::string	target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
		
		const std::string&	getTarget() const;
		std::string const&	getName() const;
		void				execute(const Bureaucrat& executor) const;

};

std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm const& form);

#endif // ShrubberyCreationForm_HPP
