#include "whatever.hpp"
#include <iostream>
int main(){
	int e = 5;
	int f = 10;
	char h = 'f';
	char i = 'g';

	std::cout << "Original values for int :\n" << "e : " << e << "\n" << "f : " << f << std::endl;
	swap(e, f);
	std::cout << "Swap :\n" << "e : " << e << "\n" << "f : " << f << std::endl;
	std::cout << "Max : " <<  max(e, f) << std::endl;
	std::cout << "Min : " << min(e, f) << std::endl;
	std::cout << "Original values for char :\n" << "h : " << h << "\n" << "i : " << i << std::endl;
	swap(h, i);
	std::cout << "Swap :\n" << "h : " << h << "\n" << "i : " << i << std::endl;
	std::cout << "Max : " <<  max(h, i) << std::endl;
	std::cout << "Min : " << min(h, i) << std::endl;
	//42 tests
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}