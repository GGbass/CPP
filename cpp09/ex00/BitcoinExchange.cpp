#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Default constructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->_map = other._map;
	std::cout << "Copy constructor called" << std::endl;
}


BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->_map = other._map;
		std::cout << "Copy constructor called" << std::endl;
	}
	return (*this);
}


BitcoinExchange::~BitcoinExchange()
{
		std::cout << "Destructor called" << std::endl;
}

int	BitcoinExchange::loadDatabase(std::string dataBase)
{
	std::ifstream db(dataBase);
	if (!db.is_open())
		throw std::runtime_error("Error: could not open the file");
	std::string line;
	while(getline(db, line))
	{
		std::cout << line << std::endl;
		//check dates on line
		//if it's right add it on the map otherwise send a error
		//
	}
	std::cout << "end of file" << std::endl;
	return (1);
}

int	BitcoinExchange::loadFileInput(std::string infile)
{
	(void)infile;
	return (0);
}
