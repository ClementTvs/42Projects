#pragma once
#include <iostream>
#include <exception>
#ifdef DEBUG
#define LOG_DEBUG(x) std::cout << "[DEBUG] " << x << std::endl;
#else
#define LOG_DEBUG(x)
#endif
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	private:
		const std::string  _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExec;

	public:
		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExec);
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);

		int getGradeToSign() const;
		int getGradeToExec() const;
		bool getSigned() const;
		const std::string &getName() const;
		bool beSigned( Bureaucrat& bureaucrat );

		class GradeTooHighException: public std::exception{
			public:
				virtual const char* what() const throw(){
					return "Grade too high !";
				}
		};

		class GradeTooLowException: public std::exception{
			public:
				virtual const char* what() const throw(){
					return "Grade too low !";
				}
		};
};

std::ostream& operator<<(std::ostream& out, const Form& Form);