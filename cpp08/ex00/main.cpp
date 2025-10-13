/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 01:34:45 by gongarci          #+#    #+#             */
/*   Updated: 2025/10/12 01:34:45 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void	notFounded(void)
{
	std::vector<int>	*vect = NULL;
	try
	{
		std::cout << "Starting point" << std::endl;
		vect = new std::vector<int>{0, 1, 2, 3, 4};
		::easyfind(*vect, -1);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	if (vect)
		delete vect;
}

void	foundCase(void)
{
	try
	{
		std::cout << "Starting point" << std::endl;
		std::vector<int>	vect = {0, 1, 2, 3, 4};
		::easyfind(vect, 4);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

int	main(void)
{
	foundCase();
	notFounded();
	return (0);
}
