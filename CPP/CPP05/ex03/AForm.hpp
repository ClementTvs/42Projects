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

class AForm{
	private:
		const std::string  _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExec;

	public:
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExec);
		virtual ~AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);

		int getGradeToSign() const;
		int getGradeToExec() const;
		bool getSigned() const;
		const std::string &getName() const;
		bool beSigned( Bureaucrat& bureaucrat );
		virtual void execute(Bureaucrat const& executor) const = 0;

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

std::ostream& operator<<(std::ostream& out, const AForm& AForm);