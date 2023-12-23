#include "Array.hpp"
#include <iostream>

int	main() {
	{
		Array<int> arr(15);
		try {
			for (int i = 0; i < 16; i++)
				std::cout << arr[i] << std::endl;	
		} catch (std::exception &err) {
			std::cout << err.what() << std::endl;
		}
	}

	std::cout << "-------------------" << std::endl;
	{
		Array<char> arr(15);
		try {
			for (int i = 0; i < 15; i++)
			{
				arr[i] = 'a';
				std::cout << "'" << arr[i] << "'" << std::endl;	
			}
		} catch (std::exception &err) {
			std::cout << err.what() << std::endl;
		}

		std::cout << "-------------------" << std::endl;
		try {
			std::cout << arr[16] << std::endl;
		} catch (std::exception &err) {
			std::cout << err.what() << std::endl;
		}
	}
	/*int *a = new int();
	std::cout << "a is "<< *a << std::endl;*/
std::cout << "-------------------" << std::endl;
{
	int j = 0;
	Array<int> *arr = new Array<int>(15);
	try {
		for (uint8_t i = 0; i < 16; i++)
		{
			(*arr)[i] = j;
			std::cout << (*arr)[i] << std::endl;
			j++;
		}
		
		}

		catch (std::exception &err) {
			std::cout << err.what() << std::endl;
		}
		delete arr;
	}
}
