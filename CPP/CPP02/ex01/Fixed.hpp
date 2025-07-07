#include <iostream>
#include <cmath>

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
	Fixed(const Fixed &fixcomma);
	Fixed &operator=(const Fixed &);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};
