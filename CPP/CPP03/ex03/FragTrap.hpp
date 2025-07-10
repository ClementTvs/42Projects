#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
	public:
	FragTrap();
	FragTrap( const std::string& name );
	FragTrap( std::string& name );
	~FragTrap();
	FragTrap( const FragTrap& other);
	FragTrap &operator=( const FragTrap& other);
	void highFiveGuys( void );
	protected:
	static int const _initHitPoints = 100;
	static int const _initEnergyPoints = 100;
	static int const _initAttackDamage = 30;
};