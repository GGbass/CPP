#include "Serializer.hpp"

int	main(void)
{
	Data *original = new Data();
	original->id = 1;
	original->content = "Hello World";
	std::cout << &original << std::endl;
	uintptr_t raw = Serializer::serialize(original);
	Data *data = Serializer::deserialize(raw);

	std::cout << &data << std::endl;
	std::cout << "ID: " << data->id << std::endl;
	std::cout << "Content: " << data->content << std::endl;
	
	original->id = 2;
	original->content =  "changed";

	std::cout << "ID: " << original->id << std::endl;
	std::cout << "Content: " << original->content << std::endl;
	std::cout << "ID: " << data->id << std::endl;

	delete original;
	return (0);
}
