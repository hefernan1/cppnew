#include "Fixed.hpp"

Fixed::Fixed(void) : _n(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n) : _n(n << this->_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const n) : _n((int)roundf(n * (1 << this->_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) : _n(src._n)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return (this->_n);
}

void	Fixed::setRawBits(int const raw)
{
	this->_n = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float) this->_n / (float)(1 << this->_bits));
}

int		Fixed::toInt(void) const
{
	return (this->_n >> this->_bits);
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &rhs)
		this->_n = rhs.getRawBits();
	return (*this);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}