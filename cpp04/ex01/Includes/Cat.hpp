#pragma once

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const & src);
		~Cat();

		Cat &	operator=(Cat const & rhs);
		Brain& getBrain(void);
		virtual void	makeSound(void) const;
		virtual void	printAllIdeas(void) const;

	private:
		Brain	*_brain;

};