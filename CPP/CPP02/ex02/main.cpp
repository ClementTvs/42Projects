#include <iostream>
#include "Fixed.hpp"

void assertFixed( Fixed expected, Fixed actual, const std::string& testName ){
	if (expected == actual)
		std::cout << "\033[32m" << "[OK] " << testName << "\033[0m" << std::endl;
	else
		std::cout << "[FAIL] " << testName
				  << " | Expected: " << expected
				  << ", Got: " << actual << std::endl;
}

void assertFixedBool( bool expected, bool actual, const std::string& testName ){
	if (expected == actual)
		std::cout << "\033[32m" << "[OK] " << testName << "\033[0m" << std::endl;
	else
		std::cout << "[FAIL] " << testName
				  << " | Expected: " << expected
				  << ", Got: " << actual << std::endl;
}

void assertFixedFloat( float expected, float actual, const std::string& testName ){
	if (expected == actual)
		std::cout << "\033[32m" << "[OK] " << testName << "\033[0m" << std::endl;
	else
		std::cout << "[FAIL] " << testName
				  << " | Expected: " << expected
				  << ", Got: " << actual << std::endl;
}

void assertFixedDefault( int expected, int actual, const std::string& testName ){
	if (expected == actual)
		std::cout << "\033[32m" << "[OK] " << testName << "\033[0m" << std::endl;
	else
		std::cout << "[FAIL] " << testName
				  << " | Expected: " << expected
				  << ", Got: " << actual << std::endl;
}

int main( void ) {
	std::cout << "___________________________________________\n\n";
	std::cout << "\033[1;36m" << "42 Main:\n\n" << "\033[0m";

	Fixed a;
	Fixed const c( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << c << std::endl;

	std::cout << Fixed::max( a, c ) << std::endl;
	a = Fixed( 0 );

	std::cout << "___________________________________________\n\n";
	std::cout << "\033[1;36m" << "Test 1:\n\n" << "\033[0m";
	assertFixedDefault(0, a.getRawBits(), "Initial number");
	
	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 2:\n\n" << "\033[0m";
	a = Fixed( 10.75f );

	assertFixedDefault(2752, a.getRawBits(), "Fixed point float number");

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 3:\n\n" << "\033[0m";
	a = Fixed( 234 );

	assertFixedDefault(59904, a.getRawBits(), "Fixed point int number");

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 4:\n\n" << "\033[0m";
	a.setRawBits(59);

	assertFixedDefault(59, a.getRawBits(), "setRawBits function");

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 5:\n\n" << "\033[0m";
	Fixed b(a);

	assertFixedDefault(a.getRawBits(), b.getRawBits(), "Copy constructor");

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 6:\n\n" << "\033[0m";
	b = Fixed( 129 );

	assertFixedDefault(59, a.getRawBits(), "Original stay unchanged");

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 7:\n\n" << "\033[0m";
	
	assertFixedFloat(129.0, b.toFloat(), "toFloat() function");

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 8:\n\n" << "\033[0m";
	a = Fixed( 234.213f );
	
	assertFixedDefault(234, a.toInt(), "toInt() function");

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 9:\n\n" << "\033[0m";
	a = Fixed( 234.5f );

	std::cout << a << std::endl;
	std::cout << "\033[32m" << "[OK] " << "<< operator" << "\033[0m" << std::endl;

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 10:\n\n" << "\033[0m";
	b = Fixed( 56.9f );

	std::cout << a + b << std::endl;
	std::cout << "\033[32m" << "[OK] " << "+ operator" << "\033[0m" << std::endl;

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 11:\n\n" << "\033[0m";

	std::cout << a - b << std::endl;
	std::cout << "\033[32m" << "[OK] " << "- operator" << "\033[0m" << std::endl;

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 12:\n\n" << "\033[0m";

	std::cout << a * b << std::endl;
	std::cout << "\033[32m" << "[OK] " << "* operator" << "\033[0m" << std::endl;

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 13:\n\n" << "\033[0m";

	std::cout << a / b << std::endl;
	std::cout << "\033[32m" << "[OK] " << "/ operator" << "\033[0m" << std::endl;

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 14:\n\n" << "\033[0m";

	assertFixedBool(true, a > b, "> operator");
	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 15:\n\n" << "\033[0m";

	assertFixedBool(true, b < a, "< operator");

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 16:\n\n" << "\033[0m";

	assertFixedBool(false, a == b, "== operator");

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 17:\n\n" << "\033[0m";

	assertFixedBool(true, a >= b, ">= operator");

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 18:\n\n" << "\033[0m";

	assertFixedBool(true, b <= a, "<= operator");

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 19:\n\n" << "\033[0m";

	assertFixedBool(true, a != b, "!= operator");

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 20:\n\n" << "\033[0m";
	a = Fixed( 0 );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << "\033[32m" << "[OK] " << "Pre incrementation" << "\033[0m" << std::endl;

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 21:\n\n" << "\033[0m";

	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << "\033[32m" << "[OK] " << "Post incrementation" << "\033[0m" << std::endl;

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 22:\n\n" << "\033[0m";

	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << "\033[32m" << "[OK] " << "Pre decrementation" << "\033[0m" << std::endl;

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 23:\n\n" << "\033[0m";

	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << "\033[32m" << "[OK] " << "Post decrementation" << "\033[0m" << std::endl;

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 24:\n\n" << "\033[0m";
	const Fixed& minConst = Fixed::min(a, b);
	assertFixed(a, minConst, "const min function");

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 25:\n\n" << "\033[0m";
	const Fixed& maxConst = Fixed::max(a, b);

	assertFixed(b, maxConst, "const max function");

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 26:\n\n" << "\033[0m";

	assertFixed(a, Fixed::min(a, b), "min function");

	std::cout << "___________________________________________\n\n" << "\033[1;36m" << "Test 27:\n\n" << "\033[0m";

	assertFixed(b, Fixed::max(a, b), "max function");
	std::cout << "___________________________________________\n\n";
	return 0;
}