#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void	printTest( const std::string testName ){
	std::string testLine = "___________________________________________\n\n";
	std::cout << testLine << BLUE << testName << RST << "\n\n";

}

int main( void ){
	printTest("FragTrap constructor test");
	FragTrap Thing("Thing");
	Thing.checkStats();
	
	printTest("FragTrap high five test");
	Thing.highFiveGuys();
	
	printTest("Destuctor");
}