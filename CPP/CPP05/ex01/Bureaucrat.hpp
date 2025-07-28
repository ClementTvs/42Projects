#pragma once
#include <iostream>
#include <exception>
#ifdef DEBUG
#define LOG_DEBUG(x) std::cout << "[DEBUG] " << x << std::endl;
#else
#define LOG_DEBUG(x)
#endif

class Bureaucrat{
	private:
		const std::string  _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);

		int getGrade() const;
		const std::string &getName() const;
		void incrementGrade();
		void decrementGrade();

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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);