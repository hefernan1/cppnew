#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Animal has been created."  << std::endl;
}

Animal::Animal(Animal const & src)
{
	*this = src;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal has been destructed." << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal make sound" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}



Animal &	Animal::operator=(Animal const & rhs)
{
	std::cout << "Animal Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return(*this);
}