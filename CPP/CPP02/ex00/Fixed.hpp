#include <iostream>

class Fixed
{
private:
	int fixcomma;
	static const int bpf = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &fixcomma);
	Fixed &operator=(const Fixed &);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

