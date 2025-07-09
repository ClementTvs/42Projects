#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << LYLW << "[debug] ScavTrap default constructor called" << RST << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << LYLW << "[debug] ScavTrap destructor called" << RST << std::endl;
}

ScavTrap::ScavTrap( const std::string& name ){
	std::cout << LYLW << "[debug] ScavTrap constructor called" << RST << std::endl;
	this->setName(name);
	this->setAttackDamage(20);
	this->setEnergyPoints(50);
	this->setHitPoints(100);
}

ScavTrap::ScavTrap( const ScavTrap& other){
	(void)other;
	std::cout << LYLW << "[debug] ScavTrap copy constructor called" << RST << std::endl;
}

ScavTrap	&ScavTrap::operator=( const ScavTrap& other)
{
	if (this != &other)
	{
		std::cout << "ScavTrap assignement operator called" << std::endl;
	}
	return *this;
}

void	ScavTrap::attack(const std::string& target){
	if (this->getEnergyPoints() > 0)
	{
		std::cout << "ScavTrap " << this->getName()
				  << " attacks " << target
				  << ", causing " << this->getAttackDamage()
				  << " points of damage!" << std::endl;
		this->setEnergyPoints(1);
	}
	else
		std::cout << this->getName() <<" has no more energy left" << std::endl;
}

void	ScavTrap::guardGate(){
	std::cout << this->getName() << " is now in Gate keeper mode" << std::endl;
}