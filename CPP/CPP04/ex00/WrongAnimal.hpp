#pragma once
# define YLW "\033[93m"
# define BLUE "\033[1;36m"
# define RST "\033[0m"
#include <iostream>

class WrongAnimal{
	protected:
		std::string type;

	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal( const WrongAnimal& other);
		WrongAnimal& operator=( const WrongAnimal& other);

		void makeSound() const;
		const std::string& getType() const;
};