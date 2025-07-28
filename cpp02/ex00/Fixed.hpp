#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &other); // copy constructor
		Fixed &operator=(const Fixed &other); // assignment operator
		//friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
	
	private:
		int	_value;
		static const int	_fractionalBits = 8;
};

#endif