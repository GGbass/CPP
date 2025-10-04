#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>


template < typename T >
void	printer(T val)
{
	std::cout << val << std::endl;
}

template <typename T>
void	iter(T const *array, size_t length, void (*function)(T))
{

	if (!array)
		return ;
	for (size_t i = 0; i < length; i++)
	{
		function(array[i]);
	}
}

#endif