#include "ScalarConverter.hpp"

int main(int argc, char **argv) 
{
	if (argc != 2) 
	{
		std::cout << "Invalid input" << std::endl;
		return (1);
	}

	try {
		ScalarConverter a(argv[1]);
		a.convert();
	} catch(std::exception &err) 
	{
		std::cout << err.what() << std::endl;
	}
}