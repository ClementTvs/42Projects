#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
	public:
	ScavTrap();
	ScavTrap( const std::string& name );
	~ScavTrap();
	ScavTrap( const ScavTrap& other);
	ScavTrap &operator=( const ScavTrap& other);
	
	void attack( const std::string& target );
	void guardGate();
};