#include "Serializer.hpp"

int main(){
	Data data;
	data.x = 8;
	data.c = 'c';

	uintptr_t raw = Serializer::serialize(&data);
	Data * recovered = Serializer::deserialize(raw);

	std::cout << "Original data : " << data.x << " Recovered data : " << recovered->x << std::endl;
	std::cout << "Original data : " << data.c << " Recovered data : " << recovered->c << std::endl;
}