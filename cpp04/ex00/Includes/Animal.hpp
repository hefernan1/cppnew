#pragma once 

#include <string>
#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(Animal const & src);
		virtual ~Animal();

		Animal &	operator=(Animal const & rhs);

		virtual	void	makeSound(void) const;
		std::string		getType(void) const;

	protected:
		std::string	_type;
};			