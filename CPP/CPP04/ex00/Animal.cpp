#include "Animal.hpp"

Animal::Animal(){
	type = "";
	#ifdef DEBUG
		std::cout << YLW << "[debug] Animal default constructor called" << RST << std::endl;
	#endif
}

Animal::~Animal(){
	std::cout << YLW << "[debug] Animal destructor called" << RST << std::endl;
}

Animal& Animal::operator=( const Animal& other){
	#ifdef DEBUG
		std::cout << YLW << "[debug] Animal assignement operator called" << RST << std::endl;
	#endif
	if (this != &other){
		type = other.type;
	}
	return *this;
}

Animal::Animal( const Animal& other){
	#ifdef DEBUG
		std::cout << YLW << "[debug] Animal copy constructor called" << RST << std::endl;
	#endif
	type = other.type;
}

void Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

const std::string& Animal::getType() const{
	return type;
}