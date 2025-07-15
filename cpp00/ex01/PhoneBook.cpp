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
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	this->nextIndex = 0;
}

void	PhoneBook::run()
{
	std::string	input;

	while (input != "EXIT")
	{
		std::cout << "ADD: save a contact" << std::endl;
		std::cout << "SEARCH: search a contact" << std::endl;
		std::cout << "EXIT: exit the program" << std::endl;
		std::cout << "\nType your option: ";
		getline(std::cin,input);
		std::cout << std::endl;
		if (input == "ADD")
		{
			std::cout << this->addContact() << " contact saved!\n\n";
		}
		else if (input == "SEARCH")
			this->search();
		else if (input == "EXIT")
			std::cout << "\n Turning off" << std::endl;
		else
			std::cout << input <<" doesn't matched any option \n" << std::endl;
	}
}

std::string	PhoneBook::intToString(int i)
{
	std::stringstream ss;
	ss << i;
	return ss.str();
}

void	PhoneBook::printCell(std::string str)
{
	if (str.length() > 10)
		str = str.substr(0, 9) + ".";
	std::cout << std::setw(10) << str;
}

void PhoneBook::search()
{
	std::string	input;
	int			index;

	if (this->contacts[0].getFirstName().empty())
	{
		std::cout << "There's any contacts \n" << std::endl;
		return ;
	}
	this->print_contacts();
	std::cout << "\nEnter the index of the contact: ";
	getline(std::cin, input);
	if (input.length() == 1 && input[0] >= '1' && input[0] <= '8')
	{
		index = input[0] - '1';
		if (this->contacts[index].getFirstName().empty())
			std::cout << "\nContact not found\n" << std::endl;
		else
		{
			std::cout << "\nFirst name: " << this->contacts[index].getFirstName() << std::endl;
			std::cout << "Last name: " << this->contacts[index].getLastName() << std::endl;
			std::cout << "Nickname: " << this->contacts[index].getNickName() << std::endl;
			std::cout << "Phone number: " << this->contacts[index].getPhoneNumber() << std::endl;
			std::cout << "Darkest secret: " << this->contacts[index].getDarkestSecret() << std::endl;
			std::cout << std::endl;
		}
	}
	else
		std::cout << "\nInvalid index\n" << std::endl;
}

std::string	PhoneBook::addContact()
{
	this->contacts[this->nextIndex] = this->createContact();
	this->nextIndex = (this->nextIndex + 1) % 8;
	return (this->contacts[(this->nextIndex - 1 + 8) % 8].getFirstName());
}

void	PhoneBook::print_contacts() const
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
		PhoneBook::printCell(this->contacts[i].getNickName());
		std::cout << "|";
		std::cout << std::endl;
	}
}

std::string PhoneBook::getInput(std::string message, std::string error_message)
{
	std::string input;
	while (input.empty())
	{
		std::cout << message;
		getline(std::cin, input);
		if (input.empty())
			std::cout << error_message << std::endl;
	}
	return (input);
}

Contact PhoneBook::createContact()
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
	return (Contact(first_name, last_name, nickname, phone_number, darkest_secret));
}
