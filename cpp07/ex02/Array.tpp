#include "Array.hpp"

template < typename T >
Array<T>::Array()
{
	T arr = new T();
	std::cout << "Default constructor called" << std::endl;
}

template < typename T >
Array<T>::Array(unsigned int n) : arr(new T[n])
{
	std::cout << "Constructor called" << std::endl;
}

template < typename T >
Array<T>::Array(const Array &other)
{
	if (this != other)
	{
		std::cout << "Copy constructor called" << std::endl;
	}
}

template < typename T >
Array<T>& Array<T>::operator=(const Array &other)
{
	if (this != other)
	{
		std::cout << "Assigning operator called" << std::endl;
	}
	return (*this);
}

template < typename T >
Array<T>::~Array()
{
	if (arr)
		delete[] arr;
	std::cout << "Destructor called" << std::endl;
}
