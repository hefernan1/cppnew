#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
    this->_type = "Cat";
    std::cout << "Cat has been created."  << std::endl;
}

Cat::Cat(Cat const & src)
{
    *this = src;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << "Cat has been destructed." << std::endl;
}

void    Cat::makeSound(void) const
{
    std::cout << "Miaouuu" << std::endl;
}

Cat &	Cat::operator=(Cat const & rhs)
{
    std::cout << "Cat Assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    return(*this);
}