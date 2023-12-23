#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap " << _name << " has been created." << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << _name << " has been created." << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	std::cout << "ScavTrap Copy constructor called -> " << _name << "has been created" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name  << " has been destructed." << std::endl;
}



void	ScavTrap::guardGate()
{
	std::cout << "Scavtrap " << this->_name << " is now in Gate Keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_EnergyPoints > 0)
	{
		this->_EnergyPoints--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_AttackDamage
		<< " points of damage! EnergyPoint: " << this->_EnergyPoints << std::endl;
	}
	else
	{
		std::cout << "ScavTrap" << this->_name << "has no more energy to attack" << std::endl;
	}
}


ScavTrap &	ScavTrap::operator=(ScavTrap const & rhs)
{
	std::cout << "ScavTrap Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name;
		_HitPoints = rhs._HitPoints;
		_EnergyPoints = rhs._EnergyPoints;
		_AttackDamage = rhs._AttackDamage;
	}
	return (*this);
}