#pragma once
#include "ICharacter.hpp"

class Character: public ICharacter{
	private:
		AMateria *_inventory[4];
		std::string _name;

	public:
		Character();
		Character( const std::string name );
		~Character();
		Character( const Character& other);
		Character& operator=( const Character& other);

		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		std::string const& getName() const;
};