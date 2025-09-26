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
	int		type = getType(str);
	if (type == -1)
	{
		std::cout << "Error: Invalid argument" << std::endl;
		return ;
	}
	printChar(str, type);
	printInt(str, type);
	printFloat(str, type);
	printDouble(str, type);
}

int	ScalarConverter::getType(std::string str)
{
	bool	dot_found = false;
	int		sign = 0;
	size_t	i = 0;

	if (str.length() == 1 && !isdigit(str[0]) && PRINTABLE(str[0]))
		return (0); // char
	if (str[0] == '-' || str[0] == '+')
	{ 
		i++;
		sign = 1;
		if (!isdigit(str[i]))
			return (-1);
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
			if (str[i] == 'f' && str[i + 1] == '\0' && dot_found)
				return (2); // float
			if (sign)
			return (-1);
		}
		i++;
	}
	if (dot_found)
		return (1); // double
	return (3); // int
}

void	ScalarConverter::printChar(std::string str, int type)
{
	char	c;
	c = static_cast<char>(atoi(str.c_str()));
	(void)type;
	if (PRINTABLE(c))
		std::cout << "char: " << c << std::endl;
	else if (str.length() >= 3)
		std::cout << "char: Impossible" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void	ScalarConverter::printInt(std::string str, int type)
{
	int		i = atoi(str.c_str());
	double	d = atof(str.c_str());

	if (d != d)
		std::cout << "int: Impossible" << std::endl;
	else if (type == 1 || type == 2 || (type == 3 && str.length() < 11))
	{
		if (OUT_OF_RANGE(d))
		{
			std::cout << "int: Impossible" << std::endl;
			return ;
		}
		std::cout << "int: " << i << std::endl;
	}
	else
		std::cout << "int: Impossible" << std::endl;
}

void	ScalarConverter::printFloat(std::string str, int type)
{
	float	f = static_cast<float>(atof(str.c_str()));

	if (f != f)
		std::cout << "float: nanf" << std::endl;
	else if (type == 1 || type == 2 || (type == 3 && str.length() < 11))
	{
		if (OUT_OF_RANGE(f))
		{
			//
			std::cout << "float: Impossible" << std::endl;
			return ;
		}
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f" << std::endl;
	}
	else
		std::cout << "float: Impossible" << std::endl;
}

void	ScalarConverter::printDouble(std::string str, int type)
{
	double	d = static_cast<double>(atof(str.c_str()));
	if (d != d)
		std::cout << "double: nan" << std::endl;
	else if (type == 1 || type == 2 || (type == 3 && str.length() < 11))
	{
		if (OUT_OF_RANGE(d))
		{
			std::cout << "double: Impossible" << std::endl;
			return ;
		}
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "double: " << d  << std::endl;
	}
	else
		std::cout << "double: Impossible" << std::endl;
}
