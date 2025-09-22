#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(std::string str)
{
	ScalarConverter::converter(str);
	std::cout << "Param constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter&  other)
{
	if (this != &other)
	{
		std::cout << "Copy constructor called" << std::endl;
	}
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this != &other)
	{
		std::cout << "Assigning operator called" << std::endl;
	}
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor calle" << std::endl;
}

void ScalarConverter::converter(std::string str)
{
	int	type = ScalarConverter::getType(str);
	if (type == -1)
	{
		std::cout << "Error: Invalid argument" << std::endl;
		return ;
	}
	ScalarConverter::printConversion(type, str);
}

/* get the base
	char
	int
	float
	double
 */

int	ScalarConverter::getType(std::string str)
{
	bool	dot_found = false;
	int		sign = 0;
	size_t	i = 0;

	if (str.length() == 1 && !isdigit(str[0]))
		return (0); // char
	if (str[0] == '-' || str[0] == '+')
	{
		i++;
		sign = 1;
	}
	while (i < str.length())
	{
		if (str[i] == '.')
		{
			if (dot_found)
				return (-1); // invalid
			dot_found = true;
		}
		else if (!isdigit(str[i]))
		{
			if (str[i] == 'f' && i == str.length() - 1 && dot_found)
				return (2); // float
			/* return (-1); */
		}
		i++;
	}
	if (dot_found)
		return (1); // double
	return (3); // int
}

void	ScalarConverter::printConversion(int type, std::string str)
{
	char	c;
	int		i;
	float	f;
	double	d;
	(void)type;
	c = static_cast<char>(str[0]);
	if (NO_PRINTABLE(c))
		std::cout << "Non displayable" << std::endl;
/* 	else if (type != 0)
		std::cout << "char: impossible" << std::endl; */
	else if (type == 2)
		std::cout << "char: *" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	/* check int */
	std::stringstream(str) >> i;
	std::cout << "int: " << i << std::endl;

	/* check float */
	std::stringstream(str) >> f;
	std::cout << "float: " << f << "f" << std::endl;
	/* check double */
	std::stringstream(str) >> d;
	std::cout << "double: " << d << std::endl;
	std::cout << "Converter called with param: " << str << std::endl;
}


/* Printing

For char: if non-printable (ASCII < 32 or = 127), print “Non displayable.”

For any impossible cast, print “impossible.”

Always append f to float outputs and set precision (.1 minimum).
*/