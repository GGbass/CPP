#include "PmergeMe.hpp"

/* --------------------- deque method ---------------------------------*/
//this function divide continously the seqeuence into smaller parts
void	PmergeMe::mergeInsertionDequeSort(std::deque<int>& arr, size_t left, size_t right)
{
	std::deque<int> temp;
	for (size_t i = left; i <= right; i++)
		temp.push_back(arr[i]);

	// Step 1: Pair elements and create larger/smaller deques
	std::deque<int> larger;
	std::deque<int> smaller;
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
		mergeInsertionDequeSort(larger, 0, larger.size() - 1);
	// Step 3: Use the now-sorted "larger" elements as the foundation
	// The "larger" vector now contains sorted values from the pairs.
	// "smaller" contains the elements that were smaller in each pair.
	
	// Step 4: Insert smaller elements into the sorted larger sequence
	std::deque<int> sorted = larger;
	if (not smaller.empty())
	{
		size_t pos = binarySearchPos(sorted, smaller[0]);
		sorted.insert(sorted.begin() + pos, smaller[0]);
	}
	// Insert remaining smaller elements
	for (size_t i = 1; i < smaller.size(); i++)
	{
		// int value = smaller[i];
		size_t pos = binarySearchPos(sorted, smaller[i]);
		sorted.insert(sorted.begin() + pos, smaller[i]);
	}
	// Step 5: Insert unpaired element
	if (hasUnpaired)
	{
		size_t pos = binarySearchPos(sorted, unpaired);
		sorted.insert(sorted.begin() + pos, unpaired);
	}
	for (size_t i = 0; i < sorted.size(); i++)
		arr[i] = sorted[i];
	return ;
}

void	PmergeMe::runDeque(int argc, char **argv)
{
	std::cout << "--- DEQUE ---" << std::endl;
	std::cout << "Before: ";
	clock_t	start = clock();

	for (int i = 1; i < argc; i++)
		this->deque.push_back(atoi(argv[i]));

	this->printDeque();
	mergeInsertionDequeSort(this->deque, 0, this->deque.size() - 1);
	clock_t end = clock();
	std::cout << "After:  ";
	this->printDeque();
	std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : "
			  << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
}
