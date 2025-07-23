#pragma once
# define YLW "\033[93m"
# define BLUE "\033[1;36m"
# define GRN "\033[38;2;0;219;0m"
# define RED "\033[38;2;219;7;21m"
# define RST "\033[0m"
#include <iostream>

class Animal{
	protected:
		std::string type;

	public:
		Animal();
		virtual ~Animal();
		Animal( const Animal& other);
		Animal& operator=( const Animal& other);

		virtual void makeSound() const;
		const std::string& getType() const;
};