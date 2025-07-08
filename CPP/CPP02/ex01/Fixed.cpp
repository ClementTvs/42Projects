#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->fixcomma = 0;
}

Fixed::Fixed( const float flt ){
	std::cout << "Float constructor called" << std::endl;
	fixcomma = roundf(flt * (1 << bpf));
}

Fixed::Fixed( const int nbr ){
	std::cout << "Int constructor called" << std::endl;
	fixcomma = nbr << bpf;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	getRawBits();
	this->fixcomma = other.fixcomma;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other){
		getRawBits();
		fixcomma = other.fixcomma;
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

float Fixed::toFloat( void ) const{
	return (float)this->fixcomma / (1 << bpf);
}

int Fixed::toInt( void ) const{
	return this->fixcomma >> 8;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed){
	out << fixed.toFloat();
	return out;
}
