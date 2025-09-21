#include "ScalarConverter.hpp"

static std::string getInputString(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return ("");
	}
	if (argv[1] == NULL || argv[1][0] == '\0')
	{
		std::cout << "Error: Empty argument" << std::endl;
		return ("");
	}
	return (argv[1]);
}

int	main(int argc, char **argv)
{
	std::string param = getInputString(argc, argv);
	if (param.empty() || param == "")
	{
		return (1);
	}
	ScalarConverter::converter(param);
	return (0);
}
