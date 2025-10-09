#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

class Awesome
{
	private:
		int _n;
	public:
		Awesome(void): _n(42) {return;}

		int	get_n() const {return (this->_n);}
		Awesome & operator=(const Awesome& rhs);
		bool operator==(Awesome const & rhs) const;
		bool operator!=(Awesome const & rhs) const;
		bool operator>(Awesome const & rhs) const;
		bool operator<(Awesome const & rhs) const;
		bool operator>=(Awesome const & rhs) const;
		bool operator<=(Awesome const & rhs) const;

};
/* << overlaod */
std::ostream & operator<<(std::ostream & os, const Awesome &a) { os << a.get_n(); return (os);}
/* operators overloads */
Awesome & Awesome::operator=(const Awesome& a) {this->_n = a._n; return (*this); }
bool Awesome::operator==(Awesome const & rhs) const { return (this->_n == rhs._n); }
bool Awesome::operator!=(Awesome const & rhs) const { return (this->_n != rhs._n); }
bool Awesome::operator>(Awesome const & rhs) const { return (this->_n > rhs._n); }
bool Awesome::operator<(Awesome const & rhs) const { return (this->_n < rhs._n); }
bool Awesome::operator>=(Awesome const & rhs) const { return (this->_n >= rhs._n); }
bool Awesome::operator<=(Awesome const & rhs) const { return (this->_n <= rhs._n); }

template< typename T >
void	print(T const & x) {std::cout << x << std::endl; return ;}



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
		function(array[i]);
}

#endif