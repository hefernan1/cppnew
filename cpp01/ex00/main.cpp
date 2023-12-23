#include "Zombie.hpp"

int main(void)
{
	std::cout << "creation of a heapzombie" << std::endl;
	Zombie *heapzombie = newZombie("Heap");
	heapzombie->announce();
	std::cout << "creation of a stackzombie" << std::endl;
	randomChump("stack");
	std::cout << "creation of a stackzombie2" << std::endl;
	randomChump("stack2");
	delete(heapzombie);
	std::cout << "end of the zombies" << std::endl;
	return (0);
}
