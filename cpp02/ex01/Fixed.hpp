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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);
