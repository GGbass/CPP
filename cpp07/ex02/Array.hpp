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
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array& operator=(const Array &other);
		~Array();

		T& operator[](unsigned int i);
		const T& operator[](unsigned int i) const;
		unsigned int	getSize() const;
		void			setIndex(unsigned int i, T content);
		void			printIndex(unsigned int i);
		void			printArray(void);

	struct OutOfRangeException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array);
/* {
for (unsigned int i = 0; i < array.getSize(); i++)
		os << array[i] << std::endl;
	return (os);
} */

#include "Array.tpp"

#endif
