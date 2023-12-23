#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main(void)
{
	std::cout << "\e[1;31mCouldn't sign cause of to low signGrade\e[0m" << std::endl;
	try
	{
		Bureaucrat	bob("bob", 150);
		std::cout << bob << std::endl;
		Form	f1("Amazing Form", 10, 10);
		std::cout << f1 << std::endl;
		bob.signForm(f1);
		std::cout << f1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\e[1;32m\nSign success example\e[0m" << std::endl;
	try
	{
		Bureaucrat	bill("bill", 42);
		std::cout << bill << std::endl;
		Form		f2;
		std::cout << f2 << std::endl;
		bill.signForm(f2);
		std::cout << f2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\e[1;32m\n1st Sign failed cause of to low grade but after gradeUp it's a success !\e[0m" << std::endl;
	try
	{
		Bureaucrat	Michel("Michel", 11);
		std::cout << Michel << std::endl;
		Form		f3("Contrat", 10, 10);
		std::cout << f3 << std::endl;
		Michel.signForm(f3);
		std::cout << f3 << std::endl;
		Michel.gradeUp();
		Michel.signForm(f3);
		std::cout << f3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\e[1;31m\nGradeDown Error\e[0m" << std::endl;
	try
	{
		Bureaucrat	lol("lol", 150);
		std::cout << lol << std::endl;
		lol.gradeDown();
		std::cout << lol << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\e[1;32m\nGradeDown Success\e[0m" << std::endl;
	try
	{
		Bureaucrat	lol("lol", 149);
		std::cout << lol << std::endl;
		lol.gradeDown();
		std::cout << lol << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\e[1;31m\nGradeUp Error\e[0m" << std::endl;
	try
	{
		Bureaucrat	lola("lola", 1);
		std::cout << lola << std::endl;
		lola.gradeUp();
		std::cout << lola << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\e[1;32m\nGradeUp Success\e[0m" << std::endl;
	try
	{
		Bureaucrat	lola("lola", 2);
		std::cout << lola << std::endl;
		lola.gradeUp();
		std::cout << lola << std::endl;
		lola.gradeUp();
		std::cout << lola << std::endl;
		lola.gradeUp();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\e[1;31m\nBad Form init with to low grade Error\e[0m" << std::endl;
	try
	{
		Form	f4("Low_form", 160, 145);
		std::cout << f4 << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\e[1;31m\nBad Form init with to High grade Error\e[0m" << std::endl;
	try
	{
		Form	f5("high_form", 0, 10);
		std::cout << f5 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}