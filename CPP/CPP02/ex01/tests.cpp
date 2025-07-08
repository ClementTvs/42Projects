#include "Fixed.hpp"
#include <iostream>

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

int main(){
	Fixed a;

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
	
	std::cout << "___________________________________________\n\n";
}