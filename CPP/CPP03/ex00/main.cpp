#include "ClapTrap.hpp"

void	printTest( const std::string testName ){
	std::string testLine = "___________________________________________\n\n";
	std::cout << testLine << BLUE << testName << RST << "\n\n";

}

int main( void ){
	printTest("Constructor test");
	ClapTrap Joe("Joe");
	printTest("Default constructor test");
	ClapTrap TheMostPowerfulMonsterOfThisUniverse;
	TheMostPowerfulMonsterOfThisUniverse.checkStats();
	printTest("Attack test");
	Joe.attack("the most powerful monster of this universe");
	printTest("Take damage test");
	TheMostPowerfulMonsterOfThisUniverse.takeDamage(0);
	printTest("Repair test");
	TheMostPowerfulMonsterOfThisUniverse.beRepaired(100000);
	printTest("Copy constructor test");
	ClapTrap John( TheMostPowerfulMonsterOfThisUniverse );
	John.checkStats();
	printTest("No more hp test");
	TheMostPowerfulMonsterOfThisUniverse.takeDamage(110000);
	TheMostPowerfulMonsterOfThisUniverse.checkStats();
	TheMostPowerfulMonsterOfThisUniverse.attack("Jhon");
	printTest("Destuctor");
}