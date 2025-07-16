#include "AMateria.hpp"

AMateria::AMateria(){
	#ifdef DEBUG
		std::cout << "[debug] AMateria default constructor called" << std::cout;	
	#endif
}

AMateria::AMateria( std::string const& type ){
	_type = type;
	#ifdef DEBUG
		std::cout << "[debug] AMateria constructor called" << std::cout;	
	#endif
}

AMateria::~AMateria(){
	#ifdef DEBUG
		std::cout << "[debug] AMateria default destructor called" << std::cout;	
	#endif
}

AMateria::AMateria( const AMateria& other ){
	_type = other._type;
	#ifdef DEBUG
		std::cout << "[debug] AMateria copy constructor called" << std::cout;	
	#endif
}

AMateria &AMateria::operator=( const AMateria& other){
	if (this != &other){
		_type = other._type;
	}
	#ifdef DEBUG
		std::cout << "[debug] AMateria assignement operator called" << std::cout;	
	#endif
	return *this;
}

void AMateria::use( ICharacter& target){
	(void)target;
}

std::string const& AMateria::getType() const{
	return _type;
}
