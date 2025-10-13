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

void	weirdCase(void)
{
	//int	*arr = new int{0 ,1, 2, 3, 4};
	std::vector<int> vect = {0, 1, 2, 3, 5};
	::easyfind(vect, 5);
	//delete vect;
	//delete arr[];
}

void	notFounded(void)
{
	std::cout << "------Not Found Case -------" << std::endl;

	std::vector<int>	*vect = NULL;
	try
	{
		vect = new std::vector<int>{0, 1, 2, 3, 4};
		::easyfind(*vect, -1);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	if (vect)
		delete vect;
	std::cout << std::endl;
}

void	foundCase(void)
{
	try
	{
		std::cout << "------Found Case --------" << std::endl;
		std::vector<int>	vect = {0, 1, 2, 3, 4};
		::easyfind(vect, 4);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main(void)
{
	foundCase();
	notFounded();
	weirdCase();
	return (0);
}
