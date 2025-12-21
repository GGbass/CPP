/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 23:47:29 by gongarci          #+#    #+#             */
/*   Updated: 2025/12/21 00:50:22 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(char	*inputFile)
{
	this->saveDatabase("data.csv");
	this->loadFileInput(std::string(inputFile));
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _dataBase(other._dataBase)
{

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
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
	if (!validValue(value))
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

int	BitcoinExchange::loadFileInput(const std::string& infile)
{
	std::ifstream inputFile(infile.c_str());
	if (!inputFile.is_open())
		throw std::runtime_error("Error: could not open the file");
	std::string line;
	bool isFirstLine = true;
	while (std::getline(inputFile, line))
	{
		if (line.empty())
			continue;
		if (isFirstLine)
		{
			isFirstLine = false;
			if (line == "date | value" || line == "date,value")
				continue;
		}
		std::istringstream ss(line);
		std::string dateToken, amountToken;
		if (!std::getline(ss, dateToken, ','))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = trimString(dateToken);
		if (!std::getline(ss, amountToken))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string amountStr = trimString(amountToken);
		double amount = std::atof(amountStr.c_str());
		if (not validDate(date) or not validValue(amount))
			continue;
		try
		{
			double exchangeRate = this->getRateValue(date);
			double result = amount * exchangeRate;
			std::cout << date << " => " << amount << " = " << result << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
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

bool	validValue(double value)
{
	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
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
	if (subDate.empty() or not validDate(subDate))
		return (std::string());
	std::map<std::string, double>::iterator it = this->_dataBase.begin();
	std::string closestDate;
	for (; it != this->_dataBase.end(); ++it)
	{
		if (it->first == subDate)
			return (it->first);
		if (it->first > subDate)
		{
			if (it == this->_dataBase.begin())
				closestDate = it->first; // No prior dates exist
			else // Use the previous (closest prior) date
			{
				--it;
				closestDate = it->first;
			}
			break;
		}
	}
	if (it == this->_dataBase.end() && !closestDate.empty() == false)
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
