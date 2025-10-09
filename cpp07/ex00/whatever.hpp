#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>

class Awesome
{
	private:
		int _n;
	public:
		Awesome(void): _n(0) {}
		Awesome(int n): _n(n) {}

		Awesome & operator=(Awesome& a);
		bool operator==(Awesome const & rhs) const;
		bool operator!=(Awesome const & rhs) const;
		bool operator>(Awesome const & rhs) const;
		bool operator<(Awesome const & rhs) const;
		bool operator>=(Awesome const & rhs) const;
		bool operator<=(Awesome const & rhs) const;
		int	get_n() const {return (_n);}
};
/* << overlaod */
std::ostream & operator<<(std::ostream & os, const Awesome &a) { os << a.get_n(); return (os);}
/* operators overloads */
Awesome & Awesome::operator=(Awesome& a) { _n = a._n; return (*this); }
bool Awesome::operator==(Awesome const & rhs) const { return (this->_n == rhs._n); }
bool Awesome::operator!=(Awesome const & rhs) const { return (this->_n != rhs._n); }
bool Awesome::operator>(Awesome const & rhs) const { return (this->_n > rhs._n); }
bool Awesome::operator<(Awesome const & rhs) const { return (this->_n < rhs._n); }
bool Awesome::operator>=(Awesome const & rhs) const { return (this->_n >= rhs._n); }
bool Awesome::operator<=(Awesome const & rhs) const { return (this->_n <= rhs._n); }

template <typename T>
void swap(T &a, T &b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T a, T b)
{
	if (a >= b)
		return (b);
	return (a);
}

template <typename T >
T max(T a, T b)
{
	if (a >= b)
		return (a);
	return (b);
}
#endif
