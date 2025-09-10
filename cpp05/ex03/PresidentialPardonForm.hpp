#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		const std::string&	getTarget() const;
		std::string const&	getName() const;
		void				execute(const Bureaucrat& executor) const;
};

std::ostream& operator<<(std::ostream& os, PresidentialPardonForm const& form);

#endif // PresidentialPardonForm_HPP
