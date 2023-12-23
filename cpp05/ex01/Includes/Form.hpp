#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public :
		Form();
		Form(std::string name, int gradeSign, int gradeExec);
		Form(Form const & src);
		~Form();

		Form &	operator=(Form const & rhs);
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		std::string		getName(void) const;
		bool			getSigned(void) const;
		int				getGradeExecute(void) const ;
		int				getGradeSign(void) const;
		void			beSigned(Bureaucrat const & bureaucrat);

	private:
		std::string const	_name;
		bool				_signed;
		int const			_toSign;
		int const			_toExec;
};

std::ostream &	operator<<(std::ostream & o, Form const & rhs);