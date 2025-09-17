#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

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

void	ScalarConverter::converter(std::string str)
{
	if (str.empty())
	{
		std::cout << "Converter called with empty param" << std::endl;
		return ;
	}
	std::cout << "Converter called with param: " << str << std::endl;
}
