#ifndef Array_HPP
# define Array_HPP
# include <iostream>
# include <stdexcept>


template < typename T >
class	Array
{
	//private:

	public:
		T *arr;
		unsigned int size;
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array& operator=(const Array &other);
		~Array();
		int	getSize() const;
		//T getSomething() const ;
};

//todo make a getter for size in order to make a copy constructor and so on

#include "Array.tpp"

#endif // Array_HPP
