#include "Fixed.hpp"


Fixed::Fixed (void) : _n(0) 
{
    std::cout << "Default constructor called"  << std::endl;
}

Fixed::Fixed(int const n) : _n(n << this->_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const n) : _n((int)roundf(n * (1 << this->_bits)))
{
	std::cout << "Float constructor called" << std::endl;
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
const Fixed	&	Fixed::min(Fixed & a, Fixed & b)
{
	return (a > b ? b : a);
}

const Fixed	&	Fixed::min(Fixed const & a, Fixed const & b)
{
	return (a > b ? b : a);
}

const Fixed	&	Fixed::max(Fixed & a, Fixed & b)
{
	return (a > b ? a : b);
}

const Fixed	&	Fixed::max(Fixed const & a, Fixed const & b)
{
	return (a > b ? a : b);
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

float	Fixed::toFloat(void) const
{
	return ((float) this->_n / (float)(1 << this->_bits));
}

int		Fixed::toInt(void) const
{
	return (this->_n >> this->_bits);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}
bool	Fixed::operator>(const Fixed & rhs) const
{
	return (_n > rhs._n);
}

bool	Fixed::operator<(const Fixed & rhs) const
{
	return (_n < rhs._n);
}

bool	Fixed::operator>=(const Fixed & rhs) const
{
	return (_n >= rhs._n);
}

bool	Fixed::operator<=(const Fixed & rhs) const
{
	return (_n <= rhs._n);
}

bool	Fixed::operator==(const Fixed & rhs) const
{
	return (_n == rhs._n);
}

bool	Fixed::operator!=(const Fixed & rhs) const
{
	return (_n != rhs._n);
}

Fixed	Fixed::operator+(const Fixed & rhs) const
{
	return (Fixed(toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed & rhs) const
{
	return (Fixed(toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed & rhs) const
{
	return (Fixed(toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed & rhs) const
{
	return (Fixed(toFloat() / rhs.toFloat()));
}

Fixed &	Fixed::operator--(void)
{
	_n--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;

	--(*this);
	return (tmp);
}

Fixed &	Fixed::operator++(void)
{
	_n++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;

	++(*this);
	return (tmp);
}