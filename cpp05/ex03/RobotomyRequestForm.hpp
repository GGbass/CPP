#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		const std::string&	getTarget() const;
		std::string const&	getName() const;
		void				execute(const Bureaucrat& executor) const;
		AForm*				clone(std::string const& target) const;
};

#endif // RobotomyRequestForm_HPP
