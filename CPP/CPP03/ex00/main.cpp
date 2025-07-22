#include "ClapTrap.hpp"

void	printTest( const std::string testName ){
	std::string testLine = "___________________________________________\n\n";
	std::cout << testLine << BLUE << testName << RST << "\n\n";

}

int main( void ){
	printTest("Constructor test");
	ClapTrap Joe("Joe");
	Joe.checkStats();

	printTest("Attack test");
	Joe.attack("Monster");

	printTest("Take damage test");
	Joe.takeDamage(5);

	printTest("Repair test");
	Joe.beRepaired(10);

	printTest("Copy constructor test");
	ClapTrap CopyJoe( Joe );
	CopyJoe.checkStats();

	printTest("Assignement operator test");
	ClapTrap Another("Another");
	Another = Joe;
	Another.checkStats();

	printTest("No more hp test");
	Joe.takeDamage(110000);
	Joe.attack("Monster");

	printTest("Destuctor");
}