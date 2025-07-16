#include "PhoneBook.hpp"

int main() {
	PhoneBook userPhoneBook;
	std::string userInput;

	while (1)
	{
		std::cout << "Please enter ADD to add a contact, SEARCH to search a contact or EXIT to quit the program" << std::endl;
		if (!std::getline(std::cin, userInput))
			return (0);
		if (userInput == "ADD")
			userPhoneBook.add_contact();
		if (userInput == "SEARCH")
			userPhoneBook.search_contact();
		if (userInput == "EXIT")
			return (0);
	}
	return (0);
}