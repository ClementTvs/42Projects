#pragma once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"

class Intern {
	public:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);

		AForm* makeForm(const std::string& name, const std::string& target);

		AForm* createShruberryCreation(const std::string &target);
		AForm* createPresidentialPardon(const std::string &target);
		AForm* createRobotomyRequest(const std::string &target);
};