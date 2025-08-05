#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int	_value;
		static const int _fractionalBits;

	public:
		Fixed();
		Fixed(const Fixed &other); //coppy constructor
		Fixed &operator=(const Fixed &other); //assignment operator
		~Fixed();
		friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
		
		Fixed (const int value);
		Fixed (const float value);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const	Fixed&	max(const Fixed& a, const Fixed& b);



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
		/* Increment and Decrement Operators */
		Fixed& operator++(); // pre-increment
		Fixed operator++(int); // post-increment
		Fixed& operator--(); // pre-decrement
		Fixed operator--(int); // post-decrement

};


#endif