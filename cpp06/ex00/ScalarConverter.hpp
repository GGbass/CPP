#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP
#include <iostream>

class ScalarConverter
{

	public:
		static void converter(std::string str);

		ScalarConverter();
		ScalarConverter(std::string str);
		ScalarConverter(const ScalarConverter&  other);
		ScalarConverter& operator=(const ScalarConverter& other);
		virtual ~ScalarConverter() = 0;

};

#endif // ScalarConverter_HPP
