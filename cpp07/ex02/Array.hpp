#ifndef Array_HPP
# define Array_HPP
# include <iostream>
# include <stdexcept>


template < typename T >
class	Array
{
	private:
		T *arr;
		unsigned int size;
	public:
		// T *arr;
		// unsigned int size;
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array& operator=(const Array &other);
		~Array();
		unsigned int	getSize() const;
		void	setIndex(unsigned int i, T content);
		void	printIndex(unsigned int i);
		//T getSomething() const ;

	struct OutOfRangeException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#include "Array.tpp"

#endif // Array_HPP
