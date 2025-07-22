#include "ScavTrap.hpp"

void	printTest( const std::string testName ){
	std::string testLine = "___________________________________________\n\n";
	std::cout << testLine << BLUE << testName << RST << "\n\n";

}

int main( void ){
	printTest("ScavTrap constructor test");
	ScavTrap John("John");
	John.checkStats();

	printTest("ScavTrap attack test");
	John.attack("Joe");
	
	printTest("Take damage test");
	John.takeDamage(20);
	John.checkStats();
	
	printTest("ScavTrap copy constructor test");
	ScavTrap Michel( John );
	Michel.checkStats();
	
	printTest("ScavTrap assignement operator test");
	ScavTrap Jack("Jack");
	Michel = Jack;
	Michel.checkStats();
	
	printTest("ScavTrap guard gate test");
	Michel.guardGate();
	
	printTest("Destuctor");
}