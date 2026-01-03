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

template <typename T, typename U>
size_t	binarySearchPos(const T& arr, U value)
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

Index:    0  1  2  3  4  5  6  7  8
Input:    2  3  1  5  4  8  7  6  9
          └──┘  └──┘  └──┘  └──┘  └─ unpaired
          (2,3) (1,5) (4,8) (7,6) (9)
For each pair, smaller element → smaller[], larger element → larger[]
Pair (2,3):   2 < 3  → smaller=[2],   larger=[3]
Pair (1,5):   1 < 5  → smaller=[2,1], larger=[3,5]
Pair (4,8):   4 < 8  → smaller=[2,1,4], larger=[3,5,8]
Pair (7,6):   7 > 6  → smaller=[2,1,4,6], larger=[3,5,8,7]

Result:
├─ smaller = [2, 1, 4, 6]
├─ larger = [3, 5, 8, 7]
└─ unpaired = 9
Step 2-5: The Recursion Process (THE KEY PART)
LEVEL 1 (First Call)
mergeInsertVectorSort([2, 3, 1, 5, 4, 8, 7, 6, 9], 0, 8)

├─ Pair and separate:
│  smaller = [2, 1, 4, 6]
│  larger = [3, 5, 8, 7]  ← Will recurse on this
│  unpaired = 9
│
├─ CHECK: Is larger.size() > 1? 
│         Yes (size = 4) → RECURSE
│
└─ RECURSIVE CALL: mergeInsertVectorSort(larger=[3, 5, 8, 7], 0, 3)
                    ↓ (goes to LEVEL 2)

					mergeInsertVectorSort([3, 5, 8, 7], 0, 3)

├─ Create temp from input: temp = [3, 5, 8, 7]
│
├─ Pair and separate (pairs at indices 0-1, 2-3):
│  Pair (3, 5):   3 < 5  → smaller=[3],   larger=[5]
│  Pair (8, 7):   8 > 7  → smaller=[3,7], larger=[5,8]
│  No unpaired
│
│  smaller = [3, 7]
│  larger = [5, 8]
│
├─ CHECK: Is larger.size() > 1?
│         Yes (size = 2) → RECURSE
│
└─ RECURSIVE CALL: mergeInsertVectorSort(larger=[5, 8], 0, 1)
                    ↓ (goes to LEVEL 3)
mergeInsertVectorSort([5, 8], 0, 1)

├─ Create temp: temp = [5, 8]
│
├─ Pair and separate:
│  Pair (5, 8):   5 < 8  → smaller=[5], larger=[8]
│  No unpaired
│
│  smaller = [5]
│  larger = [8]
│
├─ CHECK: Is larger.size() > 1?
│         NO (size = 1) → STOP RECURSION ✓
│
├─ sorted = [8]  (start with larger)
│
├─ Insert smaller[0] = 5 into sorted:
│  binarySearchPos([8], 5) → finds position 0
│  sorted.insert(position 0, 5) → sorted = [5, 8]
│
└─ RETURN sorted = [5, 8]  ↑ (back to LEVEL 2)

Now we have: larger_sorted = [5, 8] (returned from LEVEL 3)

sorted = [5, 8]  (foundation from larger)

Insert smaller = [3, 7]:
  ├─ Insert smaller[0] = 3:
  │  binarySearchPos([5, 8], 3) → finds position 0
  │  sorted.insert(0, 3) → sorted = [3, 5, 8]
  │
  └─ Insert smaller[1] = 7:
     binarySearchPos([3, 5, 8], 7) → finds position 2
     sorted.insert(2, 7) → sorted = [3, 5, 7, 8]

No unpaired in this level

RETURN sorted = [3, 5, 7, 8]  ↑ (back to LEVEL 1)
 */