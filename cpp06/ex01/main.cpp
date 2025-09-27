#include "Serializer.hpp"

int	main(void)
{
	std::string name = "Gonzo";
	std::string lastname = "Garcia";
	std::string fullname = name + " " + lastname;

	std::cout << name + lastname << std::endl;
	std::cout << fullname << std::endl;

	return (0);
}