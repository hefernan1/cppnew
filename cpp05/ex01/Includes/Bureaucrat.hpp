#pragma once

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	public :
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();


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
		int				getGrade(void) const ;
		void			gradeUp(void);
		void			gradeDown(void);
		void			signForm(Form & form);

		Bureaucrat &	operator=(Bureaucrat const & rhs);

	private :
		std::string	const 	_name;
		int 				_grade;
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs);