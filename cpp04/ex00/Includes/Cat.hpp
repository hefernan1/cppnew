#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat(void);
        Cat(Cat const & src);
        ~Cat(void);

        Cat &	operator=(Cat const & rhs);

        void	makeSound(void) const;
};