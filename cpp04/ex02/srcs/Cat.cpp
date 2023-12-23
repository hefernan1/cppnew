#include "Cat.hpp"

Cat::Cat(void) : AAnimal()
{
	_brain = new Brain;
	this->_type = "cat";
	std::cout << "Cat has been created."  << std::endl;
}

Cat::Cat(Cat const & src) : AAnimal(src), _brain(new Brain(*src._brain)) //_brain(src._brain) remove comment to explain the deep copy
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat has been destructed." << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaouuuuuuu" << std::endl;
}

void	Cat::printAllIdeas(void) const
{
	this->_brain->printIdeas();
}

Brain& Cat::getBrain(void){
	return (*this->_brain);
};

Cat &	Cat::operator=(Cat const & rhs)
{
	std::cout << "Cat Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		*this->_brain = *rhs._brain;
	}
	return(*this);
}