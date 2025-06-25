#include "PhoneBook.hpp"

int main() {
	PhoneBook userPhoneBook;
	std::string userInput;

	while (1)
	{
		cin >> userInput;	
		if (userInput == "ADD")
			userPhoneBook.add_contact();
		if (userInput == "SEARCH")
			userPhoneBook.search_contact();
	}
	return 0;
}