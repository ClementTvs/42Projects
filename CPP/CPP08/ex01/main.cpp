#include <iostream>
#include "Span.hpp"

int main()
{
	Span sp = Span(10000);
	std::vector<int> v;
	for (int i = 0; i < 9999; i++) {
		v.push_back(i);
	}

	try {
		sp.addRange(v.begin(), v.end());
		sp.addNumber(-123);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
	return 0;
}