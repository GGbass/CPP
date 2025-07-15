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
	public:
		PhoneBook();
		void		run();

	private:
		Contact		contacts[8];
		int			nextIndex;

		static		std::string intToString(int i);
		static		void printCell(std::string str);

		Contact		createContact();
		std::string	addContact();
		void		print_contacts() const;
		void		search();
		std::string	getInput(std::string message, std::string error_message);
};

#endif