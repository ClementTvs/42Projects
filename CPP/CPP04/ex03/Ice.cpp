#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {
	#ifdef DEBUG
		std::cout << "[debug] Default Ice constructor called" << std::endl;
	#endif
}

Ice::~Ice(){
	#ifdef DEBUG
		std::cout << "[debug] Default Ice destructor called" << std::endl;
	#endif
}

Ice::Ice( const Ice& other ): AMateria( other ){
	#ifdef DEBUG
		std::cout << "[debug] Ice copy constructor called" << std::endl;
	#endif
}

Ice& Ice::operator=( const Ice& other){
	#ifdef DEBUG
		std::cout << "[debug] Ice assignement operator called" << std::endl;
	#endif
	if (this != &other){
		AMateria::operator=(other);
	}
	return *this;
}

Ice* Ice::clone() const{
	Ice *newIce = new Ice();
	return newIce;
}

void Ice::use( ICharacter& target ){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}