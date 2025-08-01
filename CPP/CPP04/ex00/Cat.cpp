#include "Cat.hpp"

Cat::Cat(): Animal(){
	type = "Cat";
	#ifdef DEBUG
		std::cout << YLW << "[debug] " << type << " default constructor called" << RST << std::endl;
	#endif
}

Cat::~Cat(){
	std::cout << YLW << "[debug] Cat destructor called" << RST << std::endl;
}

Cat& Cat::operator=( const Cat& other){
	#ifdef DEBUG
		std::cout << YLW << "[debug] Cat assignement operator called" << RST << std::endl;
	#endif
	if (this != &other){
		Animal::operator=(other);
	}
	return *this;
}

Cat::Cat( const Cat& other): Animal::Animal(other) {
	#ifdef DEBUG
		std::cout << YLW << "[debug] Cat copy constructor called" << RST << std::endl;
	#endif
}

void Cat::makeSound() const {
	std::cout << "Meow Meow Meow" << std::endl;
}