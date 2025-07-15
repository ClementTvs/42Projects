#include "Character.hpp"

Character::Character(){
	_name = "";
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = 0;
	}
	#ifdef DEBUG
		std::cout << "[debug] default character constructor called" << std::endl;
	#endif
}


Character::~Character(){
	#ifdef DEBUG
		std::cout << "[debug] default character constructor called" << std::endl;
	#endif
}

Character::Character( const std::string name ): _name(name){
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = 0;
	}
	#ifdef DEBUG
		std::cout << "[debug] " << _name << " character constructor called" << std::endl;
	#endif
}

Character::Character( const Character& other ){
	#ifdef DEBUG
		std::cout << "[debug] Character copy constructor called" << std::endl;
	#endif
	_name = other._name;
	for (int i = 0; i < 4; i++){
		if (other._inventory[i] != 0)
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
}

Character Character::operator=( const Character& other ){
	#ifdef DEBUG
		std::cout << "[debug] Character assignement operator called" << std::endl;
	#endif
	if (this != &other){
		_name = other._name;
		for (int i = 0; i < 4; i++){
			if (_inventory[i] != 0){
				delete _inventory[i];
				_inventory[i] = 0;
			}
		}
		for (int i = 0; i < 4; i++){
			if (other._inventory[i] != 0){
				_inventory[i] = other._inventory[i]->clone();
			}
		}
	}
	return *this;
}

void Character::equip(AMateria *m){
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == 0)
		{
			std::cout << _name << " has equiped a new materia" << std::endl;
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << _name << "'s inventory is full!" << std::endl;
}

void Character::unequip(int idx){
	if (idx < 4)
	{
		_inventory[idx] = 0;
		std::cout << _name << " has unequiped a materia!" << std::endl; 
	}
}

void Character::use(int idx, ICharacter& target){
	if (_inventory[idx] != 0 && idx < 4)
		_inventory[idx]->use(target);
	else
		std::cout << "You must equip a Materia to use!" << std::endl;
}

std::string const& Character::getName() const{
	return _name;
}
