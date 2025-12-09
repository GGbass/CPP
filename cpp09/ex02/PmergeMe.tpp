/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:11:20 by gongarci          #+#    #+#             */
/*   Updated: 2025/12/09 01:29:11 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


template <typename T>
PmergeMe<T>::PmergeMe()
{
	std::cout << "PmergeMe default constructor called." <<  std::endl;
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe& other)
{
	(void)other;
}

template <typename T>
PmergeMe<T>& PmergeMe<T>::operator=(const PmergeMe& other)
{
	if (this not_eq &other)
	{
		// Copy member variables here if there are any
	}
	return (*this);
}

template <typename T>
PmergeMe<T>::~PmergeMe()
{
	std::cout << "PmergeMe destructor called." <<  std::endl;
}
