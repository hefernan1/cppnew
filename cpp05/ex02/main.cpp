#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main(void)
{
	ShrubberyCreationForm	f1("arbre");
	std::cout << f1 << std::endl;
	ShrubberyCreationForm	ff1("tree");
	f1 = ff1;
	Bureaucrat				b1("bob", 10);

	std::cout << f1 << std::endl;
	b1.executeForm(f1);
	b1.signForm(f1);
	std::cout << f1 << std::endl;
	b1.executeForm(f1);

	std::cout << std::endl;

	Bureaucrat				b2("lol", 45);
	RobotomyRequestForm		f2("lol");

	b2.executeForm(f2);
	b2.signForm(f2);
	std::cout << f2 << std::endl;
	b2.executeForm(f2);

	std::cout << std::endl;

	Bureaucrat				b3("bill", 6);
	PresidentialPardonForm	f3("bill");

	b3.signForm(f3);
	b3.executeForm(f3);

	std::cout << std::endl;

	Bureaucrat				b4("Paul", 140);
	PresidentialPardonForm	f4("Paul");

	b4.signForm(f4);
	b4.executeForm(f4);

	std::cout << std::endl;
	return (0);
}