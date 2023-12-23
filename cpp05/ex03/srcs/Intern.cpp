#include "Intern.hpp"


Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const & src)
{
	*this = src;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern has been destroyed" << std::endl;
}

const char * Intern::WrongFormNameException::what() const throw() 
{
	return("Intern WrongFormNameException");
}

AForm*	Intern::makeForm(std::string form, std::string target)
{
	AForm	*(Intern::*ptrfct[3])(std::string) = {&Intern::_createShrubberyForm, &Intern::_createRobotomyForm, &Intern::_createPresidentialForm};
	std::string	fctName[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (int i = 0; i < 3; i++)
	{
		if (fctName[i] == form)
		{
			std::cout << "Intern create " << form << std::endl;
			return ((this->*(ptrfct[i]))(target));
		}
	}
	throw Intern::WrongFormNameException();
	return (NULL);
}

Intern & Intern::operator=(Intern const & rhs)
{
	std::cout << "Intern assignation operator called" << std::endl;
	(void)rhs;
	return (*this);
}

AForm*	Intern::_createShrubberyForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::_createRobotomyForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::_createPresidentialForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}