#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP
# include <iostream>
# include <string>
# include <sstream>

# define NO_PRINTABLE(c) (c < 32 || c > 126)


class ScalarConverter
{
	private:
		static int		getType(std::string str);
		static void		printConversion(int type, std::string str);

	public:
		static void	converter(std::string str);

		ScalarConverter(std::string str);
		ScalarConverter(const ScalarConverter&  other);
		ScalarConverter& operator=(const ScalarConverter& other);
		virtual ~ScalarConverter() = 0;

};

#endif // ScalarConverter_HPP
