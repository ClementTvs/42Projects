#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++){
		_templates[i] = NULL;
	}
	#ifdef DEBUG
		std::cout << "[debug] default materia source constructor called" << std::endl;
	#endif
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] != NULL)
			delete _templates[i];
	}
	#ifdef DEBUG
		std::cout << "[debug] default materia source destructor called" << std::endl;
	#endif
}

MateriaSource::MateriaSource( const MateriaSource& other ){
	#ifdef DEBUG
		std::cout << "[debug] MateriaSource copy constructor called" << std::endl;
	#endif
	for (int i = 0; i < 4; i++){
		if (other._templates[i] != NULL)
			_templates[i] = other._templates[i]->clone();
		else
			_templates[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=( const MateriaSource& other ){
	#ifdef DEBUG
		std::cout << "[debug] MateriaSource assignement operator called" << std::endl;
	#endif
	if (this != &other){
		for (int i = 0; i < 4; i++){
			if (_templates[i] != NULL){
				delete _templates[i];
				_templates[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++){
			if (other._templates[i] != NULL){
				_templates[i] = other._templates[i]->clone();
			}
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia){
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] == NULL)
		{
			std::cout << "learned a new materia" << std::endl;
			_templates[i] = materia;
			return ;
		}
	}
	std::cout << "Can't learn more than 4 materias!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const& type){
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] != NULL && type == _templates[i]->getType())
		{
			return _templates[i]->clone();
		}
	}
	std::cout << "Unknown type of materia" << std::endl;
	return (0);
}