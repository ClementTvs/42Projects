#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150){
	LOG_DEBUG("Bureaucrat default constructor called");
}

Bureaucrat::~Bureaucrat(){
	LOG_DEBUG("Bureaucrat default destructor called");
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade){
	LOG_DEBUG("Bureaucrat constructor called");
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name){
	LOG_DEBUG("Bureaucrat copy constructor called");
	_grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	LOG_DEBUG("Bureaucrat assignement operator called");
	if (this != &other){
		_grade = other._grade;
	}
	return *this;
}

int Bureaucrat::getGrade() const{
	return this->_grade;
}

const std::string &Bureaucrat::getName() const {
	return this->_name;
}

void Bureaucrat::incrementGrade(){
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade(){
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}