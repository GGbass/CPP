/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:11:44 by gongarci          #+#    #+#             */
/*   Updated: 2025/12/18 00:00:00 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
#define PmergeMe_HPP
#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>

class PmergeMe
{
	private:
		std::vector<int>	vect;
		std::deque<int>		deque;
		/* vector */
		void				runVector(int argc, char **argv);
		void				mergeInsertVectorSort(std::vector<int>& arr, size_t left, size_t right);
		void				insertionSortVector(std::vector<int>& arr, size_t left, size_t right);
		void				binaryInsertVector(std::vector<int>& arr, int value, size_t upTo);
		/* deque */
		void				mergeInsertionDequeSort(std::deque<int>& arr, size_t left, size_t right);
		void				runDeque(int argc, char **argv);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		void	run(int argc, char **argv);
		void	printVector(void);
		void	printDeque(void);
};

#include "PmergeMe.tpp"

template <typename T, typename U>
size_t binarySearchPos(const T& arr, U value);

#endif
