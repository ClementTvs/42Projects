#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	type = "";
	#ifdef DEBUG
		std::cout << YLW << "[debug] WrongAnimal default constructor called" << RST << std::endl;
	#endif
}

WrongAnimal::~WrongAnimal(){
	std::cout << YLW << "[debug] WrongAnimal destructor called" << RST << std::endl;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other){
	#ifdef DEBUG
		std::cout << YLW << "[debug] WrongAnimal assignement operator called" << RST << std::endl;
	#endif
	if (this != &other){
		type = other.type;
	}
	return *this;
}

WrongAnimal::WrongAnimal( const WrongAnimal& other){
	#ifdef DEBUG
		std::cout << YLW << "[debug] WrongAnimal copy constructor called" << RST << std::endl;
	#endif
	type = other.type;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound" << std::endl;
}

const std::string& WrongAnimal::getType() const{
	return type;
}