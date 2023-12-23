#include "Zombie.hpp"

Zombie::Zombie(){};

Zombie::Zombie(std::string name) : name(name){};

Zombie::~Zombie(void)
{
	std::cout << this->name << " is destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_Name(std::string name)
{
	this->name = name; 
}
