#include "Array.hpp"

template < typename T >
Array<T>::Array() : arr(NULL), size(0)
{
	//T arr = new T();
	std::cout << "Default constructor called" << std::endl;
}

template < typename T >
Array<T>::Array(unsigned int n) : arr(new T[n]), size(n)
{
	std::cout << "Constructor called" << std::endl;
}

template < typename T >
Array<T>::Array(const Array &other) : arr(NULL), size(other.size)
{
	if (this != &other)
	{
		if (size > 0)
		{
			this->arr = new T[size];
			for (unsigned int i = 0; i < size; i++)
			{
				this->arr[i] = other.arr[i];
			}
		}
		std::cout << "Copy constructor called" << std::endl;
	}
}

template < typename T >
Array<T>& Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		if (arr)
			delete[] arr;
		
		size = other.size;
		if (size > 0)
		{
			arr = new T[size];
			for (unsigned int i = 0; i < size; i++)
				arr[i] = other.arr[i];
		}
		else
			arr = NULL;
		
		std::cout << "Assignment operator called" << std::endl;
	}
	return (*this);
}

template < typename T >
int	Array<T>::getSize(void) const
{
	return (this->size);
}


template < typename T >
Array<T>::~Array()
{
	if (arr)
		delete[] arr;
	std::cout << "Destructor called" << std::endl;
}
