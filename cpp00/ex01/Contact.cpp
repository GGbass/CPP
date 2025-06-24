#include "Contact.hpp"

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
