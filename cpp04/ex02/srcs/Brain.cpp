#include "Brain.hpp"

Brain::Brain()
{
	for (int i(0); i < 100; i++)
	{
		_ideas[i] = "I'm hungry";
	}
	std::cout << "Brain has been created." << std::endl;
}

Brain::Brain( Brain const & src )
{
	*this = src;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain has been destructed." << std::endl;
}

Brain &				Brain::operator=( Brain const & rhs )
{
	if ( this != &rhs )
	{
		for (int i(0); i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}

void	Brain::printIdeas(void)
{
	for (int i(0); i < 10; i++)
		std::cout << "idea[" << i << "] = " << this->_ideas[i] << std::endl;
}