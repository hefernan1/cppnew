#pragma once

#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(WrongCat const & src);
		~WrongCat();

		WrongCat &	operator=(WrongCat const & rhs);

		void	makeSound(void) const;

};
