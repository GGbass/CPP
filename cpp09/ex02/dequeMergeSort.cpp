#include "PmergeMe.hpp"

/* --------------------- deque method ---------------------------------*/
//this function divide continously the seqeuence into smaller parts
void	PmergeMe::mergeInsertionDequeSort(std::deque<int>& arr, size_t left, size_t right) // divide
{
	(void)arr;
	(void)left;
	(void)right;
	// Base case: use insertion sort for small arrays
	
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
