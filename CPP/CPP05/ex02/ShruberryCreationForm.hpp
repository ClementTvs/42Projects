#pragma once
#include "AForm.hpp"
#include <fstream>

class ShruberryCreationForm : public AForm {
	private:
		std::string _target;

	public:
		ShruberryCreationForm();
		ShruberryCreationForm( const std::string& target );
		~ShruberryCreationForm();
		ShruberryCreationForm(const ShruberryCreationForm& other);
		ShruberryCreationForm& operator=(const ShruberryCreationForm& other);

		void execute(Bureaucrat const& executor) const;
};