#pragma once

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog const & src);
		~Dog();
		Dog &	operator=(Dog const & rhs);

		Brain& getBrain(void);
		virtual void	makeSound(void) const;
		virtual void	printAllIdeas(void) const;

	private:
		Brain	*_brain;

};
