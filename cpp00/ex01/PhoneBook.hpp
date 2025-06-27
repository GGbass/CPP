#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP
# include <iostream>
# include <string.h>
# include <iomanip>
# include <cstdlib>
# include <sstream>

#include "Contact.hpp"

class PhoneBook
{
	private:
	Contact		contacts[8];
	int			nextIndex;

	public:		PhoneBook();
	public:		void		run();
	private:	std::string	addContact();
	private:	static		std::string intToString(int i);
	private:	static		void printCell(std::string str);
	private:	void		search();
	private:	void		print_contacts();
	private:	std::string	getInput(std::string message, std::string error_message);
	private:	Contact		createContact();
};

#endif