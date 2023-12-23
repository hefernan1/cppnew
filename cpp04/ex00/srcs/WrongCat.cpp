#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->_type = "WrongCat";
	std::cout << "WrongCat has been created."  << std::endl;
}

WrongCat::WrongCat(WrongCat const & src)
{
	*this = src;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat has been destructed." << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Miaouuuuuuu" << std::endl;
}

WrongCat &	WrongCat::operator=(WrongCat const & rhs)
{
	std::cout << "WrongCat Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return(*this);
}