#include "Replacer.hpp"

static void	errorArgvs()
{
	std::cerr << "User must provide exactly 3 arguments." << std::endl;
	std::cerr << "argv[1]: Filename" << std::endl;
	std::cerr << "argv[2]: Search string" << std::endl;
	std::cerr << "argv[3]: Replace string" << std::endl;
	exit(1);
}

int	main(int argc, char **argv)
{
	std::string filename = argv[1];
	std::string search = argv[2];
	std::string replace = argv[3];
	if (argc != 4)
		errorArgvs();

	Replacer replacer(filename, search, replace);
	replacer.fileMaker();
	return (0);
}
