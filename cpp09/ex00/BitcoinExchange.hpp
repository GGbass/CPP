#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP
#include <iostream>
#include <algorithm>
#include <map>
#include <ostream>
#include <sstream>
#include <fstream>
#include <exception>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _map;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		int loadDatabase(std::string);
		int	loadFileInput(std::string);
		//int	printResult();
};

#endif // BitcoinExchange_HPP
