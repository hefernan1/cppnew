#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int		main(void)
{
	int		nbAnimals = 4;
	int		nbDogs = nbAnimals / 2;
	int		nbCats = nbAnimals - nbDogs;

	std::cout << "Constructors" << std::endl;
	Animal	*animals[nbAnimals];
	std::cout << "-----------------------------------------------------------" << std::endl;
	// Dogs creation
	for (int i = 0; i < nbDogs; i++)
	{
		animals[i] = new Dog;
		std::cout << "animals[" << i << "] is a " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
		std::cout << std::endl;
	}
	// Cats creation
	for (int i = nbDogs; i < (nbCats + nbDogs); i++)
	{
		animals[i] = new Cat;
		std::cout << "animals[" << i << "] is a " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
		std::cout << std::endl;
	}

	std::cout << "Numbers of animals is "<< nbAnimals << " so we have "
			<< nbDogs << " Dogs and " << nbCats
			<< " Cats\n" << std::endl;

	std::cout << "animals[1] type : " << animals[1]->getType() << std::endl;
	animals[1]->printAllIdeas();
	std::cout << "\n-----------------------------------------------------------" << std::endl;
	std::cout << "\nDEEP COPY :" << std::endl;
	Dog	*bill = new Dog;
	Dog	bob(*bill);
	delete bill;
	std::cout << "type : " << bob.getType() << std::endl;
	bob.makeSound();
	bob.printAllIdeas();
	std::cout << "\n-----------------------------------------------------------" << std::endl;
	std::cout << "\nDestructors\n" << std::endl;

	for(int i(0); i < nbAnimals; i++)
		delete animals[i];
	std::cout << "\n-----------------------------------------------------------" << std::endl;
	std::cout << std::endl << "Deep copy\n" << std::endl;
		Dog* dogs[2];
		Cat* cats[2];
		dogs[0] = new Dog();
		dogs[1] = new Dog(*dogs[0]);
		cats[0] = new Cat();
		cats[1] = new Cat(*cats[0]);

		std::cout << "dogs[0] idea address: " << &(dogs[0]->getBrain()._ideas[0]) << std::endl;
		std::cout << "dogs[1] idea address: " << &(dogs[1]->getBrain()._ideas[0]) << std::endl;
		std::cout << "cats[0] idea address: " << &(cats[0]->getBrain()._ideas[0]) << std::endl;
		std::cout << "cats[1] idea address: " << &(cats[1]->getBrain()._ideas[0]) << std::endl;

		delete dogs[0];
		delete dogs[1];
		delete cats[0];
		delete cats[1];
	return (0);
}

/*
	Dog	*dog1 = new Dog;
	Dog *dog2 = new Dog;
	dog1->printAllIdeas();
	dog1->_brain->_ideas[3] = "lol"; mettre brain en public si besoin
	*dog2 = *dog1;
	dog1->printAllIdeas();
	dog2->printAllIdeas(); */