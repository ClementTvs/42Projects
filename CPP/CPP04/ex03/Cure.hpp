#pragma once
#include <iostream>
#include "AMateria.hpp"

class Cure: public AMateria{
	public:
		Cure();
		~Cure();
		Cure( const Cure& other);
		Cure& operator=( const Cure& other );
		Cure* clone() const;
		void use(ICharacter& target);
};