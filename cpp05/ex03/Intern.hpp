#ifndef Intern_HPP
#define Intern_HPP
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


class Intern
{
	private:
		std::string	formTypes[3] =
		{
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"
		};

	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		int checkShrubberyCreation(const std::string& formType);
		AForm* createForm(const std::string& formType, const std::string& target);
};

#endif // Intern_HPP
