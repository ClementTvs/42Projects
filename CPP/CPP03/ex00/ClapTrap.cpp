#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
		:	_name("The most powerful monster of this universe"), _hitPoints(10000), _energyPoints(10000), _attackDamage(10000)
{
	std::cout << YLW << "[debug] Where is this power coming from ?!" << RST << std::endl;
}

ClapTrap::ClapTrap( const std::string& name )
		:	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(10)	
{
	std::cout << YLW << "[debug] " << name << " came into the word safely.." << RST << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << YLW << "[debug] Destructor called" << RST << std::endl;
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
