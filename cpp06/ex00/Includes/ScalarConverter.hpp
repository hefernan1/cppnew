#pragma once

#include <iostream>
#include <limits>
#include <climits>
#include <iomanip>
#include <cstdlib>
#include <float.h>

class ScalarConverter
{
	private :

		static char _char;
		static int _int;
		static float _float;
		static double _double;
		static bool _nan;
		static bool _inf;
		static double _cast;

	public :

		ScalarConverter(std::string input);
		ScalarConverter(ScalarConverter &obj);
		virtual ~ScalarConverter();

		ScalarConverter	&operator=(ScalarConverter &rhs);

		static char		toChar();
		static int		toInt();
		static float	toFloat();
		static double	toDouble();
		
		static bool	isChar(const std::string input);
		static bool	isInt(const std::string input);
		static bool	isFloat(const std::string input);
		static bool	isDouble(const std::string input);

		static void		findType(std::string input);
		static void		convert();

		class EmptyString : public std::exception {
			virtual const char *what() const throw();
		};

		class BadInput : public std::exception {
			virtual const char *what() const throw();
		};

		class Impossible : public std::exception {
			virtual const char *what() const throw();
		};

		class NonDisplayable : public std::exception {
			virtual const char *what() const throw();
		};

};