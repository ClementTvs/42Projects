#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string& target) : AForm("PPF", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm(){
	LOG_DEBUG("PPF destructor called");
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PPF", 25, 5), _target("default") {
	LOG_DEBUG("PPF default constructor called");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm("PPF", 25, 5){
	LOG_DEBUG("PPF copy constructor called");
	_target = other._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	LOG_DEBUG("PPF assignment operator called")
	if (&other != this)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const{
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}