#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : nb_contact(0) {}

void PhoneBook::add_contact(){
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	int			index;

	std::cout << "What's your contact's first name: ";
	std::cin >> firstName;
	std::cout << "What's your contact's last name: ";
	std::cin >> lastName;
	std::cout << "What's your contact's nickname: ";
	std::cin >> nickName;
	std::cout << "What's your contact's phone number: ";
	std::cin >> phoneNumber;
	std::cout << "What's your contact's deepest secret: ";
	std::cin >> darkestSecret;

	index = nb_contact % 8;
	contact[index].setFirstName(firstName);
	contact[index].setLastName(lastName);
	contact[index].setNickName(nickName);
	contact[index].setPhoneNumber(phoneNumber);
	contact[index].setDarkestSecret(darkestSecret);
	nb_contact++;
}

void PhoneBook::search_contact(){
	std::cout << "Who's information do you want to check ?"
	std::cout << std::setw(10) << "Index"
	std::cout << std::setw(10) << "First Name"
	std::cout << std::setw(10) << "Last Name"
	std::cout << std::setw(10) << "NickName"
	for (int i; i < nb_contact; i++;)
	{
		std::cout << std::setw(10) << i;
		std::cout << std::setw(10) << contact[i].firstName;
		std::cout << std::setw(10) << contact[i].lastName;
		std::cout << std::setw(10) << contact[i].nickName;
	}
}