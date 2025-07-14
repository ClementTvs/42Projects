#pragma once
#include "Animal.hpp"

class Brain {
	private:
		std::string ideas[100];
	public:
	Brain();
	~Brain();
	Brain( const Brain& other);
	Brain& operator=( const Brain& other);
};