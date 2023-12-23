#pragma once

#include <string>
#include <iostream>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(AAnimal const & src);
		virtual ~AAnimal();

		AAnimal &	operator=(AAnimal const & rhs);

		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
		virtual void	printAllIdeas(void) const = 0;

	protected:
		std::string	_type;

};