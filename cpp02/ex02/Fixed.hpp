#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int	_value;
		static const int _fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other); //coppy constructor
		Fixed &operator=(const Fixed &other); //assignment operator
		~Fixed();
		friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed&	min(Fixed& a, Fixed& b);
		static Fixed&	min(Fixed& const a, Fixed& const b);
		static Fixed&	max(Fixed&  a, Fixed&  b);
		static Fixed&	max(Fixed& const a, Fixed& const b);



		/* Comparison operators */
		bool operator<(const Fixed& fixed);
		bool operator<=(const Fixed& fixed);
		bool operator>(const Fixed& fixed);
		bool operator>=(const Fixed& fixed);
		bool operator==(const Fixed& fixed);
		bool operator!=(const Fixed& fixed);
		/* voerload Aritmethic Operators */
		Fixed operator+(const Fixed&) const;
		Fixed operator-(const Fixed&) const;
		Fixed operator/(const Fixed&) const;
		Fixed operator*(const Fixed&) const;


};

#endif