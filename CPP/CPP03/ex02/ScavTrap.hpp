#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
	private:

	public:
	ScavTrap();
	ScavTrap( const std::string& name );
	ScavTrap( std::string& name );
	~ScavTrap();
	ScavTrap( const ScavTrap& other);
	ScavTrap &operator=( const ScavTrap& other);
	void attack( const std::string& target );
	void guardGate();
};