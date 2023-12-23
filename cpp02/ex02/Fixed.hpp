#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
	private:
		int					_n;
		static int const	_bits = 8;

	public:
		Fixed(void);
		Fixed(float const n);
		Fixed(int const n);
		Fixed(Fixed const & obj);
		~Fixed(void);

		Fixed	& operator=(Fixed const & rhs);

		bool	operator>(const Fixed & rhs) const;
		bool	operator<(const Fixed & rhs) const;
		bool	operator>=(const Fixed & rhs) const;
		bool	operator<=(const Fixed & rhs) const;
		bool	operator==(const Fixed & rhs) const;
		bool	operator!=(const Fixed & rhs) const;

		Fixed	operator+(const Fixed & rhs) const;
		Fixed	operator-(const Fixed & rhs) const;
		Fixed	operator*(const Fixed & rhs) const;
		Fixed	operator/(const Fixed & rhs) const;
		Fixed 	&operator--(void);
		Fixed	operator--(int);
		Fixed 	&operator++(void);
		Fixed	operator++(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

		static const Fixed	&min(Fixed & a, Fixed & b);
		static const Fixed	&min(Fixed const & a, Fixed const & b);
		static const Fixed	&max(Fixed & a, Fixed & b);
		static const Fixed	&max(Fixed const & a, Fixed const & b);
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

