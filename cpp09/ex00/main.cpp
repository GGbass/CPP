/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:13:07 by gongarci          #+#    #+#             */
/*   Updated: 2026/01/03 22:26:20 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "A file is required" << std::endl, 1);
	BitcoinExchange *btc = new BitcoinExchange();
	try
	{
		if (std::string(argv[1]) == "data.csv")
			throw std::runtime_error("Error: input file cannot be the database file");
		std::string fileInput = argv[1];
		btc->saveDatabase("data.csv");
		btc->loadFileInput(fileInput);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete btc;
	return (0);
}
