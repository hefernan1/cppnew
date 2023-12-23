#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << "Wrong number, must be positive\n" << std::endl;
		return (NULL);
	}
	Zombie *zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombieHorde[i].set_Name(name);
	return (zombieHorde);
}