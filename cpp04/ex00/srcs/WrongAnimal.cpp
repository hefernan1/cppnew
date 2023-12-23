#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << "WrongAnimal has been created."  << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	*this = src;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal has been destructed." << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal make sound" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}


WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & rhs)
{
	std::cout << "WrongAnimal Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return(*this);
}