#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void	printTest( const std::string testName ){
	std::string testLine = "___________________________________________\n\n";
	std::cout << testLine << testName << "\n\n";

}

// void printResult(const std::string& testName, bool result){
// 	if (result)
// 		std::cout << GRN << "[TEST] " << testName << ": "
// 				  << "✅ OK" << RST;
// 	else
// 		std::cout << RED << "[TEST] " << testName << ": "
// 				  << "❌ KO" << RST;
// 	std::cout << std::endl;
// }

int main(){
	printTest("BASIC TESTS");
	AMateria* cure = new Cure();
	AMateria* ice = new Ice();
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	me->equip(cure);
	me->equip(cure);
	me->equip(ice);
	me->equip(ice);
	me->equip(ice);

	me->use(0, *bob);
	me->use(2, *bob);
	me->unequip(2);
	me->use(2, *bob);
	me->equip(ice);
	delete me;
	delete cure;
	delete ice;
	delete bob;
}