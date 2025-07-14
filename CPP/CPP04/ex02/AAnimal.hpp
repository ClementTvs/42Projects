#pragma once
# define YLW "\033[93m"
# define BLUE "\033[1;36m"
# define GRN "\033[38;2;0;219;0m"
# define RED "\033[38;2;219;7;21m"
# define RST "\033[0m"
#include <iostream>

class AAnimal{
	protected:
		std::string type;
	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal( const AAnimal& other);
		AAnimal& operator=( const AAnimal& other);
		virtual void makeSound() const = 0;
		const std::string& getType() const;
};