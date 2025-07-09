#pragma once
#include <iostream>
# define YLW "\033[93m"
# define LYLW "\033[33m"
# define BLUE "\033[1;36m"
# define RST "\033[0m"

class ClapTrap{
	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
	public:
	ClapTrap();
	ClapTrap( const std::string& name);
	virtual ~ClapTrap();
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	const std::string& getName( void ) const;
	int getHitPoints( void ) const;
	int getEnergyPoints( void ) const;
	int getAttackDamage( void ) const;
	void setEnergyPoints( int nbr );
	void setAttackDamage( int nbr );
	void setHitPoints( int nbr );
	void setName( const std::string& nameToSet );
	void rmEnergyPoints( int amount );
	void checkStats( void );
};
