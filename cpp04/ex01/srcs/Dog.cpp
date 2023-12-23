#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	_brain = new Brain;
	this->_type = "Dog";
	std::cout << "Dog has been created."  << std::endl;
}

Dog::Dog(Dog const & src) : Animal(src), _brain(new Brain(*src._brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog has been destructed." << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouaaaffff" << std::endl;
}

void	Dog::printAllIdeas(void) const
{
	this->_brain->printIdeas();
}

Brain& Dog::getBrain(void){
	return (*this->_brain);
};

Dog &	Dog::operator=(Dog const & rhs)
{
	std::cout << "Dog Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		*this->_brain = *rhs._brain;
	}
	return(*this);
}