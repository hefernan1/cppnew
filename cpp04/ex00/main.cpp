#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int		main(void)
{
	
	const Animal* meta = new Animal();
	const Animal* i = new Dog();
	const Animal* j = new Cat();
	std::cout << std::endl;
	

	std::cout << i->getType() << ": " << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << std::endl;

	std::cout << j->getType() << ": " << std::endl;
	j->makeSound();
	std::cout << std::endl;

	std::cout << meta->getType() << ": " << std::endl;
	meta->makeSound();
	std::cout << std::endl;

	const WrongAnimal* k = new WrongAnimal();
	std::cout << k->getType() << ": " << std::endl;
	k->makeSound();
	std::cout << std::endl;

	const WrongAnimal* q = new WrongCat();
	std::cout << q->getType() << ": " << std::endl;
	q->makeSound();
	std::cout << std::endl;


	delete meta;
	delete i;
	delete j;
	delete k;
	delete q;
	return (0);
}