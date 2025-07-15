#pragma once
#include <iostream>
#include "AMateria.hpp"

class Ice: public AMateria{
	public:
		Ice();
		~Ice();
		Ice( const Ice& other);
		Ice& operator=( const Ice& other );
		Ice* clone() const;
		void use(ICharacter& target);
};