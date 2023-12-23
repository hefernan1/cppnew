#include "ClapTrap.hpp"

int		main(void)
{
	ClapTrap	lol("lol");
	ClapTrap	lil("lil");

	lol.attack("lil");
	lil.takeDamage(8);
	lil.attack("lol");
	lol.takeDamage(42);
	lol.takeDamage(-42);
	lol.beRepaired(45);
	lil.beRepaired(3);
	lil.beRepaired(1);
	lil.beRepaired(1);
	lil.beRepaired(1);
	lil.beRepaired(1);
	lil.beRepaired(50);
	lil.beRepaired(1);
	lil.beRepaired(1);
	lil.beRepaired(1);
	lil.beRepaired(1);
	lil.beRepaired(1);
	lil.attack("lol");
	lil.attack("lol");
	
	return (0);
}