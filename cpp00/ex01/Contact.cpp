#include "Contact.hpp"

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

Contact::Contact()
{
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkest_secret = "";
}

std::string Contact::getFirstName() const
{
	return this->first_name;
}

std::string Contact::getLastName() const
{
	return this->last_name;
}

std::string Contact::getNickName() const
{
	return this->nickname;
}

std::string Contact::getPhoneNumber() const
{
	return this->phone_number;
}

std::string Contact::getDarkestSecret() const
{
	return this->darkest_secret;
}
