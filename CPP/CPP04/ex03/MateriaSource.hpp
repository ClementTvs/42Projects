#pragma once
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class AMateria;

class MateriaSource: public IMateriaSource{
	private:
		AMateria* _templates[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource( const MateriaSource& other);
		MateriaSource& operator=( const MateriaSource& other);
		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const& type);
};