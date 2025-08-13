#include "Intern.hpp"

Intern::Intern(){
	LOG_DEBUG("Intern default constructor called");
}

Intern::~Intern(){
	LOG_DEBUG("Intern destructor called");
}

Intern::Intern(const Intern& other){
	LOG_DEBUG("Intern copy constructor called");
	(void)other;
}

Intern& Intern::operator=(const Intern& other){
	LOG_DEBUG("Intern assignement operator called");
	(void)other;
	if (this != &other)
	{}
	return *this;
}

AForm* Intern::createShruberryCreation(const std::string &target){
	return new ShruberryCreationForm(target);
}

AForm* Intern::createPresidentialPardon(const std::string &target){
	return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyRequest(const std::string &target){
	return new RobotomyRequestForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target){
	struct FormAndName {
		const std::string name;
		AForm* (Intern::*func)(const std::string& target);
	};
	FormAndName dictionnary[3] = {
		{"shruberry creation", &Intern::createShruberryCreation},
		{"robotomy request", &Intern::createRobotomyRequest},
		{"presidential pardon", &Intern::createPresidentialPardon}
	};

	for (int i = 0; i < 3; i++){
		if (dictionnary[i].name == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*dictionnary[i].func)(target);
		}
	}
	std::cout << "Form does not exist: " << name << std::endl;
	return NULL;
}
