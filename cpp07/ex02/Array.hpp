#pragma once
#include <iostream>
#include <stdint.h>

template<typename T>
class Array {
	private:
		T			*_arr;
		int			_len;

	public:
		Array() : _arr(new T[0]), _len(0) {}

		Array(unsigned int n) : _arr(new T[n]), _len(n) {
			for (unsigned int i = 0; i < n; i++)
				_arr[i] = 0;
		}
		
		Array(Array const &obj) : _arr(new T[obj._len]), _len(obj._len) {
			for (int i = 0; i < _len; i++)
				_arr[i] = obj._arr[i];
		}
		
		~Array() { delete[] _arr; }

		Array<T>   &operator=(Array<T> const &rhs) {
			if (this != &rhs) {
				delete[] _arr;
				_len = rhs._len;
				_arr = new T[_len];
				
				for (int i = 0; i < _len; i++)
					_arr[i] = rhs._arr[i];
			}
			return (*this);
		}

		T	&operator[](int index) {
			if (index >= _len)
				throw InvalidIndex();
			return (_arr[index]);
		}

		class InvalidIndex : public std::exception {
			const char	*what() const throw() {
				return ("Invalid index");
			}
		};
		
		int	size() { return (_len); }
};

