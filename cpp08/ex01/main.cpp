/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 01:24:32 by gongarci          #+#    #+#             */
/*   Updated: 2025/10/12 01:24:32 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	TenThousandsTest(void)
{
	Span *span = new Span(-1);
	std::vector<int> BigList(100000);
	try
	{
		srand(time(NULL));
		std::generate(BigList.begin(), BigList.end(), std::rand);
		span->addNumbers(BigList.begin(), BigList.end());
		std::cout << span->shortestSpan() << std::endl;
		std::cout << span->longestSpan() << std::endl;
		/* std::cout << span->getMinValue() << std::endl;
		std::cout << span->getMaxValue() << std::endl; */
		//std::cout << *span;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete span;
}

void	mainGiven()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << sp;
}

int	main(void)
{
	//mainGiven();
	TenThousandsTest();
	return (0);
}
