#include "Bureaucrat.hpp"


int main()
{
	std::cout << "\e[1;31mBad init with to Low grade Error\e[0m" << std::endl;
	try
	{
		Bureaucrat	bob("bob", 151);
		std::cout << bob << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\e[1;31m\nBad init with to High grade Error\e[0m" << std::endl;
	try
	{
		Bureaucrat	bill("bill", 0);
		std::cout << bill << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\e[1;31m\nGradeUp Error\e[0m" << std::endl;
	try
	{
		Bureaucrat	patrick("patrick", 1);
		std::cout << patrick << std::endl;
		patrick.gradeUp();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\e[1;31m\nGradeDown Error\e[0m" << std::endl;
	try
	{
		Bureaucrat	alma("alma", 150);
		std::cout << alma << std::endl;
		alma.gradeDown();
		std::cout << alma << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\e[1;32m\nGradeUp example\e[0m" << std::endl;
	try
	{
		Bureaucrat	carlos("carlos", 10);
		std::cout << carlos << std::endl;
		carlos.gradeUp();
		std::cout << carlos << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\e[1;32m\nGradeDown example\e[0m" << std::endl;
	try
	{
		Bureaucrat	toto("toto", 42);
		std::cout << toto << std::endl;
		toto.gradeDown();
		std::cout << toto << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}