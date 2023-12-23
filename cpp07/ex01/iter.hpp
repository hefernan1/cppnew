#pragma once
#include <iostream>
#include <stdint.h>

template<typename T>
void	print(T &n) { std::cout << n << " "; }

template<typename T>
void	iter(T *array, int size, void (*f)(T&)) {
	for (int i = 0; i < size; i++)
		f(array[i]);
}