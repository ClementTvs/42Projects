#include "AAnimal.hpp"
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
	// AAnimal Test; // Should make a compilation error
	AAnimal* AAnimalTab[10];
	for (int i = 0; i <= 4; i++)
		AAnimalTab[i] = new Dog();
	for (int i = 5; i <= 9; i++)
		AAnimalTab[i] = new Cat();
	for (int i = 0; i <= 9; i++)
		AAnimalTab[i]->makeSound();
	for (int i = 0; i <= 9; i++)
		delete AAnimalTab[i];
}
