#include "Dog.hpp"

Dog::Dog(): Animal(){
	type = "Dog";
	#ifdef DEBUG
		std::cout << YLW << "[debug] " << type << " default constructor called" << RST << std::endl;
	#endif
}

Dog::~Dog(){
	std::cout << YLW << "[debug] Dog destructor called" << RST << std::endl;
}

Dog& Dog::operator=( const Dog& other){
	(void)other;
	#ifdef DEBUG
		std::cout << YLW << "[debug] Dog assignement operator called" << RST << std::endl;
	#endif
	return *this;
}

Dog::Dog( const Dog& other){
	(void)other;
	#ifdef DEBUG
		std::cout << YLW << "[debug] Dog copy constructor called" << RST << std::endl;
	#endif
}

void Dog::makeSound() const {
	std::cout << "Woof Woof Woof" << std::endl;
}