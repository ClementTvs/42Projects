#include "ShruberryCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm( const std::string& target) : AForm("SCF", 145, 137), _target(target) {
	LOG_DEBUG("SCF constructor called");
}

ShruberryCreationForm::~ShruberryCreationForm(){
	LOG_DEBUG("SCF destructor called");
}

ShruberryCreationForm::ShruberryCreationForm() : AForm("SCF", 145, 137), _target("default") {
	LOG_DEBUG("SCF default constructor called");
}

ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm& other) : AForm("SCF", 145, 137){
	LOG_DEBUG("SCF copy constructor called");
	_target = other._target;
}

ShruberryCreationForm& ShruberryCreationForm::operator=(const ShruberryCreationForm& other){
	LOG_DEBUG("SCF assignment operator called")
	if (&other != this)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void ShruberryCreationForm::execute(Bureaucrat const& executor) const{
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	std::string fileName = _target + "_shruberry";
	std::ofstream file(fileName.c_str());

	if (file) {
		file <<
				"            _-_\n"
				"         /~~   ~~\\\n"
				"      /~~         ~~\\\n"
				"     {               }\n"
				"      \\  _-     -_  /\n"
				"        ~  \\\\ //  ~\n"
				"     _- -   | | _- _\n"
				"       _ -  | |   -_\n"
				"           // \\\\\n"
				"             _-_\n"
				"         /~~   ~~\\\n"
				"      /~~         ~~\\\n"
				"     {               }\n"
				"      \\  _-     -_  /\n"
				"        ~  \\\\ //  ~\n"
				"     _- -   | | _- _\n"
				"       _ -  | |   -_\n"
				"           // \\\\\n"
		<< std::endl;
	}
}
