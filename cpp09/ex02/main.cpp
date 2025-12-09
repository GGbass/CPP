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

static int	checkArg(char* arg)
{
	for (size_t i = 0; arg[i]; i++)
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (std::cerr << "Error: Invalid character '" << arg[i] << "'" << std::endl, 0);
	}
	return (1);
}

static int	checkArgs(int argc, char** argv)
{
	if (argc < 2)
		return (std::cerr << "Error: Not enough arguments" << std::endl, 0);
	for (int i = 1; argv[i]; i++)
	{
		if (argv[i][0] == '\0')
			return (std::cerr << "Error: Empty argument" << std::endl, 0);
		if (argv[i][0] == '-')
			return (std::cerr << "Error: Negative number" << std::endl, 0);
		if (!checkArg(argv[i]))
			return (0);
	}
	return (1);
}

int	main(int argc, char** argv)
{

	if (!checkArgs(argc, argv))
		return (1);
	PmergeMe<std::vector<int> >	pmergeMe;

	clock_t	start = clock();
	for (int i = 1; argv[i]; i++)
	{
int	num = atoi(argv[i]);
		(void)num;
		// pmergeMe.insert(num);
	}
	clock_t	end = clock();
	std::cout << "Time taken: " << static_cast<double>(end - start) << " seconds" << std::endl;
	return (0);
}
