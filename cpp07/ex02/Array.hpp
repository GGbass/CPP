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
		//T getSomething() const ;
};

//todo make a getter for size in order to make a copy constructor and so on
#endif // Array_HPP
