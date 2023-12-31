#pragma once

#include <string>
#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const & src);
		virtual	~WrongAnimal();

		WrongAnimal &	operator=(WrongAnimal const & rhs);

		void			makeSound(void) const;
		std::string		getType(void) const;

	protected:
		std::string	_type;
};