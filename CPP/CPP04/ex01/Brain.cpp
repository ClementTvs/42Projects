#include "Brain.hpp"

Brain::Brain(){
	#ifdef DEBUG
		std::cout << YLW << "[debug] Brain default constructor called" << RST << std::endl;
	#endif
}

Brain::~Brain(){
	std::cout << YLW << "[debug] Brain destructor called" << RST << std::endl;
}

Brain& Brain::operator=( const Brain& other){
	if (this != &other){
		for (int i = 0; i < 100; i++){
			ideas[i] = other.ideas[i];
		}
	}
	#ifdef DEBUG
		std::cout << YLW << "[debug] Brain assignement operator called" << RST << std::endl;
	#endif
	return *this;
}

Brain::Brain( const Brain& other){
	for (int i = 0; i < 100; i++){
		ideas[i] = other.ideas[i];
	}
	#ifdef DEBUG
		std::cout << YLW << "[debug] Brain copy constructor called" << RST << std::endl;
	#endif
}