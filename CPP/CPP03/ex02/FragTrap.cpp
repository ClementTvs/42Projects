#include "FragTrap.hpp"

FragTrap::FragTrap(){
	std::cout << PYLW << "[debug] FragTrap default constructor called" << RST << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << PYLW << "[debug] FragTrap destructor for " << this->getName() << " called" << RST << std::endl;
}

FragTrap::FragTrap( const std::string& name ){
	std::cout << PYLW << "[debug] FragTrap constructor called" << RST << std::endl;
	this->setName(name);
	this->setAttackDamage(30);
	this->setEnergyPoints(100);
	this->setHitPoints(100);
}

FragTrap	&FragTrap::operator=( const FragTrap& other)
{
	std::cout << PYLW << "[debug] FragTrap assignement operator called" << RST << std::endl;
	if (this != &other)
	{
		this->setName(other.getName());
		this->setAttackDamage(other.getAttackDamage());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setHitPoints(other.getHitPoints());
	}
	return *this;
}

FragTrap::FragTrap( const FragTrap& other){
	std::cout << PYLW << "[debug] FragTrap copy constructor called" << RST << std::endl;
	this->setName(other.getName());
	this->setAttackDamage(other.getAttackDamage());
	this->setEnergyPoints(other.getEnergyPoints());
	this->setHitPoints(other.getHitPoints());
}

void FragTrap::highFiveGuys( void ){
	std::cout << this->getName() << " says: High five !" << std::endl;
}