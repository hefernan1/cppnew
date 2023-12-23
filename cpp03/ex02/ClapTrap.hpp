#pragma once

#include <iostream>
#include <string>

class	ClapTrap {

	protected:
		std::string _name;
		unsigned int _HitPoints;
		unsigned int _EnergyPoints;
		unsigned int _AttackDamage;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		~ClapTrap(void);
		ClapTrap(ClapTrap const & src);

		ClapTrap &	operator=(ClapTrap const & rhs);

		std::string		getName(void);
		unsigned int	getHitPoints(void);
		unsigned int	getEnergyPoints(void);
		unsigned int	getAttackDamage(void);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};