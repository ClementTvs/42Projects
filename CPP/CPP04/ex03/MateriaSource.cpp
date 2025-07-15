#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	#ifdef DEBUG
		std::cout << "[debug] default materia source constructor called" << std::endl;
	#endif
}

MateriaSource::~MateriaSource(){
	#ifdef DEBUG
		std::cout << "[debug] default materia source destructor called" << std::endl;
	#endif
}

void MateriaSource::learnMateria(AMateria* materia){
	if (_templates[4] != 0){
		
	}
}