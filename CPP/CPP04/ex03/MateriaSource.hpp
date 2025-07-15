#pragma once
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource{
	private:
		AMateria* _templates[4];
	public:
		MateriaSource();
		~MateriaSource();
		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const& type);
};