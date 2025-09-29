#ifndef Serializer_HPP
#define Serializer_HPP
#include <iostream>
#include <stdint.h>

struct Data
{
	int			id;
	std::string	content;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		virtual ~Serializer() = 0;

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif // Serializer_HPP
