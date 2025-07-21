#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
	std::cout << MYLW << "[debug] DiamondTrap default constructor called" << RST << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << MYLW << "[debug] DiamondTrap destructor for " << _name << " called" << RST << std::endl;
}

DiamondTrap::DiamondTrap( const std::string name ): ClapTrap( name + "_clap_name" ), FragTrap(name), ScavTrap(name  + "_clap_name") {
	_name = name;
	_hitPoints = FragTrap::_initHitPoints;
	_energyPoints = ScavTrap::_initEnergyPoints;
	_attackDamage = FragTrap::_initAttackDamage;
	std::cout << MYLW << "[debug] DiamondTrap " << _name << " came into the world safely.." << RST << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& other): ClapTrap(other) {
	std::cout << MYLW << "[debug] DiamondTrap copy constructor called" << RST << std::endl;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& other){
	if (this != &other){
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return *this;
}

void	DiamondTrap::attack(const std::string& target){
	if (_energyPoints > 0)
	{
		std::cout << "DiamondTrap " << _name
				  << " attacks " << target
				  << ", causing " << _attackDamage
				  << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << _name <<" has no more energy left" << std::endl;
}

void	DiamondTrap::whoAmI( void ){
	std::cout << "I am " << _name 
              << ", and my ClapTrap name is " << ClapTrap::_name << std::endl;
}