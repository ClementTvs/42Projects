#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal(){
	type = "WrongCat";
	#ifdef DEBUG
		std::cout << YLW << "[debug] " << type << " default constructor called" << RST << std::endl;
	#endif
}

WrongCat::~WrongCat(){
	std::cout << YLW << "[debug] WrongCat destructor called" << RST << std::endl;
}

WrongCat& WrongCat::operator=( const WrongCat& other){
	#ifdef DEBUG
		std::cout << YLW << "[debug] WrongCat assignement operator called" << RST << std::endl;
	#endif
	if (this != &other){
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::WrongCat( const WrongCat& other): WrongAnimal::WrongAnimal(other) {
	#ifdef DEBUG
		std::cout << YLW << "[debug] WrongCat copy constructor called" << RST << std::endl;
	#endif
}
