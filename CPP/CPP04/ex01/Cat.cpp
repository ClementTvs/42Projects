#include "Cat.hpp"

Cat::Cat(): Animal(){
	type = "Cat";
	#ifdef DEBUG
		std::cout << YLW << "[debug] " << type << " default constructor called" << RST << std::endl;
	#endif
	brain = new Brain();
}

Cat::~Cat(){
	delete brain;
	std::cout << YLW << "[debug] Cat destructor called" << RST << std::endl;
}

Cat& Cat::operator=( const Cat& other){
	if (this != &other){
		Animal::operator=(other);
		type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	#ifdef DEBUG
		std::cout << YLW << "[debug] Cat assignement operator called" << RST << std::endl;
	#endif
	return *this;
}

Cat::Cat( const Cat& other){
	type = other.type;
	brain = new Brain(*other.brain);
	#ifdef DEBUG
		std::cout << YLW << "[debug] Cat copy constructor called" << RST << std::endl;
	#endif
}

void Cat::makeSound() const {
	std::cout << "Meow Meow Meow" << std::endl;
}