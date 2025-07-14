#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

void	printTest( const std::string testName ){
	std::string testLine = "___________________________________________\n\n";
	std::cout << testLine << BLUE << testName << RST << "\n\n";

}

void printResult(const std::string& testName, bool result){
	if (result)
		std::cout << GRN << "[TEST] " << testName << ": "
				  << "✅ OK" << RST;
	else
		std::cout << RED << "[TEST] " << testName << ": "
				  << "❌ KO" << RST;
	std::cout << std::endl;
}

int	main() {
	printTest("42 TESTS");
	// const Animal* meta = new Animal();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	// i->makeSound();
	// j->makeSound();
	// meta->makeSound();
	// delete j;
	// delete i;
	// delete meta;
	// const WrongAnimal* a = new WrongAnimal();
	// const WrongAnimal* b = new WrongCat();
	// std::cout << b->getType() << " " << std::endl;
	// b->makeSound();
	// a->makeSound();
	// delete b;
	// delete a;
	Animal* AnimalTab[10];
	for (int i = 0; i <= 4; i++)
		AnimalTab[i] = new Dog();
	for (int i = 5; i <= 9; i++)
		AnimalTab[i] = new Cat();
	for (int i = 0; i <= 9; i++)
		AnimalTab[i]->makeSound();
	for (int i = 0; i <= 9; i++)
		delete AnimalTab[i];
	// printTest("Animal TESTS");
	// Animal Joe;
	// Animal Mike( Joe );
	// Animal Alex;
	// Alex = Joe;
	// Alex.makeSound();
	// printTest("Cat TESTS");
	// Cat JoeCat;
	// Cat MikeCat( JoeCat );
	// Cat AlexCat;
	// AlexCat = JoeCat;
	// printResult("Cat getType() == 'Cat'", AlexCat.getType() == "Cat");
	// AlexCat.makeSound();
	// printTest("Dog TESTS");
	// Dog JoeDog;
	// Dog MikeDog( JoeDog );
	// Dog AlexDog;
	// AlexDog = JoeDog;
	// printResult("Dog getType() == 'Dog'", AlexDog.getType() == "Dog");
	// AlexDog.makeSound();
	// printTest("Destructors");
}
