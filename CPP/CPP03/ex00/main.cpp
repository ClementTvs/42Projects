#include "ClapTrap.hpp"

void	printTest( const std::string testName ){
	std::string testLine = "___________________________________________\n\n";
	std::cout << testLine << BLUE << testName << RST << "\n\n";

}

int main( void ){
	printTest("Constructor test");
	ClapTrap Joe("Joe");
	printTest("Default constructor test");
	ClapTrap Michel;
	printTest("Attack test");
	Joe.attack("the most powerful monster of this universe");
	printTest("Take damage test");
	Michel.takeDamage(10);
	printTest("Repair test");
	Michel.beRepaired(100000);
	printTest("Destuctor");
}