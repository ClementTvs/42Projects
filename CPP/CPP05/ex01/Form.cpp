#include "Form.hpp"

Form::Form(): _name("Default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {
	LOG_DEBUG("Form default constructor called");
}

Form::~Form(){
	LOG_DEBUG("Form default destructor called");
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExec): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec){
	LOG_DEBUG("Form constructor called");
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other): _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec){
	LOG_DEBUG("Form copy constructor called");
}

Form& Form::operator=(const Form& other){
	LOG_DEBUG("Form assignement operator called");
	if (this != &other){
		_signed = other._signed;
	}
	return *this;
}

int Form::getGradeToSign() const{
	return this->_gradeToSign;
}

int Form::getGradeToExec() const{
	return this->_gradeToExec;
}

bool Form::getSigned() const {
	return this->_signed;
}

const std::string &Form::getName() const {
	return this->_name;
}

bool Form::beSigned( Bureaucrat& bureaucrat ){
	if (bureaucrat.getGrade() <= this->getGradeToSign())
	{
		_signed = true;
		return true;
	}
	else
		throw GradeTooLowException();
	return false;
}

std::ostream& operator<<(std::ostream& out, const Form& Form)
{
	if (Form.getSigned())
	{
		out << Form.getName() << " Form, needs " << Form.getGradeToSign() << " to get signed, " 
			<< Form.getGradeToExec() << " to get executed and is signed";
	}
	else
	{
		out << Form.getName() << " Form, needs " << Form.getGradeToSign() << " to get signed, " 
			<< Form.getGradeToExec() << " to get executed and is not signed";
	}
	return out;
}