#include "PhoneBook.hpp"

int main() {
	PhoneBook userPhoneBook;
	std::string userInput;

	while (1)
	{
		std::cout << "Please enter ADD to add a contact, SEARCH to search a contact or EXIT to quit the program" << std::endl;
		getline(std::cin, userInput);
		if (userInput == "ADD")
			userPhoneBook.add_contact();
		if (userInput == "SEARCH")
			userPhoneBook.search_contact();
		if (userInput == "EXIT")
			return (0);
	}
	return (0);
}