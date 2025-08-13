#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string& target) : AForm("RRF", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm(){
	LOG_DEBUG("RRF destructor called");
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RRF", 72, 45), _target("default") {
	LOG_DEBUG("RRF default constructor called");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("RRF", 72, 45){
	LOG_DEBUG("RRF copy constructor called");
	_target = other._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	LOG_DEBUG("RRF assignment operator called")
	if (&other != this)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}
void RobotomyRequestForm::execute(Bureaucrat const& executor) const{
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	srand(time(NULL));

	std::cout << "DRRRRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;
	if (rand() % 2 == 1)
	{
		std::cout << _target << " has successfully been robotomized" << std::endl;
	}
	else
		std::cout << "Robotomization failed" << std::endl;
}