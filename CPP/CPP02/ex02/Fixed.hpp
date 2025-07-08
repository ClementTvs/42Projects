#include <iostream>
#include <cmath>
# define YLW "\033[33m"
# define RST "\033[0m"

class Fixed
{
private:
	int fixcomma;
	static const int bpf = 8;

public:
	Fixed();
	Fixed( const int nbr );
	Fixed( const float flt );
	~Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	Fixed operator-(const Fixed& fixed);
	Fixed operator+(const Fixed& fixed);
	Fixed operator/(const Fixed& fixed);
	Fixed operator*(const Fixed& fixed);
	bool operator>(const Fixed& fixed) const;
	bool operator>=(const Fixed& fixed);
	bool operator==(const Fixed& fixed);
	bool operator!=(const Fixed& fixed);
	bool operator<(const Fixed& fixed);
	bool operator<=(const Fixed& fixed);
	static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
	static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);
	static Fixed& max(Fixed& fixed1, Fixed& fixed2);
	static Fixed& min(Fixed& fixed1, Fixed& fixed2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);


