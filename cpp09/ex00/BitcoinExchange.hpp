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
class BitcoinExchange
{
	private:
		std::map<std::string, double> _map;

		int	parseLine(std::string line);
		std::string*	split(std::string, char);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		int loadDatabase(std::string);
		int	loadFileInput(std::string) {return 0;}
		//int	printResult();
};

#endif // BitcoinExchange_HPP
