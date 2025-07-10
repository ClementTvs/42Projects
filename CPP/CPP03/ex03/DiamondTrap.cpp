#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
	std::cout << MYLW << "[debug] DiamondTrap default constructor called" << RST << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << MYLW << "[debug] FragTrap destructor for " << _name << " called" << RST << std::endl;
}

DiamondTrap::DiamondTrap( const std::string name ): ClapTrap( name + "_clap_name"), FragTrap(name), ScavTrap(name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
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
		std::cout << "DiamonTrap " << _name
				  << " attacks " << target
				  << ", causing " << _attackDamage
				  << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << _name <<" has no more energy left" << std::endl;
}
