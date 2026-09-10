#include "includes/Serializer.hpp"
#include <iostream>

int main()
{
	Data data;
	data.value = 42;

	Data* original = &data;

	uintptr_t raw = Serializer::serialize(original);
	Data* restored = Serializer::deserialize(raw);

	std::cout << "original:  " << original << std::endl;
	std::cout << "restored:  " << restored << std::endl;
	std::cout << "value:     " << restored->value << std::endl;

	if (original == restored)
		std::cout << "Pointers are equal" << std::endl;
	else
		std::cout << "Pointers are different" << std::endl;

	return 0;
}
