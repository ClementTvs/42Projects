#pragma once
#ifdef DEBUG
#define LOG_DEBUG(x) std::cout << "[DEBUG] " << x << std::endl;
#else
#define LOG_DEBUG(x)
#endif
#include <iostream>
#include <stdint.h>

typedef struct Data{
	int x;
	char c;
}		Data;

class Serializer {
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& other);
		Serializer &operator=(const Serializer& other);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};