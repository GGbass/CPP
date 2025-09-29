#include "Serializer.hpp"

int	main(void)
{
	Data *original = new Data();
	original->id = 30;
	original->content = "Gonzalo";

	std::cout << "Original Data address: " << original << std::endl;
	std::cout << "Original Data id: " << original->id << std::endl;
	std::cout << "Original Data content: " << original->content << std::endl;

	uintptr_t raw = Serializer::serialize(original);
	std::cout << "Serialized Data (as uintptr_t): " << raw << std::endl;
	std::cout << "Size of uintptr_t: " << sizeof(raw) << " bytes" << std::endl;
	Data *deserialized = Serializer::deserialize(raw);

	deserialized->id = 112;
	std::cout << "Deserialized Data address: " << deserialized << std::endl;
	std::cout << "Deserialized Data id: " << deserialized->id << std::endl;
	std::cout << "Deserialized Data content: " << deserialized->content << std::endl;
	delete(original);
	return (0);
}


//serialize: convierte un puntero a un entero sin signo lo suficientemente grande como para contener un puntero (uintptr_t).
//deserialize: convierte un valor entero sin signo (uintptr_t) de nuevo a un puntero a la struct