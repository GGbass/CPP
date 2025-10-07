#include "Array.hpp"

template < typename T >
Array<T>::Array() : arr(NULL), size(0)
{
	std::cout << "Default constructor called" << std::endl;
}

template < typename T >
Array<T>::Array(unsigned int n) : arr(n > 0 ? new T[n] : NULL), size(n)
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
unsigned int	Array<T>::getSize(void) const
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

template <typename T>
const char* Array<T>::OutOfRangeException::what() const throw ()
{
	return ("Out of bounds!\n");
}

template <typename T>
void	Array<T>::printIndex(unsigned int i)
{
	if (i >= 0 && i < this->size)
		std::cout << "content: " << this->arr[i] << std::endl;
}

template <typename T>
void	Array<T>::setIndex(unsigned int i, T content)
{
	if (i >= 0 && i < this->size)
	{
		this->arr[i] = content;
	}
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= this->size)
		throw OutOfRangeException();
	std::cout << "[] operator called" << std::endl;
	return (this->arr[i]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
	if (i >= this->size)
		throw OutOfRangeException();
	std::cout << " const [] operator called" << std::endl;
	return (this->arr[i]);
}
