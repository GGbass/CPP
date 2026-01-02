/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorMergeSort.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 23:59:04 by gongarci          #+#    #+#             */
/*   Updated: 2025/12/17 23:59:04 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Binary search insertion for a single element
void	PmergeMe::binaryInsertVector(std::vector<int>& arr, int value, size_t upTo)
{
	size_t	left = 0;
	size_t	right = upTo;

	// Binary search to find insertion position
	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	
	// Insert element at found position
	arr.insert(arr.begin() + left, value);
}

void	PmergeMe::mergeInsertVectorSort(std::vector<int>& arr, size_t left, size_t right)
{
	std::vector<int> temp;
	for (size_t i = left; i <= right; i++)
		temp.push_back(arr[i]);
	// Step 1: Pair elements and create larger/smaller vectors 
	std::vector<int> larger;
	std::vector<int> smaller;
	int		unpaired = -1;
	bool	hasUnpaired = false;
	
	for (size_t i = 0; i + 1 < temp.size(); i += 2)
	{
		if (temp[i] < temp[i + 1])
		{
			smaller.push_back(temp[i]);
			larger.push_back(temp[i + 1]);
		}
		else
		{
			smaller.push_back(temp[i + 1]);
			larger.push_back(temp[i]);
		}
	}
	
	// Handle odd element
	if (temp.size() % 2 == 1)
	{
		unpaired = temp[temp.size() - 1];
		hasUnpaired = true;
	}
	
	// Step 2: Recursively sort larger elements
	if (larger.size() > 1)
		mergeInsertVectorSort(larger, 0, larger.size() - 1);
	
	// Step 3: Use the now-sorted "larger" elements as the foundation
	// The "larger" vector now contains sorted values from the pairs.
	// "smaller" contains the elements that were smaller in each pair.
	
	// Step 4: Insert smaller elements into the sorted larger sequence
	std::vector<int> sorted = larger;  // Start with sorted larger elements
	
	// for (size_t i = 0; i < sorted.size() - 1; i++)
	// 	std::cout << "-- " << sorted[i] << " ";
	// Insert smaller[0] (which pairs with larger[0])
/* 	if (not smaller.empty())
	{
		// Find correct position for smaller[0]
		size_t pos = binarySearchPos(sorted, smaller[0]);
		sorted.insert(sorted.begin() + pos, smaller[0]);
	}

	// Insert remaining smaller elements
	for (size_t i = 1; i < smaller.size(); i++)
	{
		int value = smaller[i];
		size_t pos = binarySearchPos(sorted, value);
		sorted.insert(sorted.begin() + pos, value);
	} */
	for (size_t i = 0; i < smaller.size(); i++)
	{
		int value = smaller[i];
		size_t pos = binarySearchPos(sorted, value);
		sorted.insert(sorted.begin() + pos, value);
	}
	
	// Step 5: Insert unpaired element
	if (hasUnpaired)
	{
		size_t pos = binarySearchPos(sorted, unpaired);
		sorted.insert(sorted.begin() + pos, unpaired);
	}

	// Copy sorted result back to original array
	for (size_t i = 0; i < sorted.size() && left + i <= right; i++)
	{
		arr[left + i] = sorted[i];
	}
}

void	PmergeMe::runVector(int argc, char **argv)
{
	std::cout << "--- VECTOR ---" << std::endl;
	std::cout << "Before: ";
	clock_t	start = clock();

	for (int i = 1; i < argc; i++)
		this->vect.push_back(atoi(argv[i]));

	this->printVector();
	mergeInsertVectorSort(this->vect, 0, this->vect.size() - 1);
	clock_t	end = clock();
	double	runTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "After: ";
	this->printVector();
		std::cout << "Time to process a range of " << vect.size() << " elements with std::vector : "
			  << runTime << " ms" << std::endl;
}
