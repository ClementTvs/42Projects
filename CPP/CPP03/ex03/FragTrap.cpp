#include "FragTrap.hpp"

FragTrap::FragTrap(){
	std::cout << PYLW << "[debug] FragTrap default constructor called" << RST << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << PYLW << "[debug] FragTrap destructor for " << _name << " called" << RST << std::endl;
}

FragTrap::FragTrap( const std::string& name ): ClapTrap( name ){
	std::cout << PYLW << "[debug] FragTrap " << _name << " came into the world safely.." << RST << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap	&FragTrap::operator=( const FragTrap& other)
{
	std::cout << PYLW << "[debug] FragTrap assignement operator called" << RST << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::FragTrap( const FragTrap& other): ClapTrap( other ) {
	std::cout << PYLW << "[debug] FragTrap copy constructor called" << RST << std::endl;
}

void FragTrap::highFiveGuys( void ){
	std::cout << _name << " says: High five !" << std::endl;
}