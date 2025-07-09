#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << LYLW << "[debug] ScavTrap default constructor called" << RST << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << LYLW << "[debug] ScavTrap Destructor of " << this->getName() << " called" << RST << std::endl;
}

ScavTrap::ScavTrap( const std::string& name ){
	std::cout << LYLW << "[debug] " << name << " came into the world safely.." << RST << std::endl;
	this->setName(name);
	this->setAttackDamage(20);
	this->setEnergyPoints(50);
	this->setHitPoints(100);
}

ScavTrap::ScavTrap( const ScavTrap& other){
	std::cout << LYLW << "[debug] ScavTrap copy constructor called" << RST << std::endl;
	this->setName(other.getName());
	this->setAttackDamage(other.getAttackDamage());
	this->setEnergyPoints(other.getEnergyPoints());
	this->setHitPoints(other.getHitPoints());
}

ScavTrap	&ScavTrap::operator=( const ScavTrap& other)
{
	std::cout << LYLW << "[debug] ScavTrap assignement operator called" << RST << std::endl;
	if (this != &other)
	{
		this->setName(other.getName());
		this->setAttackDamage(other.getAttackDamage());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setHitPoints(other.getHitPoints());
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
		this->rmEnergyPoints(1);
	}
	else
		std::cout << this->getName() <<" has no more energy left" << std::endl;
}

void	ScavTrap::guardGate(){
	std::cout << this->getName() << " is now in Gate keeper mode" << std::endl;
}