/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:53:45 by marvin            #+#    #+#             */
/*   Updated: 2025/04/18 21:53:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

class	Contact
{
	private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	public: Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
	{
		this->first_name = first_name;
		this->last_name = last_name;
		this->nickname = nickname;
		this->phone_number = phone_number;
		this->darkest_secret = darkest_secret;
	};

	public: Contact()
	{
		this->first_name = "";
		this->last_name = "";
		this->nickname = "";
		this->phone_number = "";
		this->darkest_secret = "";
	};

	std::string getFirstName() const
	{
		return this->first_name;
	};

	std::string getLastName() const
	{
		return this->last_name;
	};

	std::string getNickname() const
	{
		return this->nickname;
	};

	std::string getPhoneNumber() const
	{
		return this->phone_number;
	};

	std::string getDarkestSecret() const
	{
		return this->darkest_secret;
	};
};

class	PhoneBook
{
	private:
	Contact contacts[8];

	int	nextIndex;

	public: PhoneBook()
	{
		this->nextIndex = 0;
	};

	public:
	void	run()
	{
		std::string	input;

		while (input != "EXIT")
		{
			std::cout << "ADD: save a contact" << std::endl;
			std::cout << "SEARCH: search a contact" << std::endl;
			std::cout << "EXIT: exit the program" << std::endl;
			std::cout << "\nType your option:";
			getline(std::cin,input);
			std::cout << std::endl;
			if (input == "ADD")
			{
				std::cout << this->addContact() << " contact saved!\n\n";
			}
			else if (input == "SEARCH")
				this->search();
		}
	}

	private: static std::string intToString(int i)
	{
		std::stringstream ss;
		ss << i;
		return ss.str();
	}

	private: static void printCell(std::string str)
	{
		if (str.length() > 10)
			str = str.substr(0, 9) + ".";
		std::cout << std::setw(10) << str;
	}

	private: void	search()
	{
		if (this->contacts[0].getFirstName().empty())
		{
			std::cout << "No contacts found\n" << std::endl;
			return;
		}
		std::string input;
		this->print_contacts();
		std::cout << "\nEnter the index of the contact: ";
		getline(std::cin, input);
		if (input.length() == 1 && input[0] >= '1' && input[0] <= '8')
		{
			int index = input[0] - '1';
			if (this->contacts[index].getFirstName().empty())
				std::cout << "\nContact not found\n" << std::endl;
			else
			{
				std::cout << "\nFirst name: " << this->contacts[index].getFirstName() << std::endl;
				std::cout << "Last name: " << this->contacts[index].getLastName() << std::endl;
				std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
				std::cout << "Phone number: " << this->contacts[index].getPhoneNumber() << std::endl;
				std::cout << "Darkest secret: " << this->contacts[index].getDarkestSecret() << std::endl;
				std::cout << std::endl;
			}
		}
		else
			std::cout << "\nInvalid index\n" << std::endl;
	}

	std::string addContact()
	{
		this->contacts[this->nextIndex] = this->createContact();
		this->nextIndex = (this->nextIndex + 1) % 8;
		return this->contacts[(this->nextIndex - 1 + 8) % 8].getFirstName();
	}
	
	private: void	print_contacts()
	{
		std::cout << "|";
		PhoneBook::printCell("index");
		std::cout << "|";
		PhoneBook::printCell("first name");
		std::cout << "|";
		PhoneBook::printCell("last name");
		std::cout << "|";
		PhoneBook::printCell("nickname");
		std::cout << "|";
		std::cout << std::endl;
		for (int i = 0; i < 8; i++)
		{
			if (this->contacts[i].getFirstName().empty())
				break;
			std::cout << "|";
			PhoneBook::printCell(intToString(i + 1));
			std::cout << "|";
			PhoneBook::printCell(this->contacts[i].getFirstName());
			std::cout << "|";
			PhoneBook::printCell(this->contacts[i].getLastName());
			std::cout << "|";
			PhoneBook::printCell(this->contacts[i].getNickname());
			std::cout << "|";
			std::cout << std::endl;
		}
	}

	private: std::string getInput(std::string message, std::string error_message)
	{
		std::string input;
		while (input.empty())
		{
			std::cout << message;
			getline(std::cin, input);
			if (input.empty())
				std::cout << error_message << std::endl;
		}
		return input;
	}

	private: Contact	createContact()
	{
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

		first_name = this->getInput("Enter first name: ", "You have to enter a name");
		last_name = this->getInput("Enter last name: ", "You have to enter the last name");
		nickname = this->getInput("Enter the nickname: ", "You have to enter a nickname");
		phone_number = this->getInput("Enter a phone number: ", "You have to enter a phone number");
		darkest_secret = this->getInput("Enter the darkest secret: ", "You have to enter a darkest secret");

		return Contact(first_name, last_name, nickname, phone_number, darkest_secret);
	}
};
