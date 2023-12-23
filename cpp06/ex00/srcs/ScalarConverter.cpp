#include "ScalarConverter.hpp"

char	ScalarConverter::_char = 0;
int		ScalarConverter::_int = 0;
float	ScalarConverter::_float = 0.0;
double	ScalarConverter::_double = 0.0;

bool	ScalarConverter::_nan = false;
bool	ScalarConverter::_inf = false;

double	ScalarConverter::_cast = 0.0;

// construct/destruct

ScalarConverter::ScalarConverter(std::string input) 
{
	if (input.empty()) 
	{	
		throw (ScalarConverter::EmptyString());
	} else if (input == "nanf") 
	{
		_float = std::numeric_limits<float>::quiet_NaN();
		_nan = true;
	} else if (input == "nan") 
	{
		_double = std::numeric_limits<double>::quiet_NaN();
		_nan = true;
	} else if (input == "+inf") 
	{
		_double = std::numeric_limits<double>::infinity();
		_inf = true;
	} else if (input == "-inf") 
	{
		_double = -std::numeric_limits<double>::infinity();
		_inf = true;
	} else if (input == "+inff") 
	{
		_float = std::numeric_limits<float>::infinity();
		_inf = true;
	} else if (input == "-inff") 
	{
		_float = -std::numeric_limits<float>::infinity();
		_inf = true;
	} else 
	{
		findType(input);
	}
}

ScalarConverter::ScalarConverter(ScalarConverter &obj) 
{
	_char = obj._char;
	_int = obj._int;
	_float = obj._float;
	_double = obj._double;
	_nan = obj._nan;
	_inf = obj._inf;
	_cast = obj._cast;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &rhs) 
{
    if (this != &rhs) 
	{
        _char = rhs._char;
        _int = rhs._int;
        _float = rhs._float;
        _double = rhs._double;
        _nan = rhs._nan;
        _inf = rhs._inf;
        _cast = rhs._cast;
    }
    return *this;
}


// functions

void	ScalarConverter::findType(std::string input) 
{
	_cast = strtod(input.c_str(), NULL);

	if (isChar(input)) 
	{
		_char = input[0];
		_cast = static_cast<double>(input[0]);
	}
	else if ((_cast > INT_MIN && _cast < INT_MAX) && isInt(input))
		_int = atoi(input.c_str());
	else if ((_cast > -FLT_MAX && _cast < FLT_MAX) && isFloat(input))
		_float = atof(input.c_str());
	else if ((_cast > -DBL_MAX && _cast < DBL_MAX) && isDouble(input))
		_double = strtod(input.c_str(), NULL);
	else
		throw(ScalarConverter::BadInput());
}

void ScalarConverter::convert() 
{
	try 
	{
		std::cout	<< "char: "
					<< toChar() << "'"
					<< std::endl;
	} catch (std::exception &err) 
	{
		std::cout << err.what() << std::endl;
	}

	try
	{
		std::cout	<< "int: "
					<< toInt()
					<< std::endl;
	} catch (std::exception &err) 
	{
		std::cout << err.what() << std::endl;
	}

	try 
	{
		std::cout	<< "float: "
					<< std::fixed << std::setprecision(2)
					<< toFloat() << "f"
					<< std::endl;
	} catch (std::exception &err) 
	{
		std::cout << err.what() << std::endl;
	}

	try 
	{
		std::cout	<< "double: "
					<< toDouble()
					<< std::endl;
	} catch (std::exception &err)
	{
		std::cout << err.what() << std::endl;
	}
} 


// detectors


bool	ScalarConverter::isChar(const std::string input)
{
	if (input.size() == 1 && isprint(input[0]))
	{
		if (input[0] >= 48 && input[0] <= 57)
			return (false);
		return (true);
	}
	return (false);
}

bool	ScalarConverter::isInt(const std::string input)
{
	int i = 0;
	
	if (input[0] == '+' || input[0] == '-')
		i++;
	while (input[i])
	{
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	return (true);
}

bool ScalarConverter::isFloat(const std::string input) 
{
	int		i = 0;
	bool	dot = false;
	bool	is_f = false;

	if (input[0] == '-' || input[0] == '+')
		i++;

	while (input[i]) {
		if (!isdigit(input[i])) 
		{
			if (input[i] == '.') 
			{
				if (dot)
					return (false);
				dot = true;
			} 
			else if (input[i] == 'f') 
			{
				if (is_f)
					return (false);
				is_f = true;
			} else 
			{
				return (false);
			}
		}
		i++;
	}
	if (is_f == true)
		return (true);
	return (false);
}

bool ScalarConverter::isDouble(const std::string input) 
{
	int		i = 0;
	bool	dot = false;

	if (input[0] == '-' || input[0] == '+')
		i++;

	while (input[i]) 
	{
		if (!isdigit(input[i])) 
		{
			if (input[i] == '.') 
			{
				if (dot)
					return (false);
				dot = true;
			} else 
			{
				return (false);
			}
		}
		i++;
	}
	return (true);
}

// converters

char	ScalarConverter::toChar()
{
	if (_cast < 0 || _cast > CHAR_MAX || _nan || _inf)
			throw(ScalarConverter::Impossible());
	if (_cast < 32 || _cast > 126)
			throw(ScalarConverter::NonDisplayable());
	else if (_int)
	{
		std::cout << "'";
		return (static_cast<char>(_int));
	}
	else if (_float)
	{
		std::cout << "'";
		return (static_cast<char>(_float));
	}
	else if (_double)
	{
		std::cout << "'";
		return (static_cast<char>(_double));
	}
	std::cout << "'";
	return (_char);
}

int	ScalarConverter::toInt() 
{
	if (_cast < INT_MIN || _cast > INT_MAX || _nan || _inf)
		throw(ScalarConverter::Impossible());
	else if (_char)
		return (static_cast<int>(_char));
	else if (_float)
		return (static_cast<int>(_float));
	else if (_double)
		return (static_cast<int>(_double));
	return (_int);
}


float	ScalarConverter::toFloat() 
{
	if (_cast < -FLT_MAX || _cast > FLT_MAX)
		throw(ScalarConverter::Impossible());
	if (_char)
		return (static_cast<float>(_char));
	else if (_int)
		return (static_cast<float>(_int));
	else if (_double)
		return (static_cast<float>(_double));
	return (_float);
}

double	ScalarConverter::toDouble() {
	if (_cast < -DBL_MAX || _cast > DBL_MAX)
		throw(ScalarConverter::Impossible());
	else if (_char)
		return (static_cast<double>(_char));
	else if (_int)
		return (static_cast<double>(_int));
	else if (_float)
		return (static_cast<double>(_float));
	return (_double);
}


// exceptions

const char *ScalarConverter::EmptyString::what() const throw() 
{
	return ("The string is empty");
}

const char *ScalarConverter::BadInput::what() const throw() 
{
	return ("Bad Input");
}

const char *ScalarConverter::Impossible::what() const throw() 
{
	return ("Impossible");
}

const char *ScalarConverter::NonDisplayable::what() const throw() 
{
	return ("Non displayable");
}