#include "AForm.hpp"

AForm::AForm(): _name("Default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {
	LOG_DEBUG("AForm default constructor called");
}

AForm::~AForm(){
	LOG_DEBUG("AForm default destructor called");
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec){
	LOG_DEBUG("AForm constructor called");
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other): _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec){
	LOG_DEBUG("AForm copy constructor called");
}

AForm& AForm::operator=(const AForm& other){
	LOG_DEBUG("AForm assignement operator called");
	if (this != &other){
		_signed = other._signed;
	}
	return *this;
}

int AForm::getGradeToSign() const{
	return this->_gradeToSign;
}

int AForm::getGradeToExec() const{
	return this->_gradeToExec;
}

bool AForm::getSigned() const {
	return this->_signed;
}

const std::string &AForm::getName() const {
	return this->_name;
}

bool AForm::beSigned( Bureaucrat& bureaucrat ){
	if (bureaucrat.getGrade() <= this->getGradeToSign())
	{
		_signed = true;
		return true;
	}
	else
		throw GradeTooLowException();
	return false;
}

void AForm::execute(Bureaucrat const& executor) const{
	(void)executor;
}

std::ostream& operator<<(std::ostream& out, const AForm& AForm)
{
	if (AForm.getSigned())
	{
		out << AForm.getName() << " AForm, needs " << AForm.getGradeToSign() << " to get signed, " 
			<< AForm.getGradeToExec() << " to get executed and is signed";
	}
	else
	{
		out << AForm.getName() << " AForm, needs " << AForm.getGradeToSign() << " to get signed, " 
			<< AForm.getGradeToExec() << " to get executed and is not signed";
	}
	return out;
}