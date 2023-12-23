#include "Fixed.hpp"


Fixed::Fixed () : _n(0) 
{
    std::cout << "Default constructor called"  << std::endl;
}
Fixed::Fixed(Fixed const & obj) : _n(obj._n)
{
    std::cout << "Copy constructor called" << std::endl;
}

int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;

    return (this->_n);
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        _n = rhs.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

void    Fixed::setRawBits(int const raw)
{
    this->_n = raw;
}