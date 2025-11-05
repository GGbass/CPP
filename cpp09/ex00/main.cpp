/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:13:07 by gongarci          #+#    #+#             */
/*   Updated: 2025/11/05 20:31:00 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Couldn't open the file" << std::endl, 1);
	BitcoinExchange btc;
	try
	{
		std::string inputFile = argv[1];
		btc.loadDatabase("data.csv");
		//btc.loadFileInput(inputFile);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
