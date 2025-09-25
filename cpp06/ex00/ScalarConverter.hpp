#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP
# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>
# include <cstdlib>

# define NO_PRINTABLE(c) (c < 32 || c > 126)
# define PRINTABLE(c) (c >= 32 && c <= 126)
# define OUT_OF_RANGE(i) (i < -2147483648 || i > 2147483647)


class ScalarConverter
{
	private:
		static int		getType(std::string str);
		static void		printChar(std::string str, int type);
		static void		printInt(std::string str, int type);
		static void		printFloat(std::string str, int type);
		static void		printDouble(std::string str, int type);

	public:
		static void	converter(std::string str);

		ScalarConverter(std::string str);
		ScalarConverter(const ScalarConverter&  other);
		ScalarConverter& operator=(const ScalarConverter& other);
		virtual ~ScalarConverter() = 0;

};

#endif // ScalarConverter_HPP
