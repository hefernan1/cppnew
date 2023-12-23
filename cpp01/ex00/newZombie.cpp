#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie *HeapZombie = new Zombie(name);
	return (HeapZombie);
}