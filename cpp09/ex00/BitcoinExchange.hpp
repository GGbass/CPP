/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 23:47:41 by gongarci          #+#    #+#             */
/*   Updated: 2026/01/04 01:30:28 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP
#include <iostream>
#include <algorithm>
#include <map>
#include <ostream>
#include <sstream>
#include <fstream>
#include <exception>
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
		int	saveDatabase(const char* dataBase);
		int	loadFileInput(const std::string& inputFile);
		//int	printResult();
		bool	printRate(const std::string& date, double rate);
};

bool		validDate(const std::string& date);
bool		validValue(double value, int flag);
#endif
