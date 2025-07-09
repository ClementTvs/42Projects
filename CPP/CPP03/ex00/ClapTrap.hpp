#pragma once
#include <iostream>
# define YLW "\033[33m"
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
	~ClapTrap();
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
