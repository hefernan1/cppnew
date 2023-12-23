#pragma once
#include "Weapon.hpp"

class HumanB{
	public:
		HumanB(const std::string& name) : name(name){};
		void	setWeapon(Weapon& newWeapon);
		void	attack() const;
	private:
		std::string name;
		Weapon* weapon;

};