/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:11:20 by gongarci          #+#    #+#             */
/*   Updated: 2025/12/17 22:25:02 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << "PmergeMe default constructor called." <<  std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this not_eq &other)
	{
		this->vect = other.vect;
		this->deque = other.deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe destructor called." <<  std::endl;
}

void	PmergeMe::run(int argc, char **argv)
{
	runVector(argc, argv);
	runDeque(argc, argv);
}

void	PmergeMe::printVector(void)
{
	size_t size = vect.size();
	for (size_t i = 0; i < size; i++)
		std::cout << vect[i] << " ";
	std::cout << std::endl;
}

void	PmergeMe::printDeque(void)
{
	size_t size = deque.size();
	for (size_t i = 0; i < size; i++)
		std::cout << deque[i] << " ";
	std::cout << std::endl;
}
