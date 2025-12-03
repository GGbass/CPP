#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP
#include <iostream>
#include <algorithm>
#include <map>
#include <ostream>
#include <sstream>
#include <fstream>
#include <exception>
#include <cstring>
#include <climits>

class	BitcoinExchange
{
	private:
		std::map<std::string, double> _dataBase;
		double		rate;
		int			parseLine(std::string line);
		void		printDataBase();
		std::string	closestDate(const std::string& date); // find the nearest date in the database
		
	public:
		BitcoinExchange();
		BitcoinExchange(char	*inputFile);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		int saveDatabase(const char* dataBase);
		int	loadFileInput(const std::string& inputFile);
		//int	printResult();
		double	getRateValue(const std::string& date);
};

// std::string*	split(std::string, char);
bool		validDate(const std::string& date);
bool		validValue(double value);
// std::string	split(std::string str, char delimiter);
// find the neartest date in the database
#endif // BitcoinExchange_HPP
