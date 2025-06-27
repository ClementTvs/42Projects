#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : nb_contact(0) {}

int stringToInt(const std::string& str){
	int	number = 0;
	std::stringstream strs(str);
	strs >> number;
	return (number);
}

std::string truncate(std::string str){
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void PhoneBook::add_contact(){
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	int			index;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "What's your contact's first name: ";
	std::getline(std::cin, firstName);
	std::cout << "What's your contact's last name: ";
	std::getline(std::cin, lastName);
	std::cout << "What's your contact's nickname: ";
	std::getline(std::cin, nickName);
	std::cout << "What's your contact's phone number: ";
	std::getline(std::cin, phoneNumber);
	for (std::size_t i = 0; i < phoneNumber.length(); i++)
	{
		if (!std::isdigit(phoneNumber[i]))
		{
			std::cout << "Please enter a correct phone number, only numbers are allowed" << std::endl;
			std::cout << "What's your contact's phone number: ";
			std::getline(std::cin, phoneNumber);
			i = -1;
		}
	}
	std::cout << "What's your contact's deepest secret: ";
	std::getline(std::cin, darkestSecret);

	index = nb_contact % 8;
	contact[index].setFirstName(firstName);
	contact[index].setLastName(lastName);
	contact[index].setNickName(nickName);
	contact[index].setPhoneNumber(phoneNumber);
	contact[index].setDarkestSecret(darkestSecret);
	nb_contact++;
}

void PhoneBook::search_contact(){
	std::string	contactIndex;
	int	index;
	int displayCount;

	std::cout << "Who's information do you want to check ?" << std::endl;
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "NickName" << std::endl;
	displayCount = nb_contact;
	if (displayCount > 8)
	{
		displayCount = 8;
	}
	for (int i = 0; i < displayCount; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(contact[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncate(contact[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncate(contact[i].getNickName())
				  << std::endl;
	}
	std::cout << "Please, enter the index of the contact's you want to check"
			  << std::endl;
	std::cin >> contactIndex;
	for (std::size_t i = 0; i < contactIndex.length(); i++)
	{
		if (!std::isdigit(contactIndex[i]))
		{
			std::cout << "Incorrect index" << std::endl;
			return;
		}
	}
	index = stringToInt(contactIndex);
	if (index < 0 || index >= displayCount)
	{
		std::cout << "This contact does not exist" << std::endl;
		return;
	}
	std::cout << "First Name : " << contact[index].getFirstName() << std::endl
			  << "Last Name : " << contact[index].getLastName() << std::endl
			  << "Nickname : " << contact[index].getNickName() << std::endl
			  << "Phone Number : " << contact[index].getPhoneNumber() << std::endl
			  << "Darkest secret : " << contact[index].getDarkestSecret() << std::endl;
}