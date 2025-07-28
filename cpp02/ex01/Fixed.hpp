#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other); // copy constructor
		Fixed &operator=(const Fixed &other); // assignment operator
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		// Overload the insertion operator for output
		friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
	
	private:
		int	_value;
		static const int	_fractionalBits = 8;
};

#endif