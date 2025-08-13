#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){
	try {
		Bureaucrat a( "a", 1 );
		Intern someRandomIntern;
		AForm *rrf;
		AForm *scf;
		AForm *ppf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		scf = someRandomIntern.makeForm("shruberry creation", "Michel");
		ppf = someRandomIntern.makeForm("presidential pardon", "Jack");
		a.executeForm(*rrf);
		a.executeForm(*scf);
		a.executeForm(*ppf);
		delete rrf;
		delete scf;
		delete ppf;
	} catch (const std::exception& e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
}