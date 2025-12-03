#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(char* inputFile) { (void)inputFile;}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->_dataBase = other._dataBase;
	std::cout << "Copy constructor called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this not_eq &other)
	{
		this->_dataBase = other._dataBase;
		std::cout << "Copy constructor called" << std::endl;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() { }

int	BitcoinExchange::parseLine(std::string line)
{
	if (line.empty() or line == "date,exchange_rate")
		return (0);
	std::string	date;
	double		value;
	std::istringstream	ss(line);
	std::string			token;
	if (std::getline(ss, token, ','))
		date = token;
	if (std::getline(ss, token, ','))
		value = std::atof(token.c_str());
	if (not validDate(date))
		throw std::runtime_error("Error: invalid date => " + date);
	if (not validValue(value))
		throw std::runtime_error("Error: invalid value => " + token);
	this->_dataBase[date] = value;
	return (0);
}

void	BitcoinExchange::printDataBase()
{
	for (std::map<std::string, double>::iterator it = this->_dataBase.begin(); it != this->_dataBase.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
}

int	BitcoinExchange::saveDatabase(const char* dataBase)
{
	 std::ifstream db(dataBase);
	if (!db.is_open())
		throw std::runtime_error("Error: could not open the file");
	std::string	line;
	while(std::getline(db, line))
		this->parseLine(line);
	// this->printDataBase();
	db.close();
	return (1);
}

int	BitcoinExchange::loadFileInput(const std::string& infile)
{
	std::ifstream inputFile(infile.c_str());
	if (!inputFile.is_open())
		throw std::runtime_error("Error: could not open the file");
	std::string	line;
	bool isFirstLine = true;
	while(std::getline(inputFile, line))
	{
		if (line.empty())
			continue;
		if (isFirstLine)
		{
			isFirstLine = false;
			if (line == "date,value")
				continue;
		}
		
		// Parse the line: date,value
		std::istringstream ss(line);
		std::string token;
		std::string date;
		double amount;
		
		if (!std::getline(ss, token, ','))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		date = token;
		
		if (!std::getline(ss, token, ','))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		try
		{
			amount = std::atof(token.c_str());
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (!validDate(date))
		{
			std::cerr << "Error: invalid date => " << date << std::endl;
			continue;
		}
		
		if (amount < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		
		if (amount > INT_MAX)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		try
		{
			double exchangeRate = getRateValue(date);
			double result = amount * exchangeRate;
			std::cout << date << " => " << amount << " = " << result << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	inputFile.close();
	return (0);
}

/* utils */

bool	validDate(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());
	if (year < 2009 or year > 2025)
		return (false);
	if (month < 1 or month > 12 or day < 1 or day > 31)
		return (false);
	if (month == 2 and day > 29)
			return (false);
	return (true);
}

bool	validValue(double value)
{
	// std::cout << "Validating value: " << value << std::endl;
	if (value < 0 or value > INT_MAX)
		return (false);
	return (true);
}

std::string BitcoinExchange::closestDate(const std::string& date)
{
	std::map<std::string, double>::iterator it = this->_dataBase.begin();
	std::string closestDate;
	if (date.length() < 10)
		return (std::string());
	std::string subDate = date.substr(0, 10);
	if (subDate.empty())
		return (std::string());
	if (not validDate(subDate))
		return (std::string());
	for (; it != this->_dataBase.end(); ++it)
	{
		if (it->first == subDate)
			return (it->first);
		else if (it->first > subDate)
		{
			if (it == this->_dataBase.begin())
			{
				closestDate = it->first;
				break ;
			}
			else
			{
				--it;
				closestDate = it->first;
				break ;
			}
		}
	}
	if (it == this->_dataBase.end())
	{
		--it;
		closestDate = it->first;
	}
	return (closestDate);
}

double	BitcoinExchange::getRateValue(const std::string& date)
{
	std::string closest = this->closestDate(date);
	if (closest.empty())
		throw std::runtime_error("Error: no valid date found for " + date);
	return (this->_dataBase[closest]);
}
