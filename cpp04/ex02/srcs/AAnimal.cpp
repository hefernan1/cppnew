#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("AAnimal")
{
	std::cout << "AAnimal has been created."  << std::endl;
}

AAnimal::AAnimal(AAnimal const & src)
{
	*this = src;
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal has been destructed." << std::endl;
}

void	AAnimal::makeSound(void) const
{
	std::cout << "AAnimal make sound" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (_type);
}

void	AAnimal::printAllIdeas(void) const
{
	std::cout << "I dont have any Ideas" << std::endl;
}

AAnimal &	AAnimal::operator=(AAnimal const & rhs)
{
	std::cout << "AAnimal Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return(*this);
}