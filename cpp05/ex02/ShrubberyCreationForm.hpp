#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP
# include "Bureaucrat.hpp"
# include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
		
		const std::string& getTarget() const;
	
	void execute(const Bureaucrat& executor) const;

	private:
		std::string	target;

};

#endif // ShrubberyCreationForm_HPP
