#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << YLW << "[debug]Default constructor called" << RST << std::endl;
	this->fixcomma = 0;
}

Fixed::Fixed( const float flt ){
	std::cout << YLW << "[debug]Float constructor called" << RST << std::endl;
	fixcomma = roundf(flt * (1 << bpf));
}

Fixed::Fixed( const int nbr ){
	std::cout << YLW << "[debug]Int constructor called" << RST << std::endl;
	fixcomma = nbr << bpf;
}

Fixed::~Fixed(){
	std::cout << YLW << "[debug]Destructor called" << RST << std::endl;
}

Fixed::Fixed(const Fixed &other){
	std::cout << YLW << "[debug]Copy constructor called" << RST << std::endl;
	getRawBits();
	this->fixcomma = other.fixcomma;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << YLW << "[debug]Copy assignement operator called" << RST << std::endl;
	if (this != &other){
		getRawBits();
		fixcomma = other.fixcomma;
	}
	return *this;
}

int Fixed::getRawBits( void ) const{
	std::cout << YLW << "[debug]getRawBits member function called" << RST << std::endl;
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

Fixed Fixed::operator+(const Fixed& fixed){
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed& fixed){
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed& fixed){
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed& fixed){
	return Fixed(this->toFloat() / fixed.toFloat());
}

bool Fixed::operator>(const Fixed& fixed) const {
	if (this->toFloat() > fixed.toFloat())
		return true;
	return false;
}

bool Fixed::operator<(const Fixed& fixed){
	if (this->toFloat() < fixed.toFloat())
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed& fixed){
	if (this->toFloat() >= fixed.toFloat())
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed& fixed){
	if (this->toFloat() <= fixed.toFloat())
		return true;
	return false;
}

bool Fixed::operator==(const Fixed& fixed){
	if (this->toFloat() == fixed.toFloat())
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed& fixed){
	if (this->toFloat() != fixed.toFloat())
		return true;
	return false;
}

Fixed Fixed::operator++(){
	this->fixcomma++;
	return *this;
}

Fixed Fixed::operator--(){
	this->fixcomma--;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed temp = *this;
	++(*this);
	return temp;
}

Fixed Fixed::operator--(int){
	Fixed temp = *this;
	--(*this);
	return temp;
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2){
	if (fixed1 > fixed2)
		return fixed2;
	return fixed1;
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2){
	if (fixed1 > fixed2)
		return fixed1;
	return fixed2;
}

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2){
	if (fixed1 > fixed2)
		return fixed2;
	return fixed1;
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2){
	if (fixed1 > fixed2)
		return fixed1;
	return fixed2;
}