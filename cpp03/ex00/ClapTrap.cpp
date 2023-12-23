#include "ClapTrap.hpp"
ClapTrap::ClapTrap(void) : _name("Default"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0){
	std::cout << _name << " has been created" << std::endl;
}

ClapTrap::ClapTrap (std::string Name) : _name(Name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0) {

	std::cout << "ClapTrap " << Name << " appeared !" << std::endl;

}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "Copy constructor called -> " << _name << "has been created" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap (void) {
	std::cout << _name << " has been destructed" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_EnergyPoints > 0)
	{
		this->_EnergyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_AttackDamage
		<< " points of damage! EnergyPoint: " << this->_EnergyPoints << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " has no more energy to attack" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount <= 0 || amount >= 2147483648)
	{
		std::cout << "ClapTrap " << this->_name << " take damage causing 0 points of damage. Total HP: " << this->_HitPoints << std::endl;
		return ;
	}
	if (amount >= this->_HitPoints)
	{
		this->_HitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " take damage causing " << amount << " points of damage. Total HP: " << this->_HitPoints << std::endl;
		return ;
	}
	else
	{
		this->_HitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " take damage causing " << amount << " points of damage. Total HP: " << this->_HitPoints << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_EnergyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no more energy to repaired" << std::endl;
		return ;
	}
	if (amount <= 0 || amount >= 2147483648)
	{
		std::cout << "ClapTrap " << this->_name << " earned 0 Hit Points. Total HP: " << this->_HitPoints << std::endl;
		return ;
	}
	this->_HitPoints += amount;
	this->_EnergyPoints--;
	std::cout << "ClapTrap " << this->_name << " earned " << amount << " Hit Points. Total HP: " << this->_HitPoints << " EnergyPoints: " << this->_EnergyPoints << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name;
		_HitPoints = rhs._HitPoints;
		_EnergyPoints = rhs._EnergyPoints;
		_AttackDamage = rhs._AttackDamage;
	}
	return (*this);
}