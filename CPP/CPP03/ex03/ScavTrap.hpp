#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
	public:
	ScavTrap();
	ScavTrap( const std::string& name );
	ScavTrap( std::string& name );
	~ScavTrap();
	ScavTrap( const ScavTrap& other);
	ScavTrap &operator=( const ScavTrap& other);
	virtual void attack( const std::string& target );
	void guardGate();
};