#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public :
		AForm();
		AForm(std::string name, int grade, int gradeExec);
		AForm(AForm const & src);
		virtual ~AForm() = 0;

		AForm &	operator=(AForm const & rhs);
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

		class	UnsignedException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		std::string		getName(void) const;
		bool			getSigned(void) const;
		int				getGradeExecute(void) const ;
		int				getGradeSign(void) const;
		virtual void	execute(Bureaucrat const & executor) const;
		void			beSigned(Bureaucrat const & bureaucrat);
		std::string		getTarget(void) const;


	protected:
		std::string const	_name;
		bool				_signed;
		int const			_toSign;
		int const			_toExec;
		std::string			_target;
};

std::ostream &	operator<<(std::ostream & o, AForm const & rhs);