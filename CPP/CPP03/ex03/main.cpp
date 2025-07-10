#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void	printTest( const std::string testName ){
	std::string testLine = "___________________________________________\n\n";
	std::cout << testLine << BLUE << testName << RST << "\n\n";

}

int main( void ){
	// printTest("Constructor test");
	// ClapTrap Joe("Joe");
	// printTest("Default constructor test");
	// ClapTrap TheMostPowerfulMonsterOfThisUniverse;
	// TheMostPowerfulMonsterOfThisUniverse.checkStats();
	// printTest("Attack test");
	// Joe.attack("the most powerful monster of this universe");
	// printTest("Take damage test");
	// TheMostPowerfulMonsterOfThisUniverse.takeDamage(0);
	// printTest("Repair test");
	// TheMostPowerfulMonsterOfThisUniverse.beRepaired(100000);
	// printTest("Copy constructor test");
	// ClapTrap Jungor( TheMostPowerfulMonsterOfThisUniverse );
	// Jungor.checkStats();
	// printTest("No more hp test");
	// TheMostPowerfulMonsterOfThisUniverse.takeDamage(110000);
	// TheMostPowerfulMonsterOfThisUniverse.checkStats();
	// TheMostPowerfulMonsterOfThisUniverse.attack("Jungor");
	// printTest("ScavTrap constructor test");
	// ScavTrap John("John");
	// John.checkStats();
	// printTest("ScavTrap attack test");
	// John.attack("Joe");
	// printTest("Take damage test");
	// Joe.takeDamage(20);
	// Joe.checkStats();
	// printTest("ScavTrap copy constructor test");
	// ScavTrap Michel( John );
	// Michel.checkStats();
	// printTest("ScavTrap assignement operator test");
	// ScavTrap Jack("Jack");
	// Michel = Jack;
	// Michel.checkStats();
	// printTest("ScavTrap guard gate test");
	// Michel.guardGate();
	// printTest("FragTrap constructor test");
	// FragTrap Thing("Thing");
	// Thing.checkStats();
	// printTest("FragTrap high five test");
	// Thing.highFiveGuys();
	// printTest("DiamondTrap Test");
	DiamondTrap Harry("Harry");
	// DiamondTrap Mick( Harry );
	// Mick.guardGate();
	Harry.checkStats();
	Harry.guardGate();
	Harry.attack("Michel");
	Harry.highFiveGuys();
	Harry.whoAmI();
	printTest("Destuctor");
}