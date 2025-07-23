#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal{
	private:
		Brain* brain;

	public:
		Dog();
		~Dog();
		Dog( const Dog& other);
		Dog& operator=( const Dog& other);

		void makeSound() const;
};