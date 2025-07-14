#include "Dog.hpp"

Dog::Dog(): AAnimal(){
	type = "Dog";
	#ifdef DEBUG
		std::cout << YLW << "[debug] " << type << " default constructor called" << RST << std::endl;
	#endif
	brain = new Brain();
}

Dog::~Dog(){
	delete brain;
	std::cout << YLW << "[debug] Dog destructor called" << RST << std::endl;
}

Dog& Dog::operator=( const Dog& other){
	if (this != &other){
		AAnimal::operator=(other);
		type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	#ifdef DEBUG
		std::cout << YLW << "[debug] Dog assignement operator called" << RST << std::endl;
	#endif
	return *this;
}

Dog::Dog( const Dog& other){
	type = other.type;
	brain = new Brain(*other.brain);
	#ifdef DEBUG
		std::cout << YLW << "[debug] Dog copy constructor called" << RST << std::endl;
	#endif
}

void Dog::makeSound() const {
	std::cout << "Woof Woof Woof" << std::endl;
}