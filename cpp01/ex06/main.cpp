#include "Harl.hpp"

static int	oneArg(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
	{
		std::cout << "Cast your complain level: DEBUG, INFO, WARNING OR ERROR" << std::endl;
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	Harl	harl;

	switch (argc)
	{
		case 1:
			return (oneArg(argc, argv));
		case 2:
			harl.complain(argv[1]);
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}