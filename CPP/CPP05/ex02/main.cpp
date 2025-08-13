#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
	try {
		Bureaucrat b("b", 146);
		Bureaucrat a( "a", 2 );
		Bureaucrat c ( "c", 70);
		ShruberryCreationForm SCF("howqeeqweqweqwe");
		RobotomyRequestForm RRF("Robot");
		PresidentialPardonForm PPF("Michel");

		// SCF.execute(a);
		// RRF.execute(a);
		// PPF.execute(a);
		c.executeForm(PPF);
		a.executeForm(PPF);
	} catch (const std::exception& e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
}