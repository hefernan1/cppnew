#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int		main(void)
{
	/*std::cout << "\nConstructors\n--------------" << std::endl;
	FragTrap	Bob("Bob");
	std::cout << "name = " << Bob.getName() <<
		" Hitpoints = " << Bob.getHitPoints() <<
		" Energypoints = " << Bob.getEnergyPoints() <<
		" AttackDMG = " << Bob.getAttackDamage() << std::endl << std::endl;

	ClapTrap	Bill("Bill");
	std::cout << "name = " << Bill.getName() <<
		" Hitpoints = " << Bill.getHitPoints() <<
		" Energypoints = " << Bill.getEnergyPoints() <<
		" AttackDMG = " << Bill.getAttackDamage() << std::endl << std::endl;

	std::cout << "Actions\n--------------" << std::endl;
	Bill.beRepaired(50);
	Bob.attack("Bill");
	Bill.takeDamage(Bob.getAttackDamage());
	Bill.attack("Bob");
	Bob.takeDamage(Bill.getAttackDamage());
	Bob.takeDamage(58);
	Bob.highFivesGuys();
	Bob.beRepaired(100);
	Bob.takeDamage(1000);
	
	std::cout << "\nDestructors\n--------------" << std::endl;
	
	return (0);*/

	std::cout << "\nConstructors\n--------------" << std::endl << std::endl;

	FragTrap a;
	FragTrap b("bob");
	FragTrap c(b);
	FragTrap d("bill");
	a = d;

	std::cout << "Actions\n--------------" << std::endl << std::endl;

	b.highFivesGuys();
	std::cout << "Hp: " << a.getHitPoints() << " Ep: " << a.getEnergyPoints() << " Ad: " << a.getAttackDamage() << " Name: " << a.getName() << std::endl;
	std::cout << "Hp: " << b.getHitPoints() << " Ep: " << b.getEnergyPoints() << " Ad: " << b.getAttackDamage() << " Name: " << b.getName() << std::endl;
	std::cout << "Hp: " << c.getHitPoints() << " Ep: " << c.getEnergyPoints() << " Ad: " << c.getAttackDamage() << " Name: " << c.getName() << std::endl;
	std::cout << "Hp: " << d.getHitPoints() << " Ep: " << d.getEnergyPoints() << " Ad: " << d.getAttackDamage() << " Name: " << d.getName() << std::endl;
	
	std::cout << "\nDestructors\n--------------" << std::endl << std::endl;

	return 0;
}