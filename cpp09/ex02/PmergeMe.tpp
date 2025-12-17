/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 23:59:35 by gongarci          #+#    #+#             */
/*   Updated: 2025/12/17 23:59:35 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Helper function: simple binary search to find insertion position
template <typename T, typename U>
size_t binarySearchPos(const T& arr, U value)
{
	size_t	left = 0;
	size_t	right = arr.size();
	
	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}


/* 2 3 1 5 4 8 7 6 9

 Step 1: Pair elements and create larger/smaller deques
smaller				larger
 2					3
 1					5
 4					8
 7					6

 9 (unpaired)

 */