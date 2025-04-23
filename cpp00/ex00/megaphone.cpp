#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			int	j = 0;
			for (; argv[i][j]; j++)
			{
				std::cout << (char)toupper(argv[i][j]);
			}
			if (i != argc - 1)
				std::cout << " ";
		}
		std::cout << "\n";
	}
	return (0);
}
