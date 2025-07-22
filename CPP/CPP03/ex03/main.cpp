#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void	printTest( const std::string testName ){
	std::string testLine = "___________________________________________\n\n";
	std::cout << testLine << BLUE << testName << RST << "\n\n";

}

int main( void ){
	printTest("DiamondTrap Test");
	DiamondTrap Harry("Harry");
	Harry.checkStats();
	Harry.guardGate();
	Harry.attack("Michel");
	Harry.highFiveGuys();
	Harry.whoAmI();
	
	printTest("Destuctor");
}