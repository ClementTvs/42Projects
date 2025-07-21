#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->fixcomma = 0;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	this->fixcomma = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other){
		fixcomma = other.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixcomma;
}

void Fixed::setRawBits( int const raw ){
	fixcomma = raw;
}
