#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>

class	Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		Contact(std::string firstName, 
				std::string lastName, 
				std::string nickname, 
				std::string phoneNumber, 
				std::string darkestSecret);
		Contact();
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;
};

#endif