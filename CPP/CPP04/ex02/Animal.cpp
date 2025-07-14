#include "AAnimal.hpp"

AAnimal::AAnimal(){
	type = "";
	#ifdef DEBUG
		std::cout << YLW << "[debug] AAnimal default constructor called" << RST << std::endl;
	#endif
}

AAnimal::~AAnimal(){
	std::cout << YLW << "[debug] AAnimal destructor called" << RST << std::endl;
}

AAnimal& AAnimal::operator=( const AAnimal& other){
	(void)other;
	#ifdef DEBUG
		std::cout << YLW << "[debug] AAnimal assignement operator called" << RST << std::endl;
	#endif
	return *this;
}

AAnimal::AAnimal( const AAnimal& other){
	(void)other;
	#ifdef DEBUG
		std::cout << YLW << "[debug] AAnimal copy constructor called" << RST << std::endl;
	#endif
}

void AAnimal::makeSound() const {
	std::cout << "AAnimal sound" << std::endl;
}

const std::string& AAnimal::getType() const{
	return type;
}