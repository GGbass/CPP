/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 23:47:29 by gongarci          #+#    #+#             */
/*   Updated: 2025/12/22 23:55:57 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(char	*inputFile)
{
	this->saveDatabase("data.csv");
	this->loadFileInput(std::string(inputFile));
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _dataBase(other._dataBase) { }

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->_dataBase = other._dataBase;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

int	BitcoinExchange::parseLine(std::string line)
{
	if (line.empty() || line == "date,exchange_rate")
		return (0);
	std::string date;
	double value;
	std::istringstream ss(line);
	std::string token;
	if (!std::getline(ss, token, ','))
		return (0);
	date = token;
	if (!std::getline(ss, token, ','))
		return (0);
	value = std::atof(token.c_str());
	if (!validDate(date))
		throw std::runtime_error("Error: invalid date => " + date);
	if (!validValue(value, 0))
		throw std::runtime_error("Error: invalid value => " + token);
	this->_dataBase[date] = value;
	return (0);
}

int	BitcoinExchange::saveDatabase(const char* dataBase)
{
	std::ifstream db(dataBase);
	if (!db.is_open())
		throw std::runtime_error("Error: could not open the file");
	std::string line;
	while (std::getline(db, line))
		this->parseLine(line);
	db.close();
	return (1);
}

static	std::string	trimString(const std::string& str)
{
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");
	if (start == std::string::npos)
		return (std::string());
	return (str.substr(start, end - start + 1));
}

static bool	goodLine(std::string& line, bool &isFirstLine)
{
	if (line.empty() or (line.size() == 1 && line[0] == '\n'))
	{
		std::cerr << "Error: bad input =>  empty or new line" << line << std::endl;
		return (false);
	}
	if (isFirstLine && (line == "date | value"))
	{
		isFirstLine = false;
		return (false);
	}
	return (true);
}

static bool getDateAndRate(std::string& line, std::string& date, double& rate)
{
	std::istringstream	ss(line);
	std::string			dateToken;
	std::string			amountToken;
	if (!std::getline(ss, dateToken, '|'))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (false);
	}
	date = trimString(dateToken);
	if (!std::getline(ss, amountToken))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (false);
	}
	std::string amountStr = trimString(amountToken);
	// if 
	if (!isdigit(amountStr[0]))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (false);
	}
	rate = std::atof(amountStr.c_str());
	return (true);
}

int	BitcoinExchange::loadFileInput(const std::string& infile)
{
	std::ifstream inputFile(infile.c_str());
	if (not inputFile.is_open())
		throw std::runtime_error("Error: could not open the file");
	std::string line;
	bool isFirstLine = true;
	while (std::getline(inputFile, line))
	{
		if (not goodLine(line, isFirstLine))
			continue;
		std::string	date;
		double		rate;
		if (not getDateAndRate(line, date, rate))
			continue;
		if (not validDate(date) or not validValue(rate, 1))
			continue;
		printRate(date, rate);
	}
	inputFile.close();
	return (0);
}

bool	validDate(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (std::cerr << "Error: wrong date format" << std::endl, false);

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || year > 2025)
		return (std::cerr << "Error: year out of range" << std::endl, false);
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return (std::cerr << "Error: invalid month or day" << std::endl, false);
	if (month == 2 && day > 29)
		return (false);
	return (true);
}

bool	validValue(double value, int rate)
{
	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (rate && value > 1000)
	{
		std::cerr << "Error: rate greater than 1000." << std::endl;
		return (false);
	}
	if (value > INT_MAX)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

std::string BitcoinExchange::closestDate(const std::string& date)
{
	if (date.length() < 10)
		return (std::string());
	std::string subDate = date.substr(0, 10);
	std::map<std::string, double>::iterator it = this->_dataBase.begin();
	std::map<std::string, double>::iterator end = this->_dataBase.end();
	std::string closestDate = "";
	for (; it != end; ++it)
	{
		if (it->first == subDate)
			return (it->first);
		if (it->first > subDate)
		{
			if (it == this->_dataBase.begin())
				closestDate = it->first;
			else
			{
				--it;
				closestDate = it->first;
			}
			break;
		}
	}
	if (it == end && closestDate.empty())
	{
		--it;
		closestDate = it->first;
	}
	return (closestDate);
}

bool	BitcoinExchange::printRate(const std::string& date, double rate)
{
	std::string closestDate = this->closestDate(date);
	if (closestDate.empty())
	{
		std::cerr << "Error: no valid date found for " + date << std::endl;
		return (false);
	}
	double	exchangeRate = this->_dataBase[closestDate];
	double	result = rate * exchangeRate;
	std::cout << date << " => " << rate << " = " << result << std::endl;
	return (true);
}
