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

void	copyTest()
{
	Span *sp =  new Span(5);
	sp->addNumber(6);
	sp->addNumber(3);
	sp->addNumber(17);
	sp->addNumber(9);
	sp->addNumber(11);
	/* --------Copy constructor  */
	Span *spanCopy = new Span(*sp);
	delete sp;
	std::cout << spanCopy->shortestSpan() << std::endl;
	std::cout << spanCopy->longestSpan() << std::endl;
	///std::cout << *spanCopy;
	/* Assigning operator */
	Span *spanAssign = new Span();

	*spanAssign = *spanCopy;
	std::cout << std::endl;
	delete spanCopy;
	std::cout << *spanAssign;
	std::cout << std::endl;
	delete spanAssign;
}

void	TenThousandsTest(void)
{
	std::cout << " a lot of numbers test" << std::endl;
	Span *span = new Span(10000);
	std::vector<int> BigList(10000);
	try
	{

		srand(time(NULL));
		std::generate(BigList.begin(), BigList.end(), std::rand);
		span->addNumbers(BigList.begin(), BigList.end());
		std::cout << span->shortestSpan() << std::endl;
		std::cout << span->longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
		delete span;
}

void	mainGiven()
{
	std::cout << "Main given test" << std::endl;
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
	mainGiven();
	TenThousandsTest();
	//copyTest();
	return (0);
}
