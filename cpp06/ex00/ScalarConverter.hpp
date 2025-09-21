#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP
#include <iostream>

class ScalarConverter
{
	private:
		int		getType(std::string str);

	public:
		static void	converter(std::string str);

		ScalarConverter(std::string str);
		ScalarConverter(const ScalarConverter&  other);
		ScalarConverter& operator=(const ScalarConverter& other);
		virtual ~ScalarConverter() = 0;

};

#endif // ScalarConverter_HPP
