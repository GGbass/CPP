#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	// std::cout << "Default constructor" << std::endl;
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
		// std::cout << "Destructor called" << std::endl;
}

std::string*	BitcoinExchange::split(std::string line, char delimiter)
{
	std::string
}

int	BitcoinExchange::parseLine(std::string line)
{
	std::cout << line << std::endl;
	std::string	date;
	double		value = 0;

	(void)value;
	line.rfind(",", 0);
	std::string str[2];
	return (0);
}

int	BitcoinExchange::loadDatabase(std::string dataBase)
{
	std::ifstream db(dataBase);
	if (!db.is_open())
		throw std::runtime_error("Error: could not open the file");
	std::string line;
	while(getline(db, line))
	{
		//check dates on line
		this->parseLine(line);
		//if it's right add it on the map otherwise send a error
	}
	std::cout << "end of file" << std::endl;
	db.close();
	return (1);
}

/* int	BitcoinExchange::loadFileInput(std::string infile)
{
	(void)infile;
	return (0);
} */
