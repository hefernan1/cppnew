#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    this->_type = "Dog";
    std::cout << "Dog has been created."  << std::endl;
}

Dog::Dog(Dog const & src)
{
    *this = src;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "Dog has been destructed." << std::endl;
}

void    Dog::makeSound(void) const
{
    std::cout << "Wouafff" << std::endl;
}


Dog &	Dog::operator=(Dog const & rhs)
{
    std::cout << "Dog Assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    return(*this);
}
