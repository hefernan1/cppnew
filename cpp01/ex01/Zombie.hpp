#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <iomanip>
# include <string>

class	Zombie
{
	private:
		std::string name;

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
		void	set_Name(std::string name);
};

Zombie* zombieHorde(int N, std::string name);
#endif