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

int main(){
	printTest("BASIC TESTS");
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");

	AMateria* materia0;
	AMateria* materia1;
	AMateria* materia2;
	AMateria* materia3;
	AMateria* materia4;
	materia0 = src->createMateria("ice");
	me->equip(materia0);
	materia1 = src->createMateria("ca");
	me->equip(materia1);
	materia2 = src->createMateria("cure");
	me->equip(materia2);
	materia3 = src->createMateria("cure");
	me->equip(materia3);
	materia4 = src->createMateria("cure");
	me->equip(materia4);

	ICharacter* bob = new Character("bob");


	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	me->unequip(2);
	delete materia3;
	materia3 = src->createMateria("cure");
	me->equip(materia3);
	me->use(2, *bob);
	std::cout << "Hi my name is " << bob->getName() << std::endl;
	delete me;
	delete src;
	delete bob;
}