#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << LYLW << "[debug] ScavTrap default constructor called" << RST << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << LYLW << "[debug] ScavTrap Destructor of " << _name << " called" << RST << std::endl;
}

ScavTrap::ScavTrap( const std::string& name ): ClapTrap( name ){
	std::cout << LYLW << "[debug] ScavTrap " << name << " came into the world safely.." << RST << std::endl;
	_name = name;
	_attackDamage = 20;
	_energyPoints = 50;
	_hitPoints = 100;
}

ScavTrap::ScavTrap( const ScavTrap& other): ClapTrap(other) {
	std::cout << LYLW << "[debug] ScavTrap copy constructor called" << RST << std::endl;
}

ScavTrap	&ScavTrap::operator=( const ScavTrap& other){
	std::cout << LYLW << "[debug] ScavTrap assignement operator called" << RST << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

void	ScavTrap::attack(const std::string& target){
	if (_energyPoints > 0)
	{
		std::cout << "ScavTrap " << _name
				  << " attacks " << target
				  << ", causing " << _attackDamage
				  << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << _name <<" has no more energy left" << std::endl;
}

void	ScavTrap::guardGate(){
	std::cout << _name << " is now in Gate keeper mode" << std::endl;
}