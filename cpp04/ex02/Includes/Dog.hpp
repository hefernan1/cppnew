#pragma once

#include <string>
#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(Dog const & src);
		~Dog();

		Dog &	operator=(Dog const & rhs);

		virtual void	makeSound(void) const;
		virtual void	printAllIdeas(void) const;
		Brain& 	getBrain(void);

	private:
		Brain	*_brain;

};
