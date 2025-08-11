#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	try {
		Bureaucrat b("b", 149);
		Bureaucrat a( b );
		Bureaucrat d = a;
		Form formA("form A", 15, 150);

		std::cout << a << std::endl;
		std::cout << d << std::endl;
		std::cout << b << std::endl;
		std::cout << formA << std::endl;
		a.signForm( formA );
		b.decrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
	} catch (const std::exception& e) {
		std::cout << "Error : " << e.what() << std::endl;
	}

	try {
		Bureaucrat c("c", 2);
		Form formB("form B", 15, 150);

		std::cout << c << std::endl;
		c.incrementGrade();
		c.signForm( formB );
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