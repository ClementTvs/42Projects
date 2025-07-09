#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
		:	_name("DefaultConstructor"), _hitPoints(10000), _energyPoints(10000), _attackDamage(10000)
{
	std::cout << YLW << "[debug] ClapTrap default constructor called" << RST << std::endl;
}

ClapTrap::ClapTrap( const std::string& name )
		:	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(10)	
{
	std::cout << YLW << "[debug] " << name << " came into the word safely.." << RST << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << YLW << "[debug] Destructor of " << this->_name << " called" << RST << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& other){
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap& other)
		:	_name(other._name), _hitPoints(other._hitPoints),
			_energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << YLW << "[debug] Copy constructor called" << RST << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
	std::cout << this->_name << " took " << amount << " points of damage!" << std::endl;
	this->_hitPoints -= amount;
}
void	ClapTrap::attack(const std::string& target){
	if (this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " attacks " << target
				  << ", causing " << this->_attackDamage
				  << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
	else
		std::cout << this->_name <<" has no more energy left" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name
		  << " is repairing himself for " << amount
		  << " HP!" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints -= 1;
	}
	else
		std::cout << this->_name <<" has no more energy left" << std::endl;
}

int		ClapTrap::getAttackDamage( void ){
	return this->_attackDamage;
}

int		ClapTrap::getHitPoints( void ){
	return this->_hitPoints;
}

int		ClapTrap::getEnergyPoints( void ){
	return this->_energyPoints;
}

const std::string& ClapTrap::getName( void ){
	return this->_name;
}

void	ClapTrap::setEnergyPoints( int nbr ){
	this->_energyPoints -= nbr;
}

void	ClapTrap::setHitPoints( int nbr ){
	this->_hitPoints += nbr;
}

void	ClapTrap::setAttackDamage( int nbr ){
	this->_energyPoints -= nbr;
}

void		ClapTrap::setName( const std::string& nameToSet ){
	this->_name = nameToSet;
}