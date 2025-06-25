#pragma once
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contact[8];
		int		nb_contact;
	public:
		PhoneBook();
		void	add_contact();
		void	search_contact();
};

void exit();