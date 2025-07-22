#include "Harl.hpp"

void Harl::complain(std::string level)
{
	switch (level)
	{
		case "DEBUG":
			this->debug();
			break;
		case "INFO":
			info();
			break;
		case "WARNING":
			this->warning();
			break;
		case "ERROR":
			this->error();
			break;
		default:
			std::cout << "Unknown level: " << level << std::endl;
			break;
	}
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 
	7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put
	enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been
	coming here for years and you just started working here last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}