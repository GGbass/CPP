/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:11:44 by gongarci          #+#    #+#             */
/*   Updated: 2025/12/09 01:29:28 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
#define PmergeMe_HPP
#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <ctime> // clock_t, clock(), CLOCKS_PER_SEC
#include <cstdlib> // atoi

template <typename T>
class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
};

#include "PmergeMe.tpp"

#endif
