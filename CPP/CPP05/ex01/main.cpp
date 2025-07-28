#include "Bureaucrat.hpp"

int main(){
	try {
		Bureaucrat b("b", 149);
		Bureaucrat a( b );
		Bureaucrat d = a;

		std::cout << a << std::endl;
		std::cout << d << std::endl;
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
	} catch (const std::exception& e) {
		std::cout << "Error : " << e.what() << std::endl;
	}

	try {
		Bureaucrat c("c", 2);

		std::cout << c << std::endl;
		c.incrementGrade();
		std::cout << c << std::endl;
		c.incrementGrade();
	} catch (const std::exception& e) {
		std::cout << "Error : " << e.what() << std::endl;
	}

	try {
		Bureaucrat e("b", 151);
	} catch (const std::exception& e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
}