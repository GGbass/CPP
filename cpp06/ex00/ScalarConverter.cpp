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
	int	type = ScalarConverter::checkType(str);
	switch (type)
	{
		case 0:
			std::cout << "Detected type: char" << std::endl;
			break;
		case 1:
			std::cout << "Detected type: double" << std::endl;
			break;
		case 2:
			std::cout << "Detected type: float" << std::endl;
			break;
		case 3:
			std::cout << "Detected type: int" << std::endl;
			break;
		default:
			std::cout << "Detected type: invalid" << std::endl;
			break;
	}
	std::cout << "Converter called with param: " << str << std::endl;
}

/* void	ScalarConverter::converter(std::string str)
{
	if (str.empty())
	{
		std::cout << "Converter called with empty param" << std::endl;
		return ;
	}
	char	c = static_cast<char>(str[0]);
	int		i = static_cast<int>(str[0]);
	float	f = static_cast<float>(str[0]);
	double	d = static_cast<double>(str[0]);
	if (c < 32 || c > 126 && str.length() == 1)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	if (str.length() > 1)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	if ()
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
	std::cout << "Converter called with param: " << str << std::endl;
} */

int ScalarConverter::getType(std::string str)
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
	for (; i < str.length(); i++)
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
			return (-1);
		}
	}
	if (dot_found)
		return (1); // double
	return (3); // int
}



/* Printing

For char: if non-printable (ASCII < 32 or = 127), print “Non displayable.”

For any impossible cast, print “impossible.”

Always append f to float outputs and set precision (.1 minimum).
*/