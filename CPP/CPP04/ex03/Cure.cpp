#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {
	#ifdef DEBUG
		std::cout << "[debug] Default Cure constructor called" << std::endl;
	#endif
}

Cure::~Cure(){
	#ifdef DEBUG
		std::cout << "[debug] Default Cure destructor called" << std::endl;
	#endif
}

Cure::Cure( const Cure& other ): AMateria( other ){
	#ifdef DEBUG
		std::cout << "[debug] Cure copy constructor called" << std::endl;
	#endif
}

Cure& Cure::operator=( const Cure& other){
	#ifdef DEBUG
		std::cout << "[debug] Cure assignement operator called" << std::endl;
	#endif
	if (this != &other){
		AMateria::operator=(other);
	}
	return *this;
}

Cure* Cure::clone() const{
	Cure *newCure = new Cure();
	return newCure;
}

void Cure::use( ICharacter& target ){
	std::cout << "* heals " << target.getName() << "'s wound *" << std::endl;
}