#ifndef Intern_HPP
#define Intern_HPP
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


class Intern
{
	private:
		std::string	formNames[3];
		AForm*		(Intern::*forms[3])(const std::string& target);
		AForm*	createShrubberyForm(const std::string& target);
		AForm*	createPresidentialForm(const std::string& target);
		AForm*	createRobotomyForm(const std::string& target);
		int		getIndex(const std::string& formType);

	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		int checkShrubberyCreation(const std::string& formType);
		AForm* makeForm(const std::string& formType, const std::string& target);
		
};

#endif // Intern_HPP
