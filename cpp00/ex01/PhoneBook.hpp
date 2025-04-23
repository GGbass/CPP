#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP
# include <iostream>
# include <string.h>
# include <iomanip>
# include <cstdlib>
# include <sstream>

/* class	Contact{
	private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	public: Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);

	public: Contact();

	std::string getFirstName() const;

	std::string getLastName() const;

	std::string getNickname() const;

	std::string getPhoneNumber() const;

	std::string getDarkestSecret() const;
};

class PhoneBook
{
	private:
	Contact contacts[8];
	int	nextIndex;

	public: PhoneBook();
	public:		void		run();
	private:	static		std::string intToString(int i);
	private:	static		void printCell(std::string str);
	private:	void		search();
	private:	void		print_contacts();
	private:	std::string	getInput(std::string message, std::string error_message);
	private:	Contact		createContact();
}; */

#endif