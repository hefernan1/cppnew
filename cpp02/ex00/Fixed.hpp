#pragma once

#include <iostream>
#include <string>

class Fixed {
	private:
		int					_n;
		static const int	_bits = 8;

	public:
		Fixed();
		Fixed(Fixed const & obj);
		~Fixed();

		Fixed	& operator=(Fixed const & rhs);

		int		getRawBits() const;
		void	setRawBits(int const raw);
};
