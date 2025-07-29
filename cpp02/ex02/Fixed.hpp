#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &other); //coppy constructor
		Fixed &operator=(const Fixed &other); //assignment operator
		~Fixed();
		friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

		Fixed& min(Fixed& a, Fixed& b);

	private:
		int	_value;
		static const int _fractionalBits = 8;
};

#endif