#include "HumanB.hpp"

void	HumanB::setWeapon(Weapon& newWeapon) {

	weapon = &newWeapon;

}

void	HumanB::attack() const {
	if (weapon) {
			std::cout << name << " attacks with their " << weapon->getType() << std::endl;
		} 
		else {
			std::cout << name << " is unarmed and cannot attack" << std::endl;
		}
}