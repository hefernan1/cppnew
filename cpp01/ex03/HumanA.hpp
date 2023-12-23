#pragma once
#include "Weapon.hpp"


class HumanA{
	public:
		HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {};
		void	attack() const;
	private:
		std::string name;
		Weapon& weapon;
};