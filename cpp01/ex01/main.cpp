#include "Zombie.hpp"

int main(void)
{
	int N = 5;
	int n = 0;
	std::string zombieName = "John";
	std::cout << "creation of a zombie horde with wrong argument\n" << std::endl;
	Zombie *zombies1 = zombieHorde(n, zombieName);
	std::cout << "creation of a zombie horde\n" << std::endl;
	Zombie *zombies = zombieHorde(N, zombieName);
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete [] zombies;
	delete [] zombies1;
	std::cout << "End of the zombies" << std::endl;
	return (0);
}
