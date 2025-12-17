/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:10:26 by gongarci          #+#    #+#             */
/*   Updated: 2025/12/06 00:10:26 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static int	doublesNum(char **argv)
{
	for (int i = 0; argv[i]; i++)
	{
		for (int j = i + 1; argv[j]; j++)
		{
			if (atoi(argv[i]) == atoi(argv[j]))
				return (std::cerr << "Error: Duplicated number '" << argv[i] << "'" << std::endl, 0);
		}
	}
	return (1);
}

static int	wrongArg(char **arg)
{
	for (size_t i = 0; arg[i]; i++)
	{
		if (atoi(arg[i]) < 0)
			return (std::cerr << "Error: Invalid character '" << arg[i] << "'" << std::endl, 1);
	}
	return (0);
}

static int	checkArgs(int argc, char** argv)
{
	if (argc < 2)
		return (std::cerr << "Error: Not enough arguments" << std::endl, 0);
	for (int i = 1; argv[i]; i++)
	{
		if (argv[i][0] == '\0')
			return (std::cerr << "Error: Empty argument" << std::endl, 0);
	}
	if (not doublesNum(argv) || wrongArg(argv))
		return (0);
	return (1);
}

int	main(int argc, char** argv)
{
	if (!checkArgs(argc, argv))
		return (1);
	PmergeMe	pmergeMe;
	try
	{
		pmergeMe.run(argc, argv);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
